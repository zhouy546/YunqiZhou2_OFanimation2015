#pragma once
#include "ofMain.h"
class ball
{
public:
void setup();
void update();
void draw();
void resetForces();
void gravity(ofVec2f _force);
ofVec2f acc,vel,Tpos,currentPos;
ofVec2f ObTpos,ObcurrentPos;
float angle;
};

