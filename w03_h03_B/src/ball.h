#pragma once
#include "ofMain.h"
class ball
{
public:
	void setup();
	void update(int i);
	void draw();
	ofVec2f Pos, MousePos;
		float offset; 
	float Tpi;
	float x,y,posX,posY;
	float dis;

};

