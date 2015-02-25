#include "ball.h"

void ball::setup(ofVec2f _initPos, ofVec2f _finalPos,float _initT,float _finalT)
{
	
	initPos=_initPos;
	finalPos= _finalPos;
	initT= _initT;
	finalT= _finalT;
	

}
void ball::update(float _pct, float _alpha)
{
	alpha=_alpha;	
	pct=_pct;
	  
    if(currentIter < totalIter) {
		pct = easeOut(currentIter, 0.0, 1.0, totalIter);
	currentPos= (1-pct)*initPos+pct*finalPos;
	currentT = (1-alpha)*initT+alpha*finalT;
	currentIter++;
	}
}
void ball::draw()
{
	ofCircle(currentPos,10);
	ofSetColor(ofColor(100,100,200,currentT));
	
}

void ball::setNewPosition(ofVec2f _newPos, int _totalIter)
{
	  currentIter = 0;
    totalIter = _totalIter;
	initPos = currentPos;
    finalPos = _newPos;
}

float ball::easeIn (float t,float b , float c, float d) {
    float s = 1.70158f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}
float ball::easeOut(float t,float b , float c, float d) {
    float s = 1.70158f;
    return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float ball::easeInOut(float t,float b , float c, float d) {
    float s = 1.70158f;
    if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
    float postFix = t-=2;
    return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}



