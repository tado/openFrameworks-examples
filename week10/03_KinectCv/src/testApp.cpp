#include "testApp.h"

using namespace cv;
using namespace ofxCv;

void testApp::setup() {
    //画面設定
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    // Kinect初期化
    kinect.init();
	kinect.open();
    
    // GUI
    gui.setup("ofxKinect Point Cloud", 0, 0, 360, ofGetHeight());
    gui.addPanel("panel 1", 3);
	gui.setWhichColumn(0);
    gui.addSlider("Min Area Radius", "min_radius", 10, 0, 500, true);
    gui.addSlider("Max Area Radius", "max_radius", 400, 0, 500, true);
    gui.addSlider("CV Threshold", "thresh", 200, 0, 255, true);
    gui.addSlider("Camera Tilt Angle", "angle", 0, -40, 40, true);
    gui.addDrawableRect("Kinect Cam", &kinectImage, 160, 120);
    gui.addDrawableRect("Kinect Depth", &depthImage, 160, 120);
    gui.loadSettings("controlPanelSettings.xml");
}

void testApp::update() {
    kinect.update();
    gui.update();

    // カメラ角度設定
    kinect.setCameraTiltAngle(gui.getValueI("angle"));
    
    // 輪郭抽出の範囲設定
    contourFinder.setMinAreaRadius(gui.getValueI("min_radius"));
    contourFinder.setMaxAreaRadius(gui.getValueI("max_radius"));

    // 深度情報の画像から、輪郭抽出
	if(kinect.isFrameNew()) {
        // カメラ画像と深度画像を抽出
        kinectImage.setFromPixels(kinect.getPixels(), kinect.width, kinect.height, OF_IMAGE_COLOR);
        depthImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
        // ofxCvを使用して輪郭を抽出
        contourFinder.setThreshold(gui.getValueI("thresh"));
        contourFinder.findContours(depthImage);
	}
}

void testApp::draw() {
    // 深度情報を表示
    ofSetHexColor(0xffffff);
    kinect.drawDepth(0,0, ofGetWidth(), ofGetHeight());

    ofPushMatrix();
    // 輪郭線を表示
    ofScale(ofGetWidth()/(float)kinect.width, ofGetHeight()/(float)kinect.height);
    ofSetHexColor(0xff9933);
    contourFinder.draw();

    // 中心位置に円を配置
    ofSetHexColor(0x3399ff);
    for (int i = 0; i < contourFinder.size() ; i++) {
        Point2f pos = contourFinder.getCentroid(i);
        ofCircle(pos.x, pos.y, 3);
    }
    ofPopMatrix();
    
    // GUI表示
    gui.draw();
}

void testApp::mouseDragged(int x, int y, int button){
	gui.mouseDragged(x, y, button);
}

void testApp::mousePressed(int x, int y, int button){
	gui.mousePressed(x, y, button);
}

void testApp::mouseReleased(int x, int y, int button){
	gui.mouseReleased();
}
