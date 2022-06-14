#include "stdafx.h"
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>
#include<cmath>
#include<vector>

GLsizei winWidth = 400, winHeight = 300;

void init(void) {
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void displayFcn(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(30.0);
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	winWidth = newWidth;
	winHeight = newHeight;
}

void plotPoint(GLint x, GLint y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse) {
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
		plotPoint(xMouse, winHeight - yMouse);
	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Mouse Plot Points");

	init();
	glutDisplayFunc(displayFcn);
	glutReshapeFunc(winReshapeFcn);
	glutMouseFunc(mousePtPlot);
	glutMainLoop();
}