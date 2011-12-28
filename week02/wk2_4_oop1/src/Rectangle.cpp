#include "rectangle.h"

void Rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(31,127,255);
    ofRect(pos.x, pos.y, 20,20);
}