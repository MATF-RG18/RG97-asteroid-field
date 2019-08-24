#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


#include "constante.h"
#include "on_timer.h"
#include "on_key.h"
#include "on_display.h"
#include "on_reshape.h"
#include "object.h"


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
int levodesno =0;
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

