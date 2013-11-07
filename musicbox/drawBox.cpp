#include "classes.h"
#define checkImageWidth 64
#define checkImageHeight 64

int lid_angle = 0;

void drawCuboid(float h, float w, float d, GLuint wood){
	GLint faces[6][4] = {	
		{0, 1, 3, 2}, {4, 5, 7, 6}, //Back face and front 
		{0, 4, 6, 2}, {1, 3, 7, 5}, //Left face and right face
		{0, 1, 5, 4}, {2, 3, 7, 6}, //Bottom face and top face
	};
	
	GLfloat n[6][3] = {	 // Normals
		{0,0,-1}, {0,0,1},	//Back and front
		{1,0,0},{-1,0,0},	 //Left and right
		{0,1,0}, {0,-1,0}	  //Bottom and top
	};
		
	GLfloat v[8][3];	// Will be filled in with X,Y,Z vertexes.

	for(int i =0; i<8; i++){
		v[i][2] = ((7-i)/4)*d;
		v[i][0] = (i%2)*w + -(w/2);
	
		if(i<4)
			v[i][1] = (i/2)*h;
		else
			v[i][1] = (i/6)*h;
	}
	
	
	glEnable(GL_TEXTURE_2D);

   glBindTexture(GL_TEXTURE_2D, wood);
   glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	
	for (int i = 0; i < 6; i++){
		glBegin(GL_QUADS);
		glNormal3fv(n[i]);
		for (int j=0;j<4;j++){
			switch(j){
				case 0:
					glTexCoord2f(0.0f, 0.0f);
					break;
				case 1:
					glTexCoord2f(1.0f, 0.0f);
					break;
				case 2:
					glTexCoord2f(1.0f, 1.0f);
					break;
				default:
					glTexCoord2f(0.0f, 1.0f);
					break;
			}
			
			glVertex3fv(v[faces[i][j]]);
		}
		glEnd();
	}
	
	glDisable(GL_TEXTURE_2D);
}


void drawBox(GLuint texture)
{
	float H=0.3, W=2.4, D=-3.0;
	float h=1.2, d=D, w=W/8;
	float l_h=0.3, l_d=d+0.3, l_w=W;
	
	glPushMatrix();
		//Base
		glTranslatef(0,0,-D/2);
		drawCuboid(H,W,D, texture);
	
		glPushMatrix();
		//Left barrier
		glTranslatef(-(W-w)/2,H,0);
		drawCuboid(h,w,d,texture);
	
	
		//Right barrier
		glTranslatef((W-w),0,0);
		drawCuboid(h,w,d, texture);
		glPopMatrix();
		
		glPushMatrix();
		//Front barrier
		glTranslatef(0,H,D);
		drawCuboid(h, W, W/8, texture);
		
		//Back barrier
		glTranslatef(0,0,-D-(W/8));
		drawCuboid(h, W, W/8, texture);
		glPopMatrix();
	
		glPushMatrix();
			//Lid
			glTranslatef(0,h+H,l_d);
			glRotatef(lid_angle, 1,0,0);
			drawCuboid(l_h,l_w,-l_d, texture);
		glPopMatrix();
	
	glPopMatrix();
}
