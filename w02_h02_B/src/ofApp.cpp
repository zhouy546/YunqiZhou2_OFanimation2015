#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		mult = 0.03;
	noisePixels.allocate(ofGetWidth(),ofGetHeight(),OF_IMAGE_COLOR);
	offset=0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if(offset<=255){
	offset+=1;
	}else{offset= 0;}
	for(int y=0; y <ofGetHeight();y++){
		for(int x=0; x <ofGetWidth();x++){
				float myNoise= ofNoise(x*mult,y*mult);
				float r=( 1-myNoise)*200-offset ;
				float g=( myNoise)*200;
				float b=	myNoise*200+offset;
			ofColor color = ofColor(r,g,b);
			noisePixels.setColor(x,y,color);
	 
		}
	}



	noiseImg.setFromPixels(noisePixels.getPixels(),noisePixels.getWidth(),noisePixels.getHeight(),OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::draw(){
			noiseImg.draw(0,0);
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
