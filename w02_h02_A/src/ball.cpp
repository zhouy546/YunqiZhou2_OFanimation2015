#include "ball.h"

void ball::setup()
{
	currentpos.set(ofGetWindowSize()/2);

}

void ball::update(ofVec2f _dest)
{
		int choice= ofRandom(10);
	if (choice <6)	currentpos= 0.999*currentpos+0.001*_dest;
	if (choice==7)  currentpos.x--;
	if (choice==8)  currentpos.y++;
	if (choice==9)  currentpos.y--;
	
}

void ball::draw()
{
	ofCircle(currentpos,1);
}
