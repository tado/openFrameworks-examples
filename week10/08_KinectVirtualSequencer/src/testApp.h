#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxKinect.h"
#include "ofxControlPanel.h"
#include "ofxSuperColliderServer.h"
#include "ofxSuperCollider.h"
#include "MyRect.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void exit();
    
    void drawPointCloud();
    void drawCv();
    
    void keyPressed (int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
	
	ofImage kinectImage;
    ofImage depthImage;
    ofEasyCam easyCam;
    ofxControlPanel gui;
    ofxKinect kinect;
    ofxCv::ContourFinder contourFinder;
    ofxSCSynth* reverb;
    
    list <MyRect *> rects;
    ofxCv::Point2f lastPos1, lastPos2;
    ofPoint interPos;
    int drawWaitTime;
    int drawWaitCount;
    bool drawRect;
};
