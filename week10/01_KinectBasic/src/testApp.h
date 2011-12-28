#pragma once

#include "ofMain.h"
#include "ofxKinect.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

    ofxKinect kinect; //Kinectインスタンス
	ofImage kinectImage; // Kinectカメラ映像
    ofImage depthImage; // Kinect深度映像
};
