#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);
	
	for (int i = 0; i < 3000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < particles.size(); i++){
		
		//particleの力をリセット
		particles[i].resetForce();
		
		//ベクトル場から、それぞれのparticleにかかる力を算出
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		
		//Particleの状態を更新
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
	}
	
	//ベクトル場の力の減衰
	//VF.fadeField(0.998f);
}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();
	ofSetColor(0, 0, 0, 15);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());

	//ベクトル場に配置されたparticleを描画
	ofSetColor(31, 200, 255);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}

	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key) {
		case 'c':
			VF.clear();
			break;
			
		case ' ':
			//パーティクルの場所を初期化
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	} 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
	
	VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 60, 0.3f);
	
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x; 
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
