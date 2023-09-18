#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
//============================
//=====================================================
#include <stdlib.h>  // system

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//===============================
void init() {
    glClearColor(0.0, 0.59, 0.22, 1.0); // background color to green
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, +6, -6);
}
//===============================

//===============================
void Draw_point_2d(float px, float py) {
    glBegin(GL_POINTS);
    glVertex2f(px, py);
    glEnd();
}
//===============================

void display() {
    //------
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glLineWidth(1.0);

    // Yellow diamond in the middle
    glColor3f(1.0, 0.87, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 4.0);
    glVertex2f(8.0, 0.0);
    glVertex2f(0.0, -4.0);
    glVertex2f(-8.0, 0.0);
    glEnd();

    // Blue circle of the flag
    // NOTE: Here I could have just drawn a big point, but I wanted to use the 
    // polygon so I used the mathematical formula used to represent 
    // the n roots of unity in the complex plane which can be used to draw
    // regular polygons (in this case a circle approximation)
    glBegin(GL_POLYGON);
    int n=50;
    float scale = 2.5; // scale of the circle
    glColor3f(0.0, 0.13, 0.41);
    for (int k=0; k<n; k++) {
        glVertex2f(scale*cos(2*k*M_PI/n), scale*sin(2*k*M_PI/n));
    }
    glEnd();

    // White strip of the flag
    scale = 7;
    n = 200;    // We increase the size of n to get a better approximation
    glLineWidth(10.0);
    glColor3f(1.0, 1.0, 1.0);

    // The lines form the aristas of the polygon and the section is delimeted
    // by the vertices of the polygon where 50*n/65 <= k <= 58*n/65
    // These fractions are obtained by trial and error to fit the band in the circle
    // Parting from the fact that the band  should be between 3*n/4 and n
    for (int k=50*n/65; k<58*n/65; k++) {
        glBegin(GL_LINES);
        glVertex2f(scale*cos(2*k*M_PI/n)-3, scale*sin(2*k*M_PI/n)+5.5);
        glVertex2f(scale*cos(2*(k+1)*M_PI/n)-3, scale*sin(2*(k+1)*M_PI/n)+5.5);
        glEnd();
    }

    // Stars of the flag
    glPointSize(5);
    glEnable(GL_POINT_SMOOTH);
    Draw_point_2d(0.0, 0.5);
    Draw_point_2d(-1.0, 1.0);
    Draw_point_2d(0.5, 2.0);
    Draw_point_2d(1.5, 1.0);
    Draw_point_2d(-2.0, 0.5);
    Draw_point_2d(0.25, 1.25);


    glPopMatrix();
}

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(500, 300, 32, SDL_SWSURFACE | SDL_OPENGL);

    int petla = 1;

    SDL_Event zdarzenie;
    init();
    while (petla == 1) {
        while (SDL_PollEvent(&zdarzenie)) {
            switch (zdarzenie.type) {
                case SDL_QUIT:
                    petla = 0;
                    break;
            }
        }
        display();

        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}
