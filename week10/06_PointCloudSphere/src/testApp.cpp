#include "testApp.h"

void testApp::setup() {
    //画面設定
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    // Kinect初期設定
    // 深度とRGB情報のずれを補整
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    // 角度を調整(0度に)
    angle = 0;
    kinect.setCameraTiltAngle(angle);
    
    // GUI
    gui.setup("ofxKinect Point Cloud", 0, 0, 400, ofGetHeight());
    gui.addPanel("panel 1", 3);
	gui.setWhichColumn(0);
    gui.addToggle("Pick Color", "pick_color", false);
    gui.addSlider("Camera Tilt Angle", "angle", 0, -40, 40, true);
    gui.addSlider("Step size", "step", 10, 1, 20, true);
    gui.addSlider("Sphere size", "sphere_size", 10, 1, 50, false);
    gui.addSlider("Z position", "posz", -1000, -4000, 0, true);
    gui.addSlider("Z threshold", "thresh", 1000, 0, 4000, true);
    gui.loadSettings("controlPanelSettings.xml");
}

void testApp::update() {
    kinect.setCameraTiltAngle(gui.getValueI("angle"));
    // Kinect更新
    kinect.update();
    gui.update();
}

void testApp::draw() {
    // ドラッグで視線を変更できるように(ofEasyCam)
    easyCam.begin();
    //ポイントクラウドの描画
    light.enable();
    drawPointCloud();
    light.disable();
    easyCam.end();
    
    //GUI描画
    gui.draw();
}

void testApp::drawPointCloud() {
    // 画面の幅と高さ
    int w = 640;
    int h = 480;
        
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(-kinect.width/2, -kinect.height/2, gui.getValueI("posz"));
    glEnable(GL_DEPTH_TEST);
    int step = gui.getValueI("step");
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) < gui.getValueI("thresh")) {
                if (gui.getValueB("pick_color")) {
                    ofSetColor(kinect.getColorAt(x,y));
                } else {
                    ofSetColor(255,255,255);
                }
                ofxSphere(x, y, kinect.getDistanceAt(x, y), gui.getValueF("sphere_size"));
            }
        }
    }
    glDisable(GL_DEPTH_TEST);
    ofPopMatrix();
}

void testApp::exit() {
    // Kinect終了
    kinect.close();
}

void testApp::keyPressed (int key) {

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

void testApp::windowResized(int w, int h)
{}
