#include "rectangle.h"

void Rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(31,127,255);
    ofRect(pos.x, pos.y, 20,20);
}

void Rectangle::interpolateByPct(float _pct){
	pct = powf(_pct, shaper);
	pos.x = (1-pct) * startPos.x + (pct) * endPos.x;
	pos.y = (1-pct) * startPos.y + (pct) * endPos.y;
}