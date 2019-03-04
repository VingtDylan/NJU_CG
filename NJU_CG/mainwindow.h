#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include <QString>
#include <canvas.h>

namespace Ui {
class MainWindow;
}

struct CommandsLine{
    QString command;
    int commandId;
    QStringList CommandElements;
};

typedef enum{
    nonemode,
    resetCanvas,
    saveCanvas,
    setColor,
    drawLine,
    drawPolygon,
    drawEllipse,
    drawCurve,
    translate,
    rotate,
    scale,
    clip
}commandmode;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Canvas *canvas;
    QWidgetList widgetList;
    QWidget *widget=nullptr;

    void CreateCanvasIcon();
    bool CommandParse(QString str);
    void ExecuteCommand();
    void ExecuteCommand_resetCanvas();
    void ExecuteCommand_saveCanvas();
    void ExecuteCommand_setColor();
    void ExecuteCommand_drawLine();
    void ExecuteCommand_drawPolygon();//Todo
    void ExecuteCommand_drawEllipse();

private slots:
    void open();
    void ReadCommand();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAction *openAction;

    QVector<CommandsLine> CommandsLines;
    int commandCounter;
    bool parser;
    commandmode bashmode;
    int Canvascounter;

signals:
    void SendResetCanvas();
    void SendSaveCanvas(QString str);
    void SendSetColor(int R,int G,int B);
    void SendDrawLine(int id,float x1,float y1,float x2,float y2,QString algorithm);
    void SendDrawPolygon();//TODO
    void SendDrawEllipse(int id,float x,float y,float rx,float ry);
};

#endif // MAINWINDOW_H
