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

double Canvas::Factor(int n, int k){
    double sum=1;
    for(int i=1;i<=n;i++)
        sum*=i;
    for(int i=1;i<=k;i++)
        sum/=i;
    for(int i=1;i<=n-k;i++)
        sum/=i;
    return sum;
}

void Canvas::Generate_point(int x, int y,int id){
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

void Canvas::Generate_Bezier(QVector<float>x,QVector<float>y,int id,int n,double t){
    double tmpx=0,tmpy=0;
    double bezier_curve=0;
    for(int i=0;i<n;i++){
        bezier_curve=Factor(n-1,i)*pow(t,i)*pow(1-t,n-1-i);
        tmpx+=static_cast<double>(x[i])*bezier_curve;
        tmpy+=static_cast<double>(y[i])*bezier_curve;
    }
    Generate_point(static_cast<int>(tmpx),static_cast<int>(tmpy),id);
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
        float steps;
        float xIncrement,yIncrement,xstart=x1,ystart=y1;
        if(fabsf(dx)>fabsf(dy))
            steps=static_cast<int>(fabsf(dx));
        else
            steps=static_cast<int>(fabsf(dy));
        xIncrement=static_cast<float>((dx)/steps);
        yIncrement=static_cast<float>((dy)/steps);
        for(int k=0;k<steps;k++){
            Generate_point(static_cast<int>(roundf(xstart+0.5f)),static_cast<int>(roundf(ystart+0.5f)),id);
            xstart+=xIncrement;
            ystart+=yIncrement;
        }
        update();
    }else if(algorithm=="Bresenham"){
        qDebug()<<"Algorithm:Bresenham";
        float xstart=x1,ystart=y1;
        float dx=fabsf(x2-x1);
        float dy=fabsf(y2-y1);
        int xIncrement=x2>x1 ? 1 : (x2<x1 ? -1 : 0);
        int yIncrement=y2>y1 ? 1 : (y2<y1 ? -1 : 0);
        bool interchange=false;
        if(dy>dx){
            float temp=dx;
            dx=dy;
            dy=temp;
            interchange=true;
        }
        float p=2*dy-dx;
        for(int i=0;i<dx;i++){
            Generate_point(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
            if(p>=0){
                if(!interchange)
                    ystart+=yIncrement;
                else
                    xstart+=xIncrement;
                p-=2*dx;
            }
            if(!interchange)
                xstart+=xIncrement;
            else
                ystart+=yIncrement;
            p+=2*dy;
        }
        update();
    }else {
        qDebug()<<"No such algorithm"<<endl;
    }
}

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
    d=square_ry*(deltax+0.5)*(deltax+0.5)+square_rx*(deltay-1)*(deltay-1)-square_rx*square_ry;
    while(deltay>0){
        if(d<0){
            d+=square_ry*(2*deltax+2)+square_rx*((-2)*deltay+3);
            deltax++;
        }else
            d+=square_rx*((-2)*deltay+3);
        deltay--;
        Generate_Ellipse(x,y,deltax,deltay,id);
    }
    update();
}

void Canvas::ReceiveDrawCurve(int id,QVector<float>x,QVector<float>y,QString algorithm,int n){
    if(algorithm=="Bezier"){
        qDebug()<<"Algorithm:Bezier";
        //绘制轮廓(红色)
        currentPencolor[0]=255;
        currentPencolor[1]=0;
        currentPencolor[2]=0;
        for(int i=0;i<n-1;i++){
            this->ReceiveDrawLine(id,x[i],y[i],x[i+1],y[i+1],"DDA");
        }
        //绘制曲线
        int tpoints=500;//to be improved
        double t=0.0;
        double delta=1.0/tpoints;
        currentPencolor[0]=128;
        currentPencolor[1]=0;
        currentPencolor[2]=128;
        for(int i=0;i<tpoints;i++){
            t+=delta;
            Generate_Bezier(x,y,id,n,t);
        }
    }else if(algorithm=="B-spline"){
        qDebug()<<"Algorithm:B-spline";
        //TODO
    }else{
        qDebug()<<"No such algorithm"<<endl;
    }
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
