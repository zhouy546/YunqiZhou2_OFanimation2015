#include "ball.h"


void ball::setup()
{
	offset = 40;
	size = 10;
}


void ball::update(int i)
{
	
	 Pos = ofVec2f(20+offset*i,ofGetHeight()/2+Tpi*100);
	Mouse = ofVec2f(ofGetMouseX(),ofGetMouseY());
		float PosX=20+offset*i;
		float PosY=ofGetHeight()/2+Tpi*100;


		float MouseX=ofGetMouseX();
		float MouseY=ofGetMouseY();
		distance=ofDist(PosX,PosY,MouseX,MouseY);
		if(distance>=100){
		Tpi= sin(ofGetElapsedTimef()+20*i);
			ofSetColor(ofColor(200,distance/10,0,255));
			size =10;
		}else{
			ofSetColor(ofColor(255,52,199,255));
			Pos= ofVec2f(MouseX+ofRandom(0,20),MouseY+ofRandom(0,20));
			size = ofRandom(5,20);
		}
 
}

void ball::draw()
{
	ofCircle(Pos,size);
}