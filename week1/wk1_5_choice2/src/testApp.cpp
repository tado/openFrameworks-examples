#include "testApp.h"

ofPoint pos;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);
    ofSetCircleResolution(128);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());  
}

//--------------------------------------------------------------
void testApp::draw(){
    if (ofDist(ofGetWidth()/2, ofGetHeight()/2, pos.x, pos.y) < 200) {
        ofSetColor(63, 255, 63, 127);
    } else {
        if (pos.x < ofGetWidth()/2) {
            ofSetColor(63, 63, 255, 127);
        } else {
            ofSetColor(255, 63, 63, 127);
        }
    }  
    ofCircle(pos.x, pos.y, 10);
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