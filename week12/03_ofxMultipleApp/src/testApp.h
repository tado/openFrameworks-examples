#pragma once

#include "ofMain.h"
#include "ofxMultipleApp.h"
#include "SceneA.h"
#include "SceneB.h"
#include "SceneC.h"


class testApp : public ofBaseApp {
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	SceneA *sceneA;
	SceneB *sceneB;
	SceneC *sceneC;
	ofxSubApp *currentApp;
	
};
