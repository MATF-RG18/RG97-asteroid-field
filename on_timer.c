#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "constante.h"
#include "on_timer.h"

void on_timer(int id){
         
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