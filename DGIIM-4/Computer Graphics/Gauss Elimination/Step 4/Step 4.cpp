#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
//============================
//=====================================================
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // system
using namespace std;


//===============================
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
}
//===============================

//===============================
void Draw_point_2d(float px,float py)
{
glBegin(GL_POINTS);
    glVertex2f(px,py);
glEnd();
}
//===============================

//===============================
void Draw_line_2d(float px,float py,float qx,float qy)
{

glBegin(GL_LINES);
    glVertex2f(px,py);
    glVertex2f(qx,qy);
glEnd();
}
//===============================
float f(float x) {
    return (11+x)/(3.0f/2.0f);
}

float g(float x) {
    return 2;
}

void display()
{
//------
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPushMatrix();


glLineWidth(3);
// Axes
glColor3f( 0.0, 0.0, 0.0);
Draw_line_2d(-10,0,10,-0);
glBegin(GL_TRIANGLES);
    glVertex2f(0.0,10.0);
    glVertex2f(-0.25,9.5);
    glVertex2f(0.25,9.5);
glEnd();

Draw_line_2d(0,-10,0,10);
glBegin(GL_TRIANGLES);
    glVertex2f(10.0,0.0);
    glVertex2f(9.5, 0.25);
    glVertex2f(9.5,-0.25);
glEnd();

glLineWidth(5);
// Red line
glColor3f( 1.0, 0.0, 0.0);
Draw_line_2d(-10,f(-10),10,f(10));

// Green line
glColor3f( 0.0, 1.0, 0.0);
Draw_line_2d(-10,g(-10),10,g(10));

// Point P
glPointSize(5);
glColor3f( 0.0, 0.0, 1.0);
Draw_point_2d(-8,2);


glPopMatrix();

}



int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(300,300,32,SDL_SWSURFACE|SDL_OPENGL);

    int petla=1;

    SDL_Event zdarzenie;
    init();
    while (petla==1)
    {

        while (SDL_PollEvent(&zdarzenie))
        {
            switch(zdarzenie.type)
            {
                case SDL_QUIT:
                petla=0;
                break;
            }
        }
       display();

        SDL_GL_SwapBuffers();

    }
    SDL_Quit();
    return 0;
}
