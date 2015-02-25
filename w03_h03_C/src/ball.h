#pragma once
#include "ofMain.h"
class ball
{
public:
void setup();
void update(int i);
void draw();
	float offset; 
	float Tpi;
	ofVec2f Pos;
	ofVec2f Mouse;
	float distance,size;
};

