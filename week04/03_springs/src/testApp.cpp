#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	ofBackground(0,0,0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	//particleの配列を生成
	for (int i = 0; i < 20; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
		particles.push_back(myParticle);
	}
	
	//全ての配列を順番にspringで接続していく
	for (int i = 0; i < (particles.size()-1); i++){
		spring mySpring;
		mySpring.distance = 25;
		mySpring.springiness = 0.2f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//全てのparticleの力をリセット
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	//全てのばねの伸縮を計算
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	//全てのparticleの状態を更新
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0, 0.1);
		particles[i].addDampingForce();
		particles[i].bounceOffWalls();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//全てのばねを描画
	ofSetColor(127, 127, 127);
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
	
	//全てのparticleを描画
	ofSetColor(0, 127, 255);
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){

		case ' ':
			//スペースキーで全てのparticleの位置をランダムな位置に再配置
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
	particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[0].bFixed = false;
}

