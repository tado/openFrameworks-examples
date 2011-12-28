#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetBackgroundAuto(false);
	//ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	
	for (int i = 0; i < NUM; i++) {
		myRectangle[i].startPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
		myRectangle[i].endPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));		
		myRectangle[i].pct = 0.0f;
		myRectangle[i].shaper = 1.5;
		myRectangle[i].speed = ofRandom(0.002f, 0.01f);
		myRectangle[i].interpolateByPct(0.0);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < NUM; i++) {
		myRectangle[i].pct += myRectangle[i].speed;
		myRectangle[i].interpolateByPct(myRectangle[i].pct);
		if (myRectangle[i].pct > 1) {
			myRectangle[i].pct = 0;
			myRectangle[i].startPos = myRectangle[i].endPos;
			myRectangle[i].endPos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));									
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	fadeToBlack();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	for (int i = 0; i < NUM; i++) {
		myRectangle[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::fadeToBlack() {
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(0, 0, 0, 10);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}