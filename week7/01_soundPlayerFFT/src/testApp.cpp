#include "testApp.h"

void testApp::setup(){	 
   ofSetFrameRate(60);
   ofSetVerticalSync(true);
   ofSetCircleResolution(32);
   ofEnableBlendMode(OF_BLENDMODE_ADD);
   ofBackground(0, 0, 0);
   mySound.loadSound("sounds/drumLoop.aif");
   mySound.setLoop(true);
   nBandsToGet = 1024;
   mySound.play();
}

void testApp::update(){
   ofSoundUpdate();
   fft = ofSoundGetSpectrum(nBandsToGet);
}

void testApp::draw(){
   float width = float(ofGetWidth()) / float(nBandsToGet) / 2.0f;
   for (int i = 0;i < nBandsToGet; i++){
      int b = float(255) / float(nBandsToGet) * i;
      int g = 31;
      int r = 255 - b;
      ofSetColor(r, g, b);
      ofCircle(ofGetWidth()/2 + width * i, 
               ofGetHeight()/2, fft[i] * 800);
      ofCircle(ofGetWidth()/2 - width * i, 
               ofGetHeight()/2, fft[i] * 800);
   }
}
