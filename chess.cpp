#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;


	float x1,x2,y2,x3,y3; 
	//float y1;   
	float interior_color[3]={1,1,1};
	float  fill_color[3]={0,0,0} ; 
	float read_pixel[3] ;
      //co-ordinates of line....

	void myInt()
	{
		glClearColor(1.0,1.0,1.0,0.0);
		glColor3f(0.0,1.0,0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(4.0);
		gluOrtho2D(-320.0,320,-240.0,240);
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
	
	void set_pixel(int x,int y)
	{
		glColor3fv(fill_color);
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
		glFlush();
	}
	
	void getpixel(int x,int y,float *color)
	{
		glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);

	}
	
	void Flood_Fill(int x,int y)
	{
		getpixel(x,y,read_pixel);
		if(read_pixel[0]==interior_color[0] && read_pixel[1]==interior_color[1] && read_pixel[2]==interior_color[2] )		
	{
	set_pixel(x,y);
	Flood_Fill(x+1,y);
	Flood_Fill(x,y+1);
	Flood_Fill(x-1,y);
	Flood_Fill(x,y-1);
	glFlush();
	glEnd();
	}
	}

	void mouse(int btn,int state,int x,int y)
	{
		if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			x3=x;
			y3=480-y;
			Flood_Fill(x3,y3);
		}
	}
		
	
	/*void getdata()
	{
		cout<<"Enter the co-ordinates of first point -  ";
		cin>>x1>>y1;
		cout<<"Enter the co-ordinates of end point -  ";
		cin>>x2>>y2;
	}*/


	int sign(int a)
	{
		if(a>0)                    //sign function returns sign of passed value....
			return 1;
		if(a==0)
			return 0;
		return -1;
	}

	/*void axis()
	{

		int i;
		for(i=-640;i<=640;i++)                //function to plot axis.....
		{
			plot(i,0);
			plot(0,i);
		}
	}*/


	void bresenham(float x1,float y1,float x2,float y2 )
	{
		
		
	
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
	
	void line1(int x1,int y1,int x2,int y2 )
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glEnd();
		glFlush();
	}	

	void triangle(float a[2][2])
	{
		line1(a[0][0],a[1][0],a[0][1],a[1][1]);
	}	
	
	void multiply(float a[2][2],float b[2][2])
	{
		int i,j;
		float c[2][2];
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				c[i][j]=0;
				for(int k=0;k<2;k++)
				{
					c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
				}
			}
		}
		triangle(c);			
	}
	
	void rotate(float x1,float y1,float x2,float y2)
	{
		float z=45;
		z=(z*2*3.14)/360;
		float a[2][2],b[2][2],c[2][2];
		a[0][0]=cos(z);
		a[0][1]=sin(z);
		a[1][0]=-sin(z);
		a[1][1]=cos(z);
		b[0][0]=x1;
		b[0][1]=x2;
		b[1][0]=y1;
		b[1][1]=y2;
		multiply(a,b);
	}
		
	void chess()
	{
			rotate(-100,100,100,100);
			rotate(-100,100,-100,-100);
			rotate(-100,-100,100,-100);
			rotate(100,-100,100,100);
			rotate(-50,-100,-50,100);
			rotate(0,-100,0,100);
			rotate(50,-100,50,100);
			rotate(100,-100,100,100);
			rotate(-100,50,100,50);
			rotate(-100,0,100,0);
			rotate(-100,-50,100,-50);
			rotate(-100,-100,100,-100);		
	}
		

int main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	glutInitWindowPosition(150,100);
	glutInitWindowSize(640.0,480.0);
	glutCreateWindow("BRESENHAMS LINE DRAWING ALGORITHM");
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	
	glutDisplayFunc(chess);
	glutMouseFunc(mouse);      //menu attached to right button of mouse... 
	myInt();
	glutMainLoop();
}

