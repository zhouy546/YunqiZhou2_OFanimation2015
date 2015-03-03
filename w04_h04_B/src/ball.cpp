#include "ball.h"


void ball::setup()
{
 angle =0;

	currentPos= ofVec2f(0,0);
}

void ball::resetForces(){
acc*=0;

} 

void ball::gravity(ofVec2f _force){
acc+=_force;
} 

void ball::update()
{
	
	//ball move
	acc = ofVec2f(ofGetMouseX()-currentPos.x,ofGetMouseY()-currentPos.y);
	vel += 0.001*acc;
	currentPos +=vel;
	
		//Ob move
	
	angle+=0.05;
	ObcurrentPos = ofVec2f(currentPos.x+30*sin(angle),currentPos.y+40*cos(angle));

	//strain
	
	if(currentPos.x<0){
	currentPos.x=0;
	vel.x*=-.2;
	
	}
	
	if(currentPos.x > ofGetWidth()){
		currentPos.x=ofGetWidth();
	vel.x*=-.2;
	}

	if(currentPos.y<0){
		currentPos.y=0;
	vel.y*=-.2;
	}

	if(currentPos.y > ofGetHeight()){
		currentPos.y=ofGetHeight();
	vel.y*=-.2;
	}
}



void ball::draw()
{
	ofCircle(currentPos,10);

	ofCircle(ObcurrentPos,5);
}
