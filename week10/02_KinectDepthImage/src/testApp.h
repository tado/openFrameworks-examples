#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxControlPanel.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
	
	ofImage kinectImage;
    ofImage depthImage;
    ofImage threshImage;
    ofxControlPanel gui;
    ofxKinect kinect;
};
