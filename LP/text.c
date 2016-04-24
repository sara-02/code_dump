#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>

static int font_index=0;

void print_bitmap_string(/*void* font,*/ char* s)
{

      while (*s) {
         glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, *s);
         s++;
      }
  
}

void my_reshape(int w, int h)
{
   GLdouble size;
   GLdouble aspect;

   /* Use the whole window. */
   glViewport(0, 0, w, h);

   /* We are going to do some 2-D orthographic drawing. */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   size = (GLdouble)((w >= h) ? w : h) / 2.0;
   if (w <= h) {
      aspect = (GLdouble)h/(GLdouble)w;
      glOrtho(-size, size, -size*aspect, size*aspect, -100000.0, 100000.0);
   }
   else {
      aspect = (GLdouble)w/(GLdouble)h;
      glOrtho(-size*aspect, size*aspect, -size, size, -100000.0, 100000.0);
   }

   /* Make the world and window coordinates coincide so that 1.0 in */
   /* model space equals one pixel in window space.                 */
   glScaled(aspect, aspect, 1.0);

   /* Now determine where to draw things. */
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

}


void draw_stuff()
{
   char* bitmap_font_names[7] = {"This is my firs text"};

   GLfloat x, y, ystep, yild, stroke_scale;

   /* Draw the strings, according to the current mode and font. */
   glTranslatef(0.5,-1.0,0);
   glColor4f(1.0, 1.0, 0.0, 0.0);
   x = -225.0;
   y = 70.0;
   ystep  = 100.0;
   yild   = 20.0;
      glRasterPos2f(-150, y+1.25*yild);
     print_bitmap_string(bitmap_font_names[0]);
}

void my_display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   draw_stuff();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,1.0);
   
        glVertex3f(0.5f, 0.0f, -4.0f);
        glVertex3f(1.0f, 0.5f, -4.0f);
        glVertex3f(0.5f, 0.5f, -4.0f);
        
   glEnd();

   glutSwapBuffers();
}

int main(int argc, char **argv)
{

   glutInitWindowSize(500, 250);
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
   glutCreateWindow("GLUT fonts");
   glutDisplayFunc(my_display);
   glutReshapeFunc(my_reshape);
   glutMainLoop();

   return 0;
}

