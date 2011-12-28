#include "testApp.h"

void testApp::setup(){
   //画面設定
   ofSetVerticalSync(true);
   ofSetFrameRate(60);
   ofBackgroundHex(0x000000);
   // デバイスの接続するポートとスピードを設定
   ard.connect("/dev/cu.usbserial-A900ceWs", 57600);
   // Arduinoとの接続が確立するのを監視するリスナー
   ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
   // 接続の確立したかどうかのフラグ
   bSetupArduino	= false;
   
   thresh = 0.01;
   mySound.loadSound("sounds/drumLoop.aif");
   mySound.setLoop(true);
   nBandsToGet = 4;
}

void testApp::update(){
   // Arduinoを更新
   updateArduino();
   
   // FFT解析
   ofSoundUpdate();
   fft = ofSoundGetSpectrum(nBandsToGet);
}

void testApp::setupArduino(const int & version) {
   // 接続が確立したら、リスナーを削除
   ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
   // 1〜13の全てのデジタルピンをOUTPUTに
   for (int i = 0; i < 13; i++){
      ard.sendDigitalPinMode(i, ARD_OUTPUT);
      ard.sendDigital(i, ARD_LOW);
   }
   // 接続の確立のフラグをtrueに
   bSetupArduino = true;
   //サウンド再生開始
   mySound.play();
}

void testApp::updateArduino(){
   // Arduinoをアップデート、全てのデータとメッセージを取得
   ard.update();
}

void testApp::draw(){
   if (bSetupArduino){
      string msg = "";
      for (int i = 0; i < 4; i++) {
         // FFTの解析結果を表示
         msg += "FFT " + ofToString(i, 0) + " : " + ofToString(fft[i], 8) + "\n";

         // 閾値より大きければ、該当するchのLEDを点灯する
         if (fft[i] > thresh) {
            ard.sendDigital(12-i, ARD_HIGH);
         } else {
            ard.sendDigital(12-i, ARD_LOW);
         }
      }
      ofSetHexColor(0xFFFFFF);
      ofDrawBitmapString(msg, 20, 20);
   }
}