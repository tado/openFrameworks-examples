#pragma once

#include "ofMain.h"
#include "ofxMultipleApp.h"
#include "Particle.h"

class SceneC : public ofxSubApp {
	
	void setup();
	void update();
	void draw();
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	
	void show();
    void hide();
    void remove();
	
    vector <Particle> particles;
	ofImage img;
};
