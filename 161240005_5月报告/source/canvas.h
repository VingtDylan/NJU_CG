#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPushButton>

#define COMMONID 101

struct Point{
    int x;
    int y;
    int color[3];
    int size;
    int pid;
    bool chosen;
};

typedef enum{
    resetCanvas_,
    saveCanvas_,
    chooseID_,
    SetColor_,
    drawPoint_,
    drawLine_,
    drawPolygon_,
    drawFillPolygon_,
    drawEllipse_,
    drawCurve_,
    translate_,
    rotate_,
    scale_,
    clip_
}Mouse_Type;

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
    int tmpPencolor[3];//暂存画笔颜色
    int tmpChosePid;//暂存选中图元id
    int tmpChosenPos[2];//选中时的位置

    QString ImageSavePath;//图片存储路径，后续自定义用
    int imgwidth;
    int imgheight;
    int imgsave;

    QAction *actions[14];
        /*
         * 1.resetCanvas_
         * 2.saveCanvas_
         * 3.chooseID_
         * 4.SetColor_
         * 5.drawPoint_
         * 6.drawLine_
         * 7.drawPolygon_
         * 8.drawFillPolygon_
         * 9.drawEllipse_
         * 10.drawCurve_
         * 11.translate_
         * 12.rotate_
         * 13.scale_
         * 14.clip_
         * TODO_
        */
    Mouse_Type mouse=drawPoint_;

    double Factor(int n,int k);
    void Generate_point(int x,int y,int id);
    void Generate_Tmppoint(int x,int y,int id);
    void Generate_ColorTmppoint(int x,int y,int id,int color[]);
    void Generate_Bufferpoint(int x,int y,int id);
    void Generate_ColorBufferpoint(int x,int y,int id,int color[]);
    void Generate_Ellipse(float x,float y,float rx,float ry,int id);
    void Generate_Bezier(QVector<float>x,QVector<float>y,int id,int n,double t);

private:
    Ui::Canvas *ui;
    QPainter *painter;
    QImage *image;
    QDialog *mdialog;
    QVector<Point> Points;
    QVector<Point> TmpPoints;
    QVector<Point> BufferPoints;

    bool isDrawing;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void ReceiveResetCanvas();
    void ReceiveSaveCanvas(QString herit);
    void ReceiveSetColor(int R,int G,int B);
    void ReceiveDrawLine(int id,float x1,float y1,float x2,float y2,QString algorithm);
    //void ReceiveDrawPolygon(); extra
    void ReceiveDrawEllipse(int id,float x,float y,float rx,float ry);
    void ReceiveDrawCurve(int id,QVector<float>x,QVector<float>y,QString algorithm,int n);// B-spline TODO
    void ReceiveTranslate(int id,float dx,float dy);
    void ReceiveRotate(int id,float x,float y,float r);
    void ReceiveScale(int id,float x,float y,float s);
    void ReceiveClip();//TODO

    void ResetParams(QString width,QString height);
    void RotateParams(int id,float x,float y,float r);
    void ScaleParams(int id,float x,float y,float s);

    void resetCanvasTriggered();
    void saveCanvasTriggered();
    void chooseIDTriggered();
    void SetColorTriggered();
    void drawPointTriggered();
    void drawLineTriggered();
    void drawPolygonTriggered();
    void drawFillPolygonTriggered();
    void drawEllipseTriggered();
    void drawCurveTriggered();
    void translateTriggered();
    void rotateTriggered();
    void scaleTriggered();
    void clipTriggered();

    void drawBufferLine(int id,float x1,float y1,float x2,float y2);
    //void drawBufferPolygon(); extra

};

#endif // CANVAS_H
