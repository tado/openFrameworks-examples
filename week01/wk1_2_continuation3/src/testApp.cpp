#include "testApp.h"

float radius;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofEnableAlphaBlending();
    ofSetCircleResolution(128);
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
    radius = sin(2.0 * ofGetElapsedTimef()) * 100.0f + 200;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(63, 63, 255);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(0, 0, radius);
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