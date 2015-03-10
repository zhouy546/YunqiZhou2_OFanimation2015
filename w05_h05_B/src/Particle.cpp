#include "Particle.h"


Particle::Particle(ofVec2f _pos,ofVec2f _vel) {
    pos.set(_pos);
    vel.set(_vel);
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
    vel += acc;
    pos += vel;
    
	if (lifespan > 0){
	lifespan -=3;	
	} else{lifespan = 0;}
    
}

void Particle::draw() {
	float alpha = ofMap(lifespan,0,255,255,0);
	float size = ofMap(lifespan,0,255,5,1);
    ofSetColor(alpha);
    ofCircle(pos, size);
}



