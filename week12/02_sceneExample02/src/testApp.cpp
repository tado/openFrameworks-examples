#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	
	scenes[0] = new SceneA();
	scenes[1] = new SceneB();
	scenes[2] = new SceneC();
	
	currentScene = 0;
	scenes[currentScene]->setup();
}

//--------------------------------------------------------------
void testApp::update(){
	
	scenes[currentScene]->update();
}


//--------------------------------------------------------------
void testApp::draw(){
	
	scenes[currentScene]->draw();
	
	//メッセージ表示
	ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("Press [SPACE] : Change scene", 20, 20);
	ofDrawBitmapString("Press [f] : Toggle fullscreen", 20, 40);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key) {
		case ' ':
			currentScene++;
			currentScene %= 3;
			scenes[currentScene]->setup();
			break;
			
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	scenes[currentScene]->keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	scenes[currentScene]->mouseMoved(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	scenes[currentScene]->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	scenes[currentScene]->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	scenes[currentScene]->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	scenes[currentScene]->windowResized(w, h);
}
