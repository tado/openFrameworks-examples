#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetVerticalSync(true);
	
	startPos.set(10, 400);
	endPos.set(1000, 300);
	pct = 0;
}

//--------------------------------------------------------------
void testApp::update(){
	pct += 0.01f;
	if (pct > 1) {
		pct = 0;
	}	
	currentPos = interpolateByPct(pct);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(31, 127, 255);
	ofRect(currentPos.x, currentPos.y, 20, 20);
}

//--------------------------------------------------------------
ofPoint testApp::interpolateByPct(float _pct){
	float pct = _pct;
	ofPoint pos;
	pos.x = (1-pct) * startPos.x + (pct) * endPos.x;
	pos.y = (1-pct) * startPos.y + (pct) * endPos.y;
	return pos;
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