#pragma once

#include "ofMain.h"
#include "ofxMultipleApp.h"

#define WIDTH 200
#define HEIGHT 200
#define NUM_PARTICLES WIDTH * HEIGHT

class SceneB : public ofxSubApp {
	
	void setup();
	void update();
	void draw();
	
	void show();
    void hide();
    void remove();
	
	ofEasyCam cam; // カメラ
	ofVbo myVbo; // VBO
	ofVec3f myVerts[NUM_PARTICLES]; // 頂点の座標
	ofFloatColor myColor[NUM_PARTICLES]; // 頂点の色情報	
};
