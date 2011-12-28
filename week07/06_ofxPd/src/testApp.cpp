#include "testApp.h"

void testApp::setup(){
   ofSetFrameRate(60);
   ofBackground(0, 0, 0);
   
   //OSCの初期化
   static const string HOST = "localhost";
   static const int PORT = 8000;
   osc_sender.setup( "localhost", PORT);
   
   // pdのための定数を定義
   // 出力と入力のチャンネル数
   static const int NUM_OUT_CHANNELS = 2;
   static const int NUM_IN_CHANNELS = 2;
   // サンプリングレイト
   static const int BITRATE = 44100;
   // バッファーサイズ
   static const int BUFFER_SIZE = 256;
   // 使用するバッファーの数
   static const int NUM_BUFFERS = 4;
   // Pdのブロックサイズ
   static const int PD_BLOCK_SIZE = 64;
   
   // Pdを初期化
   pd.setup( "", NUM_OUT_CHANNELS, NUM_IN_CHANNELS, BITRATE, PD_BLOCK_SIZE );
   // Pdファイルを読み込み
   pd.addOpenFile( "simple_fm.pd" );
   // Pdを開始
   pd.start();
   // オーディオ入力を定義
   audioInputData = new float[BUFFER_SIZE*NUM_IN_CHANNELS];
   // サウンド出力を初期化
   ofSoundStreamSetup( NUM_OUT_CHANNELS, NUM_IN_CHANNELS, this, BITRATE, BUFFER_SIZE, NUM_BUFFERS );
   // Pdから音を出力
   pd.startDSP();
}

void testApp::update(){
}

void testApp::draw(){
   ofSetColor(0, 127, 255);
   ofCircle(mouseX, mouseY, 20);
}

void testApp::keyPressed  (int key){
}

void testApp::keyReleased  (int key){
}

void testApp::mouseMoved(int x, int y ){
   // マウスの座標をPdのパラメータとして送出
   pd.sendFloat( "modulator_freq", x );
   pd.sendFloat( "modulator_index", y );
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
}

void testApp::windowResized(int w, int h){
}

void testApp::audioOut (float * output, int bufferSize, int nChannels){
   //Pdの音を計算
   pd.renderAudio( audioInputData, output, bufferSize, nChannels );
}

void testApp::audioIn (float * input, int bufferSize, int nChannels){
   memcpy(audioInputData, input, bufferSize*nChannels*sizeof(float));
}