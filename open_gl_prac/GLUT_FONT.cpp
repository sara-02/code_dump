#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>

/* GLUT callback Handlers */

/* 
	Author : Anish Timsina
	www.anishtim.blogspot.com
*/


static void 
resize(int width, int height)
{
    const float ar = (float) width / (float) height;    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  	
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void 
display(void)
{
	char *data = {"Hello World!"};
	int length = strlen(data);
	float initialX = -2.0, initialY=5.0;
    glClear(GL_COLOR_BUFFER_BIT);    
	glColor3d(1.0,0.0,0.0);
	glLoadIdentity();
    gluPerspective(60.0, 1, 1, 100);  	
    int i;

    for(i=0; i<length; i++){    
	glRasterPos3f(initialX + (float)i*0.30 , initialY ,-10.0f);
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , data[i] );
	}

}


static void 
key(unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 'q':
            exit(0);
            break;	      			
    }
}




/* Program entry point */

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Hello World!"); 

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    
    return EXIT_SUCCESS;
}



