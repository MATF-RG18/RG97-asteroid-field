#ifndef ON_TIMER
#define ON_TIMER

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "constante.h"

extern float animation_parameter;
extern float asteroidX[];
extern float asteroidZ[];
extern int kraj_parametar;
extern int skor;
extern int levodesno;
extern int animation_ongoing;

void on_timer(int id);

#endif