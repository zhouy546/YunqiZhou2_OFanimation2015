#pragma once
#include "ofMain.h"
class ball
{
public:
void setup();
void update(ofVec2f _dest);
void draw();

ofVec2f initpos,currentpos; 
};

