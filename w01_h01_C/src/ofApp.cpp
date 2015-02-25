#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	a=1.0;
	pct=0.0;
	alpha=0.0;
	for (int i =0;i<N;i++){
	myball[i].setup(ofVec2f(ofRandom(0,1000),ofRandom(0,1000)),ofVec2f(ofRandom(0,1000),ofRandom(0,1000)),0.0,255);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if(pct<0.99){
		pct+=0.01; 
	}else{pct+=0.005;}

	if(alpha>0.99){
	alpha=0.99;
	}
	if(alpha<0.01){
	alpha=0.01;
	}
	alpha=alpha+a*0.01;

	for (int i =0;i<N;i++){
	myball[i].update(pct,alpha);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i =0;i<N;i++){
	myball[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	setup();
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
	a=-a;
	for (int i =0;i<N;i++){
		myball[i].setNewposition(ofVec2f(x,y));
	}
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
