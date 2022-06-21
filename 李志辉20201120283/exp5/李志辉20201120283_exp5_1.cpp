#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const int n = 50;
const GLfloat R = 0.9f;
const GLfloat PI = 3.24250265357f;
void myDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++) {
        glVertex2f(R * cos(2 * PI / n * i), R * sin(2 * PI / n * i));
    }
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("李志辉20201120283");
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}