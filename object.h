#ifndef OBJECT
#define OBJECT

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>



extern int kraj_parametar;
static const GLdouble clip[] = {0, 1, 0, 1};

void set_normal_and_vertex_cylinder(float u, float v);
void spaceShip(float x,float z);
void asteroid (float x, float y,float z);
void bure(float x, float y,float z);
void kraj();


#endif