#include "testApp.h"

float bg, fg;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(128);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
    bg = sin(ofGetElapsedTimef() * 2.0) * 127 + 127;
    fg = sin(ofGetElapsedTimef() * 3.0) * 127 + 127;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(bg, bg, bg);
    ofSetColor(fg, fg, fg);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(0, 0, 300);
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