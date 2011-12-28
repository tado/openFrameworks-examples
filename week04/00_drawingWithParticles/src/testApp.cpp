#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(0, 0, 0);
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	pimg.loadImage("particle32.png");
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(127, 127, 127, 200);
	ofNoFill();
	ofEnableSmoothing();
	ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
		ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
	}
	ofEndShape();
	ofDisableSmoothing();
	
	ofSetColor(255, 255, 255);
	ofFill();
	for (int i = 0; i < particles.size(); i++){
		pimg.draw(particles[i].pos.x - 16, particles[i].pos.y - 16);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == 'f') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	//1フレーム前の座標から、現在のマウス座標との差分を算出
	float dx = x - prevMouseX;
	float dy = y - prevMouseY;
	
	//新規にパーティクルを作成、計算したベクトルを付与
	particle myParticle;
	myParticle.setInitialCondition(x,y, dx*0.5,dy*0.5);
	//配列に追加
	particles.push_back(myParticle);
	
	//現在のマウス座標を記録
	prevMouseX = x;
	prevMouseY = y;	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
