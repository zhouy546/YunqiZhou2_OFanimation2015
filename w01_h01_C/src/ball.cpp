#include "ball.h"


void ball::setup(ofVec2f _initPos,ofVec2f _finalPos,float _initT,float _finalT)
{
	initPos=_initPos;
	finalPos=_finalPos;
	R=ofRandom(0,255);
	G=ofRandom(0,255);
	B=ofRandom(0,255);
}


void ball::update(float _pct,float _alpha)
{
	alpha=_alpha;
	pct=_pct;
	currentPos= (1-pct)*initPos+pct*finalPos;
	currentT = (1-alpha)*initT+alpha*finalT;
}


void ball::draw()
{
	ofCircle(currentPos,10);
	ofSetColor(ofColor(R,G,B,currentT));
}

void ball::setNewposition(ofVec2f _newPos)
{
	initPos=currentPos;
	finalPos= _newPos;
}
