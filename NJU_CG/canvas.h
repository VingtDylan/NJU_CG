#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

struct Point{
    int x;
    int y;
    int color[3];
    int size;
    int pid;
    bool chosen;//later
};

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(int x,QWidget *parent = nullptr);
    ~Canvas();
    int canvasId;//画布序号
    int currentPid;//画的图元
    int currentPencolor[3];//画笔颜色
    int currentPointSize;//画笔的粗细

    QString ImageSavePath;//图片存储路径，后续自定义用
    int imgwidth;
    int imgheight;
    int imgsave;

    void Generate_point(int x,int y,int id);
    void Generate_Ellipse(float x,float y,float rx,float ry,int id);

private:
    Ui::Canvas *ui;
    QPainter *painter;
    QImage *image;
    QVector<Point> Points;
    void paintEvent(QPaintEvent *);

private slots:
    void ReceiveResetCanvas();
    void ReceiveSaveCanvas(QString herit);
    void ReceiveSetColor(int R,int G,int B);
    void ReceiveDrawLine(int id,float x1,float y1,float x2,float y2,QString algorithm);
    void ReceiveDrawPolygon();//Todo
    void ReceiveDrawEllipse(int id,float x,float y,float rx,float ry);
    void ReceiveDrawCurve();//TODO
    void ReceiveTranslate(int id,float dx,float dy);
    void ReceiveRotate(int id,float x,float y,float r);
    void ReceiveScale(int id,float x,float y,float s);//TODO
    void ReceiveClip();//TODO
};

#endif // CANVAS_H
