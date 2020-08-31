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
extern int signal;
extern int stanje;
extern float levodesno;
extern int animation_ongoing;
extern float bureX;
extern float bureZ;

time_t t;

void on_timer(int id);

#endif
