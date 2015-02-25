#include "circle.h"


void circle::setup()
{
	offset = 40;
}

void circle::update()
{

}


void circle::draw( int i)
{
		 Tpi= sin(ofGetElapsedTimef()+20*i);
	 
	Pos = ofVec2f(20+offset*i,ofGetHeight()/2+Tpi*100);
		    

	ofCircle(Pos,10);
}
