#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

void display(void)
{
	char *s = {"Helloworld!"};
	int length = strlen(s);
	float X =-0.8, Y=0.5;
    glClear(GL_COLOR_BUFFER_BIT);    
	glColor3d(1.0,1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  	
    int i;

    for(i=0; i<length; i++){    
	glRasterPos3f(X + (float)i*0.03,Y ,0);
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , s[i] );
	}

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Hello World!"); 

    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    //glutKeyboardFunc(key);
    glutMainLoop();
    
    return EXIT_SUCCESS;
}



