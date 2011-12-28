/*
 *  MyRect.cpp
 *  ofxKinect
 *
 *  Created by Atsushi Tadokoro on 10/11/26.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MyRect.h"

MyRect::MyRect(ofPoint _p1, ofPoint _p2)
{
    p1 = _p1;
    p2 = _p2;
    
    posZ = 0;
    speedZ = ofRandom(0.02, 0.2);
    dead = false;
    
    pitchRatio[0]= 1.0;
    pitchRatio[1]= 9.0/8.0;
    pitchRatio[2]= 5.0/4.0;
    pitchRatio[3]= 4.0/3.0;
    pitchRatio[4]= 3.0/2.0;
    pitchRatio[5]= 5.0/3.0;
    pitchRatio[6]= 15.0/8.0;
    
    p2.x > p1.x ? rectPos.x = p1.x : rectPos.x = p2.x;
    p2.y > p1.y ? rectPos.y = p1.y : rectPos.y = p2.y;
    width = abs(p2.x - p1.x);
    height = abs(p2.y - p1.y);
    
    scanSpeed = ofRandom(1.0, 2.0);
    scanPos = 0;
    int zone = (ofGetHeight() - (rectPos.y + height))/(ofGetHeight()/12);
    freq = 5 * pow(2.0, zone) * pitchRatio[int(ofRandom(0, 6))];
    if (freq > 18000) {
        freq = 18000;
    }
    pan = ofRandom(-1, 1);
    amp = abs(float(p2.y - p1.y) / 1000.0);
    
    perc = new ofxSCSynth("mySaw");
    perc->set("amp", amp);
    perc->set("freq", freq);
    perc->set("decay", width/scanSpeed/60.0);
    perc->set("pan", pan);
    perc->create();
}

void MyRect::update()
{
    //posZ += speedZ;
    scanPos += scanSpeed;
    if (scanPos > width) {
        scanPos -= width;
        
        perc = new ofxSCSynth("mySaw");
        perc->set("amp", amp);
        perc->set("freq", freq);
        perc->set("decay", width/scanSpeed/60.0);
        perc->set("pan", pan);
        perc->create();
        posZ-=5;
        
        if (posZ > 1000) {
            dead = true;
        }
    }
    
}

void MyRect::draw(){
    ofFill();  
    float alpha = 255 - scanPos / width * 255.0;
    ofSetColor(0, 255, 255, alpha);
    ofPushMatrix();
    ofTranslate(0, 0, posZ);
    ofRect(rectPos.x, rectPos.y, scanPos, height);
    ofPopMatrix();
}