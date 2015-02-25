#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	mycustomCircle.setup(ofVec2f(ofRandom(0,500),ofRandom(0,500)),ofVec2f(ofRandom(0,500),ofRandom(0,500)),ofVec2f(ofRandom(0,500),ofRandom(0,500)),ofVec2f(ofRandom(0,500),ofRandom(0,500)));
	pct =0;
}

//--------------------------------------------------------------
void ofApp::update(){
	if(pct<0.99){
	pct+=0.01;
	
	}else{
		pct+=0.001;
	}
	mycustomCircle.update(pct);
}

//--------------------------------------------------------------
void ofApp::draw(){
	mycustomCircle.draw();
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
	pct = 0.0;
    
    mycustomCircle.setNewPosition(ofVec2f(x, y));
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
