#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//ofxMultipleAppの初期化
	ofxMultipleApp::init();
	
	//シーンの登録
	sceneA = new SceneA();
	sceneB = new SceneB();
	sceneC = new SceneC();
	ofxMultipleApp::addApp(sceneA);
	ofxMultipleApp::addApp(sceneB);
	ofxMultipleApp::addApp(sceneC);

	//最初に表示するシーンを選択
	currentApp = sceneA;
	currentApp->show();
	sceneA->enable = true;
	
}

//--------------------------------------------------------------
void testApp::update(){

}


//--------------------------------------------------------------
void testApp::draw(){
	//ログ表示
	ofSetHexColor(0xFFFFFF);
	ofDrawBitmapString("Press key to change scene :\nScene A [1], Scene B [2], Scene C [3]", 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	//キー入力によって、シーンを切り替え
	switch (key) {
		case '1':
			currentApp->hide();
			currentApp->enable = false;
			currentApp = sceneA;
			currentApp->show();
			sceneA->enable = true;
			break;
			
		case '2':
			currentApp->hide();
			currentApp->enable = false;
			currentApp = sceneB;
			currentApp->show();
			sceneB->enable = true;
			break;
			
		case '3':
			currentApp->hide();
			currentApp->enable = false;
			currentApp = sceneC;
			currentApp->show();
			sceneC->enable = true;
			break;		
			
		case 'f':
			ofToggleFullscreen();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
