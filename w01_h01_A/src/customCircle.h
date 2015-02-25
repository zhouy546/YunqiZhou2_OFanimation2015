#pragma once
#include "ofMain.h"
class customCircle
{
public:
	customCircle();
	void setup(ofVec2f _initPos,ofVec2f _finalPos,ofVec2f _initPos1,ofVec2f _finalPos1);
	void update(float pct);
	void draw();
	void setNewPosition(ofVec2f _newPos);
private:

	ofVec2f initPos, finalPos, currentPos , currentPos1, initPos1, finalPos1;
	float pct;
};

