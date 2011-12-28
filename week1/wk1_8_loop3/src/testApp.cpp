#include "testApp.h"

ofPoint pos;

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	num = 100;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetHexColor(0x3399ff);
    for (int i = 0; i < num; i++) {
        ofRotateZ(360.f / num);
        float pos = sin((ofGetElapsedTimef() + 10000) * ((float)i / num / 2.0)) * ofGetHeight() / 1.8;
        //ofCircle(pos, 0, 2);
		ofRect(pos, 0, 1, 1);
    }
	
	ofSetHexColor(0xffffff);
	ofDrawBitmapString("point num = " + ofToString(num, 0), 20 - ofGetWidth()/2, 20 - ofGetHeight()/2);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    num+=100;
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