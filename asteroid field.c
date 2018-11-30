#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>






static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);


int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("asteroid field");

	
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	
	glClearColor(0,0,0,0);

	glEnable(GL_DEPTH_TEST);

	glLineWidth(1);	

	glutMainLoop();
	
	return 0;

}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(EXIT_SUCCESS);
			break;
	}
}


static void on_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            7, 7, 7,
            0, 0, 0,
            0, 1, 0
        );

    
    


	glBegin(GL_LINES);

		glColor3f (0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);

		glColor3f (0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(0,50,0);

		glColor3f (1,0,0);
		glVertex3f(0,0,0);
		glVertex3f(0,0,50);

	glEnd();


	glutSwapBuffers();

}

static void on_reshape(int width, int height)
{
	
	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(float)width/height, 1, 100);
}

