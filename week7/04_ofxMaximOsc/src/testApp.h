#pragma once
#include "ofMain.h"
#include "ofxMaxim.h"

class testApp : public ofBaseApp{
public:
   void setup();
   void update();
   void draw();
   void keyPressed(int key);
   void audioOut(float * input, int bufferSize, int nChannels);
   void audioIn(float * input, int bufferSize, int nChannels);

   int initialBufferSize;
   int sampleRate;
   double wave,sample,outputs[2];
   ofxMaxiMix mymix;
   ofxMaxiOsc osc; //Oscilator
   int mode;
   
   vector <float> lAudio;
   vector <float> rAudio;
};
