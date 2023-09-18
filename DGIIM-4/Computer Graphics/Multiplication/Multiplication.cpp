#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

//===============================
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,450,0,400);
}
//===============================


//===============================
void Draw_line(float V1 [2],float V2 [2])
{

glBegin(GL_LINES);
    glVertex2f(V1[0], V1[1]);
    glVertex2f(V2[0], V2[1]);
glEnd();
}
//===============================


void display()
{
//------
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPushMatrix();


//------------------------
// Coordinate system
// X axis
glLineWidth(2.0);
glColor3f( 0.0, 0.0, 0.0);
float V1 [2] = {0.0f, 0.0f};
float V2 [2] = {450.0f, 0.0f};
Draw_line(V1,V2);

glBegin(GL_TRIANGLES);
    glVertex2f(450.0, 0);
    glVertex2f(449,-1);
    glVertex2f(449,1);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(0,400);
    glVertex2f(1,399);
    glVertex2f(-1,399);
glEnd();
//------------------------


//------------------------
//// Y axis
glLineWidth(2.0);
glColor3f( 0.0, 0.0, 0.0);
V1[0] = 0.0f, V1[1]= 0.0f;
V2[0] = 0.0f, V2[1]= 400.0f;
Draw_line(V1,V2);
//-----------------
//------------------------

//-----------------
// Point P
glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glColor3f( 0.0, 0.0, 1.0);
glBegin(GL_POINTS);
    glVertex2f(3,1);
glEnd();
//-----------------

//------------------------
//-----------------
//Vector KP1
glLineWidth(2.0);
glColor3f( 1.0, 0.0, 0.0);
V1[0] = 300.0f, V1[1]= 250.0f;
V2[0] = 100.0f, V2[1]= 350.0f;
Draw_line(V1,V2);
//-----------------
//-----------------
//Line 0.75*vKP1
glLineWidth(2.0);
glColor3f( 0.0, 0.0, 1.0);
V1[0] = 300.0f, V1[1]= 250.0f;
V2[0] = 300.0f-150.0f, V2[1]= 250.0f+75.0f;
Draw_line(V1,V2);
//-----------------
//------------------------


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
