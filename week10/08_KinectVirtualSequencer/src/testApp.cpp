#include "testApp.h"

using namespace cv;
using namespace ofxCv;

void testApp::setup() {
    //画面設定
    ofBackgroundHex(0x000000);
    ofSetFrameRate(60);
    
    // Kinect初期化
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    
    // GUI
    gui.setup("ofxKinect Point Cloud", 0, 0, 360, ofGetHeight());
    gui.addPanel("panel 1", 3);
    gui.setWhichColumn(0);
    gui.addToggle("Pick Color", "pick_color", false);
    gui.addSlider("Point size", "point_size", 2.0, 0.0, 10.0, false);
    gui.addSlider("Step size", "step", 2, 1, 10, true);
    gui.addSlider("Z position", "posz", -400, -1000, 0, true);
    gui.addSlider("Min Area Radius", "min_radius", 10, 0, 500, true);
    gui.addSlider("Max Area Radius", "max_radius", 400, 0, 500, true);
    gui.addSlider("Z threshold", "z_thresh", 1000, 0, 4000, true);
    gui.addSlider("CV Threshold", "cv_thresh", 200, 0, 255, true);
    gui.addSlider("CV Screen Offset", "cv_offset", 400, 0, 1000, true);
    gui.addSlider("Camera Tilt Angle", "angle", 0, -40, 40, true);
    gui.addDrawableRect("Kinect Depth", &depthImage, 160, 120);
    gui.loadSettings("controlPanelSettings.xml");
    
    // SuerCollier初期設定
    ofxSuperColliderServer::init();
    reverb = new ofxSCSynth("reverb");
    reverb->create();
    
    // Rect表示関係
    drawRect = false;
    drawWaitCount = 0;
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
        kinectImage.setFromPixels(kinect.getPixels(), kinect.width, kinect.height, OF_IMAGE_COLOR);
        depthImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height, OF_IMAGE_GRAYSCALE);
        contourFinder.setThreshold(gui.getValueI("cv_thresh"));
        contourFinder.findContours(depthImage);
    }
    
    
    //分析した中心点を補完
    if (contourFinder.size() == 2) {
        Point2f pos1, pos2;
        if(contourFinder.getCentroid(0).x < contourFinder.getCentroid(1).x) {
            pos1 = contourFinder.getCentroid(0);
            pos2 = contourFinder.getCentroid(1);    
        } else {
            pos1 = contourFinder.getCentroid(1);
            pos2 = contourFinder.getCentroid(0);    
        }
        
        lastPos1 += (pos1 - lastPos1) * 0.05;
        lastPos2 += (pos2 - lastPos2) * 0.05;
    } 
    
    //描画した四角形を追加
    if (contourFinder.size() == 2 && !drawRect) {
        drawWaitCount++;
        if (drawWaitCount > 120) {
            drawRect = true;
        }
    } else if (drawRect) {
        ofPoint pos1, pos2;
        pos1.x = lastPos1.x;
        pos2.x = lastPos2.x;
        pos1.y = lastPos1.y;
        pos2.y = lastPos2.y;
        MyRect* r = new MyRect(pos1, pos2);
        rects.push_back(r);
        drawRect = false;
        drawWaitCount = 0;
    }
    
    //四角形更新
    for(list <MyRect *>::iterator it = rects.begin(); it != rects.end();){
        (*it)->update();
        if ((*it)->dead) {
            delete *it;
            it = rects.erase(it);
        } else {
            ++it;
        }
    }
}

void testApp::draw() {  
    // ドラッグで視線を変更できるように(ofEasyCam)
    easyCam.begin();
    
    
    glEnable(GL_DEPTH_TEST);    
    //ポイントクラウドの描画
    ofPushMatrix();
    ofScale(1, -1, -1);
    ofTranslate(0, 0, gui.getValueI("posz"));
    drawPointCloud();
    
    // CV描画
    ofTranslate(0, 0, gui.getValueI("cv_offset"));
    drawCv();
    ofPopMatrix();
    glDisable(GL_DEPTH_TEST);
    easyCam.end();
    
    // GUI表示
    ofSetLineWidth(1);
    gui.draw();
}

void testApp::drawPointCloud() {
    // 画面の幅と高さ
    int w = 640;
    int h = 480;
    // メッシュを生成
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    // 設定した間隔で、画面の深度情報と色を取得してメッシュの頂点に設定
    int step = gui.getValueI("step");
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) < gui.getValueI("z_thresh")) {
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
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mesh.drawVertices();
    ofPopMatrix();
}

void testApp::drawCv() {
    ofPushMatrix();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofTranslate(-kinect.width/2, -kinect.height/2, 0);
    
    // 深度情報を表示
    ofSetColor(100, 100, 100);
    kinect.drawDepth(0, 0, kinect.width, kinect.height);
    
    // CV 輪郭線分析画面の表示
    ofPushMatrix();
    // 輪郭線を表示
    ofTranslate(0, 0, -1);
    ofSetColor(100, 100, 100);
    ofSetLineWidth(2);
    contourFinder.draw();
    
    // 輪郭の中心位置に円を配置
    ofSetColor(255, 127, 0);
    for (int i = 0; i < contourFinder.size(); i++) {
        Point2f pos = contourFinder.getCentroid(i);
        ofCircle(pos.x, pos.y, 3);
    }
    
    //現在描画中の四角形を表示
    if (contourFinder.size() == 2) {
        
        //補完されたBlobsの中心
        ofFill();
        ofSetColor(255, 0, 0);
        ofCircle(lastPos1.x, lastPos1.y, 3);
        ofCircle(lastPos2.x, lastPos2.y, 3);
        
        //四角形
        ofNoFill();
        ofSetColor(200, 200, 200);
        ofBeginShape();
        ofVertex(lastPos1.x, lastPos1.y);
        ofVertex(lastPos2.x, lastPos1.y);
        ofVertex(lastPos2.x, lastPos2.y);
        ofVertex(lastPos1.x, lastPos2.y);
        ofEndShape(true);
    }
    
    //listに格納した四角形の描画
    ofFill();
    list <MyRect*>::iterator it;
    for (it = rects.begin(); it != rects.end(); ++it) {
        (*it)->draw();
    }

    ofPopMatrix();
    
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
