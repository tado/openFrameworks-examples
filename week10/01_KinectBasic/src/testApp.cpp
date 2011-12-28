#include "testApp.h"

void testApp::setup() {
    //画面設定
    ofSetFrameRate(60);
    // Kinect初期化
    kinect.init();
	kinect.open();
}

void testApp::update() {
    // Kinect状態更新
    kinect.update();
}

void testApp::draw() {
    // Kinectカメラから撮影した映像
    kinect.draw(0, 0, kinect.width, kinect.height);
    // Kinect深度情報付き映像
    kinect.drawDepth(kinect.width, 0, kinect.width, kinect.height);
}
