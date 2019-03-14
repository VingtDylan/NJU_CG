#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include <QString>
#include <canvas.h>
#include <canvascommand.h>

namespace Ui {
class MainWindow;
}

struct CommandsLine{
    QString command;
    int commandId;
    int canvascommandId;
    QStringList CommandElements;
};

typedef enum{
    nonemode,
    inputCommand,
    outputCommand,
    listCommand,
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
    QString commandlists;

    void CreateCanvasIcon();
    bool CommandParse(QString str);
    void ExecuteCommand();
    void ExecuteCommand_InputCommand();
    void ExecuteCommand_OutputCommand();
    void ExecuteCommand_ListCommand();
    void ExecuteCommand_resetCanvas();
    void ExecuteCommand_saveCanvas();
    void ExecuteCommand_setColor();
    void ExecuteCommand_drawLine();
    void ExecuteCommand_drawPolygon();//TODO
    void ExecuteCommand_drawEllipse();
    void ExecuteCommand_drawCurve();//TODO
    void ExecuteCommand_translate();
    void ExecuteCommand_rotate();
    void ExecuteCommand_Scale();
    void ExecuteCommand_Clip();//TODO

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
    bool canvas_selector;
    commandmode bashmode;
    int Canvascounter;
    int currentcommand;

    //void keyPressEvent(QKeyEvent *event);

signals:
    void SendListCommand(QString commandlists);
    void SendResetCanvas();
    void SendSaveCanvas(QString str);
    void SendSetColor(int R,int G,int B);
    void SendDrawLine(int id,float x1,float y1,float x2,float y2,QString algorithm);
    //void SendDrawPolygon(int id,float x[],float y[],QString algorithm);  extra
    void SendDrawEllipse(int id,float x,float y,float rx,float ry);
    void SendDrawCurve();//TODO
    void SendTranslate(int id,float dx,float dy);
    void SendRotate(int id,float x,float y,float r);
    void SendScale(int id,float x,float y,float s);//TODO
    void SendClip();//TODO
};
#endif // MAINWINDOW_H
