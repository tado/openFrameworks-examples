#include "testApp.h"

void testApp::setup(){
   //画面設定
   ofSetVerticalSync(true);
   ofSetFrameRate(60);
   ofBackground(255,0,130);
   bgImage.loadImage("firmata.png");
   font.loadFont("franklinGothic.otf", 20);

   // デバイスの接続するポートとスピードを設定
   ard.connect("/dev/cu.usbserial-A900ceWs", 57600);
   
   // Arduinoとの接続が確立するのを監視するリスナー
   // 接続が確立したら、setupArduino()を実行
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
   
   // 1〜13の全てのデジタルピンの初期設定(OUTPUTに)
   for (int i = 0; i < 13; i++){
      ard.sendDigitalPinMode(i, ARD_OUTPUT);
   }

   // Digital 13 をOUTPUTに
   ard.sendDigitalPinMode(13, ARD_OUTPUT);
   // Analog 0 をAnalog Inに
   ard.sendAnalogPinReporting(0, ARD_ANALOG);
   // Digital 11 をPWMに
   ard.sendDigitalPinMode(11, ARD_PWM);
   // 接続の確立のフラグをtrueに
   bSetupArduino = true;
}

void testApp::updateArduino(){
   
   // Arduinoをアップデート、全てのデータとメッセージを取得
   ard.update();
   
   // もしArduinoが接続されていたら
   if (bSetupArduino) {
      // Digital 11 のPWMの値を変化させる
      ard.sendPwm(11, (int)(128 + 128 * sin(ofGetElapsedTimef())));
   }
}

void testApp::draw(){
   // 画面を描画
   bgImage.draw(0,0);
   
   // Arduinoの状態を画面に出力
   if (!bSetupArduino){
      font.drawString("arduino not ready\n", 545, 40);
   } else {
      font.drawString("analog pin 0: " + ofToString(ard.getAnalog(0)) +
                      "\nsending pwm: " + ofToString((int)(128 + 128 * sin(ofGetElapsedTimef()))), 545, 40);
   }
}

void testApp::mousePressed(int x, int y, int button){
   // マウスプレスでDigital 13をON
   ard.sendDigital(13, ARD_HIGH);
}

void testApp::mouseReleased(int x, int y, int button){
   // マウスリリースでDigital 13をOFF
   ard.sendDigital(13, ARD_LOW);
}