#pragma once
#include "ofMain.h"

class testApp : public ofBaseApp{
   
public:
   void setup();
   void update();
   void draw();
   
   ofSoundPlayer mySound;
   float * fft;
   int nBandsToGet;
};