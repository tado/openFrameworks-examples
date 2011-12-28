#pragma once

#include "ofMain.h"
//#include "ofVec3f.h"

///////////////////
//sphere:
void ofxCreateSphereList();
void ofxSphere(float x, float y, float z, float size);
void ofxSphere(float x, float y, float z, float width, float height, float depth);
void ofxSphere(float x, float y, float z, float width, float height, float depth, float rotx, float rotY, float rotZ);
//overloaded for ofxVec
void ofxSphere(ofVec3f position, float size);
void ofxSphere(ofVec3f position, ofVec3f size);
void ofxSphere(ofVec3f position, ofVec3f size, ofVec3f rotation);
void ofxSetSphereResolution(int _resolution);


///////////////////
//box:
void ofxCreateBoxList();
void ofxBox(float x, float y, float z, float size);
void ofxBox(float x, float y, float z, float width, float height, float depth);
void ofxBox(float x, float y, float z, float width, float height, float depth, float rotX, float rotY, float rotZ);
//ofVec3f:
void ofxBox(ofVec3f position, float size);
void ofxBox(ofVec3f position, ofVec3f size);
void ofxBox(ofVec3f position, ofVec3f size, ofVec3f rotation);


////////////////////
//cone
void ofxCreateConeList();
void ofxCone(float x, float y, float z, float size);
void ofxCone(float x, float y, float z, float width, float height, float depth);
void ofxCone(float x, float y, float z, float width, float height, float depth, float rotX, float rotY, float rotZ);
//ofVec3f:
void ofxCone(ofVec3f position, float size);
void ofxCone(ofVec3f position, ofVec3f size);
void ofxCone(ofVec3f position, ofVec3f size, ofVec3f rotation);
void ofxSetConeResolution(int _resolution);

//////////////////
//capsule:
void ofxCreateCapsuleList();
void ofxCapsule(float x, float y, float z, float size);
void ofxCapsule(float x, float y, float z, float width, float height, float depth);
void ofxCapsule(float x, float y, float z, float width, float height, float depth, float rotX, float rotY, float rotZ);
//ofVec3f
void ofxCapsule(ofVec3f position, float size);
void ofxCapsule(ofVec3f position, ofVec3f size);
void ofxCapsule(ofVec3f position, ofVec3f size, ofVec3f rotation);
void ofxSetCapsuleResolution(int _resolution);

///////////////////
//lines, points, etc..
void ofxLine(float x1, float y1, float z1, float x2, float y2, float z2);
void ofxLine(ofVec3f pos1, ofVec3f pos2);

void ofxPoint(float x, float y, float z);
void ofxPoint(ofVec3f pos);

void ofxQuad(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);
void ofxQuad(ofVec3f pos1, ofVec3f pos2, ofVec3f pos3, ofVec3f pos4);

void ofxTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
void ofxTriangle(ofVec3f pos1, ofVec3f pos2, ofVec3f pos3);


/*
 INCOMPLETE!!!
/////////////////
//Polygons!!

static GLuint OFX_POINTS = GL_POINTS;
static GLuint OFX_LINES = GL_LINES;
static GLuint OFX_LINE_STRIP = GL_LINE_STRIP;
static GLuint OFX_LINE_LOOP = GL_LINE_LOOP;
static GLuint OFX_TRIANGLES = GL_TRIANGLES;
static GLuint OFX_TRIANGLE_STRIP = GL_TRIANGLE_STRIP;
static GLuint OFX_TRIANGLE_FAN = GL_TRIANGLE_FAN;
static GLuint OFX_QUADS = GL_QUADS;
static GLuint OFX_QUAD_STRIP = GL_QUAD_STRIP;
static GLuint OFX_POLYGON = GL_POLYGON;

void ofxBeginShape();
void ofxBeginShape(GLuint _shapeMode);

void ofxVertex(float x, float y, float z);
void ofxVertex(ofVec3f vertex);

void ofxEndShape(bool bClose = false);

*/








































