#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(60);
	for(int i = 0 ; i<N; i++){
mycircle[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
		
		for(int i = 0 ; i<N; i++){
			mycircle[i].draw(i);
			if(i<N-4){
			
			ofLine(mycircle[i].Pos,mycircle[i+1].Pos);
			ofLine(mycircle[i].Pos,mycircle[i+4].Pos);
			}else{
	ofLine(mycircle[i].Pos,mycircle[i+1].Pos);		
			}
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
