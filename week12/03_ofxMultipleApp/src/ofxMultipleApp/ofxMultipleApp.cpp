#include "ofxMultipleApp.h"

ofxMultipleApp* ofxMultipleApp::_instance = NULL;

void ofxMultipleApp::init()
{
	if (_instance == NULL)
	{
		_instance = new ofxMultipleApp();
		
		_instance->subapps.clear();
		
		ofAddListener(ofEvents.update, _instance, &ofxMultipleApp::_update);
		ofAddListener(ofEvents.draw, _instance, &ofxMultipleApp::_draw);
		ofAddListener(ofEvents.exit, _instance, &ofxMultipleApp::_exit);
		
		ofAddListener(ofEvents.windowResized, _instance, &ofxMultipleApp::_windowResized);
		
		ofAddListener(ofEvents.keyPressed, _instance, &ofxMultipleApp::_keyPressed);
		ofAddListener(ofEvents.keyReleased, _instance, &ofxMultipleApp::_keyReleased);
		
		ofAddListener(ofEvents.mouseMoved, _instance, &ofxMultipleApp::_mouseMoved);
		ofAddListener(ofEvents.mouseDragged, _instance, &ofxMultipleApp::_mouseDragged);
		ofAddListener(ofEvents.mousePressed, _instance, &ofxMultipleApp::_mousePressed);
		ofAddListener(ofEvents.mouseReleased, _instance, &ofxMultipleApp::_mouseReleased);
	}
}

void ofxMultipleApp::addApp(ofxSubApp *app)
{
	init();
	
	vector<ofxSubApp*>::iterator it = find(_instance->subapps.begin(), _instance->subapps.end(), app);
	
	if (it == _instance->subapps.end())
	{
		_instance->subapps.push_back(app);
		app->setup();
	}
}

void ofxMultipleApp::removeApp(ofxSubApp *app)
{
	init();
	
	vector<ofxSubApp*>::iterator it = find(_instance->subapps.begin(), _instance->subapps.end(), app);
	if (it != _instance->subapps.end())
	{
		_instance->subapps.erase(it);
	}	
}

void ofxMultipleApp::_update(ofEventArgs&)
{
	for (int i = 0; i < subapps.size(); i++) if (subapps[i]->enable) subapps[i]->update();
}

void ofxMultipleApp::_draw(ofEventArgs&)
{
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
		{
			glPushMatrix();
			subapps[i]->draw();
			glPopMatrix();
		}
}

void ofxMultipleApp::_exit(ofEventArgs&)
{
	for (int i = 0; i < subapps.size(); i++) subapps[i]->exit();
}

void ofxMultipleApp::_windowResized(ofResizeEventArgs &e)
{
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
			subapps[i]->windowResized(e.width, e.height);
}

void ofxMultipleApp::_keyPressed(ofKeyEventArgs &e)
{
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
			subapps[i]->keyPressed(e.key);
}

void ofxMultipleApp::_keyReleased(ofKeyEventArgs &e)
{
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
			subapps[i]->keyReleased(e.key);	
}

void ofxMultipleApp::_mouseMoved(ofMouseEventArgs &e)
{
	_mouseX = e.x;
	_mouseY = e.y;
	
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
		{
			subapps[i]->mouseX = _mouseX;
			subapps[i]->mouseY = _mouseY;
			subapps[i]->mouseMoved(e.x, e.y);
		}
}

void ofxMultipleApp::_mouseDragged(ofMouseEventArgs &e)
{
	_mouseX = e.x;
	_mouseY = e.y;
    
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
		{
			subapps[i]->mouseX = _mouseX;
			subapps[i]->mouseY = _mouseY;
			subapps[i]->mouseDragged(e.x, e.y, e.button);
		}
}

void ofxMultipleApp::_mousePressed(ofMouseEventArgs &e)
{
	_mouseX = e.x;
	_mouseY = e.y;
    
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
		{
			subapps[i]->mouseX = _mouseX;
			subapps[i]->mouseY = _mouseY;
			subapps[i]->mousePressed(e.x, e.y, e.button);
		}
}

void ofxMultipleApp::_mouseReleased(ofMouseEventArgs &e)
{
	_mouseX = e.x;
	_mouseY = e.y;
    
	for (int i = 0; i < subapps.size(); i++)
		if (subapps[i]->enable)
		{
			subapps[i]->mouseX = _mouseX;
			subapps[i]->mouseY = _mouseY;
			subapps[i]->mouseReleased(e.x, e.y, e.button);
		}
}

