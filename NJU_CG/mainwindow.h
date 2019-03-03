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

private slots:
    void open();
    void ReadCommand();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QAction *openAction;

    std::vector<CommandsLine> CommandsLines;
    int commandCounter;
    bool parser;
    commandmode bashmode;
    int Canvascounter;

signals:
    void SendResetCanvas();
    void SendSaveCanvas(QString str);
    void SendSetColor(int R,int G,int B);
};

#endif // MAINWINDOW_H
