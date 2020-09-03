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


unsigned int tekstura(const char * putanja);
//koordinate asteroida
float asteroidX[BR_ASTEROIDA]={15,20,25,30,
							   30,35,35,40,
							   45,50,50,55};
float asteroidZ[BR_ASTEROIDA]={2,-2,0,-2,
							   2,-2,0,0,
							   2,0,2,-2};

//koordinate bureta
float bureX=57.5;
float bureZ=2;

//
int animation_ongoing = 0;
float animation_parameter=0;

//promenljive za teksture
extern unsigned int kamen;
extern unsigned int pozadina;
extern unsigned int bum;

//polozaj svemirskog broda
float levodesno =0;
int signal =0;
int stanje =0;


//parametar za zavrsetak
int kraj_parametar = 0;

//rezultat
int skor = 0;

int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("asteroid field");

	glEnable(GL_TEXTURE_2D);
	kamen = tekstura("asteroid.bmp");
	pozadina = tekstura("Pozadina.bmp");
  	bum = tekstura("bum.bmp");

	printf("G -> GO\n"\
			"P -> PAUSE\n"\
			"A -> LEFT\n"\
			"D -> RIGHT\n"\
			"Esc -> ESCAPE\n\n");

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

//funkcija za ucitavanje tekstura
unsigned int tekstura(const char * putanja){
  FILE *file=fopen(putanja,"rb");
    if(file==NULL){
        return 10000;
    }
    unsigned int sirina;
    unsigned int visina;
    unsigned short bit_c;
    unsigned int djubre;

  fread(&djubre, 2, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&djubre, 4, 1, file);

  fread(&djubre, 4, 1, file);
  fread(&sirina, 4, 1, file);
  fread(&visina, 4, 1, file);
  fread(&djubre, 2, 1, file);
  fread(&bit_c, 2, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);
  fread(&djubre, 4, 1, file);

  char *pixeli;
  unsigned char r,g,b,a;
  if(bit_c==24)
    pixeli=(char *)malloc(3*sirina*visina*sizeof(char));
else if(bit_c==32)
    pixeli=(char *)malloc(4*sirina*visina*sizeof(char));
else 
    return 10001;
    if(bit_c==24)
    for (int i = 0; i < sirina * visina; i++) {
      fread(&b, sizeof(char), 1, file);
      fread(&g, sizeof(char), 1, file);
      fread(&r, sizeof(char), 1, file);

      pixeli[3 * i] =g;
      pixeli[3 * i + 1] = b;
      pixeli[3 * i + 2] = r;
    }
    if(bit_c==32)
    for (int i = 0; i < sirina * visina; i++) {
      fread(&b, sizeof(char), 1, file);
      fread(&g, sizeof(char), 1, file);
      fread(&r, sizeof(char), 1, file);
      fread(&a, sizeof(char), 1, file);

      pixeli[4 * i] = g;
      pixeli[4 * i + 1] = b;
      pixeli[4 * i + 2] = r;
      pixeli[4 * i + 3] = a;
    }
    unsigned int id;
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 sirina, visina, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, pixeli);
    free(pixeli);
    fclose(file);
    glBindTexture(GL_TEXTURE_2D,0);
    
  return id;
}