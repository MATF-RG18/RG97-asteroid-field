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
		case 27:
			exit(EXIT_SUCCESS);
			break;
		 case 'g':
         case 'G':
        if(!animation_ongoing){
      
          animation_ongoing=1;
          glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
        }
             break;
         case 'p':
         case 'P':
           animation_ongoing=0;
           break;
        case 'a':
        case 'A':
        	if(levodesno==-2)
        		break;
        	levodesno-=2;
        	break;
        case 'd':
        case 'D':
        	if(levodesno==2)
        		break;
        	levodesno+=2;
        	break;
    }
}