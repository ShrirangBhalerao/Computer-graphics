#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

class line
{
private:
	float x1,y1,x2,y2;          //co-ordinates of line....
public:

	void myInt()
	{
		glClearColor(1.0,1.0,1.0,0.0);
		glColor3f(0.0,0.0,0.0);
		glPointSize(4.0);
		gluOrtho2D(-320.0,320.0,-320.0,320.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
	}

	void plot(int x,int y)                  
	{
		glBegin(GL_POINTS);
			glVertex2i(x,y);            //plot function...             
		glEnd();
			glFlush();
	}


	void getdata()
	{
		cout<<"Enter the co-ordinates of first point -  ";
		cin>>x1>>y1;
		cout<<"Enter the co-ordinates of end point -  ";
		cin>>x2>>y2;
	}


	int sign(int a)
	{
		if(a>0)                    //sign function returns sign of passed value....
			return 1;
		if(a==0)
			return 0;
		return -1;
	}

	void axis()
	{

		int i;
		for(i=-640;i<=640;i++)                //function to plot axis.....
		{
			plot(i,0);
			plot(0,i);
		}
	}


	void bresenham(int a)
	{
		if(a!=1)
		getdata();
	
		int s1,s2,dx,dy,ex,x,y,temp,g;
		dx=abs(x2-x1);
		dy=abs(y2-y1);
		x=x1;
		y=y1;
		s1=sign(x2-x1);
		s2=sign(y2-y1);

		if(dy>dx)           //bresenhams line drawing algorithm.....
		{
			temp=dx;
			dx=dy;
			dy=temp;
			ex=1;
		}
		else
			ex=0;

		g=2*dy-dx;
		int i=1;
		while(i<dx)
		{
			if(i%a==0)
			plot(x,y);
			while(g>=0)
			{
				if(ex==1)
				{
					x=x+s1;
				}
				else
					y=y+s2;
				g=g-2*dx;
			}
			if(ex==1)
				y=y+s2;
			else
				x=x+s1;
			g=g+2*dy;
				i++;
		}
	}

	void pattern()
	{
		x1=-200, y1=200;
		x2=200 ,y2=200;
			bresenham(1);
		x1=-200, y1=200;
		x2=-200 ,y2=-200;                      //pattern....
			bresenham(1);
		x1=-200, y1=-200;
		x2=200 ,y2=-200;
			bresenham(1);
		x1=200, y1=-200;
		x2=200 ,y2=200;
			bresenham(1);
		x1=-200, y1=0;
		x2=0 ,y2=200;
			bresenham(1);
		x1=0, y1=200;
		x2=200 ,y2=0;
			bresenham(1);
		x1=200, y1=0;
		x2=0 ,y2=-200;
			bresenham(1);
		x1=0, y1=-200;
		x2=-200 ,y2=0;
			bresenham(1);
		x1=-100, y1=100;
		x2=-100 ,y2=-100;
			bresenham(1);
		x1=-100 , y1=-100 ;
		x2=100 ,y2=-100;
			bresenham(1);
		x1=100, y1=-100;
		x2=100 ,y2=100;
			bresenham(1);
		x1=100, y1=100;
		x2=-100 ,y2=100;
			bresenham(1);
	}
	
	line()
	{
		glClear(GL_COLOR_BUFFER_BIT);      //default constructor.....
	}

};


void menu(int a)
{
	line l;
	if(a==3)
		exit(0);
	if(a==100)
		l.pattern();                   //menu...
	else
	{	l.axis();
		l.bresenham(a);
	
	}
}


int main(int argc,char **argv)
{
	line m;
	glutInit(&argc,argv);
	glutInitWindowPosition(150,100);
	glutInitWindowSize(640.0,640.0);
	glutCreateWindow("BRESENHAMS LINE DRAWING ALGORITHM");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	
	glutCreateMenu(menu);
	glutAddMenuEntry("line",2);
	glutAddMenuEntry("pattern",100);
	glutAddMenuEntry("dotted-line",15);
	glutAddMenuEntry("dash-line",6);
	glutAddMenuEntry("exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);       //menu attached to right button of mouse... 
	m.myInt();
	glutMainLoop();
}


