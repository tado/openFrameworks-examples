#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxControlPanel.h"

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	void grabBackgroundEvent(guiCallbackData & data);
	void drawInputEvent(guiCallbackData & data);
	void toggleLiveVideoEvent(guiCallbackData & data);
	
	ofVideoGrabber vidGrabber;
	ofVideoPlayer vidPlayer;
	ofxCvColorImage colorImg;
	
	ofxCvGrayscaleImage grayImage;
	ofxCvGrayscaleImage grayBg;
	ofxCvGrayscaleImage grayDiff;
	
	ofxCvContourFinder contourFinder;
	
	int threshold;
	bool bLearnBakground;
	
	ofxControlPanel gui;
	bool useLiveVideo;
	bool drawInputVideo;
};

