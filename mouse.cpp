#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
#define w 700
#define h 700
float a[30][3];
int k,c;

void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.22f,1.0f,0.08f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0.0,640.0,0.0,480.0);
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
int sign(float i)
{
	if(i<0)
		return -1;
	else if(i==0)
		return 0;
	else if(i>0)
		return 1;			
}
void Plot(float x,float y)
{
	glBegin(GL_POINTS);
        glVertex2i(x,y);

        glEnd();
        glFlush();
}

void DDA(float x1,float y1,float x2,float y2)
{
	float length,dx,dy,x,y;
	
	if(abs(x2-x1)>=abs(y2-y1))
	
		length=abs(x2-x1);
	else
	length=abs(y2-y1);
	
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	
	int i=1;
	while(i<=length)
	{
		
		Plot(round(x),round(y));	
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
}


void myMouse(GLint button,GLint state,GLint x,GLint y)
{
	int i=0;
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			a[k][0]=(float)(x-360);
			a[k][1]=(float)(240-y);
			glBegin(GL_POINTS);
			glVertex2f(a[k][0],a[k][1]);
			cout<<"\n POINTS :"<<a[k][0]<<","<<a[k][1];
			glEnd();
			k++;
			glFlush();
		}
		if(button==GLUT_RIGHT_BUTTON)
		{
			
			for(i=0;i<k-1;i++)
			{
				DDA(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
			}
			DDA(a[k-1][0],a[k-1][1],a[0][0],a[0][1]);
				glEnd();
					
				k=0;
				glFlush();
		}
	}
}

void myDisplay()
{
   int i;
   //glClear(GL_COLOR_BUFFER_BIT);
   
   glColor3f(1.0,1.0,1.0);
   glPointSize(2.0);
   
   for (i=-w; i<=w; i+=2) 
   {
   	Plot(i,0);
   	Plot(0,i);
   }
   
   for (i=-h; i<=h; i+=2) 
   {
   	Plot(0,i);
   	Plot(i,0);
   }
   //accept();
}
	
void menu(int num)
{
	if(num==1)
	{
		glColor3f(0.0,0.0,0.0);
		
	}
	if(num==2)
	{
		glColor3f(1.0,0.0,0.0);
	}
	if(num==3)
	{
		glColor3f(0.0,1.0,0.0);
		
	}
	if(num==4)
	{
		glColor3f(0.0,0.0,1.0);
		
	}
	if(num==5)
	{
		cout<<"Exit";
		exit(0);
	}
	
}



int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Assignment");
	glutCreateMenu(menu);
	glutAddMenuEntry("Black",1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Green",3);
	glutAddMenuEntry("Blue",4);
	glutAddMenuEntry("Exit",5);
	glutMouseFunc(myMouse);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}   					
