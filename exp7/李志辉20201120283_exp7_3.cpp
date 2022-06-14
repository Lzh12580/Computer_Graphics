#include<iostream>
#include<math.h>
#include<windows.h>
#include<gl/glut.h>

// myInit
void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.5f, 0.4f, 0.9f);
	glPointSize(5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
}
///myDisplay//
void myDisplay()
{
	glBegin(GL_POINTS);
	glVertex2i(1, 1);
}
/// myMouse///
void myMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		glBegin(GL_POINTS);
		glVertex2i(x, 480 - y);
		glEnd();
		glFlush();
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		glClearColor(0.8, 0.6, 0.7, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}
///main///
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("李志辉20201120283");

	myInit();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutMainLoop();
}
