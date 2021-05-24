#include<iostream>
#include<GL/glut.h>
using namespace std;



int x=0,y=0,x1,y1;
float dp;

void myInt()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(4.0);
	gluOrtho2D(-320.0,320.0,-320.0,320.0);
}

void getdata()
{
	cout<<"ENTER THE CO-ORDINATED OF CIRCLE ";
	cout<<"x =  ";
	cin>>x;
	cout<<"y = ";
	cin>>y;
	//cout<<"ENTER THE RADIUS OF CIRCLE  ";
	//cin>>radius;
}
void plot(int a,int b)
{
	glBegin(GL_POINTS);
	glVertex2i(a,b);
	glEnd();
	glFlush();
}
void axis()
{
	int a;
	for(a=-640;a<=640;a++)
	{
		plot(a,0);
		plot(0,a);
	}
	//glEnd();
	//glFlush();

}



void plotCircle(int x1,int y1)
{
	plot(x+x1,y+y1);
	plot(x+x1,y-y1);
	plot(x-x1,y+y1);
	plot(x-x1,y-y1);
	plot(x+y1,y+x1);
	plot(x+y1,y-x1);
	plot(x-y1,y+x1);
	plot(x-y1,y-x1);
}


void draw(int radius)
{

	x1=0;
	y1=radius;
	
	dp=3-(2*radius);
	
	axis();
	//glFlush();
	while(x1<=y1)
	{
		if(dp<=0)
		{
			dp=dp+(4*x1)+6;
		}
		else
		{	
			dp=dp+(4*(x1-y1))+10;
			y1--;
		}
		x1++;
		
		plotCircle(x1,y1);
	}
	
	
}

void coin()
{
int a=5;
int radius=50;
glClear(GL_COLOR_BUFFER_BIT);
while(a!=0)
{
radius+=30;
draw(radius);
a--;
}
}



int main(int argc,char ** argv)
{
	//Circle c;
	glutInit(&argc,argv);
	glutInitWindowSize(640.0,640.0);
	glutInitWindowPosition(150,100);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("BRESSENHAM'S CIRCLE DRAWING ALGORITHM");
	glutDisplayFunc(coin);
	//c.draw();
	myInt();
	glutMainLoop();

}
