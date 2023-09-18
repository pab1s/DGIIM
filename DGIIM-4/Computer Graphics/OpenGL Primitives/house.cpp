#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>
//============================
//=====================================================
#include <stdlib.h>  // system

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//===============================
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 12);
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

    glLineWidth(20);

    // Blue body of the House
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-6, -6);
    glVertex2f(6, -6);
    glVertex2f(6, 6);
    glVertex2f(-6, 6);
    glEnd();

    // Red roof of the House
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-6, 6);
    glVertex2f(0, 10);
    glVertex2f(6, 6);
    glEnd();

    // Gray door of the House
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-5, -6);
    glVertex2f(-3, -6);
    glVertex2f(-3, 1);
    glVertex2f(-5, 1);
    glEnd();

    // Gray window of the house
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0, 1);
    glVertex2f(4, 1);
    glVertex2f(4, -3);
    glVertex2f(0, 0 - 3);
    glEnd();

    glPopMatrix();
}

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(600, 600, 32, SDL_SWSURFACE | SDL_OPENGL);

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
