#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"


class testApp : public ofBaseApp{
   
public:
   ~testApp();
   void setup();
   void update();
   void draw();
   void audioOut(float * input, int bufferSize, int nChannels); /* output method */
   void audioIn(float * input, int bufferSize, int nChannels); /* input method */
	
   int initialBufferSize;
   int sampleRate;
   double outputs[2];
   double wave;

   ofxMaxiMix mymix; //Mixer
   ofxMaxiOsc car; //FM career
   ofxMaxiOsc mod; //FM modulator
   
   vector <float> lAudio;
   vector <float> rAudio;
};
