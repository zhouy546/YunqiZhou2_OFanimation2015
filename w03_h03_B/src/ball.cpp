#include "ball.h"


void ball::setup()
{
		offset = 10;
}


void ball::update(int i)
{
	 x = ofGetMouseX();
	 y = ofGetMouseY();
	MousePos = ofVec2f(x,y);

	posX=offset*i;
	posY=ofGetHeight()/2+Tpi*100;
		Pos = ofVec2f(posX,posY);

	//ifxxxxxx
	dis=ofDist(x,y,posX,posY);
			 Tpi= tan(ofGetElapsedTimef()+dis/1000);
	 

}

void ball::draw()
{

	float alpha= ofMap(dis,0,1280,250,0);
	float size = ofMap(dis,0,1000,30,5);
		    

	ofCircle(Pos,size);
	ofSetColor(ofColor(255,100,100,alpha));

}
