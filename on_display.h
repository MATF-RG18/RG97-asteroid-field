#ifndef ON_DISPLAY
#define ON_DISPLAY

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "constante.h"

extern float brzina;
extern float animation_parameter;
extern int levodesno;
extern float asteroidX[];
extern float asteroidZ[];
extern int kraj_parametar;
extern float bureX;
extern float bureZ;

void on_display(void);


#endif