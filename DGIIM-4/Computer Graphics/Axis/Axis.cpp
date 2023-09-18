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



void display()
{
//------
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPushMatrix();

glLineWidth(1);
glColor3f( 0.0, 0.0, 0.0);

glBegin(GL_LINES);
    glVertex2f(-10,0);
    glVertex2f(10,0);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2d(10,0);
    glVertex2d(9.5,0.5);
    glVertex2d(9.5, -0.5);
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
