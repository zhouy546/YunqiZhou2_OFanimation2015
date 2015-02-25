#pragma once
#include "ofMain.h"
class ball
{
public:
void setup(ofVec2f _initPos, ofVec2f _finalPos,float _initT,float _finalT);
	void update(float _pct, float _alpha);
	void draw();
	void setNewPosition(ofVec2f _newPos,int _totalIter);


	    float easeIn (float t,float b , float c, float d);
    float easeOut (float t,float b , float c, float d);
    float easeInOut (float t,float b , float c, float d);
    
    //t == currentIteration
    //b == startValue
    //c == changeInValue
    //d == totalIterations


private:
	int currentIter, totalIter;
	ofVec2f initPos, currentPos, finalPos;
	float initT,currentT,finalT;
	float pct, alpha;
};

