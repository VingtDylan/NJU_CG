//#include <QWidget>
//#include <QDebug>
//#include <opengldraw.h>
//#include <QDate>
//#include <QPainter>
//#include <QPen>
//#include <QPaintEvent>
//#include <windows.h>
//#include <GL/glu.h>
//#include <glut.h>
//#include <QOpenGLFunctions>
//#include <QOpenGLWidget>
//#include <QWidget>
//#include <QPainter>

//OpenGLDraw::OpenGLDraw(QWidget *parent) : QOpenGLWidget(parent)
//{
//    opengldraw=new OpenGLDraw(this);
//    opengldraw->setMinimumSize(400,400);
//    opengldraw->setGeometry(300, 200, 640, 480);

//    currentPid = 0;
//    currentPencolor[0] = 255;
//    currentPencolor[1] = 0;
//    currentPencolor[2] = 0;
//    currentPointSize = 10;

//    for(int i=150;i<250;i++){
//        for(int j=1;j<100;j++){
//            struct Point tmppoint;
//            tmppoint.x=i;
//            tmppoint.y=j;
//            Points.push_back(tmppoint);
//        }
//    }
//}

//OpenGLDraw::~OpenGLDraw()
//{

//}

//void OpenGLDraw::initializeGL()
//{
//    initializeOpenGLFunctions();
//    glClearColor(1.0, 1.0, 1.0,1.0);
//    glPointSize(currentPointSize);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    glEnable(GL_COLOR_MATERIAL);
//}

//void OpenGLDraw::paintGL()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glBegin(GL_TRIANGLES);
//        glColor3f(1.0, 0.0, 0.0);
//        glVertex3f(-5, -5, 0);
//        glColor3f(0.0, 1.0, 0.0);
//        glVertex3f( 5, -5, 0);
//        glColor3f(0.0, 0.0, 1.0);
//        glVertex3f( 0.0,  5, 0);
//    glEnd();
//}

//void OpenGLDraw::resizeGL(int width, int height)
//{
//    glViewport(0,0,width,height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-width/2,width/2,-height/2,height/2,-1,1);
//    glMatrixMode(GL_MODELVIEW);
//}

//void OpenGLDraw::On_Click_CreateCanvas()
//{
//    for(int i=1;i<199;i++){
//        for(int j=1;j<199;j++){
//            drawPoint(i, j);
//        }
//    }
//    qDebug() << "Date:" << QDate::currentDate();
//    qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);
//}

//void OpenGLDraw::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    for(int i=0;i<(int)Points.size();i++){
//        painter.drawPoint(Points[i].x,Points[i].y);
//    }
//}


//void OpenGLDraw::drawPoint(double x, double y)
//{
//    Point *newPoint = new Point;
//    newPoint->x = x;
//    newPoint->y = y;
//    newPoint->color[0] = currentPencolor[0];
//    newPoint->color[1] = currentPencolor[1];
//    newPoint->color[2] = currentPencolor[2];
//    newPoint->size = currentPointSize;
//    newPoint->pid = currentPid;
//    newPoint->chosen = false;

//}
