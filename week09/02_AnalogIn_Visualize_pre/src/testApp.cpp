#include "testApp.h"

void testApp::setup() {
	ofSetFrameRate(60);
   ofBackgroundHex(0x000000);
	glPointSize(1.0);
		
	for (int i=0; i<NUM_PARTICLES; i++) {
		myVels[i].set(ofRandomf(), -1.0, ofRandomf());
		myVerts[i].set(0, 0, 0);
		myColor[i].set(1, 1, 1, 1);
	}
	
	myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

void testApp::update() {
	float t = ofGetElapsedTimef();
	float div = 100.0f;
	
	for (int i=0; i<NUM_PARTICLES; i++) {
		ofVec3f vec(ofSignedNoise(t, myVerts[i].y/div, myVerts[i].z/div),
                  ofSignedNoise(myVerts[i].x/div, t, myVerts[i].z/div),
                  ofSignedNoise(myVerts[i].x/div, myVerts[i].y/div, t));
		vec *= 0.2f;
		myVels[i] += vec;
		myVerts[i] += myVels[i];
		myVels[i]  *= 0.9f;	
	}
   
   // move the camera around
	float mx = (float)mouseX/(float)ofGetWidth();
	float my = (float)mouseY/(float)ofGetHeight();
	ofVec3f des(mx * 360.0, my * 360.0, 0);
	cameraRotation += (des-cameraRotation) * 0.03;
}

void testApp::draw() {
   ofSetHexColor(0xffffff);
   ofPushMatrix();
   ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
   ofRotate(cameraRotation.x, 1, 0, 0);
	ofRotate(cameraRotation.y, 0, 1, 0);
	ofRotate(cameraRotation.y, 0, 0, 1);
	myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
	ofPopMatrix();
}

void testApp::keyPressed(int key){
	if(key == 'f') ofToggleFullscreen();
}
