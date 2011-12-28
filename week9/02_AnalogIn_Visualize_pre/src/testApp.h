#pragma once
#include "ofMain.h"
#include "ofVbo.h"

#define	NUM_PARTICLES	20000

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	ofVbo myVbo;
	ofVec3f myVerts[NUM_PARTICLES];
	ofVec3f myVels[NUM_PARTICLES];
	ofFloatColor myColor[NUM_PARTICLES];
   ofVec3f cameraRotation;
};









