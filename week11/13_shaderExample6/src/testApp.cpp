#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	for (int i = 0; i < 50; i++){
		particle myParticle;
		
		float x = 500 + 100 * cos ( (i / 200.0) * TWO_PI);
		float y = 500 + 100 * sin ( (i / 200.0) * TWO_PI);
		
		myParticle.setInitialCondition(x,y ,0,0);
		particles.push_back(myParticle);
	}
	
	// change this to
	// for (int i = 0; i < 10; i++){
	// to see a chain
	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		mySpring.distance		= 8;
		mySpring.springiness	= 0.2f;
		mySpring.particleA = & (particles[i  ]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
	
	
	//shader.setup("shaders/gradient");
	shader.load("shaders/gradient.vert", "shaders/gradient.frag");
	shader.printActiveUniforms();
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.7f);
		
		for (int j = 0; j < i; j++){
			particles[i].addRepulsionForce(particles[j], 80, 0.2);
		}
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	float minx, maxx, miny, maxy;
	
	for (int i = 0; i < particles.size(); i++){
		if (i == 0) {
			minx = particles[i].pos.x;
			maxx = particles[i].pos.x;
			miny = particles[i].pos.y;
			maxy = particles[i].pos.y;
		} else {
			
			minx = min(minx, particles[i].pos.x);
			maxx = max(maxx, particles[i].pos.x);
			miny = min(miny, particles[i].pos.y);
			maxy = max(maxy, particles[i].pos.y);
		}
	}
	
	float x = minx;
	float y = miny;
	float w = maxx - minx;
	float h = maxy - miny;

	shader.begin();
	
	shader.setUniform1f("x", x);
	shader.setUniform1f("y", y);
	shader.setUniform1f("w", w);
	shader.setUniform1f("h", h);
	
	
	shader.setUniform2f("gradientCenter", x + w * 0.5f, y + h*0.5f);
	shader.setUniform2f("gradientAngle",  (float)sin(PI/4.0), (float)cos(PI/4.0));
	shader.setUniform1f("gradientLength", 250.0f);
	
	shader.setUniform3f("gradientColorA", 10.0f / 255.0f, 175.0f / 255.0f, 240.0f / 255.0f);
	shader.setUniform3f("gradientColorB", 10.0f / 255.0f, 240.0f / 255.0f, 63.0f / 255.0f);
	
	shader.setUniform1f("gradientAlpha", 1.0f);

	
	ofFill();
	ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
		ofVertex(particles[i].pos.x, particles[i].pos.y);
	}
	ofEndShape();
	
	shader.end();
	
	
	
	
	ofSetColor(0xffffff);
	
	/*for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}*/

}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
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
	/*particles.erase(particles.begin());
	particle myParticle;
	myParticle.setInitialCondition(x,y,0,0);
	particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
	particles[0].bFixed = false;
}

