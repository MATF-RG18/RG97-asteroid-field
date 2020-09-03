#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <string.h>

#include"object.h"
#include"constante.h"


//pomocna funkcija pri crtanju valjka

void set_normal_and_vertex_cylinder(float u, float v)
{
    glNormal3f(0,cos(v),sin(v));
    glVertex3f(u,cos(v),sin(v));
}

//-----------svemirski brod-----------

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

//-----------asteroid-----------
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

//-----------gorivo-----------
void bure(float x, float y,float z){
	
	y+=1;

	glEnable(GL_CLIP_PLANE0);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
      
    glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    GLfloat Materialbure[] = { 0.9, 0.2, 0.1, 1.0 }; 
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Materialbure);

    glPushMatrix();
    glClipPlane(GL_CLIP_PLANE0, clip);
    glTranslatef(x,y,z);
    glRotatef(90,1,0,0);
    glutSolidCone(0.7,300,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.1,0.71,20,20);
    glPopMatrix();

    y--;
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.1,0.71,20,20);
    glPopMatrix();

    y--;
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(90,1,0,0);
    glutSolidTorus(0.1,0.71,20,20);
    glPopMatrix();

    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_LIGHTING);
}

//-----------crveni ekran da oznaci kraj-----------
void kraj (){
int i;
	for (i = 0; sqrt(i) < 10000; i++);

    glPushMatrix();
	
	glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    	glTexCoord2f(0,0);
        glVertex3f(-6, 4, -6);
        glTexCoord2f(0,1);
        glVertex3f(-6, 4, 6);
        glTexCoord2f(1,1);
        glVertex3f(6, 4, 6);
        glTexCoord2f(1,0);
        glVertex3f(6, 4, -6);
    glEnd();
    glPopMatrix();


    kraj_parametar=(-1);
	
}

//----------pozadina----------
void mapa(){

	glPushMatrix();
	
	glColor3f(0.5,0.5, 0.5);
    glBegin(GL_TRIANGLE_FAN);
    	glTexCoord2f(0,0);
        glVertex3f(-15, -3, -15);
        glTexCoord2f(0,1);
        glVertex3f(-15, -3, 15);
        glTexCoord2f(1,1);
        glVertex3f(15, -3, 15);
        glTexCoord2f(1,0);
        glVertex3f(15, -3, -15);
    glEnd();
    glPopMatrix();
}

//-----skor ispisan na ekranu----
void poeni(){
	glColor3f(1,1,1);

	char string[16] ="skor: ";

	char sk[10];
	sprintf(sk, "%d", skor);

	strcat(string,sk);


	glRasterPos2f(0,0);
	int i;
  	for (i=0;i<strlen(string);i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]); 
  }
}