#include "testApp.h"

testApp::~testApp() {

}

void testApp::setup(){
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	sampleRate 			= 44100;
	initialBufferSize	= 512;
	
	ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
   
   lAudio.assign(initialBufferSize, 0.0);
	rAudio.assign(initialBufferSize, 0.0);
}

void testApp::update(){

}

void testApp::draw(){
   ofSetColor(225);
	ofDrawBitmapString("MAXIMILIAN FM SYNTHESIS", 32, 32);
	
	ofNoFill();
	
	// draw the left channel:
	ofPushStyle();
   ofPushMatrix();
   ofTranslate(32, 100, 0);
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
   ofTranslate(32, 300, 0);
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
      
      float index, modFreq;
      ofMap(modFreq, 0, mouseX, 20, 8000);
      ofMap(index, 0, mouseY, 1, 2000); 
      
      wave = car.sinewave(mouseY*mod.sinewave(mouseX/10)+440); //FM Synth
      mymix.stereo(wave, outputs, 0.5);
      
		lAudio[i] = output[i*nChannels    ] = outputs[0];
		rAudio[i] = output[i*nChannels + 1] = outputs[1];
	}
}

void testApp::audioIn(float * input, int bufferSize, int nChannels){	
	for (int i = 0; i < bufferSize; i++){
		
	}
	
}