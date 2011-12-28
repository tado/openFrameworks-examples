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
   
   ofSoundPlayer mySound; // サウンドプレーヤー
   float * fft; // FFT解析結果
   int nBandsToGet; // FFT解析バンド数
   float thresh; // LED ON/OFFの閾値
};

