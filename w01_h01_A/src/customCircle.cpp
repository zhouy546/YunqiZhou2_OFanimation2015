#include "customCircle.h"

customCircle::customCircle() {
    
}
void customCircle::setup(ofVec2f _initPos,ofVec2f _finalPos,ofVec2f _initPos1,ofVec2f _finalPos1)
{
	initPos=_initPos;
	finalPos=_finalPos;
		initPos1=_initPos1;
	finalPos1=_finalPos1;
}


void customCircle::update(float _pct)
{
	pct=_pct;
	currentPos=(1-pct)*initPos + pct*	finalPos;
	currentPos1=(1-pct)*initPos1 + pct*	finalPos1;

}

void customCircle::draw()
{
	ofCircle(currentPos,10);
	ofCircle(currentPos1,10);
}

void customCircle::setNewPosition(ofVec2f _newPos)
{
	 initPos = currentPos;
    finalPos = _newPos;
		 initPos1 = currentPos1;
    finalPos1 = _newPos;
}