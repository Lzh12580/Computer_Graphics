#include <gl\glut.h>
#include <iostream>
using namespace std;

//transilate时，x，y上的增量
float i = 0, j = 0;
//rotate时的角度增量
GLint angle = 0;
//scale时，x,y上的增量
float s1 = 1, s2 = 1;

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(300 + i, 300 + j, 0);
	glRotatef(angle % 360, 0, 0, 1);
	glScalef(s1, s2, 0);

	glColor3f(0, 0.6, 0.5);
	glRectf(-100, 100, 100, -100);

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		j = j + 5; break;
	case 's':
		j = j - 5; break;
	case 'a':
		i = i - 5; break;
	case 'd':
		i = i + 5; break;
	case 'q':
		angle += 10; break;
	case 'e':
		angle -= 10; break;
	case 'z':
		s1 += 0.1; break;
	case 'x':
		s2 += 0.1; break;
	case 'c':
		s1 -= 0.1; break;
	case 'v':
		s2 -= 0.1; break;
	}
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(400, 50);
	glutInitWindowSize(400, 400);
	glutCreateWindow("李志辉20201120283： 二维几何变换");

	init();

	glutDisplayFunc(display);

	cout << " w,s,a,d键 分别为上下左右平移" << endl;
	cout << " q,e键 分别为逆时针旋转，顺时针旋转" << endl;
	cout << " z,x,c,v键 分别为长宽的放大缩小" << endl;
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}