#include "ofApp.h"
#include <algorithm>

float t;

const float complexity = .8; // wind complexity
const float timeSpeed = .004; // wind variation speed
const float phase = TWO_PI; // separate u-noise from v-noise

const float removeAllTime = 40;

// small amount of particles
//const float gridSize = 10.3;
//const float dotSize  = 7.0;
//const int takeFalloff = 4;
//const float fallOffTime = 2.1;

// a lot of particles
const float gridSize = 2.8;
const float dotSize  = 2.8;
const int takeFalloff = 40;
const float fallOffTime = .4;



ofVec2f ofApp::getField(ofVec2f* position) {
    
    t = ofGetFrameNum() * timeSpeed;

	float normx = ofNormalize(position->x, 0, ofGetWidth());
	float normy = ofNormalize(position->y, 0, ofGetHeight());
	float u = ofNoise(t + phase, normx * complexity + phase, normy * complexity + phase);
	float v = ofNoise(t - phase, normx * complexity - phase, normy * complexity + phase);
	return ofVec2f(u, v);
}




void ofApp::startParticles(){
  //  for (auto& p : particles)
   // {
   for(std::vector<Particle*>::iterator it = particles.begin();it != particles.end();++it )
       
   {
       Particle* p = (*it);
       p->position->set(p->targetPosition + ofVec2f(ofGetWidth(),ofGetHeight()) );
       p->waitTime = p->delay;
       p->isMoving = true;
       p->reset();
    }
  
}
//--------------------------------------------------------------
void ofApp::setup() {


	//sound```````````````````````````````````````````````````````````````````````````````
	soundStream.listDevices();
	int bufferSize =256;
	left.assign(bufferSize,0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    // Rasp Pi window size
   // ofSetWindowShape(720, 480);
    
    ofSetFullscreen(false);
    ofSetFrameRate(60);
    //ofHideCursor();
    ofDisableAlphaBlending();
   // ofDisableAntiAliasing(); //<-- only when speed is really dramatic

    
    txtData.loadImage("yunqi.png");

    unsigned char * pixels = txtData.getPixels();

    Particle* particle;
    
    int i=0;
    for (float x = 0 ; x < txtData.getWidth(); x += gridSize*2) {
        for (float y = 0 ; y < txtData.getHeight(); y+= gridSize*2 ) {
            if(txtData.getColor(x, y).getBrightness() < 255){
                ++i;
            }
        }
    }
    
    // reserve space before adding otherwise the pointers get invalid by the automatic resizing of std::vector
    particles.reserve(i);
    vboColors.reserve(i);
    vboPoints.reserve(i);

    for (float x = 0 ; x < txtData.getWidth(); x += gridSize*2) {
        for (float y = 0 ; y < txtData.getHeight(); y+= gridSize*2 ) {

            ofColor cur = txtData.getColor(x, y);
            
            if(cur.getBrightness() < 255){

                particle = new Particle();
                particles.push_back(particle);
                
                vboColors.push_back(ofFloatColor());
                vboPoints.push_back(ofVec2f());
                
                particle->color = &(vboColors.back());
                particle->position = &(vboPoints.back());
                
                particle->targetPosition.set(x,y) ;
                
                particle->color->set(255, 255, 255);
                particle->delay = ofRandom(0.0,3.5);
                particle->position->set(particle->targetPosition+ ofVec2f(ofGetWidth(),ofGetHeight()));
                
            }
        }
    }
    

    startParticles();
    
    currentState = STATE_BLANK;
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	ofxKinectNui::InitSetting initSetting;
	initSetting.grabVideo = false;
	initSetting.grabDepth = false;
	initSetting.grabAudio = false;
	initSetting.grabLabel = false;
	initSetting.grabSkeleton = true;
	initSetting.grabCalibratedVideo = false;
	initSetting.grabLabelCv = false;

	initSetting.videoResolution = NUI_IMAGE_RESOLUTION_640x480;
	initSetting.depthResolution = NUI_IMAGE_RESOLUTION_640x480;
	kinect.init(initSetting);
//	kinect.setMirror(false); // if you want to get NOT mirror mode, uncomment here
//	kinect.setNearmode(true); // if you want to set nearmode, uncomment here
	kinect.open();

	kinect.addKinectListener(this, &ofApp::kinectPlugged, &ofApp::kinectUnplugged);
	

	ofSetVerticalSync(false);

	kinectSource = &kinect;
	angle = kinect.getCurrentAngle();
	
	bPlugged = kinect.isConnected();
	//nearClipping = kinect.getNearClippingDistance();
	//farClipping = kinect.getFarClippingDistance();
	



	ofSetFrameRate(60);
	
	//calibratedTexture.allocate(kinect.getDepthResolutionWidth(), kinect.getDepthResolutionHeight(), GL_RGB);

	skeletonDraw_ = new ofxKinectNuiDrawSkeleton();

	kinect.setSkeletonDrawer(skeletonDraw_);

}

//--------------------------------------------------------------
void ofApp::update() {
	
	//particle_sound```````````````````````````````````````````````````````````````````````````````````````

	//sound
		//lets scale the vol up to a 0-1 range 
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
		speed = scaledVol*5;
		g = max(g,speed);
		
   /// return;
    int skipSome=0;

    for(std::vector<Particle*>::iterator it = particles.begin();it != particles.end();++it )
    {
        Particle* p = (*it);
        
        if (p->position->x < -dotSize || p->position->y < -dotSize) {
            continue;
        }

        // mouse stuff
        ofVec2f dist = *(p->position) - ofVec2f(x,y);

        if(dist.length() < 150){
            
            float force = (150-dist.length()) / 150;
            p->pushForce += (dist * force *0.01) ;
            
            if(ofGetMousePressed()){
                if(++skipSome >= 20){
                    skipSome =0;
                    p->startFallOff(dist.length()/150.0 * 2.0);
                }
            }
            
        }

        p->offset = getField(p->position);
        p->update();
    }


    
    
    if(currentState == STATE_BLANK){
		g=0;
        newMessage -= ofGetLastFrameTime();
        if(newMessage <= 0){
            currentState = STATE_NEW_MESSAGE;
            removeAllTriger = removeAllTime;
            startParticles();
            fallOffTriger = ofGetElapsedTimef();
            std::cout << "new state STATE_NEW_MESSAGE " << std::endl;
        }
    }else if(currentState == STATE_NEW_MESSAGE){
        removeAllTriger= g;
	//	cout<<removeAllTriger<<endl;///11111111111111
        if(fallOffTriger > 0 && (ofGetElapsedTimef() - fallOffTriger) > fallOffTime){
            fallOffTriger = ofGetElapsedTimef();
            
            int take =  std::min((int)particles.size(),takeFalloff);
            int randomIndex = ofRandom(particles.size()-take-1);
            
            for(int i = randomIndex ; i < randomIndex + take;++i){
                particles[i]->startFallOff(ofRandom(.8));
            }
        }
        
        if(removeAllTriger >4.9){
            currentState = STATE_REMOVE_ALL;
            std::cout << "new state STATE_REMOVE_ALL " << std::endl;

            newMessage = 13;
            removeAll();
			
        }
    }else if(currentState == STATE_REMOVE_ALL){
        currentState = STATE_BLANK;

    
    }
//`````````````````````````````````````````````````````````````````````````````````````
	kinectSource->update();

}
void ofApp::removeAll(){
    for(std::vector<Particle*>::iterator it = particles.begin();it != particles.end();++it )
    {
        (*it)->startFallOff(ofRandom(5.8));

    }

}
//--------------------------------------------------------------
void ofApp::draw() {
		ofBackground(0);
	
	// Draw video only
	
		kinect.drawSkeleton(0, 0, 1024, 768);	// draw skeleton images on video images
		
		
		x= ofMap(skeletonDraw_->righthandpos.x,0,680,0,ofGetWidth());
		y= ofMap(skeletonDraw_->righthandpos.y,0,480,0,ofGetHeight());
		ofSetColor(255,0,0);
		ofCircle(x,y, 20);

//```````````````````````````````````````````````````````````````````````````````````````````````		   
    glPointSize(dotSize);

    vbo.setVertexData (&vboPoints[0], (int)vboPoints.size(), GL_DYNAMIC_DRAW);
    vbo.setColorData(&vboColors[0], (int)vboColors.size(), GL_STATIC_DRAW);
    
    vbo.draw(GL_POINTS, 0, (int)vboPoints.size());
   
    ofSetColor(255);
    ofDrawBitmapString(ofToString(particles.size()) + " particles " +ofToString(ofGetFrameRate()) + " fps" , 10, 10);
    
}
	
void ofApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
}

//--------------------------------------------------------------



//--------------------------------------------------------------
void ofApp::exit() {
	
	
		delete skeletonDraw_;
		skeletonDraw_ = NULL;
	
	kinect.setAngle(0);
	kinect.close();
	kinect.removeKinectListener(this);



}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::kinectPlugged(){
	bPlugged = true;
}

//--------------------------------------------------------------
void ofApp::kinectUnplugged(){
	bPlugged = false;
}


