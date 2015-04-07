#include "ofApp.h"
const int N = 300;		//Number of bands in spectrum
float spectrum[ N ];	//Smoothed spectrum values
float Rad = 500;		//Cloud raduis parameter
float Vel = 0.1;		//Cloud points velocity parameter
int bandRad = 2;		//Band index in spectrum, affecting Rad value
int bandVel = 100;		//Band index in spectrum, affecting Vel value

const int n = 300;		//Number of cloud points	

//Offsets for Perlin noise calculation for points
float tx[n], ty[n];				
ofPoint p[n];			//Cloud's points positions

float time0 = 0;		//Time value, used for dt computing

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(60);
	ofBackground(0);
		sound.loadSound( "sound.mp3" );	
	sound.setLoop( true );
	sound.play();

		for (int i=0; i<N; i++) {
		spectrum[i] = 0.0f;
	}
		 for (int i = 0; i < n; i++) {
		
        Particle myParticle;
		myParticle.setup();
        particles.push_back(myParticle);
		  
    }

}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofSoundUpdate();

	float *val = ofSoundGetSpectrum(N);

	for ( int i=0; i<N; i++ ) {
		spectrum[i] *= 0.97;	
		spectrum[i] = max( spectrum[i], val[i] );
	}

	
	   for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForces();
	

        //get the force of the flowfield at the particle position

		 frc = ofVec2f(ofRandom(-.5,.5)*spectrum[i],ofRandom(-.5,.5)*spectrum[i]);

	
	
        
        //apply force to the particle
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
        
    }


	   
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//ofPushMatrix();
	//ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
	for (int i = 0; i < particles.size(); i++){
		float size =spectrum[i]*20 ;
		particles[i].draw(size);
		
		for(int j = 0; j < particles.size();j++){
			float dis = 100; 

			if(ofDist(particles[i].pos.x,particles[i].pos.y,particles[j].pos.x,particles[j].pos.y)<dis&&size>10){
				ofLine(particles[i].pos,particles[j].pos);
			}

		}
	
    }
		//ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
