#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	a=1.0;
	pct=0.0;
	alpha=0.0;
	myball.setup(ofVec2f(ofRandom(0,500),ofRandom(0,500)),ofVec2f(ofRandom(0,500),ofRandom(0,500)),0.0,255);
}

//--------------------------------------------------------------
void ofApp::update(){
	if(pct<0.99){
		pct+=0.01; 
	}else{pct+=0.001;}

		if(alpha>0.99){
	alpha=0.99;
	}
	if(alpha<0.01){
	alpha=0.01;
	}
	alpha=alpha+a*0.01;

	myball.update(pct,alpha);
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	pct=0;
	a=-a;
	myball.setNewPosition(ofVec2f(x, y),100);
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
