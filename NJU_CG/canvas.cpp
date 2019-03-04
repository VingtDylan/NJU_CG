#include "canvas.h"
#include "ui_canvas.h"
#include "QPainter"
#include "QDebug"
#include "QImage"
#include "QtMath"

Canvas::Canvas(int x,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    canvasId=x;
    setWindowTitle("Canvas_"+QString::number(canvasId));
    currentPid=1;
    currentPencolor[0]=255;
    currentPencolor[1]=0;
    currentPencolor[2]=0;
    currentPointSize=1;
    imgsave=false;

//    for(int i=1;i<100;i+=5){
//        for(int j=1;j<100;j+=5){
//            struct Point tmppoint;
//            tmppoint.x=i;
//            tmppoint.y=this->height()-j;
//            tmppoint.color[0]=currentPencolor[0];
//            tmppoint.color[1]=currentPencolor[1];
//            tmppoint.color[2]=currentPencolor[2];
//            tmppoint.size=currentPointSize;
//            tmppoint.pid=currentPid;
//            Points.push_back(tmppoint);
//        }
//    }
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(int i=0;i<Points.size();i++){
       painter.setPen(QColor(Points[i].color[0],Points[i].color[1],Points[i].color[2]));
       painter.drawPoint(Points[i].x,Points[i].y);
    }
}

void Canvas::ReceiveResetCanvas()
{
    Points.clear();
}

void Canvas::ReceiveSaveCanvas(QString herit)
{
    imgwidth=this->width();
    imgheight=this->height();
    QImage image(imgwidth,imgwidth,QImage::Format_RGB32);
    QPainter img_painter;
    img_painter.begin(&image);
    image.fill(QColor(219,207,202));
    for(int i=0;i<Points.size();i++){
        img_painter.setPen(QColor(Points[i].color[0],Points[i].color[1],Points[i].color[2]));
        img_painter.drawPoint(Points[i].x,Points[i].y);
    }
    img_painter.end();
    image.save(QString("../NJU_CG/images/")+herit+QString(".bmp"),"BMP",100);
}

void Canvas::ReceiveSetColor(int R,int G,int B){
    currentPencolor[0]=R;
    currentPencolor[1]=G;
    currentPencolor[2]=B;
    update();
}

void Canvas::ReceiveDrawLine(int id,float x1,float y1,float x2,float y2,QString algorithm){
    //DDA
    if(algorithm=="DDA"){
        qDebug()<<"Algorithm:DDA"<<endl;
        float dx=x2-x1;
        float dy=y2-y1;
        int steps;
        float xIncrement,yIncrement,xstart=x1,ystart=y1;
        if(fabsf(dx)>fabsf(dy))
            steps=static_cast<int>(fabsf(dy));
        else
            steps=static_cast<int>(fabsf(dx));
        xIncrement=static_cast<float>((dx)/float(steps));
        yIncrement=static_cast<float>((dy)/float(steps));
        for(int k=0;k<steps;k++){
            xstart+=xIncrement;
            ystart+=yIncrement;
            struct Point tmppoint;
            tmppoint.x=static_cast<int>(roundf(xstart));
            tmppoint.y=this->height()-static_cast<int>(roundf(ystart));
            tmppoint.color[0]=currentPencolor[0];
            tmppoint.color[1]=currentPencolor[1];
            tmppoint.color[2]=currentPencolor[2];
            tmppoint.size=currentPointSize;
            tmppoint.pid=id;
            Points.push_back(tmppoint);
        }
        update();
    }else if(algorithm=="Bresenham"){
        qDebug()<<"Algorithm:Bresenham"<<endl;
        float dx=x2-x1;
        float dy=y2-y1;
        float xIncrement=((dx>0)*2)-1;
        float yIncrement=((dy>0)*2)-1;
        float xstart=x1,ystart=y1,eps=0;
        if(fabsf(dx)>fabsf(dy)){
            for(;fabsf(xstart-x2)>=0.01f;xstart+=xIncrement){
                struct Point tmppoint;
                tmppoint.x=static_cast<int>(roundf(xstart));
                tmppoint.y=this->height()-static_cast<int>(roundf(ystart));
                tmppoint.color[0]=currentPencolor[0];
                tmppoint.color[1]=currentPencolor[1];
                tmppoint.color[2]=currentPencolor[2];
                tmppoint.size=currentPointSize;
                tmppoint.pid=id;
                Points.push_back(tmppoint);
                eps+=dy;
                if((eps*2)>=dx){
                    ystart+=yIncrement;
                    eps-=dx;
                }
            }
        }else{
            for(;fabsf(ystart-y2)>=0.01f;ystart+=yIncrement){
                struct Point tmppoint;
                tmppoint.x=static_cast<int>(roundf(xstart));
                tmppoint.y=this->height()-static_cast<int>(roundf(ystart));
                tmppoint.color[0]=currentPencolor[0];
                tmppoint.color[1]=currentPencolor[1];
                tmppoint.color[2]=currentPencolor[2];
                tmppoint.size=currentPointSize;
                tmppoint.pid=id;
                Points.push_back(tmppoint);
                eps+=dx;
                if((eps*2)>=dy){
                    xstart+=xIncrement;
                    eps-=dy;
                }
            }
        }
        update();
    }else {
        qDebug()<<"No such algorithm"<<endl;
    }
}

void Canvas::ReceiveDrawPolygon(){
    update();
    //Todo
}
void Canvas::ReceiveDrawEllipse(int id,float x,float y,float rx,float ry){
    qDebug()<<id<<x<<y<<rx<<ry<<endl;
    update();
}

void Canvas::ReceiveDrawCurve(){
    //TODO
    update();
}

void Canvas::ReceiveTranslate(){
    update();
    //TODO
}

void Canvas::ReceiveRotate(){
    update();
    //TODO
}

void Canvas::ReceiveScale(){
    update();
    //TODO
}

void Canvas::ReceiveClip(){
    update();
    //TODO
}
