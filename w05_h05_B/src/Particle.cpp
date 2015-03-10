#include "Particle.h"


Particle::Particle(ofVec2f _pos) {
    pos.set(_pos);
		vel.x = ofRandom(-4,4);
	vel.y = ofRandom(-5,-1);
    lifespan = 255;
}

void Particle::setup() {

}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::update() {
	acc = ofVec2f((ofGetMouseX()-pos.x)/100,(ofGetMouseY()-pos.y)/100);
    vel += acc;
    pos += vel;
    
    if (lifespan > 0){
		lifespan -= 1.0;
	}else{lifespan =0;
		
	}
    
}

void Particle::draw() {
	/*
	float pct= ofMap(lifespan,0,255,0,120);
		if(pct>112.5){
			ofSetColor(255,ofMap(pct,112.5,120,255,0),0,lifespan);
		} else if(pct>105){
			ofSetColor(ofMap(pct,105,112.5,0,255),255,0,lifespan);
		}else if (pct>97.5){
			ofSetColor(0,255,ofMap(pct,90,97.5,255,0),lifespan);
		}	else if (pct>90){
			ofSetColor(0,ofMap(pct,82.5,90,0,255),255,lifespan);
		}else if (pct >82.5){
			ofSetColor(ofMap(pct,75,82.5,255,0),0,255,lifespan);
		}else if (pct >75){
			ofSetColor(255,0,ofMap(pct,67.5,75,0,255),lifespan);
		}
		*/
		ofSetColor(255,255,255,lifespan);
   
    ofCircle(pos, 5);
}
