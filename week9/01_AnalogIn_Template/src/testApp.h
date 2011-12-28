#pragma once
#include "ofMain.h"
#include "ofEvents.h"

class testApp : public ofSimpleApp{

public:
	void setup();
	void update();
	void draw();
	void setupArduino(const int & version);
	void updateArduino();

	ofArduino ard;       //Arduinoへの接続
	bool bSetupArduino;  //Arduinoに接続したかのフラグ
};

