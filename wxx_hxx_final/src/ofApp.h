/******************************************************************/
/**
 * @file	ofApp.h
 * @brief	Example for ofxKinectNui addon
 * @note
 * @todo
 * @bug	
 *
 * @author	sadmb
 * @date	Oct. 28, 2011
 */
/******************************************************************/
#pragma once

#include "ofMain.h"
#include "ofxKinectNui.h"
#include "ofxKinectNuiDraw.h"
#include "particle.h"
enum PlayState {STATE_BLANK, STATE_NEW_MESSAGE,STATE_WAIT,STATE_REMOVE_ALL};

class ofxKinectNuiDrawTexture;
class ofxKinectNuiDrawSkeleton;

// uncomment this to read from two kinects simultaneously
//#define USE_TWO_KINECTS


class ofApp : public ofBaseApp {
	public:

		//particle
 std::vector<Particle*> particles;
    ofImage txtData;
	 void removeAll();	
	  void audioIn(float * input, int bufferSize, int nChannels); 
    PlayState currentState;
    void startParticles();
    std::vector<ofVec2f> vboPoints;
    std::vector<ofFloatColor> vboColors;	
	  ofVec2f getField(ofVec2f* position);
   
    float fallOffTriger;
    float newMessage;
    float removeAllTriger;
    
    ofVbo vbo;

	//```````````````````````````````````
	//sound
	ofSoundStream soundStream;
	vector <float> left;
		vector <float> right;
			vector <float> volHistory;
		
		int 	bufferCounter;
		int 	drawCounter;
		
		float smoothedVol;
		float scaledVol;
		float speed;
		float g;
		
		//------------------------------------------------------------
		void setup();
		void update();
		void draw();
		
		/**
		 * @brief	example for adjusting video images to depth images
		 * @note	inspired by akira's video http://vimeo.com/17146552
		 */
		void drawCalibratedTexture();
		void exit();
		void drawCircle3f(int n, int radius, ofVec3f cur);
		

		void keyPressed  (int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void kinectPlugged();
		void kinectUnplugged();
		
	

		ofxKinectNui kinect;

		
		
		 
		ofxBase3DVideo* kinectSource;


		
	
		bool bPlugged;
		bool bUnplugged;
		
		//unsigned short nearClipping;
		//unsigned short farClipping;
		int angle;
		
		int mRotationX, mRotationY;

		// Please declare these texture pointer and initialize when you want to draw them
		
		ofxKinectNuiDrawSkeleton*	skeletonDraw_;

		float x,y;
		

};
