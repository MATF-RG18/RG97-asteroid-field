#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "on_key.h"
#include "constante.h"
#include "on_timer.h"


void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27: //escape
			exit(EXIT_SUCCESS);
			break;

		 case 'g'://go
         case 'G':
        if(!animation_ongoing){
      
          animation_ongoing=1;
          glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
             break;
         case 'p'://pause
         case 'P':
           animation_ongoing=0;
           break;

        case 'a'://left
        case 'A':
        	if (stanje ==0){
        		signal=-1;break;
        	}else if(stanje==2){
        		signal=-10;break;
        	}else if(stanje ==-2){
        		break;
        	}

        case 'd'://right
        case 'D':
        	if (stanje ==0){
        		signal=1;break;
        	}else if(stanje==-2){
        		signal=10;break;
        	}else if(stanje ==2){
        		break;
        	}
    }
}