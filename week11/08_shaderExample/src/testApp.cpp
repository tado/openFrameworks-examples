#include "testApp.h"

void testApp::setup(){

	//画面設定
	ofBackgroundHex(0x000000);
	ofEnableAlphaBlending();
	glEnable(GL_DEPTH_TEST);
	cam.setDistance(100);
	
	//シェーダー読込み
	shader.load("gradient");
}

void testApp::update(){
}

void testApp::draw(){
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	cam.begin();
	
	//シェーダー開始
	shader.begin();

	// 球体と立方体を描画
	ofSphere(0, -22, 0, 20);
	ofBox(0, 22, 0, 30);
	
	// シェーダー終了
	shader.end();

	cam.end();
	ofPopMatrix();
}

void testApp::keyPressed(int key){
	if (key == 'f') ofToggleFullscreen();
}