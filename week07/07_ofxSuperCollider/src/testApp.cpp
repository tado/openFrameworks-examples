#include "testApp.h"

void testApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    
    reverb = new ofxSCSynth("reverb");
    reverb->create();
    baseSound = new ofxSCSynth("baseSound");
    baseSound->create();
}

void testApp::update(){
    //Ring更新
    for(vector <Ring *>::iterator it = rings.begin(); it != rings.end();){
        (*it)->update();
        if ((*it)->dead) {
            delete (*it);
            it = rings.erase(it);
        } else {
            ++it;
        }
    }
}

void testApp::draw(){
    //Ringを描画
    for(vector <Ring *>::iterator it = rings.begin(); it != rings.end(); ++it){
        (*it)->draw();
    }
}

void testApp::keyPressed(int key){}

void testApp::keyReleased(int key){}

void testApp::mouseMoved(int x, int y ){}

void testApp::mouseDragged(int x, int y, int button){}

void testApp::mousePressed(int x, int y, int button){}

void testApp::mouseReleased(int x, int y, int button){
    //newRingの楽器を新規に生成し演奏
    int note[8] = {28, 35, 40, 47, 52, 59, 64, 71};
    newRing = new ofxSCSynth("newRing");
    newRing->set("note", note[int(ofRandom(0, 8))]);
    newRing->set("pan", (x - ofGetWidth() / 2.0) / ofGetWidth() * 2.0);
    newRing->create();
    
    //Ringを追加
    rings.push_back(new Ring(ofPoint(x, y)));
}

void testApp::windowResized(int w, int h){}