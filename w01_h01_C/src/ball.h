#pragma once
#include "ofMain.h"
class ball
{
public:
	void setup(ofVec2f _initPos,ofVec2f _finalPos,float _initT,float _finalT);
	void update(float _pct, float _alpha);
	void draw();
	void setNewposition(ofVec2f _newPos);

private:
	ofVec2f initPos, currentPos, finalPos;
	float initT,currentT,finalT;
	float pct, R, G, B,alpha;
};

