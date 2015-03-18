#pragma once

#include "ofMain.h"
#include "ofxFluid.h"
class fluid
{
public:
		
	void creatpoint();
		void setup();
		void update(float _R,float _G ,float _B);
		void draw(float _R,float _G,float _B);
		float Maxspeed, Minspeed;

		ofxFluid myfluid;

		ofVec2f oldM;

		ofVec2f pos,vel,acc;

		float size;
};

