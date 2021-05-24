#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

class transform
{
private:
double a[3][3],b[3][3],c[3][3];
float i,tx,ty,sx,sy,f,v1,v2;
float z;
public:

transform()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void plot(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void axis()
{
	int i;
	for(i=-250;i<=250;i+=2)
	{
		plot(i,0);
		plot(0,i);
	}
}

void multiply()
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
	
}

void triangle()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(c[0][0],c[1][0]);
	glVertex2i(c[0][1],c[1][1]);
	glVertex2i(c[0][2],c[1][2]);
	glEnd();
	glFlush();
	glColor3f(0.0,0.0,0.0);
}

void equi()
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(0,0);
	glVertex2i(i,0);
	glVertex2i(i/2,i);
	glEnd();
	glFlush();
	b[0][0]=0;
	b[0][1]=i;
	b[0][2]=i/2;
	b[1][0]=0;
	b[1][1]=0;
	b[1][2]=i;
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
}


void translation()
{

	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	equi();
	cout<<"ENTER THE VALUES OF tx AND ty  :  ";
	cin>>tx>>ty;
	a[0][0]=1;
	a[0][1]=0;
	a[0][2]=tx;
	a[1][0]=0;
	a[1][1]=1;
	a[1][2]=ty;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;

	multiply();
	triangle();

}

void equi_1()
{
	b[0][0]=v1;
	b[0][1]=v1+i;
	b[0][2]=(2*v1+i)/2;
	b[1][0]=v2;
	b[1][1]=v2;
	b[1][2]=v2+i;
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
}



void rotation()
{
	int w;
	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	equi();
	cout<<"ENTER THE VALUES OF angle  :  ";
	cin>>z;
	cout<<"ANTICLOCK-WISE OR CLOCK-WISE (1/0)";
	cin>>w;
	z=z*(2*3.14)/360;

	if(w==1)
	{
		a[0][0]=cos(z);
		a[0][1]=sin(z);
		a[0][2]=0;
		a[1][0]=-sin(z);
		a[1][1]=cos(z);
		a[1][2]=0;
		a[2][0]=0;
		a[2][1]=0;
		a[2][2]=1;
	}
	else
	{
		a[0][0]=cos(z);
		a[0][1]=-sin(z);
		a[0][2]=0;
		a[1][0]=sin(z);
		a[1][1]=cos(z);
		a[1][2]=0;
		a[2][0]=0;
		a[2][1]=0;
		a[2][2]=1;
	}
	multiply();
	triangle();

}



void scaling()
{

	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	equi();
	cout<<"ENTER THE VALUES OF sx AND sy  :  ";
	cin>>sx>>sy;

	a[0][0]=sx;
	a[0][1]=0;
	a[0][2]=0;
	a[1][0]=0;
	a[1][1]=sy;
	a[1][2]=0;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;

	multiply();
	triangle();

}

void reflection(int x)
{

	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	equi();

	if(x==11)
	{
		a[0][0]=-1;
		a[1][1]=-1;
	}	

	if(x==12)
	{
		a[0][0]=1;
		a[1][1]=-1;
	}

	if(x==13)
	{
		a[0][0]=-1;
		a[1][1]=1;
	}

	a[0][1]=0;
	a[0][2]=1;
	a[1][0]=0;
	a[1][2]=1;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	multiply();
	triangle();

}

void shear(int x)
{

	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	equi();
	cout<<"ENTER THE VALUE constant factor  :  ";
	cin>>f;

	if(x==21)
	{
		a[0][1]=f;
		a[1][0]=0;
	}

	if(x==22)
	{
		a[0][1]=0;
		a[1][0]=f;
	}

	a[0][0]=1;
	a[0][2]=0;
	a[1][1]=1;
	a[1][2]=0;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	multiply();
	triangle();

}

void plot1()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(b[0][0],b[1][0]);
	glVertex2f(b[0][1],b[1][1]);
	glVertex2f(b[0][2],b[1][2]);
	glEnd();
}

void c_rotation()
{
	int w;
	cout<<"ENTER THE VALUES OF angle  :  ";
	cin>>z;
	z=z*(2*3.14)/360;
	cout<<"ENTER THE LENGTH OF SIDE OF EQUILATERAL TRIANGLE  :  ";
	cin>>i;
	cout<<"ENTER THE STARTING VERTEX  : ";
	cin>>v1>>v2;
	equi_1();
	plot1();
		
		a[0][0]=cos(z);
		a[0][1]=-sin(z);
		a[0][2]=(-tx*cos(z)+ty*sin(z)+tx);
		a[1][0]=sin(z);
		a[1][1]=cos(z);
		a[1][2]=(-tx*sin(z)-ty*cos(z)+ty);
		a[2][0]=0;
		a[2][1]=0;
		a[2][2]=1;
		b[0][0]=v1;
	b[0][1]=v1+i;
	b[0][2]=(2*v1+i)/2;
	b[1][0]=v2;
	b[1][1]=v2;
	b[1][2]=v2+i;
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
		//equi_1();
		multiply();
		triangle();

}

void getdata()
{
	cout<<"ENTER THE COORDINATES OF STARTING POINT  ";
	cin>>v1>>v2;
	cout<<"ENTER SCALING FACTOR  ";
	cin>>sx>>sy;
	cout<<"enter the side of equilateral triangle  ";
	cin>>i;
}



void c_scaling()
{
	axis();
	getdata();
	equi_1();
	plot1();
	b[0][0]=v1;
	b[0][1]=v1+i;
	b[0][2]=(2*v1+i)/2;
	b[1][0]=v2;
	b[1][1]=v2;
	b[1][2]=v2+i;
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
	//equi_1();
	a[0][0]=1;
	a[0][1]=0;
	a[0][2]=-v1;
	a[1][0]=0;
	a[1][1]=1;
	a[1][2]=-v2;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	glColor3f(1,0,0);	
	multiply();
	tx=v1;
	ty=v2;
	v1=0,v2=0;
	b[0][0]=v1;
	b[0][1]=v1+i;
	b[0][2]=(2*v1+i)/2;
	b[1][0]=v2;
	b[1][1]=v2;
	b[1][2]=v2+i;
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
		//equi_1();
	a[0][0]=sx;
	a[0][1]=0;
	a[0][2]=0;
	a[1][0]=0;
	a[1][1]=sy;
	a[1][2]=0;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	glColor3f(0,1,0);
	multiply();
	b[0][0]=c[0][0];
	b[0][1]=c[0][1];
	b[0][2]=c[0][2];
	b[1][0]=c[1][0];
	b[1][1]=c[1][1];
	b[1][2]=c[1][2];
	b[2][0]=1;
	b[2][1]=1;
	b[2][2]=1;
	
	a[0][0]=1;
	a[0][1]=0;
	a[0][2]=tx;
	a[1][0]=0;
	a[1][1]=1;
	a[1][2]=ty;
	a[2][0]=0;
	a[2][1]=0;
	a[2][2]=1;
	glColor3f(0,0,1);
	multiply();
	triangle();
}	




};

void menu1(int x)
{
	transform t;
	t.axis();
	t.reflection(x);
}


void menu2(int x)
{
	transform t;
	t.axis();
	t.shear(x);
}




void myInt()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-250,250,-250,250);
}

void menu(int a)
{
	if(a==1)
	{
		transform t;
		t.axis();
		t.translation();
	}
	if(a==2)
		exit(0);

	if(a==3)
	{
		transform t;
		t.axis();
		t.rotation();
	}

	if(a==4)
	{
		transform t;
		t.axis();
		t.scaling();
	}
	if(a==5)
	{
		transform t;
		t.axis();
		t.c_rotation();
	}
	
	if(a==6)
	{
		transform t;
		
		t.c_scaling();
	}
}



int main(int argc,char **argv)
{
	int i,j;
	glutInit(&argc,argv);
	glutInitWindowSize(500.0,500.0);
	glutInitWindowPosition(100,150);
	glutCreateWindow("BASIC TRANSFORMATIONS");
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	i=glutCreateMenu(menu1);
	glutAddMenuEntry("ABOUT ORIGIN",11);
	glutAddMenuEntry("ABOUT X-AXIS",12);
	glutAddMenuEntry("ABOUT Y-AXIS",13);
	j=glutCreateMenu(menu2);
	glutAddMenuEntry(" X-SHEAR",21);
	glutAddMenuEntry(" Y-SHEAR",22);
	glutCreateMenu(menu);
	glutAddMenuEntry("translation",1);
	glutAddMenuEntry("rotation",3);
	glutAddMenuEntry("scaling",4);
	glutAddMenuEntry("composite rotation",5);
	glutAddMenuEntry("composite scaling",6);
	glutAddSubMenu("reflection ",i);
	glutAddSubMenu("shear",j);
	glutAddMenuEntry("exit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//glutDisplayFunc(display);
	myInt();
	glutMainLoop();
}









