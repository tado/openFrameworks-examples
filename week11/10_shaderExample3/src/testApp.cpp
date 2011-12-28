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
	
	//シェーダーへ値を送信
	shader.setUniform1f("mousex", (float)mouseX - ofGetWidth()/2);
	shader.setUniform1f("mousey", (float)mouseY - ofGetHeight()/2);
	
	// 球体と立方体を描画
	ofSphere(-22, 0, 0, 20);
	ofBox(22, 0, 0, 40);
	
	// シェーダー終了
	shader.end();

	cam.end();
	ofPopMatrix();	
}

void testApp::keyPressed(int key){
	if (key == 'f') ofToggleFullscreen();
}


