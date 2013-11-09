
#include <cstdlib> // C++ standard definitions
#include "classes.h"
#include "humanBody.h"



GLuint dancer_head(GLuint skin, GLuint hair) {
	GLuint head = glGenLists(1);
	glNewList(head, GL_COMPILE);
		glScalef(0.9, 0.9, 0.9);
		glColor3f(0.9, 0.6, 0.4);
		
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, skin);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		
		// Bottom
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.1, -0.15, 0.1);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.1, -0.15, 0.1);
		glEnd();
		// Front
		glColor3f(0.9, 0.6, 0.4);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.12, 0.15, -0.12);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.12, 0.15, -0.12);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, hair);
		glColor4f(1.0, 1.0, 1.0, 1.0); // reset color
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		
		// Top
		glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.12, 0.15, -0.12);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.12, 0.15, -0.12);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.12, 0.15, 0.12);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.12, 0.15, 0.12);
		glEnd();
		// Right side
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.12, 0.15, -0.12);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.12, 0.15, 0.12);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-0.1, -0.15, 0.1);
		glEnd();
		// Left side
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.1, -0.15, -0.1);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.1, -0.15, 0.1);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.12, 0.15, 0.12);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.12, 0.15, -0.12);
		glEnd();
		// Back
		glColor3f(0.25, 0.0, 0.0);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.1, -0.15, 0.1);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(-0.1, -0.15, 0.1);
			glTexCoord2f(1.0f, 1.0f);	glVertex3f(-0.12, 0.15, 0.12);
			glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.12, 0.15, 0.12);
		glEnd();

		glDisable(GL_TEXTURE_2D);

	glEndList();
	return head;
}


GLuint dancer_torso1(GLuint shirt_tex) {
	GLuint torso1 = glGenLists(1);
	glNewList(torso1, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, shirt_tex);
				glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//glColor3f(1.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 0.5);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluQuadricTexture(quadratic, GL_TRUE);
		gluCylinder(quadratic,0.2f,0.17f,0.30f,32,32);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glEndList();
	return torso1;
}


GLuint dancer_torso2() {
	GLuint torso2 = glGenLists(1);
	glNewList(torso2, GL_COMPILE);
		glColor3f(0.0, 0.5, 0.0);
		glScalef(0.8, 0.8, 0.2);
		glutSolidSphere(0.15, 20, 20);
	glEndList();
	return torso2;
}


GLuint dancer_torso3(GLuint shirt_tex) {
	GLuint torso3 = glGenLists(1);
	glNewList(torso3, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
			glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, shirt_tex);
				glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//glColor3f(0.0, 1.0, 0.0);
		glScalef(1.0, 1.0, 0.5);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic, GL_TRUE);
		gluCylinder(quadratic,0.175f,0.195f,0.25f,32,32);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	return torso3;
}


GLuint dancer_neck() {
	GLuint neck = glGenLists(1);
	glNewList(neck, GL_COMPILE);
		glColor3f(0.0, 0.0, 1.0);
		glScalef(1.0, 0.8, 1.0);
		glutSolidCube(0.125);
	glEndList();
	return neck;
}


GLuint dancer_eye() {
	GLuint eye = glGenLists(1);
	glNewList(eye, GL_COMPILE);
		glColor3f(0.0, 0.0, 0.0);
		glScalef(1.0, 1.0, 0.5);
		glutSolidSphere(0.02, 10, 10);
	glEndList();
	return eye;
}


GLuint dancer_nose() {
	GLuint nose = glGenLists(1);
	glNewList(nose, GL_COMPILE);
		glColor3f(0.25, 0.0, 0.0);
		glRotatef(180, 1.0, 0.0, 0.0);
		glutSolidCone(0.02, 0.05, 10, 10);
	glEndList();
	return nose;
}



GLuint dancer_mouth() {
	GLuint mouth = glGenLists(1);
	glNewList(mouth, GL_COMPILE);
		glColor3f(0.0, 0.0, 0.0);
		glScalef(1.0, 0.4, 0.8);
		glutSolidSphere(0.08, 10, 10);
	glEndList();
	return mouth;
}


GLuint dancer_greek_hat() {
	GLuint greek_hat = glGenLists(1);
	glNewList(greek_hat, GL_COMPILE);
		glPushMatrix();
			glColor3f(1.0, 0.85, 0.75);
			glTranslatef(0.0, 0.0, -0.05);
			glScalef(0.8, 0.2, 1.15);
			glutSolidSphere(0.17, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0, 0.25, 1.0);
			glTranslatef(0.0, 0.01, 0.05);
			glScalef(0.78, 0.18, 0.7);
			glutSolidCube(0.35);
		glPopMatrix();
	glEndList();
	return greek_hat;
}




GLuint dancer_shoulder() {
	GLuint shoulder = glGenLists(1);
	glNewList(shoulder, GL_COMPILE);
		glColor3f(0.5, 0.0, 0.5);
		glutSolidSphere(0.07, 10, 10);
	glEndList();
	return shoulder;
}



GLuint dancer_upper_arm(GLuint shirt_tex) {
	GLuint upper_arm = glGenLists(1);
	glNewList(upper_arm, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, shirt_tex);
				//glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		//glColor3f(0.5, 0.0, 0.0);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluQuadricTexture(quadratic, GL_TRUE);
		gluCylinder(quadratic,0.04f,0.04f,0.30f,20,20);
		glDisable(GL_TEXTURE_2D);
	glEndList();
	return upper_arm;
}



GLuint dancer_elbow() {
	GLuint elbow = glGenLists(1);
	glNewList(elbow, GL_COMPILE);
		glColor3f(0.0, 0.0, 0.5);
		glScalef(0.8, 0.7, 0.8);
		glutSolidSphere(0.07,10,10);
	glEndList();
	return elbow;
}




GLuint dancer_lower_arm(GLuint skin) {
	GLuint lower_arm = glGenLists(1);
	glNewList(lower_arm, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();

		glEnable(GL_TEXTURE_2D);
		
		//gluQuadricNormals(quadratic, GLU_SMOOTH);
		gluQuadricTexture(quadratic,GL_TRUE);

		glBindTexture(GL_TEXTURE_2D, skin);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	   glColor3f(1.0, 1.0, 0.0);
      glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
      gluCylinder(quadratic,0.04f,0.03f,0.35f,20,20);
      glDisable(GL_TEXTURE_2D);
	glEndList();
	return lower_arm;
}



GLuint dancer_wrist() {
	GLuint wrist = glGenLists(1);
	glNewList(wrist, GL_COMPILE);
		glColor3f(1.0, 0.0, 0.0);
		glScalef(1.0, 0.4, 1.0);
		glutSolidSphere(0.04, 10, 10);
	glEndList();
	return wrist;
}



GLuint dancer_hand() {
	GLuint hand = glGenLists(1);
	glNewList(hand, GL_COMPILE);
		glColor3f(1.0, 0.55, 0);
		glScalef(0.35, 1.0, 0.6);
		glutSolidSphere(0.08, 10, 10);
	glEndList();
	return hand;
}



GLuint dancer_hip() {
	GLuint hip = glGenLists(1);
	glNewList(hip, GL_COMPILE);
		glColor3f(0.0, 0.5, 0.0);
		glutSolidSphere(0.085, 10, 10);
	glEndList();
	return hip;
}



GLuint dancer_thigh(GLuint jeans_tex) {
	GLuint thigh = glGenLists(1);
	glNewList(thigh, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, jeans_tex);
				//glColor4f(1.0, 1.0, 1.0, 1.0); // reset color

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		//glColor3f(0.5, 0.5, 0.0);
        glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic,0.08f,0.06f,0.35f,20,20);
        glDisable(GL_TEXTURE_2D);
	glEndList();
	return thigh;
}



GLuint dancer_knee() {
	GLuint knee = glGenLists(1);
	glNewList(knee, GL_COMPILE);
	    glColor3f(0.73, 0.56, 0.56);
        glScalef(1.0, 0.9, 1.0);
        glutSolidSphere(0.07, 10, 10);
	glEndList();
	return knee;
}



GLuint dancer_leg(GLuint skin) {
	GLuint leg = glGenLists(1);
	glNewList(leg, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();

		glEnable(GL_TEXTURE_2D);
		
		gluQuadricNormals(quadratic, GLU_SMOOTH);
		gluQuadricTexture(quadratic,GL_TRUE);

		glBindTexture(GL_TEXTURE_2D, skin);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

     glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
     gluCylinder(quadratic,0.06f,0.045f,0.40f,20,20);
     glDisable(GL_TEXTURE_2D);
	glEndList();
	return leg;
}



GLuint dancer_ankle() {
	GLuint ankle = glGenLists(1);
	glNewList(ankle, GL_COMPILE);
		glColor3f(0.0, 0.0, 1.0);
		glScalef(1.0, 0.7, 1.0);
		glutSolidSphere(0.05, 10, 10);
	glEndList();
	return ankle;
}



GLuint dancer_foot() {
	GLuint foot = glGenLists(1);
	glNewList(foot, GL_COMPILE);
		glColor3f(1.0, 1.0, 0.0);
		glScalef(0.5, 0.25, 1.1);
		glutSolidSphere(0.08, 10, 10);
	glEndList();
	return foot;
}


