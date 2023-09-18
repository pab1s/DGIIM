#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<cmath>

//============================
//=====================================================
using namespace std;

//------------------------
// Range:
float Xmin = -10, Xmax = 10;
float Ymin = -10, Ymax = 10;
//------------------------

//===============================
void Draw_line(float V1 [2],float V2 [2])
{
glBegin(GL_LINES);
    glVertex2f(V1[0], V1[1]);
    glVertex2f(V2[0], V2[1]);
glEnd();
}
//===============================


//===============================
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Xmin,Xmax,Ymin,Ymax);
}
//===============================




void display()
{
//------
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//---------------------------------
// Coordinate system
glLineWidth(2.0);
glColor3f( 0.0, 0.0, 0.0);
//------------------------
// Border
glBegin(GL_LINES);
    glVertex2f(-10,-10);
    glVertex2f(-10,10);
glEnd();
glBegin(GL_LINES);
    glVertex2f(-10,10);
    glVertex2f(10,10);
glEnd();
glBegin(GL_LINES);
    glVertex2f(10,10);
    glVertex2f(10,-10);
glEnd();
glBegin(GL_LINES);
    glVertex2f(-10,10);
    glVertex2f(-10,1-0);
glEnd();

// X axis
float V1 [2] = {Xmin, 0.0f};
float V2 [2] = {Xmax, 0.0f};
Draw_line(V1,V2);

// Y axis
float U1 [2] = {0.0f, Ymin};
float U2 [2] = {0.0f, Ymax};
Draw_line(U1,U2);

//------------------------
// Axis arrows:
float XarrowW=(Xmax-Xmin)*.01;// arrow width
float XarrowL=(Xmax-Xmin)*.04;// arrow length
float YarrowW=(Ymax-Ymin)*.01;// arrow width
float YarrowL=(Ymax-Ymin)*.04;// arrow length

glBegin(GL_TRIANGLES);
    glVertex2f(Xmax-XarrowL,-XarrowW);
    glVertex2f(Xmax,0);
    glVertex2f(Xmax-XarrowL,XarrowW);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(-YarrowW,Ymax-YarrowL);
    glVertex2f(0,Ymax);
    glVertex2f(YarrowW,Ymax-YarrowL);
glEnd();
//------------------------

// Curve = y=(x+2)^2
glColor3f( 0.0, 0.0, 1.0);
for (int i=0; i<100; i++) {
    V1[0] = i*0.1;
    V1[1] = (V1[0]+2)*V1[0];
    V2[0] = (i+1)*0.1;
    V2[1] = (V2[0]+2)*V2[0];
    Draw_line(V1,V2);
}
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
