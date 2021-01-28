#include<bits/stdc++.h>
#include <gl/glut.h>
#include <stdio.h>


int r,x,y;

void myInit()
{


    glClearColor(1.0, 1.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 1.0 ,0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-350, 700, -350, 700);
}


void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_circle(int r,int ax,int by){
    int x,y;
    int d=3-2*r;
    x=0;
    y=r;
    int a[100000],b[100000],ina=0;

    draw_pixel(x+ax,y+by);
    draw_pixel(y+ax,x+by);

    while(1){
        if(d<0){
            d=d+4*x+6;
            x=x+1;
        }
        else{
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
        if(x>y) break;
            a[ina]=x;
            b[ina]=y;
            ina++;
        if(x!=y){
            a[ina]=y;
            b[ina]=x;
            ina++;
        }

    }
    for(int i=0;i<ina;i++){
        draw_pixel(a[i]+ax,b[i]+by);
        draw_pixel(-a[i]+ax,b[i]+by);
        draw_pixel(a[i]+ax,-b[i]+by);
        draw_pixel(-a[i]+ax,-b[i]+by);
    }
}

void myDisplay() {
	draw_circle(r,x,y);
	glFlush();
}

int main(int argc, char **argv) {

	printf( "Radious of circle: \n");
	scanf("%d", &r);
	printf("Enter the center of the circle : \n");
	scanf("%d%d",&x,&y);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Bresenham's Circle Drawing");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
