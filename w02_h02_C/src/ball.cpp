#include "ball.h"



void ball::steup()
{
			float num= ofxGaussian();
	float sd =120;
	float offset = 2;
	 size = num*5;
	 x = sd*num+ofGetWidth()/2;
	
	 
}

void ball::update()
{

}


void ball::draw()
{
	ofCircle(x,ofGetHeight()/2,size);

}

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ball::ofxGaussian(){
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}


