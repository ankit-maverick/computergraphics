#ifndef __CLASSES_H
#define __CLASSES_H
#include<iostream>
#include<cstdlib>
#include<fstream>
#include <cmath>
#include "bezier.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 
using namespace std;

void mouseHandler(int button, int state, int x, int y);
void reshapeHandler( int w, int h );
void keyHandler(unsigned char key, int x, int y);

void drawBox(GLuint);
void drawBody(GLuint, GLuint);

void updateLookat();
GLuint LoadTexture(const char* filepath);

int write_keyframe();
void clear_keyframes();
int read_keyframes_and_playback();



extern float eye_x;
extern float eye_y;
extern float eye_z;

extern float center_x;
extern float center_y;
extern float center_z;

extern float dancer_pos;
extern unsigned char keyMode;

extern int WIN_WIDTH;
extern int WIN_HEIGHT;
extern int lid_angle;
extern Bezier curve;

extern bool light0;
extern bool light1;

#endif
