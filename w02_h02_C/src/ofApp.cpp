#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofBackground(0);
	ofSetColor(255,100);
	ofSetBackgroundAuto(false);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	for(int i= 0;i<N;i++){
	myball[i].steup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
		
			
	
}

//--------------------------------------------------------------
void ofApp::draw(){
		
	for(int i= 0;i<N;i++){
	myball[i].draw();
	}
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
