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
    imgsave=false;//emmmm
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

void Canvas::Generate_point(int x, int y,int id){
//    for(int i=0;i<Points.size();i++){
//        if(Points[i].x==x&&Points[i].y==y)
//            Points.erase(Points.begin()+i);
//    }
    struct Point tmppoint;
    tmppoint.x=x;
    tmppoint.y=this->height()-y;
    tmppoint.color[0]=currentPencolor[0];
    tmppoint.color[1]=currentPencolor[1];
    tmppoint.color[2]=currentPencolor[2];
    tmppoint.size=currentPointSize;
    tmppoint.pid=id;
    Points.push_back(tmppoint);
}

void Canvas::Generate_Ellipse(float x,float y,float rx,float ry,int id){
    Generate_point(static_cast<int>(x-rx),static_cast<int>(y-ry),id);
    Generate_point(static_cast<int>(x-rx),static_cast<int>(y+ry),id);
    Generate_point(static_cast<int>(x+rx),static_cast<int>(y-ry),id);
    Generate_point(static_cast<int>(x+rx),static_cast<int>(y+ry),id);
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
        qDebug()<<"Algorithm:DDA";
        float dx=x2-x1;
        float dy=y2-y1;
        int steps;
        float xIncrement,yIncrement,xstart=x1,ystart=y1;
        if(fabsf(dx)>fabsf(dy))
            steps=static_cast<int>(fabsf(dx));
        else
            steps=static_cast<int>(fabsf(dy));
        xIncrement=static_cast<float>((dx)/float(steps));
        yIncrement=static_cast<float>((dy)/float(steps));
        for(int k=0;k<steps;k++){
            xstart+=xIncrement;
            ystart+=yIncrement;
            Generate_point(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
        }
        update();
    }else if(algorithm=="Bresenham"){
        qDebug()<<"Algorithm:Bresenham";
        float dx=x2-x1;
        float dy=y2-y1;
        float xIncrement=((dx>0?1:0)*2)-1;
        float yIncrement=((dy>0?1:0)*2)-1;
        float xstart=x1,ystart=y1,eps=0;
        if(fabsf(dx)>fabsf(dy)){
            for(;fabsf(xstart-x2)>=0.01f;xstart+=xIncrement){
                Generate_point(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
                eps+=dy;
                if((eps*2)>=dx){
                    xstart+=xIncrement;
                    eps-=dx;
                }
            }
        }else{
            for(;fabsf(ystart-y2)>=0.01f;ystart+=yIncrement){
                Generate_point(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
                eps+=dx;
                if((eps*2)>=dy){
                    ystart+=yIncrement;
                    eps-=dy;
                }
            }
        }
        update();
    }else {
        qDebug()<<"No such algorithm"<<endl;
    }
}

//drawPolygon 8 4 Bresenham 100 100 300 100 300 300 100 300

//void Canvas::ReceiveDrawPolygon(){
//    update();
//    //Todo
//}

void Canvas::ReceiveDrawEllipse(int id,float x,float y,float rx,float ry){
    //中心圆算法
    double square_rx=static_cast<double>(rx*rx);
    double square_ry=static_cast<double>(ry*ry);
    double d=square_ry+square_rx*(0.25-static_cast<double>(ry));
    int deltax=0,deltay=static_cast<int>(ry);
    Generate_Ellipse(x,y,deltax,deltay,id);
    while(square_ry*(deltax+1)<square_rx*(deltay-0.5)){
        if(d<0)
            d+=square_ry*(2*deltax+3);
        else {
            d+=(square_ry*(2*deltax+3)+square_rx*((-2)*deltay+2));
            deltay--;
        }
        deltax++;
        Generate_Ellipse(x,y,deltax,deltay,id);
    }
    d=static_cast<double>(ry)*(deltax+0.5)*2+static_cast<double>(rx)*(deltay-1)*2-static_cast<double>((rx-ry))*2;
    while(deltay>0){
        if(d<0){
            d+=square_ry*(2*deltax+2)+square_rx*((-2)*deltay+3);
            deltax++;
        }else{
            d+=square_rx*((-2)*deltay+3);
        }
        deltay--;
        Generate_Ellipse(x,y,deltax,deltay,id);
    }
    update();
}

void Canvas::ReceiveDrawCurve(){
    //TODO
    update();
}

void Canvas::ReceiveTranslate(int id,float dx,float dy){
    for(int i=0;i<Points.size();i++){
        if(Points[i].pid==id){
            Points[i].x+=dx;
            Points[i].y-=dy;
        }
    }
    update();
}

void Canvas::ReceiveRotate(int id,float x,float y,float r){
    float relative_position_x,relative_position_y;
    for(int i=0;i<Points.size();i++){
        if(Points[i].pid==id){
            relative_position_x=Points[i].x-x;
            relative_position_y=Points[i].y-y;
            float radians=qDegreesToRadians(r);
            Points[i].x=static_cast<int>(roundf(static_cast<float>(static_cast<float>(qCos(static_cast<qreal>(radians))))*relative_position_x+static_cast<float>(static_cast<float>(qSin(static_cast<qreal>(radians))))*relative_position_y
                                                )+x);
            Points[i].y=static_cast<int>(roundf(static_cast<float>(static_cast<float>(-qSin(static_cast<qreal>(radians))))*relative_position_x+static_cast<float>(static_cast<float>(qCos(static_cast<qreal>(radians))))*relative_position_y
                                                )+y);
        }
    }
    update();
}

void Canvas::ReceiveScale(int id,float x,float y,float s){
    float relative_position_x,relative_position_y;
    for(int i=0;i<Points.size();i++){
        if(Points[i].pid==id){
            relative_position_x=Points[i].x-x;
            relative_position_y=Points[i].y-y;
            Points[i].x=static_cast<int>(roundf(relative_position_x*s+x));
            Points[i].y=static_cast<int>(roundf(relative_position_y*s+y));
        }
    }
    update();
}

void Canvas::ReceiveClip(){
    update();
    //TODO
}
