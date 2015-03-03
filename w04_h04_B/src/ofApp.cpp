#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	myball.setup();
	gravity.set(0,50);
}

//--------------------------------------------------------------
void ofApp::update(){
	myball.resetForces();
	myball.gravity(gravity);
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
		


begin = clock();
/* here, do your time-consuming job */

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<"time"<<time_spent;
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
