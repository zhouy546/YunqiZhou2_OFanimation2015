


#include "Particle.h"


void Particle::setup() {
	

	pos.x = ofRandom(ofGetWidth()/2-500,ofGetWidth()/2+500);
	pos.y = ofRandom(ofGetHeight()/2-350,ofGetHeight()/2+350);
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
   acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos +=vel;
	
	if(pos.x>=ofGetWidth()||pos.x<=0){
	vel=-.8*vel;
	}

	if(pos.y>=ofGetHeight()||pos.y<=0){
	vel=-.8*vel;
	}

	

    
}

void Particle::draw(float _size) {
    ofCircle(pos, _size);
}

