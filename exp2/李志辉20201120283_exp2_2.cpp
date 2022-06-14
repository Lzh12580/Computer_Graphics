#include<gl/glut.h>
#include<math.h>


void MidPLine(int x0, int y0, int x1, int y1)
{
    glColor3f(0.0f, 0.0f, 1.0f);//设置颜色，蓝色
    glPointSize(3);//栅格化点，直径为3

    int a, b, d, x, y, temp, tag = 0;
    if (abs(x1 - x0) < abs(y1 - y0))	//若斜率的绝对值大于1，将坐标x和坐标y互换
    {
        temp = x0, x0 = y0, y0 = temp;
        temp = x1, x1 = y1, y1 = temp;
        tag = 1;
    }
    if (x0 > x1)//保证x0<x1
    {
        temp = x0, x0 = x1, x1 = temp;
        temp = y0, y0 = y1, y1 = temp;
    }
    a = y0 - y1;//判别式的a
    b = x1 - x0;//判别式的b
    d = a + b / 2;//判别式的初值
    if (y0 < y1)//斜率为正
    {
        x = x0; y = y0;
        glBegin(GL_POINTS);//画起点
        glVertex2i(x, y);
        glEnd();
        while (x < x1)
        {
            if (d < 0) //判别式<0，取点P2，增量为a+b
            {
                x++; y++; d = d + a + b;
            }
            else//判别式>=0，取点P1，增量为a
            {
                x++; d += a;
            }
            if (tag)//斜率大于1
            {
                glBegin(GL_POINTS);
                glVertex2i(y, x);
                glEnd();
            }
            else
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
        }  /* while */
    }
    else//斜率为负(y0>=y1)
    {
        x = x1;
        y = y1;
        glBegin(GL_POINTS);//画起点
        glVertex2i(x, y);
        glEnd();
        while (x > x0)
        {
            if (d < 0)//判别式<0，增量为-a+b
            {
                x--; y++; d = d - a + b;
            }
            else//判别式>=0，增量为-a
            {
                x--; d -= a;
            }
            if (tag)//斜率大于1
            {
                glBegin(GL_POINTS);
                glVertex2i(y, x);
                glEnd();
            }
            else
            {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                glEnd();
            }
        }  /* while */
    }
}
void myDisplay()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);//清除颜色，白色
    glClear(GL_COLOR_BUFFER_BIT);//消除缓冲区，使用上述清除颜色消除


    //MidPLine(0, 0, 200, 200);
    //MidPLine(200, 200, 0, 0);
    //MidPLine(0, 200, 100, 100);
    MidPLine(200, 200, 400, 0);

    glFlush();//强制刷新
}

void Reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //定义视口大小
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);//使左下角坐标为（0，0），右上角坐标为（w,h）
}

void main(int argc, char* argv[])
{
    glutInit(&argc, argv);//初始化GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//显示模式
    glutInitWindowPosition(100, 100);//窗口位置,窗口左上角在屏幕的坐标
    glutInitWindowSize(400, 400);//窗口大小
    glutCreateWindow("中点画线法");//创建窗口，参数是窗口的标题
    glutDisplayFunc(myDisplay);//告诉GLUT哪个函数负责绘图，即注册一个绘图函数myDisplay
    glutReshapeFunc(Reshape); //窗口发生改变时，使用什么函数进行重绘
    glutMainLoop();//处理永不结束的循环监听
}

