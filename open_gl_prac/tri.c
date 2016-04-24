#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1,0,1,-1,1);
}
void winreshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}
void disp()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glVertex3f(-0.5f, 0.5f, -5.0f);
        glVertex3f(-1.0f, 1.5f, -5.0f);
        glVertex3f(-1.5f, 0.5f, -5.0f);


        glVertex3f(0.5f, 0.5f, -5.0f);
        glVertex3f(1.0f, 1.5f, -5.0f);
        glVertex3f(1.5f, 0.5f, -5.0f);
   
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(0.5f, 0.0f, -4.0f);
        glVertex3f(0.5f, -0.5f, -4.0f);
        glVertex3f(1.5f, -0.5f, -4.0f);
        glVertex3f(1.5f, 0.0f, -4.0f);
glutSwapBuffers();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutCreateWindow("Triangle");
	init();
	glutDisplayFunc(disp);
	glutReshapeFunc(winreshape);
	glutMainLoop();
return 0;
}
