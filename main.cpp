#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SCENE 10
int input[10];
//int k=1;
static GLint axis=0;
int btn,state;
int i=0;
int n=0;
int x=100;
int y=100;
int l1=0,l2=0,l3=0,l4=0;
enum { FRONTPAGE, POLAR_CODING, EXIT };
void *font = GLUT_BITMAP_HELVETICA_12;
//text styles
void *fonts[] = { GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_10, GLUT_BITMAP_TIMES_ROMAN_24,GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_HELVETICA_18, };
// TO DISPLAY THE TEXT INFORMATION
void output(int x, int y, char string[], int j)
{
	int len, i;
 	glRasterPos2f(x, y);
 	len = (int)strlen(string);
 	for (i = 0; i < len; i++)
 		glutBitmapCharacter(fonts[j], string[i]);
}
void front_page()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	output(140, 400, " BMS INSTITUTE OF TECHNOLOGY AND MANGAGEMENT", 2);
 //output(320, 500, "", 2);
	output(200,350, " MINI PROJECT ON", 2);
	output(195, 300, " POLAR LINE CODING", 2);
	output(60, 250, "Guide:", 5);
	output(75, 220, "Shankar Sir",2);
 //output(175, 150, "Name 2", 2);
	output(370, 250, "By:", 5);
	output(385, 220, "Kushal B Biradar",2);
	output(385, 190, "M Manju", 2);
	output(208, 100, " Press S to start", 2);
	glFlush();
 	glCallList(SCENE);
 	glPopMatrix();
 	glutSwapBuffers();
}
void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,1.0,1.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glFlush();
    glutSwapBuffers();
}
/*void draw_pixel(int x,int y)
{
		glColor3f(0.0,1.0,1.0);
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	glutPostRedisplay();
}*/
void draw_line(int a,int b,int c,int d)
{
	if(axis==1)
	{
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINES);
		glVertex2i(a,b);
		glVertex2i(c,d);
		glEnd();
		glFlush();
	}
	//glutPostRedisplay();
}

/*void draw0()
{
	y=y+50;
			l1=x;l2=y;//draw_pixel(x,y);
			x=x+25;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			l1=l3;l2=l4;//draw_pixel(x,y);
			y=y-100;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			x=x+25;
			l1=l3;l2=l4;//draw_pixel(x,y);
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			y=y+50;
}
void draw1()
{
			y=y-50;
			l1=x;l2=y;//draw_pixel(x,y);
			x=x+25;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			l1=l3;l2=l4;//draw_pixel(x,y);
			y=y+100;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			x=x+25;
			l1=l3;l2=l4;//draw_pixel(x,y);
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			y=y-50;
}*/
void polarmanch(int input[],int n)
{

	int x=100,y=100;

	//for(;i==k-1;)
	for(i=0;i<n;i++)
	{
		if(input[i]==0)
		{
			y=y+50;
			l1=x;l2=y;//draw_pixel(x,y);
			x=x+25;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			l1=l3;l2=l4;//draw_pixel(x,y);
			y=y-100;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			x=x+25;
			l1=l3;l2=l4;//draw_pixel(x,y);
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			y=y+50;

			//break;
		}
		if(input[i]==1)
		{

			y=y-50;
			l1=x;l2=y;//draw_pixel(x,y);
			x=x+25;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			l1=l3;l2=l4;//draw_pixel(x,y);
			y=y+100;
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			x=x+25;
			l1=l3;l2=l4;//draw_pixel(x,y);
			l3=x;l4=y;//draw_pixel(x,y);
			draw_line(l1,l2,l3,l4);
			y=y-50;
			//break;
		}
		if(i<(n-1))
		{
			if(input[i]==input[i+1])
			{
				if(input[i]==0)
				{
					l1=l3;l2=l4;
					l3=x;l4=150;
					draw_line(l1,l2,l3,l4);
					//break;
				}
				else
				{
					l1=l3;l2=l4;
					l3=x;l4=50;
					draw_line(l1,l2,l3,l4);
					//break;
				}
			}
		}
		/*if(i==(n-1))
		{
			if(input[i]==0)
			{
				l1=l3;l2=l4;
				y=y+50;
				l3=x;l4=y;
				draw_line(l1,l2,l3,l4);
			}
			else
			{
				l1=l3;l2=l4;
				y=y-50;
				l3=x;l4=y;
				draw_line(l1,l2,l3,l4);
			}
		}*/

	}
	//k++;
}
void diffmanch(int input[],int n)
{

	int x=100,y=350,flag=0,change=0;
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			if((change==1&&input[i]==0)||(change==0&&input[i]==0))
			{
				l1=x;l2=y-50;
				l3=x;l4=y+50;
				draw_line(l1,l2,l3,l4);
			}
		}
		if(flag==0)
		{
			if(input[i]==0)
			{
				y=y-50;
				l1=x;l2=y;//draw_pixel(x,y);
				x=x+25;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				l1=l3;l2=l4;//draw_pixel(x,y);
				y=y+100;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				x=x+25;
				l1=l3;l2=l4;//draw_pixel(x,y);
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				y=y-50;
			}
			else if(input[i]==1)
			{
				y=y+50;
				l1=x;l2=y;//draw_pixel(x,y);
				x=x+25;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				l1=l3;l2=l4;//draw_pixel(x,y);
				y=y-100;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				x=x+25;
				l1=l3;l2=l4;//draw_pixel(x,y);
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				y=y+50;
				if(flag==0)
					flag=1;
				else
					flag=0;
				if(change=0)
					change=1;
				else
					change=0;
			}
		}
		else if(flag==1)
		{
			if(input[i]==1)
			{
				y=y-50;
				l1=x;l2=y;//draw_pixel(x,y);
				x=x+25;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				l1=l3;l2=l4;//draw_pixel(x,y);
				y=y+100;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				x=x+25;
				l1=l3;l2=l4;//draw_pixel(x,y);
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				y=y-50;
				if(flag==1)
					flag=0;
				else
					flag=1;
				if(change=0)
					change=1;
				else
					change=0;
			}
			else if(input[i]==0)
			{
				y=y+50;
				l1=x;l2=y;//draw_pixel(x,y);
				x=x+25;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				l1=l3;l2=l4;//draw_pixel(x,y);
				y=y-100;
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				x=x+25;
				l1=l3;l2=l4;//draw_pixel(x,y);
				l3=x;l4=y;//draw_pixel(x,y);
				draw_line(l1,l2,l3,l4);
				y=y+50;

			}
		}

		/*if((input[i]==0)&&(input[i+1]==0))
		{
			l1=l3;l2=l4;
			l3=x;l4=300;
			draw_line(l1,l2,l3,l4);
		}
		if((input[i]==1)&&(input[i+1]==0))
		{
			l1=l3;l2=l4;
			l3=x;l4=300;
			draw_line(l1,l2,l3,l4);
		}*/
	}
}
void mouse(int btn,int state,int x,int y)
{

	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		//polarmanch(input,n);
		//i++;
		glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2i(100,25);
		glVertex2i(100,175);
		glVertex2i(100,100);
		glVertex2i(450,100);
		glVertex2i(100,275);
		glVertex2i(100,425);
		glVertex2i(100,350);
		glVertex2i(450,350);
		glEnd();
		axis=1;
		polarmanch(input,n);
		diffmanch(input,n);
	}
}
void linecode()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	output(160,450,"DIFFERENTIAL MANCHESTER",2);
	output(160,200,"MANCHESTER",2);
	glutMouseFunc(mouse);
	glFlush();
}
static void menu(int mode)
{
	switch (mode)
	{
		case FRONTPAGE: glutDisplayFunc(front_page); break;
		case POLAR_CODING: glutDisplayFunc(linecode); break;
		case EXIT: exit(0);
	}
	glutPostRedisplay();
}
void key(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'F': case 'f':glutDisplayFunc(front_page);break;
		case 'S': case 's':glutDisplayFunc(linecode); break;
		case 'q': case 'Q': exit(0);
	}
	glutPostRedisplay();
}

void myDisplay()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	front_page();
 	glFlush();
 	glutSwapBuffers();
}

int main(int argc, char **argv)
{
    printf("Enter the length of the bit stream:\n");
    scanf("%d",&n);
    printf("Enter the bit stream:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(2000, 2000);
    glClearColor(1.0,1.0,1.0,1.0);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Polar Line Coding");
    glutKeyboardFunc(key);
    //glutMouseFunc(mouse);
    myInit();
    glutDisplayFunc(myDisplay);
    glutCreateMenu(menu);
    glutAddMenuEntry("Front Page", FRONTPAGE);
    glutAddMenuEntry("PolarCoding", POLAR_CODING);
    glutAddMenuEntry("Exit", EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
