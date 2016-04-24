#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdlib.h>

float scale_v=0.5;
float rt_v=30;
void keypress(int key,int x,int y)
{
	if(key==GLUT_KEY_UP)
		scale_v+=0.05;
	if(key==GLUT_KEY_DOWN)
		scale_v-=0.05;
	if(key==GLUT_KEY_LEFT)
		rt_v+=0.5;
	if(key==GLUT_KEY_RIGHT)
		rt_v-=0.5;
	glutPostRedisplay();
}
void update(int value)
{
	rt_v+=0.5;
	if(rt_v>360)
		rt_v=rt_v-360;
 	glutPostRedisplay();
 	glutTimerFunc(25,update,0);
}
void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(double) w/(double) h,1.0,200.0);
}
void init()
{
	glEnable(GL_DEPTH_TEST);
}
void disp()
{ 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0,1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glScalef(scale_v,scale_v,1.0f);
	glRotatef(rt_v,0,0,1);
	glBegin(GL_POLYGON);
		glVertex3f(1.0f, 0.0f, -5.0f);
        glVertex3f(0.0f, 1.0f, -5.0f);
        glVertex3f(-1.0f, 0.0f, -5.0f);
	glEnd();
	//update();
	glutSwapBuffers();
}
int main(int argc, char ** argv)
{	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Scaling");
	init();
	glutDisplayFunc(disp);
	//glutKeyboardFunc(keypress);
	//glutSpecialFunc(keypress);
	glutReshapeFunc(reshape);
	glutTimerFunc(25,update,0);	
	glutMainLoop();
   return 0;
}
