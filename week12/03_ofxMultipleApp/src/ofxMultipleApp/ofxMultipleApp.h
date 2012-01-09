#pragma once

#include "ofMain.h"

#define OF_BASE_APP ofBaseApp

class ofxSubApp : public OF_BASE_APP
{
public:
	
	bool enable;
	
	ofxSubApp() { enable = false; }
	virtual ~ofxSubApp() {}
	
	virtual void show() { enable = true; }
	virtual void hide() { enable = false; }
	
};

class ofxMultipleApp
{
	static ofxMultipleApp *_instance;
	vector<ofxSubApp*> subapps;
	
	int _mouseX, _mouseY;
	
	void _update(ofEventArgs&);
	void _draw(ofEventArgs&);
	void _exit(ofEventArgs&);
	
	void _windowResized(ofResizeEventArgs&);
	
	void _keyPressed(ofKeyEventArgs&);
	void _keyReleased(ofKeyEventArgs&);
	
	void _mouseMoved(ofMouseEventArgs&);
	void _mouseDragged(ofMouseEventArgs&);
	void _mousePressed(ofMouseEventArgs&);
	void _mouseReleased(ofMouseEventArgs&);

	
public:
	
	static void init();
	
	static void addApp(ofxSubApp *app);
	static void removeApp(ofxSubApp *app);
};