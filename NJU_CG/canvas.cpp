#include "canvas.h"
#include "ui_canvas.h"
#include "QPainter"
#include "QDebug"
#include "QImage"

Canvas::Canvas(int x,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    canvasId=x;
    setWindowTitle("Canvas_"+QString::number(canvasId));
    //currentPid;
    currentPencolor[0]=255;
    currentPencolor[1]=0;
    currentPencolor[2]=0;
    currentPointSize=1;
    imgsave=false;

    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            struct Point tmppoint;
            tmppoint.x=i;
            tmppoint.y=this->height()-j;
            tmppoint.color[0]=currentPencolor[0];
            tmppoint.color[1]=currentPencolor[1];
            tmppoint.color[2]=currentPencolor[2];
            tmppoint.size=currentPointSize;
            Points.push_back(tmppoint);
        }
    }

}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for(unsigned long long i=0;i<Points.size();i++){
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
    for(unsigned long long i=0;i<Points.size();i++){
        img_painter.setPen(QColor(Points[i].color[0],Points[i].color[1],Points[i].color[2]));
        img_painter.drawPoint(Points[i].x,Points[i].y);
    }
    img_painter.drawEllipse(10,10, 80,80);
    img_painter.end();
    image.save(QString("../NJU_CG/images/")+herit+QString(".bmp"),"BMP",100);
}

void Canvas::ReceiveSetColor(int R,int G,int B){
    currentPencolor[0]=R;
    currentPencolor[1]=G;
    currentPencolor[2]=B;
    Points.clear();
    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            struct Point tmppoint;
            tmppoint.x=i;
            tmppoint.y=this->height()-j;
            tmppoint.color[0]=currentPencolor[0];
            tmppoint.color[1]=currentPencolor[1];
            tmppoint.color[2]=currentPencolor[2];
            tmppoint.size=currentPointSize;
            Points.push_back(tmppoint);
        }
    }
    //update();
}
