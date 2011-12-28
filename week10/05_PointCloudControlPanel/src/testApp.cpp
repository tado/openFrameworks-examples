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
	gui.addPanel("Kinect Params", 1);
	gui.setWhichPanel(0);
	gui.setWhichColumn(0);
	gui.addToggle("Pick Color", "pick_color", false);
	gui.addToggle("Blendmode Add", "blend_add", false);
	gui.addSlider("Camera Tilt Angle", "angle", 0, -40, 40, true);
	gui.addSlider("Point size", "point_size", 2.0, 0.0, 10.0, false);
	gui.addSlider("Step size", "step", 2, 1, 10, true);
	gui.addSlider("Z position", "posz", -1000, -4000, 0, true);
	gui.addSlider("Z threshold", "thresh", 1000, 0, 4000, true);
	gui.addPanel("Kinect Images", 1);
	gui.setWhichPanel(1);
	gui.setWhichColumn(0);
	gui.addDrawableRect("Kinect Cam", &kinectCam, 320, 240);
	gui.addDrawableRect("Kinect Depth", &kinectDepth, 320, 240);
	gui.loadSettings("controlPanelSettings.xml");
	gui.toggleView();
	
	glEnable(GL_POINT_SMOOTH);
}

void testApp::update() {
	kinect.setCameraTiltAngle(gui.getValueI("angle"));
	// Kinect更新
	kinect.update();
	gui.update();
	if (kinect.isFrameNew()) {
		kinectCam.setFromPixels(kinect.getPixels(), kinect.width, kinect.height, OF_IMAGE_COLOR);
		kinectDepth.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
	}
}

void testApp::draw() {
	// ドラッグで視線を変更できるように(ofEasyCam)
	easyCam.begin();
	//ポイントクラウドの描画
	drawPointCloud();
	easyCam.end();
	gui.draw();
}

void testApp::drawPointCloud() {
	// 画面の幅と高さ
	int w = 640;
	int h = 480;
	// メッシュを生成
	//ofMesh mesh;
	ofVboMesh mesh;
	mesh.setMode(OF_PRIMITIVE_POINTS);

	// ブレンド設定
	if (gui.getValueB("blend_add")) {
		ofEnableBlendMode(OF_BLENDMODE_ADD);
	}
		
	// 設定した間隔で、画面の深度情報と色を取得してメッシュの頂点に設定
	int step = gui.getValueI("step");
	for(int y = 0; y < h; y += step) {
		for(int x = 0; x < w; x += step) {
			if(kinect.getDistanceAt(x, y) < gui.getValueI("thresh")) {
				if (gui.getValueB("pick_color")) {
					mesh.addColor(kinect.getColorAt(x,y));
				} else {
					mesh.addColor(ofFloatColor(255,255,255));
				}
				mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
			}
		}
	}
	
	// メッシュの頂点を描画
	glPointSize(gui.getValueF("point_size"));
	ofPushMatrix();
	ofScale(1, -1, -1);
	ofTranslate(0, 0, gui.getValueI("posz"));
	glEnable(GL_DEPTH_TEST);
	mesh.drawVertices();
	glDisable(GL_DEPTH_TEST);
	ofPopMatrix();
}

void testApp::exit() {
	// Kinect終了
	kinect.close();
}

void testApp::keyPressed (int key) {
	if (key == ' ') {
		gui.toggleView();
	}
	if (key == 'f') {
		ofToggleFullscreen();
	}
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
