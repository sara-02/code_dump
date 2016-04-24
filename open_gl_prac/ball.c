#include <stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>

float ball_x=0.5;
float ball_y=0.0;
float ball_z=0.0;
static int flag=0;

void init()
{
	glEnable(GL_DEPTH_TEST);
}
/*
void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,0, 1.0, 200.0);	
}*/
void updatevert()
{
	if(!flag)
    {
        ball_y+=0.05;
        if(ball_y>1.0)
            flag=1;
    }
    if(flag)
    {
        ball_y-=0.05;
        if(ball_y<-1)
            flag=0;
    }
	glutPostRedisplay();
	glutTimerFunc(25,updatevert,0);
}
void updatehori()
{
	if(!flag)
	{
		ball_x+=0.05;
		if(ball_x>1.0)
			flag=1;
	}
	if(flag)
	{
		
	 ball_x-=0.05;
        if(ball_x<-1)
            flag=0;
    }
	glutPostRedisplay();
	glutTimerFunc(25,updatehori,0);

}	
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,0);	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0,0,0);
	glTranslatef(ball_x,ball_y,ball_z);
	glutSolidSphere(0.1,23,23);
	glutSwapBuffers();	
}
int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("BOUNCING BALLS");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	//glutReshapeFunc(reshape);
	glutTimerFunc(25,updatevert,0);
	//glutTimerFunc(25,updatehori,0);
	glutMainLoop();
return 0;
}
