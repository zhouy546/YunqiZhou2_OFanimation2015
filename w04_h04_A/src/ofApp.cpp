#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	myball.setup();
	ofSetFrameRate(60);
	gravity.set(0,6);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	myball.applyForce(gravity*myball.mass);
	myball.applyFampingForce(0.01*myball.mass);
	myball.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	myball.draw();
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
	myball.vel.set(0,0);
	myball.acc.set(myball.pos.x-ofGetPreviousMouseX(),myball.pos.y-ofGetPreviousMouseY());
	
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
