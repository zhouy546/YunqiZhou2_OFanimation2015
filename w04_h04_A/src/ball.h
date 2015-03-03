#pragma once
#include "ofMain.h"
class ball
{
public:
void setup();
void update();
void draw();
void resetForces();
void applyForce(ofVec2f force);
void applyFampingForce(float damping);
ofVec2f acc,vel, pos;
float R,mass;
};

