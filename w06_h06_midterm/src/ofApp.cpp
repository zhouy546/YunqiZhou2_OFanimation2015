#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	 N = 0;
		R =255;
	G =255;
	B =255;
			ofEnableAlphaBlending();
	ofBackground(255);
	myfluid.setup();

	myfluid.creatpoint();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	changeC();
	myfluid.update(R,G,B);

}

//--------------------------------------------------------------
void ofApp::draw(){
	myfluid.draw(R,G,B);
}

//--------------------------------------------------------------
void ofApp::changeC(){
		dis = ofDist(myfluid.pos.x,myfluid.pos.y,ofGetWidth()/2,ofGetHeight()/4);
	if(dis<=50){
		
		N++;
		if(N == 1){
		R=ofRandom(0,1);
			G=ofRandom(0,1);
			B=ofRandom(0,1);
			cout<<"i am working";
			cout<<"r"<<R;
			cout<<"G"<<G;
			cout<<"B"<<B;
		}			
	}else{N = 0;}
}



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
