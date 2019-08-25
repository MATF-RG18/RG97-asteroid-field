#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "on_display.h"
#include "constante.h"
#include "object.h"


 void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0,1,0,1,-1,1);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();






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
           -2, 10, sin(animation_parameter/50),
            3, 0, 0,
            0, 1, 0
        );

    //svemirski brod 
        spaceShip(-2,levodesno);

    //crtanje bureta
        bure(bureX,0,bureZ);

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