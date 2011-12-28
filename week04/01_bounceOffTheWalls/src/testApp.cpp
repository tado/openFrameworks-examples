#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetBackgroundAuto(false);
	//ofEnableAlphaBlending();
	
	ofBackground(0, 0, 0);
	pimg.loadImage("particle32.png");
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addForce(0.0, 0.28);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofSetColor(0, 0, 0, 31);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofSetColor(255, 255, 255);
	for (int i = 0; i < particles.size(); i++){
		pimg.draw(particles[i].pos.x-16, particles[i].pos.y-16);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	//1フレーム前の座標から、現在のマウス座標との差分を算出
	float dx = x - preMouse.x;
	float dy = y - preMouse.y;
	
	//新規にパーティクルを作成、計算したベクトルを付与
	particle myParticle;
	myParticle.setInitialCondition(x,y, dx*0.5,dy*0.5);
	//配列に追加
	particles.push_back(myParticle);
	
	//現在のマウス座標を記録
	preMouse.x = x;
	preMouse.y = y;	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles.clear();
	preMouse.x = x;
	preMouse.y = y;	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
