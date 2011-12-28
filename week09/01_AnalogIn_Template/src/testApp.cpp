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
}

void testApp::update(){
   // Arduinoを更新
   updateArduino();
}

void testApp::setupArduino(const int & version) {
   // 接続が確立したら、リスナーを削除
   ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
   // 0〜5のAnalog INを初期化
   for (int i = 0; i < 6; i++) {
      ard.sendAnalogPinReporting(i, ARD_ANALOG);
   }
   // 接続の確立のフラグをtrueに
   bSetupArduino = true;
}

void testApp::updateArduino(){
   // Arduinoをアップデート、全てのデータとメッセージを取得
   ard.update();
}

void testApp::draw(){
   // Analog INの値を利用して描画する
   // ard.getAnalog(0) 〜 ard.getAnalog(5)
   
   // 全てのAnalog Inの値をメッセージ出力
   if (bSetupArduino){
      string msg = "";
      for (int i = 0; i < 6; i++) {
         msg += "Analog IN " + ofToString(i, 0) 
         + " : " + ofToString(ard.getAnalog(i), 0) + "\n";
      }
      ofSetHexColor(0xFFFFFF);
      ofDrawBitmapString(msg, 20, 20);
   }
}