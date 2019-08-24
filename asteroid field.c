#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define TIMER_ID (0)
#define TIMER_INTERVAL (20)
#define PI (3.1415926535)
#define EPSILON (0.01)
#define BR_ASTEROIDA (12)

static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void on_timer(int);

void set_normal_and_vertex_cylinder(float u, float v);
void spaceShip(float x,float z);
void asteroid (float x, float y,float z);
void mapa();
void kraj();


float asteroidXstart[BR_ASTEROIDA]={15,20,25,30,
							   30,35,35,40,
							   45,50,50,55};
float asteroidZstart[BR_ASTEROIDA]={2,-2,0,-2,
							   2,-2,0,0,
							   2,0,2,-2};

float asteroidX[BR_ASTEROIDA]={15,20,25,30,
							   30,35,35,40,
							   45,50,50,55};
float asteroidZ[BR_ASTEROIDA]={2,-2,0,-2,
							   2,-2,0,0,
							   2,0,2,-2};

int animation_ongoing = 0;
float animation_parameter=0;
float levodesno =0;
int kraj_parametar = 0;
int skor = 0;

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("asteroid field");

	printf("press G to GO\n");

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
         case 'p':
         case 'P':
           animation_ongoing=0;
           break;
        case 'a':
        case 'A':
        	if(levodesno==-2)
        		break;
        	levodesno-=2;
        	break;
        case 'd':
        case 'D':
        	if(levodesno==2)
        		break;
        	levodesno+=2;
        	break;
    }
}



static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);
//1
    glMatrixMode(GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0,1,0,1,-1,1);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


//crtanje pozadine
	mapa();


//2
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1, 0.1, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();






    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            -0.5, 9, 0,
            3, 0, 0,
            0, 1, 0
        );
   //svemirski brod 
        spaceShip(-2,levodesno);

   //polje asteroida
        int i;
        for(i=0;i< BR_ASTEROIDA;i++){
        	asteroid(asteroidX[i],0,asteroidZ[i]);
        }

        if(abs(kraj_parametar) == 1){
        	kraj();
        }


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

//TODO
//mapa
void mapa(){

}


//--------------------------------crtanje broda-------------------------------------------------------
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


 static void on_timer(int id){
         
    if(id != TIMER_ID)
        return;

    animation_parameter += 0.5;
         
    int i;
    for(i=0;i<12;i++){
        asteroidX[i]-=0.1;//brzina
        
        if (asteroidX[i] < -4.9)
        		asteroidX[i]+=40;
        if(kraj_parametar == (-1)){
			printf("skor:\n%d\n",skor);
			int j,k;
			for (j=0;j<100000000;j++){k=sqrt(j);}//pauza
			exit(EXIT_SUCCESS); 
		}
        if (asteroidX[i]< 3.3 && asteroidX[i]>0 && asteroidZ[i]==levodesno){
        	skor =(int) animation_parameter;
        	kraj_parametar=1;
        }
    }
      
          
         
    if (animation_ongoing) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
      
        glutPostRedisplay();
}
