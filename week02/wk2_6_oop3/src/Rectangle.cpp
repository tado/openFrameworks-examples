#include "rectangle.h"

void Rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(0, 63, 255);
    ofRect(pos.x, pos.y, 5, 5);
}

void Rectangle::interpolateByPct(float _pct){
	float ppct = powf(_pct, shaper);
	pos.x = (1-ppct) * startPos.x + (ppct) * endPos.x;
	pos.y = (1-ppct) * startPos.y + (ppct) * endPos.y;
}