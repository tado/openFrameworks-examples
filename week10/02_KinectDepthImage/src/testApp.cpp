#include "testApp.h"

void testApp::setup() {
    //画面設定
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    threshImage.allocate(kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
    
    // Kinect初期化
    kinect.init();
	kinect.open();
    
    // GUI
    gui.setup("ofxKinect Point Cloud", 0, 0, ofGetWidth(), ofGetHeight());
    gui.addPanel("panel 1", 2);
	gui.setWhichColumn(0);
    gui.addDrawableRect("Kinect Cam", &kinectImage, kinect.width/2, kinect.height/2);
    gui.addSlider("Camera Tilt Angle", "angle", 0, -45, 45, true);
    gui.setWhichColumn(1);
    gui.addDrawableRect("Kinect Depth", &depthImage, kinect.width/2, kinect.height/2);
    gui.addDrawableRect("Depth Threshold", &threshImage, kinect.width/2, kinect.height/2);
    gui.addSlider("Near Threshold", "near_thresh", 255, 0, 255, true);
    gui.addSlider("Far Threshold", "far_thresh", 127, 0, 255, true);
    gui.loadSettings("controlPanelSettings.xml");
}

void testApp::update() {
    kinect.update();
    gui.update();

    // カメラ角度設定
    kinect.setCameraTiltAngle(gui.getValueI("angle"));
    
    // Kinectからの画像を更新
	if(kinect.isFrameNew()) {
        // カメラ映像取得
        kinectImage.setFromPixels(kinect.getPixels(), kinect.width, kinect.height, OF_IMAGE_COLOR);
        // 深度情報画像を取得
        depthImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);

        // 閾値の範囲の深度の物体だけを抽出
        threshImage = depthImage;
        unsigned char * pix = threshImage.getPixels();
        int numPixels = threshImage.getWidth() * threshImage.getHeight();
        int near = gui.getValueI("near_thresh");
        int far = gui.getValueI("far_thresh");
        for(int i = 0; i < numPixels; i++) {
            if(pix[i] < near && pix[i] > far) {
                pix[i] = 255;
            } else {
                pix[i] = 0;
            }
        }
        threshImage.setFromPixels(pix, kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
	}
}

void testApp::draw() {
    // 閾値の範囲の物体を描画
    threshImage.draw(0, 0, ofGetWidth(), ofGetHeight());
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
