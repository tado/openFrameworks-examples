#pragma once
#include "ofMain.h"

class Rectangle {
    
public:
    void draw();
	void interpolateByPct(float pct);
	
	ofPoint pos;
	ofPoint startPos;
	ofPoint endPos;
	float speed;
	float pct;
	float shaper;
};