#pragma once

#include "ofMain.h"
#include "ofxFluid.h"
#include "fluid.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void changeC();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		float R,G,B,dis;
		fluid myfluid;
		int N;
};
