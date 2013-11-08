
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "classes.h"
#include "humanBody.h"
#include "Room.h"
#include "bezier.h"

#define pi 3.14

using namespace std;


/* GLOBAL VARIABLES */

int WIN_HEIGHT = 512;
int WIN_WIDTH = 512;

int rot_left_elbow;
int rot_right_elbow;

int rot_left_shoulder_x; // _* denotes the direction of rotation/tilt and not the axis of rotation
int rot_right_shoulder_x;
int rot_left_shoulder_z;
int rot_right_shoulder_z;

int rot_right_wrist;
int rot_left_wrist;

int rot_left_hip_x;
int rot_right_hip_x;
int rot_left_hip_z;
int rot_right_hip_z;

float mouth_speak = 0.005;

int rot_neck_x;
int rot_neck_y;

int rot_right_knee;
int rot_left_knee;

int rot_left_ankle;
int rot_right_ankle;

int rot_torso2_x;
int rot_torso2_y;


GLuint skin_tex;
GLuint hair_tex;

int rotate_x = 0;
int rotate_y = 0;

bool light0;
bool light1;
float dancer_pos=0;

Bezier curve = Bezier(0.0125);

GLuint table_tex;
GLuint door_tex;
GLuint floor_tex;
GLuint ceiling_tex;
GLuint wall_tex;
GLuint portrait_frame_tex;
GLuint portrait_pic_tex;
GLuint wall_mounted_lamp_base_tex;
GLuint bed_side_tex;
GLuint bed_mattress_tex;
GLuint stool_bottom_tex;
GLuint stool_seat_tex;
GLuint pillow_tex;
GLuint box_tex;
GLuint window_tex;
GLuint rod1_tex;
GLuint rod2_tex;
GLuint lamp_base_tex;

//BezierCurve curve = BezierCurve(0.04);

/*
GLuint LoadTexture(const char* filepath) {
  GLuint texture; 
  unsigned char header[54];
  unsigned int position = 54;
  unsigned int width;
  unsigned int height;
  unsigned int imagesize; 
  unsigned char* pixel;

  FILE * bmpfile;
  bmpfile  = fopen(filepath, "rb"); 
  if(!bmpfile) {printf("Image not found\n"); return 0;}
  fread(header,1,54,bmpfile);
  width = *(int*)&(header[18]);
  height = *(int*)&(header[22]);
  imagesize = width*height*3;

  pixel = new unsigned char[imagesize];
  fread(pixel,1,imagesize,bmpfile);
  fclose(bmpfile);

  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  
  glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixel);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  return texture;
}
*/

float eye_x = 0.0;
float eye_y = 0.0;
float eye_z = 5.0;

float center_x = 0.0;
float center_y = 0.0;
float center_z = 0.0;

float r = 5;
float theta = 0;
float phi = 0;
float theta1,phi1;


// The following R, theta, phi 3d navigation model adapted from
// Parthe - Jinit's group
void updateXYZ()
{
    theta1 = pi*( 90 + theta)/180;
    phi1  =  pi*phi/180;

    eye_x = r*sin(theta1)*sin(phi1);
    eye_y = r*cos(theta1);
    eye_z = r*sin(theta1)*cos(phi1);

}

void updateLookAt()
{    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z,center_x,center_y,center_z,0,1,0);
}


void keyboardspecial(int a, int b, int c)
{
    switch (a)
    {
        case GLUT_KEY_UP: 
            
            theta = theta - 3;
            updateXYZ();
            
            break;
        case GLUT_KEY_DOWN: 
            
            theta = theta + 3;
            updateXYZ();
            
            break;
        case GLUT_KEY_LEFT: 
            
            phi = phi - 3;
            updateXYZ();
            
            break;
        case GLUT_KEY_RIGHT: 
            
            phi = phi + 3;
            updateXYZ();
            
            break;
        case GLUT_KEY_PAGE_UP: 
            if (r >0.6)
                r = r - 0.2;
            updateXYZ();
            
            break;
        case GLUT_KEY_PAGE_DOWN: 
            if (r < 10)
                r = r + 0.2;
            updateXYZ();

            break;
        default: exit(0);break;
    }

    glutPostRedisplay();
}



void display(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, //Field of view
                   1.0, //Aspect ratio
                    0.3, // Z near
                    1000.0);// Z far

    updateLookAt();

    //Configuring GL_LIGHT1 i.e. Table Lamp
    GLfloat light_ambient1[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat light_diffuse1[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular1[] = {0.0, 1.0, 0.0, 1.0};
    GLfloat light_position1[] = {-0.2, 0.35, 0.60, 1.0};
    GLfloat light_direction1[] = {1.0,-0.5,0.0};

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction1);
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF, 60);
    
    // Room cuboid
    glPushMatrix();
        glTranslatef(0.0, 0.1, 0.0);
        draw_room(floor_tex, ceiling_tex, wall_tex);
    glPopMatrix();

    // Table
    glPushMatrix();
        glTranslatef(0.0, -0.18, 0.60);
        glScalef(0.7, 0.7, 0.7);
        draw_table(table_tex);
    glPopMatrix();

    // Table Lamp
    glPushMatrix();
        glTranslatef(-0.2, -0.15, 0.60);
        glRotatef(180, 0.0, 1.0, 0.0);
        glScalef(0.7, 0.7, 0.7);
        draw_table_lamp(rod1_tex, rod2_tex, lamp_base_tex);
    glPopMatrix();

    if (light1 == true){
        glEnable(GL_LIGHT1);
    }
    else if(light1 == false){
        glDisable(GL_LIGHT1);
    }


    // Door
    glPushMatrix();
        glTranslatef(0.7, -0.05, 0.8);
        glScalef(0.7, 0.7, 0.7);
        draw_door(door_tex);
    glPopMatrix();

    // Portrait
    glPushMatrix();
        glTranslatef(-0.6, 0.3, 0.8);
        glScalef(1.5, 1.5, 1.0);
        draw_portrait(portrait_frame_tex, portrait_pic_tex);
    glPopMatrix();

    // Window
    glPushMatrix();
        glTranslatef(0.4, 0.1, -0.8);
        glRotatef(180, 0.0, 1.0, 0.0);
        glScalef(2.5, 2.5, 1.0);
        draw_portrait(table_tex, window_tex);
    glPopMatrix();

    // Wall Mounted Lamp
    glPushMatrix();
        glTranslatef(-0.2, 0.5, -0.8);
        glRotatef(180, 0.0, 1.0, 0.0);
        draw_wall_mounted_lamp(wall_mounted_lamp_base_tex);
    glPopMatrix();

    if (light0 == true){
        glEnable(GL_LIGHT0);
    }
    else if(light0 == false){
        glDisable(GL_LIGHT0);
    }

    // Bed
    glPushMatrix();
        glTranslatef(-0.7, -0.34, -0.4);
        glRotatef(-90, 0.0, 1.0, 0.0);
        draw_bed(bed_side_tex, bed_mattress_tex);
        glPushMatrix();
            glTranslatef(0.5, 0.1, 0.0);
            draw_pillow(pillow_tex);
        glPopMatrix();
    glPopMatrix();

    // Stool
    glPushMatrix();
        glTranslatef(-0.2, -0.46, 0.30);
        draw_stool(stool_bottom_tex, stool_seat_tex);
    glPopMatrix();

    // Dancer
    glPushMatrix();
        glTranslatef(0.1, 0.10, 0.60);
        glScalef(0.08, 0.08, 0.08);
        drawBody(skin_tex, hair_tex);
    glPopMatrix();

    // MusicBox
    glPushMatrix();
        glTranslatef(0.1, -0.163, 0.62);
        glScalef(0.1, 0.1, 0.1);
        drawBox(box_tex);
    glPopMatrix();


        Bezier::Stack_node* curr_node = curve.control_points.head;
    
        for(int i=0; i<curve.control_points.num_nodes; i++){
            glPushMatrix();
                glTranslatef(curr_node->x, curr_node->y, curr_node->z);
                glColor3f(0.0, 0.0, 1.0);
                glutSolidSphere(0.003, 20, 20);
                //glFlush();
            glPopMatrix();
        
            curr_node = curr_node->next;
        }
    
        for(int i=0; i<curve.numSamples-1; i++){
            glBegin(GL_LINES);
                glVertex3f(curve.sampledCurve[i*3], curve.sampledCurve[i*3 + 1], curve.sampledCurve[i*3 + 2]);
                glVertex3f(curve.sampledCurve[(i+1)*3], curve.sampledCurve[(i+1)*3 + 1], curve.sampledCurve[(i+1)*3 + 2]);
            glEnd();

            glPushMatrix();
                glTranslatef(curve.sampledCurve[i*3], curve.sampledCurve[i*3 + 1], curve.sampledCurve[i*3+2]);
                glColor3f(0.0, 1.0, 0.0);
                glutSolidCube(0.005);
            glPopMatrix();
        }

	glFlush();
	glutSwapBuffers();

}



void init(void){
    table_tex = LoadTexture("tex/wood2.bmp");
    door_tex = LoadTexture("tex/door.bmp");
    floor_tex = LoadTexture("tex/floor3.bmp");
    wall_tex = LoadTexture("tex/metal2.bmp");
    ceiling_tex = LoadTexture("tex/walls2.bmp");
    portrait_frame_tex = LoadTexture("tex/wood.bmp");
    portrait_pic_tex = LoadTexture("tex/vangogh.bmp");
    wall_mounted_lamp_base_tex = LoadTexture("tex/sunnymossy_wall.bmp");
    bed_side_tex = LoadTexture("tex/wood.bmp");
    bed_mattress_tex = LoadTexture("tex/mattress1.bmp");
    stool_bottom_tex = LoadTexture("tex/metal2.bmp");
    stool_seat_tex = LoadTexture("tex/fabric2.bmp");
    pillow_tex = LoadTexture("tex/fabric1.bmp");
    skin_tex = LoadTexture("tex/skin.bmp");
    hair_tex = LoadTexture("tex/hair.bmp");
    box_tex = LoadTexture("tex/wood3.bmp");
    window_tex = LoadTexture("tex/beachview.bmp");
    rod1_tex = LoadTexture("tex/black.bmp");
    rod2_tex = LoadTexture("tex/black.bmp");
    lamp_base_tex = LoadTexture("tex/brown.bmp");



    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable (GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);

    //Configuring GL_LIGHT0 i.i. Wall Mounted Lamp
    GLfloat light_ambient0[] ={0.7, 0.7, 0.7, 1.0};
    GLfloat light_diffuse0[] ={1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular0[] ={0.0, 1.0, 0.0, 1.0};
    GLfloat light_position0[] ={-0.2, 0.5, -0.8, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);

/*
    //Configuring GL_LIGHT1 i.e. Table Lamp
    GLfloat light_ambient1[] ={0.7, 0.7, 0.7, 1.0};
    GLfloat light_diffuse1[] ={1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular1[] ={0.0, 1.0, 0.0, 1.0};
    GLfloat light_position1[] ={-0.2, 0.35, 0.60, 1.0};
    GLfloat light_direction1[] = {-1.0,-1.0,0.0};

    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_direction1);
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF, 60);
*/       


/*
    glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);
    //glShadeModel(GL_FLAT);
    //glEnable()
    glEnable(GL_LIGHT0);

    // Create light components
    GLfloat ambientLight[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
    GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat position[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    
    //glDisable(GL_LIGHT0);
    //updateLookAt();
*/
}




int main(int argc, char* argv[]){
 
    glutInit(&argc,argv);
 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition (100, 100);

    glutCreateWindow("MusicBox!!");
    clear_keyframes();

    glEnable(GL_DEPTH_TEST);
 	glClearColor(0.0f,0.0f,0.0f, 1.0f);

    glutDisplayFunc(display);
    glutSpecialFunc(keyboardspecial);
    glutKeyboardFunc(keyHandler);
    glutMouseFunc(mouseHandler);

    init();

    glutMainLoop();
 
    return 0;
 
}

