#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>
#include <time.h>
#include <sys/timeb.h>
#include<bits/stdc++.h>
using namespace std;




void draw(int dis)
{   dis%=20;
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3d(0,0,0);
    glBegin(GL_LINES);
    glVertex2d(0,85);
    glVertex2d(640,85);
    glVertex2d(0,40);
    glVertex2d(640,40);
    glEnd();
    glColor3d(0,0,0);
    glBegin(GL_POINTS);
    circle_half(200,200,80);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(120,200);
    glVertex2d(280,200);
    glEnd();
    glBegin(GL_POINTS);
    circle(150,150,20);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(150,130);
    glVertex2d(150,78);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(150,78);
    glVertex2d(150-dis,50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(150,78);
    glVertex2d(150+dis,50);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(200,200);
    glVertex2d(200,130);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(150,120);
    glVertex2d(170,110);
    glEnd();glBegin(GL_LINES);
    glVertex2d(150,115);
    glVertex2d(170,105);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(200,130);
    glVertex2d(170,110);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(200,130);
    glVertex2d(170,105);
    glEnd();

    for(int i=1;i<=1000;i++)
    {


        int x=rand(),y=rand();
        x%=640; y%=480;
        if(x>=120&&x<=280&&y<=280)continue;
        glBegin(GL_LINES);
        glColor3b(1,1,1);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

}

void plot(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,1,0);
    glBegin(GL_POINTS);
    for(int i=1;i<=100;i++)
    {


        int x=rand(),y=rand();
        x%=640; y%=480;
        if(x>=120&&x<=280&&y<=280)continue;
        glBegin(GL_LINES);
        glColor3b(1,1,1);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

    for(int i=1;i<=10000;i+=5)
    draw(i);

    glFlush();
}
void Init()
{
    /* Set clear color to white */
    glClearColor(1.0,1.0,1.0,0);
    /* Set fill color to black */
    glColor3f(0.0,0.0,0.0);
    /* glViewport(0 , 0 , 640 , 480); */
    /* glMatrixMode(GL_PROJECTION); */
    /* glLoadIdentity(); */
    gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{





    /* Initialise GLUT library */
    glutInit(&argc,argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("Rain");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(plot);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}
