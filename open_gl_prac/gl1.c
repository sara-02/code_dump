#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define X .525731112119133606 
#define Z .850650808352039932

#define PI 3.1415926535898 
GLint circle_points = 100; 


void display(void)
{
	int i; float angle;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
   /* glBegin(GL_TRIANGLES);
		//glVertex2f(0.0, 0.0);
   //glVertex2f(0.0, 0.3);
   glVertex2f(0.4, 0.3);
   glVertex2f(0.6, .15);
   glVertex2f(0.4, 0.0);        
		/*glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    glFlush ();/*
/*glBegin(GL_POLYGON);
   glVertex2f(0.0, 0.0);
   glVertex2f(0.0, 3.0);
   glVertex2f(4.0, 3.0);
   glVertex2f(6.0, 1.5);
   glVertex2f(4.0, 0.0);
glEnd();
glFlush();
glLineStipple(1, 0x3F07);
glEnable(GL_LINE_STIPPLE);
glBegin(GL_LINE_LOOP); 
for (i = 0; i < circle_points; i++) {    
   angle = 2*PI*i/circle_points; 
   glVertex2f(cos(angle), sin(angle)); 
} 
glEnd();*/
static GLfloat vdata[12][3] = {    
   {-X, 0.0, Z}, {X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},    
   {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},    
   {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} 
};
static GLuint tindices[20][3] = { 
   {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
   {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
   {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
   {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11} };
//int i;

glBegin(GL_TRIANGLES);    
for (i = 0; i < 20; i++) {    
   /* color information here */ 
   glVertex3fv(&vdata[tindices[i][0]][0]); 
   glVertex3fv(&vdata[tindices[i][1]][0]); 
   glVertex3fv(&vdata[tindices[i][2]][0]); 
}
glEnd();
glFlush();

}
void init (void) 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000); 
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init ();
    glutDisplayFunc(display); 
    glutMainLoop();
    return 0;   
}
