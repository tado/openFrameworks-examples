/*
 *  MyRect.h
 *  ofxKinect
 *
 *  Created by Atsushi Tadokoro on 10/11/26.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MY_RECT
#define _MY_RECT

#include "ofMain.h"
#include "ofxSuperCollider.h"

class MyRect
{
public:
    MyRect(ofPoint p1, ofPoint p2);
    void update();
    void draw();
    
    ofPoint p1, p2;
    ofPoint rectPos;
    float width;
    float height;
    
    float pitchRatio[7];
    float scanSpeed;
    float scanPos;
    float freq;
    float pan;
    float amp;
    float posZ;
    float speedZ;
    bool dead;
        
    ofxSCSynth* perc;
};

#endif