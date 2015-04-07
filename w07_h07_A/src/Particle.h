#pragma once
#include "ofMain.h"
class Particle
{
public:
  void soundSetup();
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw(float _size);
    
    ofVec2f pos, vel, acc;

};

