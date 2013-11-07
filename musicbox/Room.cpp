
#include <cstdlib> // C++ standard definitions

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Room.h"



GLuint door(GLuint door_tex){
	GLuint drawn_door = glGenLists(1);
	glNewList(drawn_door, GL_COMPILE);
		glScalef(0.5, 1.1, 0.05);
		//glColor3f(0.9, 0.6, 0.4);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, door_tex);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		//The color of the material
    	GLfloat doorColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the door
    	GLfloat doorSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the door
    	GLfloat doorEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat doorshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, doorColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, doorSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, doorEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, doorshininess); //The shininess parameter


		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();
	return drawn_door;
}


void draw_door(GLuint door_tex){
	GLuint drawn_door = door(door_tex);
	glCallList(drawn_door);
}


GLuint table_top_cuboid(GLuint wood){
	GLuint top_cuboid = glGenLists(1);
	glNewList(top_cuboid, GL_COMPILE);
		//glColor3f(1.0, 0.0, 0.0);
		glScalef(1.0, 0.05, 0.6);
		glScalef(0.8, 0.8, 0.8);
    
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//The color of the material
    	GLfloat tabletopColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the tabletop
    	GLfloat tabletopSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the tabletop
    	GLfloat tabletopEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat tabletopshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, tabletopColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, tabletopSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, tabletopEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, tabletopshininess); //The shininess parameter


		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();
	return top_cuboid;
}


GLuint table_foot(GLuint wood){
	GLuint foot = glGenLists(1);
	glNewList(foot, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		glScalef(0.05, 0.8, 0.05);
		glScalef(0.6, 0.6, 0.6);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//The color of the tabletop
    	GLfloat tablefootColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the tablefoot
    	GLfloat tablefootSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the tablefoot
    	GLfloat tablefootEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat tablefootshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, tablefootColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, tablefootSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, tablefootEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, tablefootshininess); //The shininess parameter

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();

	return foot;
}



GLuint portrait_frame(GLuint wood){
	GLuint frame = glGenLists(1);
	glNewList(frame, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		//glScalef(0.05, 0.8, 0.05);
		glScalef(0.6, 0.6, 0.05);
		glScalef(0.4, 0.4, 0.4);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();

	return frame;
}



GLuint portrait_pic(GLuint wood){
	GLuint pic = glGenLists(1);
	glNewList(pic, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		//glScalef(0.05, 0.8, 0.05);
		glScalef(0.55, 0.55, 0.05);
		glScalef(0.4, 0.4, 0.4);

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);


		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();


	glEndList();

	return pic;
}


GLuint wall_mounted_lamp_base(GLuint wood){
	GLuint base = glGenLists(1);
	glNewList(base, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		//glScalef(0.05, 0.8, 0.05);
		glScalef(0.15, 0.06, 0.04);
		//glScalef(0.4, 0.4, 0.4);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();

	return base;
}


void draw_wall_mounted_lamp(GLuint base_tex){
	GLuint base = wall_mounted_lamp_base(base_tex);
	//GLUquadricObj *quadratic;
	//quadratic = gluNewQuadric();

	glPushMatrix();
		glCallList(base);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.02);
		glColor3f(1.0, 1.0, 1.0);
		glScalef(1.0, 0.4, 0.2);
		glutSolidSphere(0.065, 20, 20);
	glPopMatrix();
}


void draw_portrait(GLuint frame_tex, GLuint pic_tex){
	GLuint frame = portrait_frame(frame_tex);
	GLuint pic = portrait_pic(pic_tex);
	glPushMatrix();
		glCallList(frame);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, -0.01);
		glCallList(pic);
	glPopMatrix();
}


GLuint room_cuboid(GLuint floor_tex, GLuint ceiling_tex, GLuint wall_tex){
	GLuint room = glGenLists(1);
	glNewList(room, GL_COMPILE);
		//glColor3f(0.0, 1.0, 0.0);
		glScalef(2.0, 1.2, 1.6);
		//glScalef(1.3, 1.3, 1.3);

		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, floor_tex);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//The color of the material
    	GLfloat floorColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the floor
    	GLfloat floorSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the floor
    	GLfloat floorEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat floorshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, floorColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, floorSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, floorEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, floorshininess); //The shininess parameter


		// Floor
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, ceiling_tex);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		//The color of the material
    	GLfloat ceilingColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the ceiling
    	GLfloat ceilingSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the ceiling
    	GLfloat ceilingEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat ceilingshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ceilingColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, ceilingSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, ceilingEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, ceilingshininess); //The shininess parameter


		// Ceiling
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, wall_tex);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		
		//The color of the material
    	GLfloat wallColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    	//The specular (shiny) component of the wall
    	GLfloat wallSpecular[] = {0.8, 0.2, 0.2, 1.0f};
    	//The color emitted by the wall
    	GLfloat wallEmission[] = {0.2, 0.2, 0.2, 1.0f};
    	GLfloat wallshininess = 6;
    	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wallColor);
    	glMaterialfv(GL_FRONT, GL_SPECULAR, wallSpecular);
    	glMaterialfv(GL_FRONT, GL_EMISSION, wallEmission);
    	glMaterialf(GL_FRONT, GL_SHININESS, wallshininess); //The shininess parameter


		// Right side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);

		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();
	return room;
}


GLuint bed_side(GLuint wood){
	GLuint side = glGenLists(1);
	glNewList(side, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		//glScalef(0.05, 0.8, 0.05);
		//glScalef(0.1, 0.3, 0.4);
		//glScalef(0.4, 0.4, 0.4);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();

	return side;	
}


GLuint bed_mattress(GLuint wood){
	GLuint mattress = glGenLists(1);
	glNewList(mattress, GL_COMPILE);
		//glColor3f(0.0, 0.0, 1.0);
		//glScalef(0.05, 0.8, 0.05);
		//glScalef(0.1, 0.3, 0.4);
		//glScalef(0.4, 0.4, 0.4);
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, wood);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Bottom
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Top
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, 0.5, -0.5);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glNormal3i(1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glNormal3i(-1, 0, 0);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Front
		//glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glNormal3i(0, -1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, -0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, -0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, -0.5);
		glEnd();
		// Back
		//glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glNormal3i(0, 1, 0);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(0.5, -0.5, 0.5);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-0.5, 0.5, 0.5);
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glDisable(GL_TEXTURE_2D);
	glEndList();

	return mattress;	
}



GLuint table_lamp(GLuint rod1_tex, GLuint rod2_tex, GLuint cyl_fan){
	GLuint t_lamp = glGenLists(1);
	glNewList(t_lamp, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();

		// frame
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(1.0, 0.2, 1.0);
			glutSolidCube(0.2);
		glPopMatrix();
		glPushMatrix();

			// Lower Rod
			glColor3f(1.0, 1.0, 0.0);
			glPushMatrix();
				glEnable(GL_TEXTURE_2D);

				glBindTexture(GL_TEXTURE_2D, rod1_tex);
				glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

				glScalef(0.5, 1.0, 0.5);
				glRotatef(-90, 1.0, 0.0, 0.0);
				gluQuadricTexture(quadratic, GL_TRUE);
				gluCylinder(quadratic,0.04f,0.04f,0.25f,20,20);
				glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			// Lower joint
			glPushMatrix();
				glColor3f(0.9, 0.9, 0.9);
				glTranslatef(0.0, 0.25, 0.0);
				glutSolidSphere(0.025, 10, 10);
				
				// Upper rod
				glColor3f(1.0, 0.0, 0.0);
				glPushMatrix();
					//glScalef(0.5, 1.0, 0.5);
					glEnable(GL_TEXTURE_2D);

					glBindTexture(GL_TEXTURE_2D, rod2_tex);
					glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

					glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
					glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

					glRotatef(60, 0.0, 0.0, 1.0);
					glRotatef(-90, 1.0, 0.0, 0.0);
					gluQuadricTexture(quadratic, GL_TRUE);
					gluCylinder(quadratic,0.02f,0.02f,0.15f,20,20);
					glDisable(GL_TEXTURE_2D);

				glPopMatrix();

				// Upper Joint
				glPushMatrix();
					glColor3f(0.0, 0.3, 0.8);
					glTranslatef(-0.125, 0.075, 0.0);
					glutSolidSphere(0.025, 10, 10);

					// Light Cone
					glPushMatrix();
						glEnable(GL_TEXTURE_2D);

					glBindTexture(GL_TEXTURE_2D, cyl_fan);
					glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

					glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
					glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

						glColor3f(0.0, 1.0, 0.0);
						glRotatef(-45, 0.0, 0.0, 1.0);
						glRotatef(-90, 1.0, 0.0, 0.0);
						glTranslatef(0.0, 0.0, -0.08);
						gluQuadricTexture(quadratic, GL_TRUE);
						gluCylinder( quadratic, 0.06, 0.005, 0.1, 20, 20);
						glDisable(GL_TEXTURE_2D);
					glPopMatrix();
				glPopMatrix();


			glPopMatrix();
		glPopMatrix();

	glEndList();
	return t_lamp;
}


void draw_bed(GLuint wood, GLuint mattress_tex){
	GLuint side = bed_side(wood);
	GLuint mattress = bed_mattress(mattress_tex);

	// Left
	glPushMatrix();
	
	glPushMatrix();
		glTranslatef(0.0, -0.05, 0.0);
		glScalef(0.1, 0.25, 0.4);
		glCallList(side);
	glPopMatrix();

	// Right
	glPushMatrix();
		glTranslatef(0.6, 0.0, 0.0);
		glScalef(0.1, 0.35, 0.4);
		glCallList(side);
	glPopMatrix();

	// Center
	glPushMatrix();
		glTranslatef(0.3, 0.0, 0.0);
		glScalef(0.6, 0.1, 0.4);
		glCallList(side);
	glPopMatrix();

	// Mattress
	glPushMatrix();
		glTranslatef(0.3, 0.06, 0.0);
		glScalef(0.6, 0.05, 0.4);
		glCallList(mattress);
	glPopMatrix();
	glPopMatrix();

}


void draw_pillow(GLuint pillow_tex){
	GLuint pillow = bed_side(pillow_tex);

	glPushMatrix();
		glScalef(0.1, 0.03, 0.2);
		glCallList(pillow);
	glPopMatrix();
}


void draw_stool(GLuint stool_bottom_tex, GLuint stool_seat_tex){

	GLuint bottom = bed_side(stool_bottom_tex);
	GLuint seat = bed_side(stool_seat_tex);

	glPushMatrix();
	glTranslatef(0.0, 0.1, -0.1);
	glPushMatrix();
		glTranslatef(0.0, -0.125, 0.0);
		glScalef(0.1, 0.05, 0.1);
		glCallList(bottom);
	glPopMatrix();

	// Rod
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glScalef(0.03, 0.25, 0.03);
		glCallList(bottom);
	glPopMatrix();

	// Seat
	glPushMatrix();
		glTranslatef(0.0, 0.125, 0.0);
		glScalef(0.2, 0.05, 0.2);
		glCallList(seat);
	glPopMatrix();
	glPopMatrix();
}


void draw_table_lamp(GLuint rod1_tex, GLuint rod2_tex, GLuint cyl_fan){
	GLuint t_lamp = table_lamp(rod1_tex, rod2_tex, cyl_fan);
	glCallList(t_lamp);
}


void draw_table(GLuint wood){
	GLuint top_cuboid = table_top_cuboid(wood);
	GLuint foot = table_foot(wood);
	glPushMatrix();
		glCallList(top_cuboid);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.36, -0.24, 0.20);
		glCallList(foot);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.36, -0.24, 0.20);
		glCallList(foot);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.36, -0.24, -0.20);
		glCallList(foot);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.36, -0.24, -0.20);
		glCallList(foot);
	glPopMatrix();
}


void draw_room(GLuint floor_tex, GLuint ceiling_tex, GLuint wall_tex){
	GLuint room = room_cuboid(floor_tex, ceiling_tex, wall_tex);
	glCallList(room);
}

