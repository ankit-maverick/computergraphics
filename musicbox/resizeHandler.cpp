
#include "classes.h"


void reshapeHandler( int w, int h )
{
  if  ( h == 0 ) h = 1;
 
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
 
  glOrtho( 0.0, (GLdouble)w, 0.0, (GLdouble)h, -1., 1. );
  glViewport( 0, 0, w, h );
 
  WIN_HEIGHT = w;
  WIN_HEIGHT = h;
 
  glutPostRedisplay();
}
