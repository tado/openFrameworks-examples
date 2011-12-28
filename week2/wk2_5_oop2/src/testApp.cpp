#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetBackgroundAuto(false);
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	
	myRectangle.startPos.set(10, 400);
	myRectangle.endPos.set(1000, 200);
	myRectangle.shaper = 2.0;
	pct = 0.0;
	myRectangle.interpolateByPct(pct);
}

//--------------------------------------------------------------
void testApp::update(){
	pct += 0.01f;
	if (pct > 1) {
		pct = 0;
	}
	myRectangle.interpolateByPct(pct);
}

//--------------------------------------------------------------
void testApp::draw(){
	fadeToBlack();
	myRectangle.draw();
}

//--------------------------------------------------------------
void testApp::fadeToBlack() {
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(0, 0, 0, 20);
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