#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

#include <math.h>


//===================================

double pi=3.14159265359;

//---------------------------
// Camera position:
void Camera_position()
{
GLfloat a=pi/4;
GLfloat R=15;

gluLookAt(R*cos(a), R*sin(a), -4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}
//---------------------------


// Formulas:

//-------------------------------
// Surface parametrization F

double r=3;
// ranges
double x1_min=0, x1_max=2*pi, dx1=.1;
double x2_min=0, x2_max=pi, dx2=.1;

double F1(double x1, double x2) {
  return r*cos(x1)*sin(x2);
}

double F2(double x1, double x2) {
  return r*sin(x1)*sin(x2);
}

double F3(double x1, double x2) {
  return r*cos(x2);
}

//-------------------------------

//-------------------------------
// Curve parametrization
// range
double t_min=-pi/4, t_max=3*pi/4, dt=.1;

double c1(double t) {
  return pi/4+t;
}

double c2(double t) {
  return 3*pi/4-t;
}
//-------------------------------


//-------------------------------
// Vectors w

double d = 1;
// d scales vector w
// used in function Draw_wc


double w1(double x1, double x2) {
  return cos(x1)*sin(x2);
}

double w2(double x1, double x2) {
  return sin(x1)*sin(x2);
}

double w3(double x1, double x2) {
  return cos(x2);
}

//-------------------------------

//-------------------------------------
// Drawing:


//-------------------------------
void Draw_segment(float V1 [3],float V2 [3])
{

glBegin(GL_LINES);
    glVertex3f(V1[0], V1[1], V1[2]);
    glVertex3f(V2[0], V2[1], V2[2]);
glEnd();
}
//-------------------------------


//--------------------------------------
// Coordinate system
void Draw_coord_system()
{
//------------------------
// X axis
glLineWidth(5.0);
glColor3f( 1.0, 0.0, 0.0);
float V1 [3] = {-5.0, 0.0f,0.0f};
float V2 [3] = {5.0, 0.0f,0.0f};
Draw_segment(V1,V2);

//-----------------
// Tip of axis
glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glColor4f( 1.0, 0.0, 0.0, 1);
glBegin(GL_POINTS);
    glVertex3f(5,0,0);
glEnd();
//-----------------
//------------------------


//------------------------
// Y axis
glColor3f( 0.0, 1.0, 0.0);
V1[0] = 0.0;
V1[1] = -5.0;
V2[0] = 0.0;
V2[1] = 5.0;
Draw_segment(V1,V2);

//-----------------
// Tip of axis
glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glColor4f( 0.0, 1.0, 0.0, 1);
glBegin(GL_POINTS);
    glVertex3f(0,5,0);
glEnd();
//-----------------

//------------------------

//------------------------
// Z axis
glColor3f( 0.0, 0.0, 1.0);
V1[1] = 0.0;
V1[2] = -5.0;
V2[1] = 0.0;
V2[2] = 5.0;
Draw_segment(V1,V2);

//-----------------
// Tip of axis
glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glColor4f( 0.0, 0.0, 1.0, .4);
glBegin(GL_POINTS);
    glVertex3f(0,0,5);
glEnd();
//-----------------
// end: Z axis
//------------------------

}
//End: coord system
//--------------------------------------


//-------------------------------
void Draw_surface()
{
//--------------------------

double y1=0, y2=0, y3=0;
double x1=0;
double x2=0;

glColor4f( 0.3, 0.3, 0.3, 0.1);
//--------------------------

//--------------------------
for (int j = 0; x2_min+j*dx2 <= x2_max; j++) {
// build horizontally
glBegin(GL_TRIANGLE_STRIP);
for (int i = 0; x1_min+i*dx1 <= x1_max; i++) {
//--------------
// First point
  x1=x1_min+i*dx1;
  x2=x2_min+j*dx2;

  y1=F1(x1,x2);
  y2=F2(x1,x2);
  y3=F3(x1,x2);

  glVertex3f(y1,y2,y3);
//--------------

//--------------
// Second point
  x2=x2+dx2;

  y1=F1(x1,x2);
  y2=F2(x1,x2);
  y3=F3(x1,x2);

  glVertex3f(y1,y2,y3);
//--------------

}
glEnd();
}
//--------------------------
}
//-------------------------------

//-------------------------------
void Draw_point_p(double px, double py)
{
glPointSize(15);
glEnable(GL_POINT_SMOOTH);
glColor4f( 0.0, 0.0, 1.0, 1);
glBegin(GL_POINTS);
    glVertex3f(F1(px,py),F2(px,py),F3(px,py));
glEnd();
}
//-------------------------------

//-------------------------------
void Draw_Fc()
{
double t= t_min, x1, x2, y1,y2,y3;
float V1 [3], V2 [3];

glLineWidth(5.0);
glColor3f( 1.0, 0.0, 0.0);
//------------------------------
for (int i = 0; t_min+i*dt <= t_max; i++) {

//--------------
// First point
  t=t_min+i*dt;

  x1=c1(t);
  x2=c2(t);

  y1=F1(x1,x2);
  y2=F2(x1,x2);
  y3=F3(x1,x2);

  V1[0]=y1;
  V1[1]=y2;
  V1[2]=y3;
//--------------

//--------------
// Second point
  t=t+dt;

 x1=c1(t);
  x2=c2(t);

  y1=F1(x1,x2);
  y2=F2(x1,x2);
  y3=F3(x1,x2);

  V2[0]=y1;
  V2[1]=y2;
  V2[2]=y3;
//--------------

Draw_segment(V1,V2);
}
}
//-------------------------------



//-------------------------------
void Draw_wc()
{
double nw=15; // how many vectors
double t= t_min, x1, x2, y1,y2,y3;
float V1 [3], V2 [3];

glLineWidth(5.0);
glColor3f( 1.0, 1.0, 0.0);
//------------------------------
double dtw=(t_max-t_min)/nw;
for (int i = 0; i<= nw; i++) {

//--------------
// First point
  t=t_min+i*dtw;

  x1=c1(t);
  x2=c2(t);


  y1=F1(x1,x2);
  y2=F2(x1,x2);
  y3=F3(x1,x2);


  V1[0]=y1;
  V1[1]=y2;
  V1[2]=y3;
//--------------

//--------------
// Second point

  V2[0]=V1[0]+w1(x1,x2)*d;
  V2[1]=V1[1]+w2(x1,x2)*d;
  V2[2]=V1[2]+w3(x1,x2)*d;

//--------------

Draw_segment(V1,V2);
}
}
//-------------------------------

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,320.0/240.0,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
}






void display()
{
//------
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glLoadIdentity();
glPushMatrix();


Camera_position();

Draw_coord_system();
Draw_surface();
Draw_point_p(pi/4,3*pi/4);
Draw_Fc();
Draw_wc();


glPopMatrix();

}



int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(320,240,32,SDL_SWSURFACE|SDL_OPENGL);

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
