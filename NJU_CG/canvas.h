#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

struct Edge{
    int ymax;
    int x;
    double dx;
    Edge *next;
};

struct Point{
    int x;
    int y;
    int color[3];
    int size;
    int pid;
    bool chosen;
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
    int currentPid;//画的图元???
    int currentPencolor[3];//画笔颜色
    int currentPointSize;//画笔的粗细

    QString ImageSavePath;//图片存储路径，后续自定义用
    int imgwidth;
    int imgheight;
    int imgsave;

private:
    Ui::Canvas *ui;
    QPainter *painter;
    QImage *image;
    std::vector<Point> Points;
    void paintEvent(QPaintEvent *);

private slots:
    void ReceiveResetCanvas();
    void ReceiveSaveCanvas(QString herit);
    void ReceiveSetColor(int R,int G,int B);

};

#endif // CANVAS_H
