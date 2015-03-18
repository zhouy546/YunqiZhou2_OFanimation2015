#include "fluid.h"


void fluid::setup()
{

	Maxspeed = 7;
	Minspeed = -7;
	pos.set(ofGetWidth()/2,ofGetHeight()/2);
	myfluid.allocate(ofGetWidth(),ofGetHeight()/2,0.3,true);
	myfluid.dissipation= .95;
	myfluid.velocityDissipation=.95;
	myfluid.setGravity(ofVec2f(0.0,0.0));

}

void fluid::update(float _R,float _G ,float _B)
{
	
	acc=ofVec2f(ofGetMouseX()-pos.x,ofGetMouseY()-pos.y);
	vel+=0.001*acc;
	pos+=vel;
	ofPoint m = ofPoint(pos);
	ofPoint d = -(m-oldM)*2;
	oldM=m;
	size =0.05*acc.length();
	if(size >6){
	size = 6;
	}
	myfluid.addTemporalForce(m, d, ofFloatColor(_R,_G,_B)*abs(sin(ofGetElapsedTimef())),size);
	myfluid.update();
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//speed limited ___________________________
	if (vel.x>Maxspeed){
	vel.x=Maxspeed;
	
	}
	if (vel.x<Minspeed){
	vel.x=Minspeed;
	}

	if (vel.y>Maxspeed){
	vel.y=Maxspeed;
	}

	if (vel.y<Minspeed){
	vel.y=Minspeed;
	}

	//and rebounce___________________________
	if(pos.x<-50){
	vel.x=-.5*vel.x;
	}

	if(pos.x>ofGetWidth()+50){
	vel.x=-.5*vel.x;
	}

	if( pos.y<-50){
	vel.y=-.5*vel.y;
	}

	if( pos.y>ofGetHeight()+50){
	vel.y=-.5*vel.y;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

}

void fluid::draw(float _R,float _G,float _B)
{
	
		 myfluid.draw();
		 float alpha;
		 
		 if(pos.y<ofGetHeight()/2){
		
		 }
		if(pos.y>=ofGetHeight()/2){
		 	 ofSetColor(_R*255,_G*255,_B*255);
			 ofCircle(pos,size*3);
		 }
	
		 
}


void fluid::creatpoint(){
	myfluid.addConstantForce(ofPoint(ofGetWidth()/2,ofGetHeight()/4), ofPoint(0,-.1), ofFloatColor(0.5,0.1,0.0), 10.f);

}


