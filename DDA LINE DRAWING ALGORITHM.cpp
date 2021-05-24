#include<iostream>
#include<GL/glut.h>
using namespace std;

int a[100][3],k=0,c;

class line                              //class line....
{
public:
	float x1,y1,x2,y2;
	
	
public:
	
	void myInt()
	{
		glClearColor(1.0,1.0,1.0,0.0);
		glColor3f(0.0,0.0,0.0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glPointSize(4.0);
		gluOrtho2D(-350,350,-350,350);
	}

	void plot(int x,int y)
	{
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();                    //plot function.....
      		glFlush();
	}

	void axis()
	{	
		int i;
		for(i=-350;i<=350;i++)                //axis ploting.....
		{
			plot(i,0);
			plot(0,i);
		}
	}

	int  sign(int a)
	{
		if(a>0)
			return 1;              //sign function.....
		else
			if(a==0)
				return 0;
			else
				return -1;
	}

	void getdata()
	{
		while(1)
		{
			cout<<"Enter the co-ordinates of first point :  ";
			cin>>x1>>y1;
			cout<<endl;
			cout<<"Enter the co-ordinates of last point :  ";
			cin>>x2>>y2;
			cout<<endl; 
			if(x1!=x2 && y1!=y2)
				break;
			else
				cout<<"invalid coordinates , enter again ";
		}                 //getdata function.....
	}

	void dda(int a)
	{
		if(a!=1)
		getdata();
	
		int x,y;
		int length,dx,dy;
		if(abs(x2-x1)>=abs(y2-y1))
			length=abs(x2-x1);
		else
			length=abs(y2-y1);

		dx=(x2-x1)/length;
		dy=(y2-y1)/length;               //dda line drawing algorithm....

		x=x1+0.5*sign(dx);
		y=y1+0.5*sign(dy);

		
		int r=0;
		while(r<=length)
		{
			if(r%a==0)
			plot(x,y);
			x=x+dx;
			y=y+dy;
			r++;
		}
	}

	line()
	{
		glClear(GL_COLOR_BUFFER_BIT);    //default constructor...
	}

	void boat()
	{
		x1=200,y1=200;
		x2=-200,y2=200;
			dda(1);
		x1=100,y1=100;
		x2=-100,y2=100;          //boat.....
			dda(1);
		x1=200,y1=200;
		x2=100,y2=100;
			dda(1);
		x1=-200,y1=200;
		x2=-100,y2=100;
			dda(1);
		x1=50,y1=200;
		x2=150,y2=300;
			dda(1);
		x1=150,y1=200;
		x2=150,y2=300;
			dda(1);
	}
};

void myMouse(GLint button,GLint state,GLint x,GLint y)
{
	int i=0;
	line l;
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			a[k][0]=(float)(x-350);
			a[k][1]=(float)(350-y);
			glBegin(GL_POINTS);
			glVertex2f(a[k][0],a[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		
		if(button==GLUT_RIGHT_BUTTON)
		{
			
			for(i=0;i<k-1;i++)
			{
				l.x1=a[i][0],l.y1=a[i][1],l.x2=a[i+1][0],l.y2=a[i+1][1];
				l.dda(1);
			}
			l.x1=a[k-1][0],l.y1=a[k-1][1],l.x2=a[0][0],l.y2=a[0][1];
			l.dda(1);
				glEnd();
					
				k=0;
				glFlush();
		}
	}
}


void menu(int a)
{
	line l;
	if(a==9)
		exit(0);            //menu function.....
	if(a==1)
		l.boat();
		
	else
	{	
		l.axis();
		l.dda(a);
	}	
}


void menu1(int a)
{
	if(a==11)
	{
		glColor3f(1.0,0.0,0.0);
		glutMouseFunc(myMouse);
	}
	if(a==12)
	{
		glColor3f(0.0,0.0,1.0);
		glutMouseFunc(myMouse);
	}
	if(a==13)
	{
		glColor3f(0.0,1.0,0.0);
		glutMouseFunc(myMouse);
	}
}

int main(int argc,char ** argv)
{
	line m;
	int a,b;
	glutInit(&argc,argv);
	glutInitWindowSize(700.0,700.0);
	glutInitWindowPosition(150,100);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("DDA LINE DRAWING ALGORITHM");
	a=glutCreateMenu(menu1);
		glutAddMenuEntry("red",11);
		glutAddMenuEntry("blue",12);
		glutAddMenuEntry("green",13);	
	b=glutCreateMenu(menu);
		glutAddMenuEntry("line",2);         //menu creation....
		glutAddMenuEntry("dotted-line",15);
		glutAddMenuEntry("dash-line",4);
		glutAddMenuEntry("boat",1);
		glutAddSubMenu(" polygon",a);        //submenu....
		glutAddMenuEntry("exit",9);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	m.myInt();
	glutMainLoop();

}
