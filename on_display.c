#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "on_display.h"
#include "constante.h"
#include "object.h"

unsigned int kamen;
unsigned int pozadina;

unsigned int bum;


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

    //mapa
        glBindTexture(GL_TEXTURE_2D,pozadina);
        glDisable(GL_LIGHTING);
        mapa();
        glEnable(GL_LIGHTING);
        glBindTexture(GL_TEXTURE_2D,0);

    //svemirski brod 
        spaceShip(-2,levodesno);

    //crtanje bureta
        bure(bureX,0,bureZ);

    //polje asteroida
 		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D,kamen);

        int i;
        for(i=0;i< BR_ASTEROIDA;i++){
        	asteroid(asteroidX[i],0,asteroidZ[i]);
        }
        
        glBindTexture(GL_TEXTURE_2D,0);
       	glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);

	//kraj
        if(abs(kraj_parametar) == 1){
        	glBindTexture(GL_TEXTURE_2D,bum);
            glDisable(GL_LIGHTING);
            kraj();
            glEnable(GL_LIGHTING);
            glBindTexture(GL_TEXTURE_2D,0);
        }

    //skor
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0,500,0,500);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_DEPTH_TEST);

        poeni();

	glutSwapBuffers();

}