#include "testApp.h"

void testApp::setup(){
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	sampleRate 			= 44100; /* Sampling Rate */
	initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
	
	ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
   
   lAudio.assign(initialBufferSize, 0.0);
	rAudio.assign(initialBufferSize, 0.0);
   
   mode = 0;
}

void testApp::update(){
   
}

void testApp::draw(){
   ofSetColor(225);
	ofDrawBitmapString("MAXIMILIAN OSCILATORS", 32, 32);
   ofDrawBitmapString("0:sin, 1:saw, 2:pulse, 3:phasor, 4:triangle, 5:noise", 32, 48);
	
	ofNoFill();
	
	// draw the left channel:
	ofPushStyle();
   ofPushMatrix();
   ofTranslate(32, 150, 0);
   
   ofSetColor(225);
   ofDrawBitmapString("Left Channel", 4, 18);
   
   ofSetLineWidth(1);	
   ofRect(0, 0, 900, 200);
   
   ofSetColor(245, 58, 135);
   ofSetLineWidth(3);
   
   ofBeginShape();
   for (int i = 0; i < lAudio.size(); i++){
      float x =  ofMap(i, 0, lAudio.size(), 0, 900, true);
      ofVertex(x, 100 -lAudio[i]*100.0f);
   }
   ofEndShape(false);
   
   ofPopMatrix();
	ofPopStyle();
   
	// draw the right channel:
	ofPushStyle();
   ofPushMatrix();
   ofTranslate(32, 350, 0);
   
   ofSetColor(225);
   ofDrawBitmapString("Right Channel", 4, 18);
   
   ofSetLineWidth(1);	
   ofRect(0, 0, 900, 200);
   
   ofSetColor(245, 58, 135);
   ofSetLineWidth(3);
   
   ofBeginShape();
   for (int i = 0; i < rAudio.size(); i++){
      float x =  ofMap(i, 0, rAudio.size(), 0, 900, true);
      ofVertex(x, 100 -rAudio[i]*100.0f);
   }
   ofEndShape(false);
   
   ofPopMatrix();
	ofPopStyle();
	
}

void testApp::audioOut 	(float * output, int bufferSize, int nChannels){
   for (int i = 0; i < bufferSize; i++){
      float freq = mouseY;
      float pan = (float)mouseX / (float)ofGetWidth();
      
      switch (mode) {
         case 0:
            wave = osc.sinewave(freq);
            break;
         case 1:
            wave = osc.saw(freq);
            break;
         case 2:
            wave = osc.pulse(freq, 0.99);
            break;
         case 3:
            wave = osc.phasor(freq);
            break;            
         case 4:
            wave = osc.triangle(freq);
            break;            
         case 5:
            wave = osc.noise();
            break;
         default:
            wave = osc.sinewave(freq);
            break;
      }
      
      mymix.stereo(wave, outputs, pan);
      lAudio[i] = output[i*nChannels    ] = outputs[0];
      rAudio[i] = output[i*nChannels + 1] = outputs[1];
   }	
}

void testApp::audioIn 	(float * input, int bufferSize, int nChannels){	
	for (int i = 0; i < bufferSize; i++){
		
	}
	
}

void testApp::keyPressed(int key){
   if (key == '0') {
      mode = 0;
   }
   if (key == '1') {
      mode = 1;
   }
   if (key == '2') {
      mode = 2;
   }
   if (key == '3') {
      mode = 3;
   }
   if (key == '4') {
      mode = 4;
   }
   if (key == '5') {
      mode = 5;
   }   
}