//#include<iostream>
#include<stdlib.h>

#ifdef __APPLE__
#include<openGL/openGL.h>
#include<GLUT/glut.h>
#else 
#include<GL/glut.h>
#endif

//using namespace std;

double rotate_by_key=0;

double rotate_x=0.5;

void keyPress(int key,int x,int y)
{

    if(key==27)
          exit(0);
    if (key == GLUT_KEY_UP)
            rotate_x += .05;
        if (key == GLUT_KEY_DOWN)
            rotate_x -= .05;

    glutPostRedisplay();
   
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}


//Called when the window is resized
void handleResize(int w, int h) {
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
    
    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
    gluPerspective(45.0,                  //The camera angle
                   (double)w / (double)h, //The width-to-height ratio
                   1.0,                   //The near z clipping coordinate
                   200.0);                //The far z clipping coordinate
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   
    glMatrixMode(GL_MODELVIEW);
   
    glLoadIdentity();

    glScalef( rotate_x,rotate_x,1.0f );
    //glScalef(1.0f,1.0f,rotate_x);
    glRotatef(  rotate_by_key,-1.0f, 1.5f, -5.0f );
    glBegin(GL_TRIANGLES);

        glVertex3f(1.0f, 0.0f, -5.0f);
        glVertex3f(0.0f, 1.0f, -5.0f);
        glVertex3f(-1.0f, 0.0f, -5.0f);

    glEnd();
   
    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
   
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
   
    glutInitWindowSize(400,400);
   
    glutCreateWindow("My triangle");
   
    initRendering();
   
    glutDisplayFunc(drawScene);
   
    glutSpecialFunc(keyPress);

    glutReshapeFunc(handleResize);
   
    glutMainLoop();
   
    return(0);
}

