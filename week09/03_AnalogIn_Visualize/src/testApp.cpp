#include "testApp.h"

void testApp::setup() {
	ofSetFrameRate(60);
   ofBackgroundHex(0x000000);
	glPointSize(1.0);
	cameraRotation = 0;
	zoom = -500;
	zoomTarget = 200;
		
	for (int i=0; i<NUM_PARTICLES; i++) {
		myVels[i].set(ofRandomf(), -1.0, ofRandomf());
		myVerts[i].set(0, 0, 0);
		myColor[i].set(1, 1, 1, 1);
	}
	
	myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
   
   // デバイスの接続するポートとスピードを設定
   ard.connect("/dev/cu.usbserial-A900ceWs", 57600);
   // Arduinoとの接続が確立するのを監視するリスナー
   ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
   // 接続の確立したかどうかのフラグ
   bSetupArduino	= false;
}

void testApp::update() {
   // Arduinoを更新
   updateArduino();
   float ardIn = (float)ard.getAnalog(0) / 2048.0f;
   
	float t = ofGetElapsedTimef();
	float div = 100.0f;
	for (int i=0; i<NUM_PARTICLES; i++) {
		ofVec3f vec(ofSignedNoise(t, myVerts[i].y/div, myVerts[i].z/div),
                  ofSignedNoise(myVerts[i].x/div, t, myVerts[i].z/div),
                  ofSignedNoise(myVerts[i].x/div, myVerts[i].y/div, t));
		vec *= ardIn;
		myVels[i] += vec;
		myVerts[i] += myVels[i];
		myVels[i]  *= 0.9f;	
	}
   // move the camera around
	float mx = (float)mouseX/(float)ofGetWidth();
	float my = (float)mouseY/(float)ofGetHeight();
	ofVec3f des(mx * 360.0, my * 360.0, 0);
	cameraRotation += (des-cameraRotation) * 0.03;
}

void testApp::setupArduino(const int & version) {
   // 接続が確立したら、リスナーを削除
   ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
   // 0〜5のAnalog INを初期化
   for (int i = 0; i < 6; i++) {
      ard.sendAnalogPinReporting(i, ARD_ANALOG);
   }
   // 接続の確立のフラグをtrueに
   bSetupArduino = true;
}

void testApp::updateArduino(){
   // Arduinoをアップデート、全てのデータとメッセージを取得
   ard.update();
}

void testApp::draw() {
   ofSetHexColor(0xffffff);
   ofPushMatrix();
   ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
   ofRotate(cameraRotation.x, 1, 0, 0);
	ofRotate(cameraRotation.y, 0, 1, 0);
	ofRotate(cameraRotation.y, 0, 0, 1);
	myVbo.setVertexData(myVerts, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.setColorData(myColor, NUM_PARTICLES, GL_DYNAMIC_DRAW);
	myVbo.draw(GL_POINTS, 0, NUM_PARTICLES);
	ofPopMatrix();
}

void testApp::keyPressed(int key){
	if(key == 'f') ofToggleFullscreen();
	if(key == OF_KEY_UP) 	zoomTarget +=10;
	if(key == OF_KEY_DOWN) 	zoomTarget -=10;
}
