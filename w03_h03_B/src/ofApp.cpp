#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		ofBackground(0);
	ofSetFrameRate(60);
	for(int i = 0 ; i<N; i++){
myball[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){
		for(int i = 0 ; i<N; i++){
			myball[i].update(i);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i = 0 ; i<N; i++){
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
