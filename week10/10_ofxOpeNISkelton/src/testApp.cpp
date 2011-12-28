#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofBackground(0, 0, 0);
    hardware.setup();
    hardware.setLedOption(LED_OFF);
    context.setup();
    depth.setup(&context);
    user.setup(&context);
}

//--------------------------------------------------------------
void testApp::update(){
	hardware.update();
    context.update();
    depth.update();
    user.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    depth.draw(0,0,640,480);
	user.draw();
	ofxTrackedUser* tracked = user.getTrackedUser(0);
    tracked->debugDraw();
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

