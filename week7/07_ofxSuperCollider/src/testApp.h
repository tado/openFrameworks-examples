#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxSuperCollider.h"
#include "Ring.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofxSCSynth *reverb; // SC楽器 "reverb"
    ofxSCSynth *newRing; // SC楽器 "newRing"
    ofxSCSynth *baseSound;  // SC楽器 "baseSound"
    vector <Ring *> rings; //拡大する輪"Ring"の配列
};

#endif
