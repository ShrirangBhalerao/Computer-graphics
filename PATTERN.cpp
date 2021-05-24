#include<iostream>
#include<GL/glut.h>
using namespace std;
class pattern
{
public:
int x1,y1,x2,x3,x4,y2,y3,y4,a1,b1,a2,a3,a4,b2,b3,b4,c1,d1,c2,c3,c4,d2,d3,d4;
int h;

void plot(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
glBegin(GL_LINE_LOOP);
glVertex2i(x1,y1);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);
glEnd();
glFlush();
}

void getdata()
{
cout<<"ENTER THE LENGTH :  ";
cin>>h;
cout<<"Enter the staring coordinates :  ";
cin>>x1>>y1;
}

void dis()
{
x2=x1+h;
y2=y1;
x4=x1,y4=y1+h;
x3=x2,y3=y2+h;
plot(x1,y1,x2,y2,x3,y3,x4,y4);

a1=(x1+x4)/2;
a2=(x1+x2)/2;
b1=(y1+y4)/2;
b2=(y1+y2)/2;
a3=(x2+x3)/2;
a4=(x3+x4)/2;
b3=(y2+y3)/2;
b4=(y3+y4)/2;

plot(a1,b1,a2,b2,a3,b3,a4,b4);

c1=(a1+a4)/2;
c2=(a1+a2)/2;
d1=(b1+b4)/2;
d2=(b1+b2)/2;
c3=(a2+a3)/2;
c4=(a3+a4)/2;
d3=(b2+b3)/2;
d4=(b3+b4)/2;

plot(c1,d1,c2,d2,c3,d3,c4,d4);









}

void plot1(int x,int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}



void axis()
{
int i;
for(i=-250;i<=250;i++)
{
plot1(0,i);
plot1(i,0);
}
}






pattern()
{
glClear(GL_COLOR_BUFFER_BIT);
}

};

void display()
{
pattern p;
p.axis();
p.getdata();
p.dis();
}



void myInit(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250.0,250.0,-250.0,250.0);
}



int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500,500);
     glutInitWindowPosition(100,150);
     glutCreateWindow("PATTERN");
     glutDisplayFunc(display);
     myInit();
     glutMainLoop();
  return 0;
}


