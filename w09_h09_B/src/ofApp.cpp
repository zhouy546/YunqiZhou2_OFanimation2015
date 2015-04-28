#include "ofApp.h"
const int N =400;
float spectrum[ N ];
//--------------------------------------------------------------
void ofApp::setup(){

	//sound-------------------------------------------------------------------------
	sound.loadSound("sound.mp3");
	sound.setLoop(true);
	sound.play();
	//-----------------------------------------------
	ofBackground(0);
	width=20;
	height = 20;
	res = 10;
	for(int y = -height/2;y<height/2;y++){
		for (int x = -width/2; x < width/2; x++)
		{
			mesh.addVertex(ofPoint(x*res,y*res));
		}
	}

	for (int y = 0; y<height-1;y++){
	
		for(int x = 0;x<width-1;x++){
			mesh.addIndex(x+y*width);
			mesh.addIndex(x+1+y*width);
			mesh.addIndex(x+(y+1)*width);

			mesh.addIndex((x+1)+y*width);
			mesh.addIndex((x+1)+(y+1)*width);
			mesh.addIndex(x+(y+1)*width);

		}
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	//sound--------------------------------------------------
	ofSoundUpdate();
	float *val = ofSoundGetSpectrum(N);
	
	for ( int i=0; i<N; i++ ) {
		spectrum[i] *= 0.97;	//Slow decreasing
		spectrum[i] = max( spectrum[i], val[i] );
	}


	//
	for (int y = 0; y<width; y++)
	{
		for (int x = 0; x < height; x++)
		{

			int index = y*width+x;
			if(index<height*width/2){
				q = N-index*2-1;
			}else{q=abs(N-index*2+1);
			
			}

		ofVec3f pos =mesh.getVertex(index);

		
	//	int height = abs((width*height)-x*2-y*width*2);
			pos.z = -spectrum[q]*100;
			mesh.setVertex(index,pos);
		}

	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();
	easyCam.begin();
	mesh.drawWireframe();
	easyCam.end();
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
