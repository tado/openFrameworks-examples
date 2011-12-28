#pragma once
#include "ofMain.h"
#include "ofVbo.h"
#include "ofEvents.h"

#define	NUM_PARTICLES	30000

class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
   void setupArduino(const int & version);
	void updateArduino();

	ofVec3f		cameraRotation;
	float		zoom, zoomTarget;
	ofVbo myVbo;
	ofVec3f myVerts[NUM_PARTICLES];
	ofVec3f myVels[NUM_PARTICLES];
	ofFloatColor myColor[NUM_PARTICLES];
   
   ofArduino ard;       //Arduinoへの接続
	bool bSetupArduino;  //Arduinoに接続したかのフラグ
};