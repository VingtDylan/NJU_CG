#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QAction"
#include "QMenuBar"
#include "QStatusBar"
#include "QToolBar"
#include "QDebug"
#include "QTimer"
#include "QPainter"
#include "QSize"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //主窗口ui
    ui->setupUi(this);
    setWindowTitle(tr("CG_Design"));
    setFixedSize(this->width(), this->height());
    setGeometry(700,800,this->width(),this->height());
    //bash_Setting
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ReadCommand()));
    timer->start(100);
    commandCounter=-1;
    bashmode=nonemode;
    //Menu_Setting
    this->CreateCanvasIcon();
    //Point_INITIALIZE
//    for(int i=1;i<100;i++){
//        for(int j=1;j<100;j++){
//            struct DrawnPoint tmppoint;
//            tmppoint.x=i;
//            tmppoint.y=j;
//            DrawnPoints.push_back(tmppoint);
//        }
//    }
    Canvascounter=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReadCommand(){
    QString str = ui->textEdit->toPlainText();
    if(str.right(1)!='\n'&&str!=nullptr)
        qDebug() << "Commands:" << str;
    else if (str.right(1)=='\n') {
        ui->textEdit->setText("");
        if(CommandParse(str))
            ExecuteCommand();
    }
}

bool MainWindow::CommandParse(QString str)
{
//    1.重置画布：
//    resetCanvas width height
//    2.保存画布：
//    saveCanvas name
//    3.设置画笔颜色：
//    setColor R G B
//    4.绘制线段：
//    drawLine id x1 y1 x2 y2 algorithm
//    5.绘制多边形：
//    drawPolygon id n algorithm
//    x1 y1 x2 y2 … xn yn
//    6.绘制椭圆（中点圆生成算法）：
//    drawEllipse id x y rx ry
//    7.绘制曲线：
//    drawCurve id n algorithm
//    x1 y1 x2 y2 … xn yn
//    8.对图元平移：
//    translate id dx dy
//    9.对图元旋转：
//    rotate id x y r
//    10.对图元缩放：
//    rotate id x y s
//    11.对线段裁剪：
//    clip id x1 y1 x2 y2 algorithm
    commandCounter++;
    struct CommandsLine tmpcommand;
    tmpcommand.command=str;
    tmpcommand.commandId=commandCounter;

    if(str.left(11)=="resetCanvas"){
       str=str.left(str.length()-1);
       tmpcommand.CommandElements=str.split(" ");
       if(tmpcommand.CommandElements.length()==3){
          ui->textEdit2->setText(QString("width:")+tmpcommand.CommandElements[1]+QString("\t height:")+tmpcommand.CommandElements[2]);
          parser=true;
          bashmode=resetCanvas;
       }
       else{
          ui->textEdit2->setText("Invalid Command! Check again!");
          str+="  Invalid";
          parser=false;
          bashmode=nonemode;
          tmpcommand.command=str;
       }
    }else if(str.left(10)=="saveCanvas"){
       str=str.left(str.length()-1);
       tmpcommand.CommandElements=str.split(" ");
       if(tmpcommand.CommandElements.length()==2){
          ui->textEdit2->setText(QString("save as ")+tmpcommand.CommandElements[1]+QString(".bmp"));
          parser=true;
          bashmode=saveCanvas;
       }
       else{
          ui->textEdit2->setText("Invalid Command! Check again!");
          str+="  Invalid";
          parser=false;
          bashmode=nonemode;
          tmpcommand.command=str;
       }
    }else if(str.left(8)=="setColor"){
        str=str.left(str.length()-1);
        tmpcommand.CommandElements=str.split(" ");
        if(tmpcommand.CommandElements.length()==4){
           ui->textEdit2->setText(QString("new Color with RGB: R:")+tmpcommand.CommandElements[1]+QString(", G:")+tmpcommand.CommandElements[2]+QString(", B:")+tmpcommand.CommandElements[3]);
           parser=true;
           bashmode=setColor;
        }
        else{
           ui->textEdit2->setText("Invalid Command! Check again!");
           str+="  Invalid";
           parser=false;
           bashmode=nonemode;
           tmpcommand.command=str;
        }
    }else if(str.left(8)=="drawLine"){
       ui->textEdit2->setText(QString("Line has drawn"));
    }else if(str.left(11)=="drawPolygon"){
       ui->textEdit2->setText(QString("Polygon has drawn"));
    }else if(str.left(11)=="drawEllipse"){
       ui->textEdit2->setText(QString("Ellipse has drawn"));
    }else if(str.left(9)=="drawCurve"){
       ui->textEdit2->setText(QString("Curve has drawn"));
    }else if(str.left(9)=="translate"){
       ui->textEdit2->setText(QString("Translate has done"));
    }else if(str.left(6)=="rotate"){
//        if(){

//        }else {

//        }
    }else if(str.left(4)=="clip"){
       ui->textEdit2->setText("Cilp completed");
    }else{
       ui->textEdit2->setText("Invalid Command!");
       str+="  Invalid";
       tmpcommand.command=str;
    }
    CommandsLines.push_back(tmpcommand);
    if(parser)
        return true;
    return false;
}

void MainWindow::ExecuteCommand(){
    switch (bashmode) {
        case nonemode:break;
        case resetCanvas:ExecuteCommand_resetCanvas(); break;
        case saveCanvas:ExecuteCommand_saveCanvas();break;
        case setColor:ExecuteCommand_setColor(); break;
        case drawLine:break;
        case drawEllipse:break;
        case drawCurve:break;
        case drawPolygon:break;
        case translate:break;
        case rotate:break;
        case scale:break;
        case clip:break;
    }
}

void MainWindow::ExecuteCommand_resetCanvas()
{
    qDebug()<<"Command:resetCanvas";
    widgetList = QApplication::allWidgets();
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_1")
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textEdit2->setText("Invalid Command! Check again!(Hints:no such win!)");
    }
    else {
        int change_width = CommandsLines[commandCounter].CommandElements[1].toInt();
        int change_height = CommandsLines[commandCounter].CommandElements[2].toInt();
        widget->setGeometry(640,320,change_width,change_height);
        connect(this,SIGNAL(SendResetCanvas()),widget,SLOT(ReceiveResetCanvas()));
        emit SendResetCanvas();
    }
}

void MainWindow::ExecuteCommand_saveCanvas()
{
    qDebug()<<"Command:saveCanvas";
    widgetList = QApplication::allWidgets();
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_1")
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textEdit2->setText("Invalid Command! Check again!(Hints:no such win!)");
    }
    else {
        connect(this,SIGNAL(SendSaveCanvas(QString)),widget,SLOT(ReceiveSaveCanvas(QString)));
        emit SendSaveCanvas(CommandsLines[commandCounter].CommandElements[1]);
    }
}

void MainWindow::ExecuteCommand_setColor(){
    qDebug()<<"Command:setColor";
    widgetList = QApplication::allWidgets();
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_1")
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textEdit2->setText("Invalid Command! Check again!(Hints:no such win!)");
    }
    else {
        int R=CommandsLines[commandCounter].CommandElements[1].toInt();
        int G=CommandsLines[commandCounter].CommandElements[2].toInt();
        int B=CommandsLines[commandCounter].CommandElements[3].toInt();
        connect(this,SIGNAL(SendSetColor(int,int,int)),widget,SLOT(ReceiveSetColor(int,int,int)));
        emit SendSetColor(R,G,B);
    }
}

void MainWindow::open()
{
    //OpenGLDraw myOpenGLDraw;
    //myOpenGLDraw.On_Click_CreateCanvas();
    QMessageBox::information(this, tr("Information"), tr("Canvas created!"));
}

void MainWindow::CreateCanvasIcon()
{
    openAction = new QAction(QIcon(":/menu_icons/arrow"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);//快捷键
    openAction->setStatusTip(tr("Open an existing file"));//划过时的提示
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("&Home"));
    file->addAction(openAction);
    QToolBar *toolBar = addToolBar(tr("&Home"));
    toolBar->addAction(openAction);
    statusBar() ;
}

void MainWindow::on_pushButton_clicked()
{
    Canvascounter++;
    canvas = new  Canvas(Canvascounter);
    canvas->show();
}
