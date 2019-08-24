#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include"object.h"
#include"constante.h"


//pomocna funkcija pri crtanju valjka

void set_normal_and_vertex_cylinder(float u, float v)
{
    glNormal3f(0,cos(v),sin(v));
    glVertex3f(u,cos(v),sin(v));
}

//svemirski brod

void spaceShip(float x,float z){
		GLfloat Material[] = { 0.7, 0.7, 0.7, 1.0 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    float u, v;
// telo

    glPushMatrix();
    glTranslatef(0,0,z);
   	glScalef(1,0.5,0.5);

    for (u = 0; u < 1.5; u += PI / 20) {
        glBegin(GL_TRIANGLE_STRIP);
        for (v = 0; v <= PI*2 + EPSILON; v += PI / 20) {
            set_normal_and_vertex_cylinder(u, v);
            set_normal_and_vertex_cylinder(u + PI / 20, v);
        }
        glEnd();
    }
    glPopMatrix();
//vrh

    GLfloat Material_vrh[] = { 0.7, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_vrh);
    glPushMatrix();
   
    glTranslatef(1.57,0,z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.5,1,40,40);

	glPopMatrix();
// dno

	GLfloat Material_dno[] = { 0.2, 0.2, 0.2, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_dno);
	glPushMatrix();
	glTranslatef(0,0,z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.5,0.1,40,40);

	glPopMatrix();

//auspuh

	GLfloat Material_auspuh[] = { 0.7, 0.2, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_auspuh);
	glPushMatrix();
	glTranslatef(-0.2,0.25,z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2,-0.15,0.25+z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();	

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2,-0.15,-0.25+z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();

  //narandzasta vatra iz auspuha

	GLfloat Material_auspuh1[] = { 0.2, 0.2, 0.2, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_auspuh1);
	glPushMatrix();
	glTranslatef(-0.19,0.25,z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.19,-0.15,0.25+z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();	

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.19,-0.15,-0.25+z);
	glRotatef(90,0,1,0);
	glutSolidCone(0.2,1,20,20);

	glPopMatrix();

//kabina
	
	GLfloat Material_kabina[] = { 0.5, 0.5, 1, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_kabina);

	glPushMatrix();
	
	glTranslatef(1.2,0.5,z);
	glutSolidSphere(0.25,20,20);
	
	glPopMatrix();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);

//krilca
	GLfloat Material_krilca[] = { 0.7, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_krilca);
	glPushMatrix();
	glTranslatef(0,0,z);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7,0,0);
	glVertex3f(0,0,0);
	glVertex3f(0,-0.5,1);
	glVertex3f(1.5,0,0);
	glEnd();	

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7,0,0);
	glVertex3f(0,0,0);
	glVertex3f(0,-0.5,-1);
	glVertex3f(1.5,0,0);
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.7,0,0);
	glVertex3f(0,0,0);
	glVertex3f(0,1,0);
	glVertex3f(1.5,0,0);
	glEnd();
	glPopMatrix();

}

// asteroid
void asteroid (float x, float y,float z){

	GLfloat Material_asteroid[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_asteroid);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glPushMatrix();
	
	glTranslatef(x,y,z);
	glutSolidSphere(0.75,20,20);
	
	glPopMatrix();
	glDisable(GL_LIGHTING);

}

void kraj (){

    GLfloat Material_kraj[] = { 0.7, 0, 0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Material_kraj);
	glPushMatrix();
	
	
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(-2, 7, -2);
        glVertex3f(-2, 7, 2);
        glVertex3f(2, 7, 2);
        glVertex3f(2, 7, -2);
    glEnd();
    glPopMatrix();

    kraj_parametar=(-1);
	
}

//void mapa(){}
