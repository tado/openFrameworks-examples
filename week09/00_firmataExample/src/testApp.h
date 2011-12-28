#pragma once
#include "ofMain.h"
#include "ofEvents.h"

class testApp : public ofSimpleApp{

public:

	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
		
	void setupArduino(const int & version);
	void updateArduino();

	ofImage bgImage;
	ofTrueTypeFont font; 
	ofArduino ard;       //Arduinoへの接続
	bool bSetupArduino;  //Arduinoに接続したかのフラグ
};

