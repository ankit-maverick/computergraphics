#include "classes.h"
#include "bezier.h"
#include <iostream>
using namespace std;



float* GetOGLPos(int x, int y)
{
     //Code from http://nehe.gamedev.net/article/using_gluunproject/16013/
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
    float values[3];
 
    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );
 
    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
 
    // 0.1 is for giving a depth offset from the eye position
    gluUnProject( winX, winY, 0.1, modelview, projection, viewport, &posX, &posY, &posZ);
    cerr << " 0.1 : " << posX << "\t" << posY << "\t" << posZ << endl;
     values[0]=posX;
     values[1]=posY;
     values[2]=posZ;

    //gluUnProject( winX, winY, 1.0, modelview, projection, viewport, &posX, &posY, &posZ);
    //cerr << " 1.0 : " << posX << "\t" << posY << "\t" << posZ << endl;
    return values;
}


void mouseHandler(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        float* values;
        cout << x << "," << y << "\n";
        
        values = GetOGLPos(x, y);
        
        curve.addPoint(values[0],values[1],values[2]);

    }
 
    glutPostRedisplay();
 
}
