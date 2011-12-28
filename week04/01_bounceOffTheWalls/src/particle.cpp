#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.001f;
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	//壁の範囲を設定
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	//左右の壁でのバウンド
	if (pos.x > maxx){
		pos.x = maxx;
		vel.x *= -1;
	} else if (pos.x < minx){
		pos.x = minx;
		vel.x *= -1;
	}
	//上下の壁でのバウンド
	if (pos.y > maxy){
		pos.y = maxy;
		vel.y *= -1;
	} else if (pos.y < miny){
		pos.y = miny;
		vel.y *= -1;
	}
}
