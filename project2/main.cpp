#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <string>
#define PI 3.1416r
using namespace std;

static int xp = 50;
static int yp = 465;
int xf = 10;
int yf = 10;

static void key(int key, int x, int y)
{
    switch(key)
    {
        case 'q':
        exit(0);
        break ;
        case GLUT_KEY_RIGHT:
        if(xp<1000)
        xp=xp+xf;
        if(xp==700)
            exit(0);
        break ;
        case GLUT_KEY_LEFT :
        if(xp<720)
        xp=xp-xf;
        //exit(0);
        break ;
        case GLUT_KEY_UP :
        if(yp<500)
        yp=yp+yf;
        break ;
        case GLUT_KEY_DOWN:
        if(yp>120)
        yp=yp-yf;
        break ;
    }
    glutPostRedisplay();
}

int windowWidth = 1000, windowHeight = 1000;
void rectangle(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float r,float g,float b)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(r,g,b);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
}
void line(float x1,float y1,float x2,float y2,float r,float g,float b)
{
    glBegin(GL_LINES);
    glColor3f(r,g,b);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void circle(float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0 * 3.1415926 * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x, y);//output vertex
    }
    glEnd();

}
static void idle(void)
{
    glutPostRedisplay();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 700);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glViewport(0, 0,windowWidth,windowHeight);

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(100.0,200.0,600.0,200.0,1.0,1.0,1.0); //crease
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(100.0,200.0,100.0,325.0,1.0,1.0,1.0); //stump-1
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(600.0,200.0,600.0,325.0,1.0,1.0,1.0); //stump-2
    glPopMatrix();


    glPushMatrix();
    rectangle(75.0,225.0,75.0,375.0,125.0,375.0,125.0,225.0,1.0,0.0,1.0); //bowler-body
    glPopMatrix();

    glPushMatrix();
    rectangle(75.0-10,201.0,75.0,224.0,100.0,224.0,100.0-10,201.0,1.0,0.0,1.0); //bowler-left-leg
    glPopMatrix();

    glPushMatrix();
    rectangle(99.0+10,201.0,99.0,224.0,125.0,224.0,125.0+10,201.0,1.0,0.0,1.0); //bowler-right-leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100,400,0);
    circle(25,200);  //bowler-head
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(100.0,370.0,50.0,450.0,1.0,1.0,1.0); //bowler-hand
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(100.0,370.0-25,50.0,450.0,1.0,1.0,1.0); //bowler-hand
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(125.0,370.0,125.0+25,370.0-80,1.0,1.0,1.0); //bowler-hand
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(125.0,370.0-25,125.0+25,370.0-80,1.0,1.0,1.0); //bowler-hand
    glPopMatrix();



    glPushMatrix();
    rectangle(500.0,250.0,500.0,400.0,550.0,400.0,550.0,250.0,1.0,0.0,1.0); //batsman-body
    glPopMatrix();

    glPushMatrix();
    rectangle(500.0,201.0,500.0,249.0,524.0,249.0,524.0,201.0,1.0,0.0,1.0); //batsman-left-leg
    glPopMatrix();

    glPushMatrix();
    rectangle(526.0,201.0,526.0,249.0,550.0,249.0,550.0,201.0,1.0,0.0,1.0); //batsman-right-leg
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(525.0,375.0,475.0,325.0,1.0,1.0,1.0); //batsman-hand
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(525.0,350.0,475.0,325.0,1.0,1.0,1.0); //batsman-hand
    glPopMatrix();

    glPushMatrix();
    glTranslatef(525,425,0);
    circle(25,200);  //batsman-head
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(470.0,335.0,485.0,330.0,1.0,1.0,1.0); //BAT-handle
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(465.0,310.0,480.0,305.0,1.0,1.0,1.0); //BAT-handle
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(465.0,310.0,470.0,335.0,1.0,1.0,1.0); //BAT-handle
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(485.0,330.0,480.0,305.0,1.0,1.0,1.0); //BAT-handle
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(465.0-5,310.0+2,465.0,310.0,1.0,1.0,1.0); //BAT-body
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(480.0,305.0,480.0+5,305.0-2,1.0,1.0,1.0); //BAT-body
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(460.0-15,312.0-80,485.0-15,303.0-80,1.0,1.0,1.0); //BAT-body
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(460.0-15,312.0-80,460.0,312.0,1.0,1.0,1.0); //BAT-body
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);//position of now the cursor
    line(485.0-15,303.0-80,485.0,303.0,1.0,1.0,1.0); //BAT-body
    glPopMatrix();


    glPushMatrix();
    glTranslatef(xp,yp,0);
    circle(15,200);
    glPopMatrix();



    glFlush();
    glutSwapBuffers();
}



int main (int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowWidth,windowHeight);
    glutCreateWindow("Cricket");

    glutDisplayFunc(display);
   glutSpecialFunc(key);
    glutIdleFunc(idle);

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
    return 0;
}
