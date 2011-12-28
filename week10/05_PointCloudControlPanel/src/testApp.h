#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxControlPanel.h"

class testApp : public ofBaseApp {
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void drawPointCloud();
    
    void keyPressed (int key);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofxKinect kinect;
    int angle;
    ofEasyCam easyCam;
    ofxControlPanel gui;
    ofImage kinectCam;
    ofImage kinectDepth;
};
