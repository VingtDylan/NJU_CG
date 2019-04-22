#include "canvas.h"
#include "ui_canvas.h"
#include "QPainter"
#include "QDebug"
#include "QImage"
#include "QtMath"
#include <QAction>
#include <QIcon>
#include <QToolBar>
#include <QColorDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "resetdialog.h"

Canvas::Canvas(int x,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    canvasId=x;
    setWindowIcon(QIcon(":/menu_icons/NJU"));
    setWindowTitle("Canvas_"+QString::number(canvasId));
    currentPid=1;
    currentPencolor[0]=128;
    currentPencolor[1]=0;
    currentPencolor[2]=128;
    currentPointSize=1;
    imgsave=false;//emmmm

    QToolBar *toolbar=new QToolBar(this);
    toolbar->setIconSize(QSize(15,15));
    actions[0]=new QAction(QIcon(":/menu_icons/reset"),"",this);
    actions[1]=new QAction(QIcon(":/menu_icons/save"),"",this);
    actions[2]=new QAction(QIcon(":/menu_icons/choose"),"",this);
    actions[3]=new QAction(QIcon(":/menu_icons/color"),"",this);
    actions[4]=new QAction(QIcon(":/menu_icons/point"),"",this);
    actions[5]=new QAction(QIcon(":/menu_icons/line"),"",this);
    actions[6]=new QAction(QIcon(":/menu_icons/polygon"),"",this);
    actions[7]=new QAction(QIcon(":/menu_icons/polygon_fill"),"",this);
    actions[8]=new QAction(QIcon(":/menu_icons/ellipse"),"",this);
    actions[9]=new QAction(QIcon(":/menu_icons/curve"),"",this);
    actions[10]=new QAction(QIcon(":/menu_icons/translate"),"",this);
    actions[11]=new QAction(QIcon(":/menu_icons/rotate"),"",this);
    actions[12]=new QAction(QIcon(":/menu_icons/scale"),"",this);
    actions[13]=new QAction(QIcon(":/menu_icons/clip"),"",this);
    //actions[0]->setShortcut(Qt::Key_Control);
    actions[0]->setToolTip("resetCanvas");
    actions[1]->setToolTip("saveCanvas");
    actions[2]->setToolTip("chooseID");
    actions[3]->setToolTip("setColor");
    actions[4]->setToolTip("drawPoint");
    actions[5]->setToolTip("drawLine");
    actions[6]->setToolTip("drawPolygon");
    actions[7]->setToolTip("drawFillPolygon");
    actions[8]->setToolTip("drawEllipse");
    actions[9]->setToolTip("drawCurve");
    actions[10]->setToolTip("translate");
    actions[11]->setToolTip("rotate");
    actions[12]->setToolTip("scale");
    actions[13]->setToolTip("clip");
    toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    for(int i=0;i<14;i++){
        toolbar->addAction(actions[i]);
    }
    connect(actions[0],SIGNAL(triggered()),this,SLOT(resetCanvasTriggered()));
    connect(actions[1],SIGNAL(triggered()),this,SLOT(saveCanvasTriggered()));
    connect(actions[2],SIGNAL(triggered()),this,SLOT(chooseIDTriggered()));
    connect(actions[3],SIGNAL(triggered()),this,SLOT(SetColorTriggered()));
    connect(actions[4],SIGNAL(triggered()),this,SLOT(drawPointTriggered()));
    connect(actions[5],SIGNAL(triggered()),this,SLOT(drawLineTriggered()));
    connect(actions[6],SIGNAL(triggered()),this,SLOT(drawPolygonTriggered()));
    connect(actions[7],SIGNAL(triggered()),this,SLOT(drawFillPolygonTriggered()));
    connect(actions[8],SIGNAL(triggered()),this,SLOT(drawEllipseTriggered()));
    connect(actions[9],SIGNAL(triggered()),this,SLOT(drawCurveTriggered()));
    connect(actions[10],SIGNAL(triggered()),this,SLOT(translateTriggered()));
    connect(actions[11],SIGNAL(triggered()),this,SLOT(rotateTriggered()));
    connect(actions[12],SIGNAL(triggered()),this,SLOT(scaleTriggered()));
    connect(actions[13],SIGNAL(triggered()),this,SLOT(clipTriggered()));

    this->setMouseTracking(true);

    for(int i=100;i<200;i++){
        for(int j=100;j<200;j++){
            currentPencolor[0]=0;
            currentPencolor[1]=0;
            currentPencolor[2]=0;
            Generate_point(i,j,COMMONID);
        }
    }
}

void Canvas::resetCanvasTriggered(){
    mouse=resetCanvas_;
    mdialog=new ResetDialog();
    mdialog->show();
    connect(mdialog, SIGNAL(sendString(QString,QString)), this, SLOT(ResetParams(QString,QString)));
    Points.clear();
}

void Canvas::ResetParams(QString width,QString height){
    //qDebug()<<width.toInt()<<" "<<height.toInt()<<endl;
    this->setGeometry(640,320,width.toInt(),height.toInt());
}

void Canvas::saveCanvasTriggered(){
    mouse=saveCanvas_;
    QString filename = QFileDialog::getSaveFileName(this,
        tr("Save Image"),
        "",
        tr("*.bmp;; *.png;; *.jpg;; *.tif;; *.GIF")); //选择路径
    imgwidth=this->width();
    imgheight=this->height();
    QImage image(imgwidth,imgwidth,QImage::Format_RGB32);
    QPainter img_painter;
    img_painter.begin(&image);
    //image.fill(Qt::transparent);
    image.fill(QColor(219,207,202));
    for(int i=0;i<Points.size();i++){
        img_painter.setPen(QColor(Points[i].color[0],Points[i].color[1],Points[i].color[2]));
        img_painter.drawPoint(Points[i].x,Points[i].y);
    }
    img_painter.end();
    if(filename.isEmpty()){
      return;
    }
    else{
      if(!(image.save(filename,"BMP",100))){
         QMessageBox::information(this,
            tr("Failed to save the image"),
            tr("Failed to save the image!"));
         return;
      }
    }
}

void Canvas::chooseIDTriggered(){
    mouse=chooseID_;
}

void Canvas::SetColorTriggered(){
    mouse=SetColor_;
    QColorDialog getcolor;
    QColor color=getcolor.getColor();
    currentPencolor[0]=color.red();
    currentPencolor[1]=color.green();
    currentPencolor[2]=color.blue();
}

void Canvas::drawPointTriggered(){
    mouse=drawPoint_;
}

void Canvas::drawLineTriggered(){
    mouse=drawLine_;
}

void Canvas::drawPolygonTriggered(){
    mouse=drawPolygon_;
}

void Canvas::drawFillPolygonTriggered(){
    mouse=drawFillPolygon_;
}

void Canvas::drawEllipseTriggered(){
    mouse=drawEllipse_;
}

void Canvas::drawCurveTriggered(){
    mouse=drawCurve_;
}

void Canvas::translateTriggered(){
    mouse=translate_;
}

void Canvas::rotateTriggered(){
    mouse=rotate_;
}

void Canvas::scaleTriggered(){
    mouse=scale_;
}

void Canvas::clipTriggered(){
    mouse=clip_;
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent *)
{
    //qDebug()<<Points.length()<<TmpPoints.length()<<BufferPoints.length()<<endl;
    QPainter painter(this);
    //painter.drawLine(138,141,281,319);
    for(int i=0;i<Points.size();i++){
       painter.setPen(QColor(Points[i].color[0],Points[i].color[1],Points[i].color[2]));
       painter.drawPoint(Points[i].x,Points[i].y);
    }
    for(int i=0;i<TmpPoints.size();i++){
       painter.setPen(QColor(TmpPoints[i].color[0],TmpPoints[i].color[1],TmpPoints[i].color[2]));
       painter.drawPoint(TmpPoints[i].x,TmpPoints[i].y);
    }
    for(int i=0;i<BufferPoints.size();i++){
       painter.setPen(QColor(BufferPoints[i].color[0],BufferPoints[i].color[1],BufferPoints[i].color[2]));
       painter.drawPoint(BufferPoints[i].x,BufferPoints[i].y);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        isDrawing=true;
        //qDebug()<<event->x()<<endl;
        //qDebug()<<event->y()<<endl;
        switch(mouse){
          case resetCanvas_:
          case saveCanvas_:break;
          case chooseID_:{
               bool choose=false;
               for(int i=0;i<Points.length();i++){
                 if(Points[i].x==event->x()&&Points[i].y==event->y()){
                    tmpChosePid=Points[i].pid;
                    choose=true;
                 }
               }
               if(choose){
                   BufferPoints.clear();
                   for(int i=0;i<Points.length();i++){
                       if(Points[i].pid==tmpChosePid){
                           Generate_Bufferpoint(Points[i].x,this->height()-Points[i].y,Points[i].pid);
                       }
                   }
               }else{
                   tmpChosePid=COMMONID+1;//No Chosen
               }
            }
            break;
          case SetColor_:break;
          case drawPoint_:
               for(int i=0;i<2;i++)
                 for(int j=0;j<2;j++)
                   Generate_point(event->x()+i,this->height()-(event->y()+j),COMMONID);
               break;
          case drawLine_:
               if(TmpPoints.length()==0){
                    Generate_Tmppoint(event->x(),event->y(),COMMONID);
               }else if(TmpPoints.length()==1){
                    for(int i=0;i<BufferPoints.length();i++)
                        Points.append(BufferPoints[i]);
                    BufferPoints.clear();
                    TmpPoints.clear();
               }
               break;
          case drawPolygon_:
               Generate_Tmppoint(event->x(),event->y(),COMMONID);
               break;
          case drawFillPolygon_:
               break;
          case drawEllipse_:
               break;
          case drawCurve_:
               break;
          case translate_:{
               bool choose=false;
               for(int i=0;i<Points.length();i++){
                 if(Points[i].x==event->x()&&Points[i].y==event->y()){
                    tmpChosePid=Points[i].pid;
                    choose=true;
                 }
               }
               if(choose){
                 BufferPoints.clear();
                 for(int i=0;i<Points.length();i++){
                   if(Points[i].pid==tmpChosePid){
                     Generate_ColorBufferpoint(Points[i].x,this->height()-Points[i].y,Points[i].pid,Points[i].color);
                     Generate_ColorTmppoint(Points[i].x,this->height()-Points[i].y,Points[i].pid,Points[i].color);
                   }
                 }
               }else{
                   tmpChosePid=COMMONID+1;
               }
               tmpChosenPos[0]=event->x();
               tmpChosenPos[1]=event->y();
            }
               break;
          case rotate_:
               break;
          case scale_:
               break;
          case clip_:
               break;
           /*TODO*/
        }
    }else if(event->button()==Qt::RightButton){
        isDrawing=false;
        switch(mouse){
            case resetCanvas_:break;
            case saveCanvas_:break;
            case chooseID_:break;
            case SetColor_:break;
            case drawPoint_:break;
            case drawLine_:break;
            case drawPolygon_:{
                for(int i=0;i<BufferPoints.length();i++)
                    Points.append(BufferPoints[i]);
                BufferPoints.clear();
                TmpPoints.clear();
                break;
              }
            case drawFillPolygon_:break;
            case drawEllipse_:break;
            case drawCurve_:break;
            case translate_:break;
            case rotate_:break;
            case scale_:break;
            case clip_:break;
        }
    }
    update();
}

void Canvas::mouseMoveEvent(QMouseEvent *event){
    //qDebug()<<event->x()<<event->y()<<endl;
    switch (mouse){
        case resetCanvas_:
        case saveCanvas_:
        case chooseID_:
        case SetColor_:
        case drawPoint_:break;
        case drawLine_:{
            if(TmpPoints.length()==1){
                BufferPoints.clear();
                Generate_Bufferpoint(event->x(),event->y(),COMMONID);
                float x1=TmpPoints[0].x;
                float x2=BufferPoints[0].x;
                float y1=TmpPoints[0].y;
                float y2=BufferPoints[0].y;
                drawBufferLine(COMMONID,x1,y1,x2,y2);
            }
          }
          break;
        case drawPolygon_:{
            if(TmpPoints.length()==1){
                BufferPoints.clear();
                Generate_Bufferpoint(event->x(),event->y(),COMMONID);
                float x1=TmpPoints[0].x;
                float x2=BufferPoints[0].x;
                float y1=TmpPoints[0].y;
                float y2=BufferPoints[0].y;
                drawBufferLine(COMMONID,x1,y1,x2,y2);
            }else if(TmpPoints.length()>1){
                BufferPoints.clear();
                Generate_Bufferpoint(event->x(),event->y(),COMMONID);
                float x1,x2,y1,y2;
                for(int i=0;i<TmpPoints.length()-1;i++){
                    x1=TmpPoints[i].x;
                    x2=TmpPoints[i+1].x;
                    y1=TmpPoints[i].y;
                    y2=TmpPoints[i+1].y;
                    drawBufferLine(COMMONID,x1,y1,x2,y2);
                }
                x1=TmpPoints[0].x;
                x2=BufferPoints[0].x;
                y1=TmpPoints[0].y;
                y2=BufferPoints[0].y;
                drawBufferLine(COMMONID,x1,y1,x2,y2);
                x1=TmpPoints[TmpPoints.length()-1].x;
                x2=BufferPoints[0].x;
                y1=TmpPoints[TmpPoints.length()-1].y;
                y2=BufferPoints[0].y;
                drawBufferLine(COMMONID,x1,y1,x2,y2);
            }
          }
          break;
        case drawFillPolygon_:break;
        case drawEllipse_:break;
        case drawCurve_:break;
        case translate_:{
            if(isDrawing){
                int dx=event->x()-tmpChosenPos[0];
                int dy=event->y()-tmpChosenPos[1];
                //qDebug()<<tmpChosenPos[0]<<tmpChosenPos[1]<<endl;
                for(int i=0;i<BufferPoints.length();i++){
                    BufferPoints[i].x=TmpPoints[i].x+dx;
                    BufferPoints[i].y=TmpPoints[i].y+dy;
                }
            }
           }
           break;
        case rotate_:break;
        case scale_:break;
        case clip_:break;
        /*TODO*/
    }
    update();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        isDrawing=false;
        switch (mouse) {
            case chooseID_:BufferPoints.clear();break;
            case translate_:
                TmpPoints.clear();
                if(BufferPoints.length()>0){
                    int s=0;
                    for(int i=0;i<Points.length();i++){
                        if(Points[i].pid==tmpChosePid){
                            s++;
                            Points.remove(i);
                            i--;/*这个bug我是哭了！*/
                        }
                    }
                    //qDebug()<<"s"<<s<<endl;
                    //qDebug()<<"Pid"<<tmpChosePid<<endl;
                    //qDebug()<<Points.length()<<endl;
                    for(int i=0;i<BufferPoints.length();i++){
                        Points.append(BufferPoints[i]);
                    }
                    BufferPoints.clear();
                }
                break;
            default:break;
        }

    }
    update();
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
    tmppoint.chosen=false;
    Points.push_back(tmppoint);
}

void Canvas::Generate_Tmppoint(int x, int y, int id){
    struct Point tmppoint;
    tmppoint.x=x;
    tmppoint.y=this->height()-y;
    tmppoint.color[0]=currentPencolor[0];
    tmppoint.color[1]=currentPencolor[1];
    tmppoint.color[2]=currentPencolor[2];
    tmppoint.size=currentPointSize;
    tmppoint.pid=id;
    tmppoint.chosen=false;
    TmpPoints.push_back(tmppoint);
}

void Canvas::Generate_ColorTmppoint(int x, int y, int id,int color[]){
    struct Point tmppoint;
    tmppoint.x=x;
    tmppoint.y=this->height()-y;
    tmppoint.color[0]=color[0];
    tmppoint.color[1]=color[1];
    tmppoint.color[2]=color[2];
    tmppoint.size=currentPointSize;
    tmppoint.pid=id;
    tmppoint.chosen=false;
    TmpPoints.push_back(tmppoint);
}

void Canvas::Generate_Bufferpoint(int x, int y, int id){
    struct Point tmppoint;
    tmppoint.x=x;
    tmppoint.y=this->height()-y;
    tmppoint.color[0]=128;
    tmppoint.color[1]=0;
    tmppoint.color[2]=128;
    tmppoint.size=currentPointSize;
    tmppoint.pid=id;
    tmppoint.chosen=false;
    BufferPoints.push_back(tmppoint);
}

void Canvas::Generate_ColorBufferpoint(int x, int y, int id,int color[]){
    struct Point tmppoint;
    tmppoint.x=x;
    tmppoint.y=this->height()-y;
    tmppoint.color[0]=color[0];
    tmppoint.color[1]=color[1];
    tmppoint.color[2]=color[2];
    tmppoint.size=currentPointSize;
    tmppoint.pid=id;
    tmppoint.chosen=false;
    BufferPoints.push_back(tmppoint);
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
    //image.fill(Qt::transparent);
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
        //暂存画笔颜色
        tmpPencolor[0]=currentPencolor[0];
        tmpPencolor[1]=currentPencolor[1];
        tmpPencolor[2]=currentPencolor[2];
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
        //currentPencolor[0]=128;
        //currentPencolor[1]=0;
        //currentPencolor[2]=128;
        currentPencolor[0]=tmpPencolor[0];
        currentPencolor[1]=tmpPencolor[1];
        currentPencolor[2]=tmpPencolor[2];
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

void Canvas::drawBufferLine(int id,float x1,float y1,float x2,float y2){
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
         Generate_Bufferpoint(static_cast<int>(roundf(xstart)),static_cast<int>(roundf(ystart)),id);
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
}
