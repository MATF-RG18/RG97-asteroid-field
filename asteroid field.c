#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define TIMER_ID (0)
#define TIMER_INTERVAL (20)
#define PI (3.1415926535)
#define EPSILON (0.01)


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int);
void set_normal_and_vertex_cylinder(float u, float v);
void spaceShip(float x,float z);
int animation_ongoing = 0;
float animation_parameter=0;
float zoom = 5;
float rotacija =0;
float levodesno =0;
float goredole=0;

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("asteroid field");

	
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);
	glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
	
	glClearColor(0,0,0,0);

	glEnable(GL_DEPTH_TEST);

	glLineWidth(1);	

	glutMainLoop();
	
	return 0;

}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(EXIT_SUCCESS);
			break;
		 case 'g':
         case 'G':
        if(!animation_ongoing){
      
          animation_ongoing=1;
          glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
             break;
         case 's':
         case 'S':
           animation_ongoing=0;
           break;
        case 'j':
        case 'J':
        	zoom+=0.1;
        	break;
        case 'k':
        case 'K':
        	zoom-=0.1;
        	break;
        case 'u':
        case 'U':
        	rotacija-=0.03;
        	break;
        case 'i':
        case 'I':
        	rotacija+=0.03;
        	break;
        case 't':
        case 'T':
        	goredole+=0.1;
        	break;
        case 'y':
        case 'Y':
        	goredole-=0.1;
        	break;
        case 'a':
        case 'A':
        	levodesno-=0.1;
        	break;
        case 'd':
        case 'D':
        	levodesno+=0.1;
        	break;

      
    }
}



static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            -1*zoom*cos(rotacija), 0.5*zoom+goredole*zoom, zoom*sin(rotacija),
            0, 0, 0,
            0, 1, 0
        );

    glColor3f(1, 0, 0);
        glPushMatrix();
        glTranslatef(0.5, 0.5, 0.5);
        glutWireCube(1);
        glPopMatrix();
    
        spaceShip(-2,levodesno);
	glBegin(GL_LINES);

		glColor3f (0,0,1); //blue x
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);

		glColor3f (0,1,0); //green y
		glVertex3f(0,0,0);
		glVertex3f(0,50,0);

		glColor3f (1,0,0); //red z
		glVertex3f(0,0,0);
		glVertex3f(0,0,50);

	glEnd();


	glutSwapBuffers();

}

static void on_reshape(int width, int height)
{
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)width/height, 1, 100);
}
//pomocna funkcija pri crtanju valjka
void set_normal_and_vertex_cylinder(float u, float v)
{
    glNormal3f(0,cos(v),sin(v));
    glVertex3f(u,cos(v),sin(v));
}


//--------------------------------crtanje brodica-------------------------------------------------------
void spaceShip(float x,float z){
		GLfloat Material[] = { 0.7, 0.7, 0.7, 1.0 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Material);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
		glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);

    float u, v;
// telo - valjak
    glPushMatrix();
    glTranslatef(0,0,z);
   	glScalef(1,0.5,0.5);
    //glColor3f(0.5,0.5,0.5);
    for (u = 0; u < 1.5; u += PI / 20) {
        glBegin(GL_TRIANGLE_STRIP);
        for (v = 0; v <= PI*2 + EPSILON; v += PI / 20) {
            set_normal_and_vertex_cylinder(u, v);
            set_normal_and_vertex_cylinder(u + PI / 20, v);
        }
        glEnd();
    }
    glPopMatrix();
//kupa-vrh
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

//kupa-auspuh
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

              //nadogradja da izgleda kao da se nesto izbacuje iz auspuha
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
 static void on_timer(int id)
     {
         if(id != TIMER_ID)
          return;
         /*postavljamo tajmer dok je manje od 90 stepeni animacija se pokrece i povecavaju se
          ili smanjuju odredjeni parametri*/
        
           animation_parameter += 0.5;
      
      
          
         
         if (animation_ongoing) {
             glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
         }
      
        glutPostRedisplay();
     }