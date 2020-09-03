#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<time.h>

#include "constante.h"
#include "on_timer.h"


float limit =500;
float brzina =0.1;
float nivo=250;

void on_timer(int id){
         
    if(id != TIMER_ID)
        return;

    skor=(int)animation_parameter;

    if(animation_parameter>nivo){
        brzina+=0.05;
        nivo+=500;
    }

    //povecava se vreme u naimacij/rezultat
    //i smanjuje se gorivo u rezervoaru
    animation_parameter += 0.5;
    limit-=0.5;
         
    //kretanje asteroida (u odnosu na brod)
    int i;
    for(i=0;i<12;i++){

        //brzina
        asteroidX[i]-=brzina;
        
        //resetovanje asteroida
        if (asteroidX[i] < -4.9)
        		asteroidX[i]+=40;
        
        //ispisivanje rezultata na kraju i izlazak iz programa
        if(kraj_parametar == (-1)){
			printf("\nrezultat:\n%d\n",skor);
			int j,k;
            for (i = 0; sqrt(i) < 10000; i++);
			exit(EXIT_SUCCESS); 
		}

        //obrada kolizija
        if (asteroidX[i]< 3.3 && asteroidX[i]>(-0.1) && asteroidZ[i]==levodesno){
        	skor =(int) animation_parameter;
        	kraj_parametar=1;
        }
    }
    
    //kretanje broda
    if(signal==10){
    	if(levodesno>0){
    		levodesno=0;
    		stanje=0;
    		signal =0;
    	}else{
    		levodesno+=brzina*1.5;

    	}
    }else if(signal ==-10){
    	if(levodesno<0){
    		levodesno=0;
    		stanje=0;
    		signal =0;
    	}else{
    		levodesno-=brzina*1.5;
    	}
    }else if(signal==1){
    	if(levodesno>2){
    		levodesno=2;
    		stanje=2;
    		signal =0;
    	}else{
    		levodesno+=brzina*1.5;
    	}
    }else if(signal==-1){

    	if (levodesno<-2){
    		levodesno=-2;
    		stanje=-2;
    		signal =0;
    	}else{
    		levodesno-=brzina*1.5;
    	}
    }
    
    //kretane bureta sa kerozinom
    bureX-=brzina;

    //resetovanje bureta
    if (bureX<-4.9){
        bureX+=40; 

        srand( time(&t));
        bureZ=(float)(rand()%3 - 1) * 2;
    }

    //skupljeno bure, pun rezervoar, resetovanje bureta
    if (bureX< 3.3 && bureX>0 && bureZ==levodesno){
        bureX+=80;
        limit=1000;

        srand( time(&t));
        bureZ=(float)(rand()%3 - 1) * 2;
    }

    //prazan rezervoar
    if(limit<0){
        printf("Prazan rezervoar :(\n");
        skor=(int)animation_parameter;
        kraj_parametar=(-1);
    }
         
    if (animation_ongoing) {
        glutTimerFunc(TIMER_INTERVAL, on_timer, TIMER_ID);
    }
      
        glutPostRedisplay();
}
