#include "ball.h"


void ball::setup()
{
	mass = 3;
	R=20;
	pos= ofVec2f(ofGetWidth()/2,ofGetHeight()-19);
	//acc.set(1,1);
}

void ball::resetForces(){
acc*=0;

} 

void ball::applyForce(ofVec2f force){
	acc-=force/mass;
}

void ball::applyFampingForce(float damping){
	acc-=vel.getNormalized()*damping;
}

void ball::update()
{
	
	


	vel+=0.001*-acc;
	pos+=vel;
		//strain
	
	if(pos.x<R){
	pos.x=R;
	vel.x*=-.5;
	
	}
	
	if(pos.x > ofGetWidth()-R){
		pos.x=ofGetWidth()-R;
	vel.x*=-.5;
	}

	if(pos.y<R){
		pos.y=R;
	vel.y*=-.5;
	}

	if(pos.y > ofGetHeight()-R){
		pos.y=ofGetHeight()-R;
	vel.y*=-.5;
	}
}

void ball::draw()
{
	ofCircle(pos,R);
	ofSetColor(255,0,0);
	
}
