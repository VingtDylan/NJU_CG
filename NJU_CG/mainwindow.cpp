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
#include "canvascommand.h"
#include "QKeyEvent"
#include "QFile"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //主窗口ui
    ui->setupUi(this);
    setWindowTitle(tr("CG_Design"));
    setFixedSize(this->width(), this->height());
    setGeometry(300,200,this->width(),this->height());
    ui->textEdit->setPlaceholderText("此处输入命令");
    ui->textBrowser->setPlaceholderText("运行结果显示");
    //bash_Setting
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ReadCommand()));
    timer->start(100);
    commandCounter=-1;
    bashmode=nonemode;
    //Menu_Setting
    this->CreateCanvasIcon();
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
    commandCounter++;
    struct CommandsLine tmpcommand;
    tmpcommand.command=str;
    tmpcommand.commandId=commandCounter+1;
    tmpcommand.canvascommandId=1;//will be improved!
    currentcommand=commandCounter;
    str=str.left(str.length()-1);
    tmpcommand.CommandElements=str.split(" ");
    if(tmpcommand.CommandElements[0]=="input"){
        if(tmpcommand.CommandElements.length()==2){
           ui->textBrowser->setText("Commands input from text");
           parser=true;
           bashmode=inputCommand;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==3){
           ui->textBrowser->setText("Commands input from text will be executed in-->>"+QString(" Canvas")+tmpcommand.CommandElements[2]);
           parser=true;
           bashmode=inputCommand;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[2].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="output"){
        if(tmpcommand.CommandElements.length()==2){
           ui->textBrowser->setText("Commands output from text");
           parser=true;
           bashmode=outputCommand;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==3){
           ui->textBrowser->setText("Commands output from text will be executed in-->>"+QString(" Canvas")+tmpcommand.CommandElements[2]);
           parser=true;
           bashmode=outputCommand;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[2].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="list"){
        if(tmpcommand.CommandElements.length()==1){
           ui->textBrowser->setText("Commands will be listed");
           parser=true;
           bashmode=listCommand;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==2){
           ui->textBrowser->setText("Commands will be listed in-->>"+QString(" Canvas")+tmpcommand.CommandElements[1]);
           parser=true;
           bashmode=listCommand;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[1].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="resetCanvas"){
       if(tmpcommand.CommandElements.length()==3){
          ui->textBrowser->setText(QString("width:")+tmpcommand.CommandElements[1]+QString("\t height:")+tmpcommand.CommandElements[2]);
          parser=true;
          bashmode=resetCanvas;
          canvas_selector=false;
       }else if(tmpcommand.CommandElements.length()==4){
          ui->textBrowser->setText(QString("width:")+tmpcommand.CommandElements[1]+QString("\t height:")+tmpcommand.CommandElements[2]+QString(" executed in canvas ")+tmpcommand.CommandElements[3]);
          parser=true;
          bashmode=resetCanvas;
          canvas_selector=true;
          tmpcommand.canvascommandId=tmpcommand.CommandElements[3].toInt();
       }
       else{
          ui->textBrowser->setText("Invalid Command! Check again!");
          str+=" Invalid\n";
          parser=false;
          bashmode=nonemode;
          canvas_selector=false;
          tmpcommand.command=str;
       }
    }else if(tmpcommand.CommandElements[0]=="saveCanvas"){
       if(tmpcommand.CommandElements.length()==2){
          ui->textBrowser->setText(QString("save as ")+tmpcommand.CommandElements[1]+QString(".bmp"));
          parser=true;
          bashmode=saveCanvas;
          canvas_selector=false;
       }else if(tmpcommand.CommandElements.length()==3){
          ui->textBrowser->setText(QString("save as ")+tmpcommand.CommandElements[1]+QString(".bmp")+QString(" executed in canvas ")+tmpcommand.CommandElements[2]);
          parser=true;
          bashmode=saveCanvas;
          canvas_selector=true;
          tmpcommand.canvascommandId=tmpcommand.CommandElements[2].toInt();
       }else{
          ui->textBrowser->setText("Invalid Command! Check again!");
          str+=" Invalid\n";
          parser=false;
          bashmode=nonemode;
          canvas_selector=false;
          tmpcommand.command=str;
       }
    }else if(tmpcommand.CommandElements[0]=="setColor"){
        if(tmpcommand.CommandElements.length()==4){
           ui->textBrowser->setText(QString("new Color with RGB: R:")+tmpcommand.CommandElements[1]+QString(", G:")+tmpcommand.CommandElements[2]+QString(", B:")+tmpcommand.CommandElements[3]);
           parser=true;
           bashmode=setColor;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==5){
           ui->textBrowser->setText(QString("new Color with RGB: R:")+tmpcommand.CommandElements[1]+QString(", G:")+tmpcommand.CommandElements[2]+QString(", B:")+tmpcommand.CommandElements[3]+QString(" executed in canvas ")+tmpcommand.CommandElements[4]);
           parser=true;
           bashmode=setColor;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[4].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="drawLine"){
        if(tmpcommand.CommandElements.length()==7){
           ui->textBrowser->setText(QString("Line has drawn"));
           parser=true;
           bashmode=drawLine;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==8){
           ui->textBrowser->setText(QString("Line has drawn")+QString(" executed in canvas ")+tmpcommand.CommandElements[7]);
           parser=true;
           bashmode=drawLine;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[7].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="drawPolygon"){
        int pointsCounter=tmpcommand.CommandElements[2].toInt();
        if(tmpcommand.CommandElements.length()==4+2*pointsCounter){
           ui->textBrowser->setText(QString("Polygon has drawn"));
           parser=true;
           bashmode=drawPolygon;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==4+2*pointsCounter+1){
           ui->textBrowser->setText(QString("Polygon has drawn")+QString(" executed in canvas ")+tmpcommand.CommandElements[4+2*pointsCounter]);
           parser=true;
           bashmode=drawPolygon;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[4+2*pointsCounter].toInt();
        }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="drawEllipse"){
        if(tmpcommand.CommandElements.length()==6){
           ui->textBrowser->setText(QString("Ellipse has drawn"));
           parser=true;
           bashmode=drawEllipse;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==7){
           ui->textBrowser->setText(QString("Ellipse has drawn")+QString(" executed in canvas ")+tmpcommand.CommandElements[6]);
           parser=true;
           bashmode=drawEllipse;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[6].toInt();
         }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="drawCurve"){
       int pointsCounter=tmpcommand.CommandElements[2].toInt();
       if(tmpcommand.CommandElements.length()==4+2*pointsCounter){
          ui->textBrowser->setText(QString("Curve has drawn"));
          parser=true;
          bashmode=drawPolygon;
          canvas_selector=false;
       }else if(tmpcommand.CommandElements.length()==4+2*pointsCounter+1){
          ui->textBrowser->setText(QString("Curve has drawn")+QString(" executed in canvas ")+tmpcommand.CommandElements[4+2*pointsCounter]);
          parser=true;
          bashmode=drawPolygon;
          canvas_selector=true;
          tmpcommand.canvascommandId=tmpcommand.CommandElements[4+2*pointsCounter].toInt();
       }else{
          ui->textBrowser->setText("Invalid Command! Check again!");
          str+=" Invalid\n";
          parser=false;
          bashmode=nonemode;
          canvas_selector=false;
          tmpcommand.command=str;
       }
    }else if(tmpcommand.CommandElements[0]=="translate"){
        if(tmpcommand.CommandElements.length()==4){
           ui->textBrowser->setText(QString("Translate has done"));
           parser=true;
           bashmode=translate;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==5){
           ui->textBrowser->setText(QString("Translate has done")+QString(" executed in canvas ")+tmpcommand.CommandElements[4]);
           parser=true;
           bashmode=translate;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[4].toInt();
         }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="rotate"){
        if(tmpcommand.CommandElements.length()==5){
           ui->textBrowser->setText("Rotate completed");
           parser=true;
           bashmode=rotate;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==6){
           ui->textBrowser->setText(QString("Rotate completed")+QString(" executed in canvas ")+tmpcommand.CommandElements[5]);
           parser=true;
           bashmode=rotate;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[5].toInt();
         }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="scale"){
        if(tmpcommand.CommandElements.length()==5){
           ui->textBrowser->setText("Scale completed");
           parser=true;
           bashmode=scale;
           canvas_selector=false;
        }else if(tmpcommand.CommandElements.length()==6){
           ui->textBrowser->setText(QString("Scale completed")+QString(" executed in canvas ")+tmpcommand.CommandElements[5]);
           parser=true;
           bashmode=scale;
           canvas_selector=true;
           tmpcommand.canvascommandId=tmpcommand.CommandElements[5].toInt();
         }else{
           ui->textBrowser->setText("Invalid Command! Check again!");
           str+=" Invalid\n";
           parser=false;
           bashmode=nonemode;
           canvas_selector=false;
           tmpcommand.command=str;
        }
    }else if(tmpcommand.CommandElements[0]=="clip"){
       ui->textBrowser->setText("Cilp completed");
    }else{
       ui->textBrowser->setText("Invalid Command!");
       str+=" Invalid\n";
       bashmode=nonemode;
       canvas_selector=false;
       tmpcommand.command=str;
    }
    CommandsLines.push_back(tmpcommand);
    if(parser)
        return true;
    return false;
}

void MainWindow::ExecuteCommand(){
    switch (bashmode) {
        case nonemode:
                    break;
        case inputCommand:
                    ExecuteCommand_InputCommand();
                    break;
        case outputCommand:
                    ExecuteCommand_OutputCommand();
                    break;
        case listCommand:
                    ExecuteCommand_ListCommand();
                    break;
        case resetCanvas:
                    ExecuteCommand_resetCanvas();
                    break;
        case saveCanvas:
                    ExecuteCommand_saveCanvas();
                    break;
        case setColor:
                    ExecuteCommand_setColor();
                    break;
        case drawLine:
                    ExecuteCommand_drawLine();
                    break;
        case drawPolygon:
                    ExecuteCommand_drawPolygon();
                    break;
        case drawEllipse:
                    ExecuteCommand_drawEllipse();
                    break;
        case drawCurve:
                    ExecuteCommand_drawCurve();
                    break;
        case translate:
                    ExecuteCommand_translate();
                    break;
        case rotate:
                    ExecuteCommand_rotate();
                    break;
        case scale:
                    ExecuteCommand_Scale();
                    break;
        case clip:
                    ExecuteCommand_Clip();
                    break;
    }
}

//画布映射 TODO

void MainWindow::ExecuteCommand_InputCommand(){
    qDebug()<<"Command:InputCommand";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[2];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        QFile file("../NJU_CG/scripts/"+CommandsLines[commandCounter].CommandElements[1]+QString(".txt"));
        if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
            while(!file.atEnd()){
                QByteArray line=file.readLine();
                QString command(line);
                if(command.right(1)!='\n')
                    command.append('\n');
                if(CommandParse(command))
                    ExecuteCommand();
            }
            file.close();
        }
    }
}

void MainWindow::ExecuteCommand_OutputCommand(){
    qDebug()<<"Command:OutputCommand";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[2];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        QFile file("../NJU_CG/scripts/"+CommandsLines[commandCounter].CommandElements[1]+QString(".txt"));
        if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
            QTextStream stream(&file);
            stream.seek(0);
            file.flush();
            for(int i=0;i<CommandsLines.size();i++){
                QString qsoutput;
                qsoutput.append(QString::number(CommandsLines[i].commandId)+QString(":->>>: ")+CommandsLines[i].command);
                stream<<qsoutput;
            }
            file.close();
        }
    }
}

void MainWindow::ExecuteCommand_ListCommand(){
    qDebug()<<"Command:ListCommand";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[1];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="CanvasCommand_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        widget = new CanvasCommand(executeCanvas);
        widget->show();
    }
    QString lists="";
    for(int i=0;i<CommandsLines.size();i++){
        if(CommandsLines[i].canvascommandId==executeCanvas.toInt()){
            lists=lists+" "+QString::number(CommandsLines[i].commandId)+":"+CommandsLines[i].command+"\n";
        }
    }
    connect(this,SIGNAL(SendListCommand(QString)),widget,SLOT(ReceiveListCommand(QString)));
    emit SendListCommand(lists);
    disconnect(this,SIGNAL(SendListCommand(QString)),widget,SLOT(ReceiveListCommand(QString)));

}

void MainWindow::ExecuteCommand_resetCanvas()
{
    qDebug()<<"Command:resetCanvas";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[3];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int change_width = CommandsLines[commandCounter].CommandElements[1].toInt();
        int change_height = CommandsLines[commandCounter].CommandElements[2].toInt();
        widget->setGeometry(640,320,change_width,change_height);
        connect(this,SIGNAL(SendResetCanvas()),widget,SLOT(ReceiveResetCanvas()));
        emit SendResetCanvas();
        disconnect(this,SIGNAL(SendResetCanvas()),widget,SLOT(ReceiveResetCanvas()));
    }
}

void MainWindow::ExecuteCommand_saveCanvas()
{
    qDebug()<<"Command:saveCanvas";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[2];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        connect(this,SIGNAL(SendSaveCanvas(QString)),widget,SLOT(ReceiveSaveCanvas(QString)));
        emit SendSaveCanvas(CommandsLines[commandCounter].CommandElements[1]);
        disconnect(this,SIGNAL(SendSaveCanvas(QString)),widget,SLOT(ReceiveSaveCanvas(QString)));
    }
}

void MainWindow::ExecuteCommand_setColor(){
    qDebug()<<"Command:setColor";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[4];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int R=CommandsLines[commandCounter].CommandElements[1].toInt();
        int G=CommandsLines[commandCounter].CommandElements[2].toInt();
        int B=CommandsLines[commandCounter].CommandElements[3].toInt();
        connect(this,SIGNAL(SendSetColor(int,int,int)),widget,SLOT(ReceiveSetColor(int,int,int)));
        emit SendSetColor(R,G,B);
        disconnect(this,SIGNAL(SendSetColor(int,int,int)),widget,SLOT(ReceiveSetColor(int,int,int)));

    }
}

void MainWindow::ExecuteCommand_drawLine(){
    qDebug()<<"Command:drawLine";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[7];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x1=CommandsLines[commandCounter].CommandElements[2].toFloat();
        float y1=CommandsLines[commandCounter].CommandElements[3].toFloat();
        float x2=CommandsLines[commandCounter].CommandElements[4].toFloat();
        float y2=CommandsLines[commandCounter].CommandElements[5].toFloat();
        QString algorithm=CommandsLines[commandCounter].CommandElements[6];
        connect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));
        emit SendDrawLine(id,x1,y1,x2,y2,algorithm);
        disconnect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));

    }
}

void MainWindow::ExecuteCommand_drawPolygon(){
    qDebug()<<"Command:drawPolygon";
    QString executeCanvas="1";
    int n=CommandsLines[commandCounter].CommandElements[2].toInt();
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[4+2*n];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x1,y1,x2,y2;
        QString algorithm=CommandsLines[commandCounter].CommandElements[3];
        for(int i=1;i<=n;i++){
            x1=CommandsLines[commandCounter].CommandElements[2+2*i].toFloat();
            y1=CommandsLines[commandCounter].CommandElements[3+2*i].toFloat();
            x2=CommandsLines[commandCounter].CommandElements[4+(2*i)%(2*n)].toFloat();
            y2=CommandsLines[commandCounter].CommandElements[4+(1+2*i)%(2*n)].toFloat();
            connect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));
            emit SendDrawLine(id,x1,y1,x2,y2,algorithm);
            disconnect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));
        }
    }
}

void MainWindow::ExecuteCommand_drawEllipse(){
    qDebug()<<"Command:Ellipse";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[6];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x=CommandsLines[commandCounter].CommandElements[2].toFloat();
        float y=CommandsLines[commandCounter].CommandElements[3].toFloat();
        float rx=CommandsLines[commandCounter].CommandElements[4].toFloat();
        float ry=CommandsLines[commandCounter].CommandElements[5].toFloat();
        connect(this,SIGNAL(SendDrawEllipse(int,float,float,float,float)),widget,SLOT(ReceiveDrawEllipse(int,float,float,float,float)));
        emit SendDrawEllipse(id,x,y,rx,ry);
        disconnect(this,SIGNAL(SendDrawEllipse(int,float,float,float,float)),widget,SLOT(ReceiveDrawEllipse(int,float,float,float,float)));
    }
}

void MainWindow::ExecuteCommand_drawCurve(){
    qDebug()<<"Command:drawCurve";
    QString executeCanvas="1";
    int n=CommandsLines[commandCounter].CommandElements[2].toInt();
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[4+2*n];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x1,y1,x2,y2;
        QString algorithm=CommandsLines[commandCounter].CommandElements[3];
        for(int i=1;i<=n;i++){
            x1=CommandsLines[commandCounter].CommandElements[2+2*i].toFloat();
            y1=CommandsLines[commandCounter].CommandElements[3+2*i].toFloat();
            x2=CommandsLines[commandCounter].CommandElements[4+(2*i)%(2*n)].toFloat();
            y2=CommandsLines[commandCounter].CommandElements[4+(1+2*i)%(2*n)].toFloat();
            connect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));
            emit SendDrawLine(id,x1,y1,x2,y2,algorithm);
            disconnect(this,SIGNAL(SendDrawLine(int,float,float,float,float,QString)),widget,SLOT(ReceiveDrawLine(int,float,float,float,float,QString)));
        }
    }
}

void MainWindow::ExecuteCommand_translate(){
    qDebug()<<"Command:translate";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[4];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float dx=CommandsLines[commandCounter].CommandElements[2].toFloat();
        float dy=CommandsLines[commandCounter].CommandElements[3].toFloat();
        connect(this,SIGNAL(SendTranslate(int,float,float)),widget,SLOT(ReceiveTranslate(int,float,float)));
        emit SendTranslate(id,dx,dy);
        disconnect(this,SIGNAL(SendTranslate(int,float,float)),widget,SLOT(ReceiveTranslate(int,float,float)));
    }
}

void MainWindow::ExecuteCommand_rotate(){
    qDebug()<<"Command:rotate";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[5];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x=CommandsLines[commandCounter].CommandElements[2].toFloat();
        float y=CommandsLines[commandCounter].CommandElements[3].toFloat();
        float r=CommandsLines[commandCounter].CommandElements[4].toFloat();
        connect(this,SIGNAL(SendRotate(int,float,float,float)),widget,SLOT(ReceiveRotate(int,float,float,float)));
        emit SendRotate(id,x,y,r);
        disconnect(this,SIGNAL(SendRotate(int,float,float,float)),widget,SLOT(ReceiveRotate(int,float,float,float)));
    }
}

void MainWindow::ExecuteCommand_Scale(){
    qDebug()<<"Command:scale";
    QString executeCanvas="1";
    if(canvas_selector){
        executeCanvas=CommandsLines[commandCounter].CommandElements[5];
        canvas_selector=false;
    }
    widgetList = QApplication::allWidgets();
    widget=nullptr;
    for(int i=0;i<widgetList.length();i++){
        if(widgetList.at(i)->windowTitle()=="Canvas_"+executeCanvas)
            widget=widgetList.at(i);
    }
    if(widget==nullptr){
        ui->textBrowser->setText("Invalid Command! Check again!(Hints:no such win!)");
    }else {
        int id=CommandsLines[commandCounter].CommandElements[1].toInt();
        float x=CommandsLines[commandCounter].CommandElements[2].toFloat();
        float y=CommandsLines[commandCounter].CommandElements[3].toFloat();
        float s=CommandsLines[commandCounter].CommandElements[4].toFloat();
        connect(this,SIGNAL(SendScale(int,float,float,float)),widget,SLOT(ReceiveScale(int,float,float,float)));
        emit SendScale(id,x,y,s);
        disconnect(this,SIGNAL(SendScale(int,float,float,float)),widget,SLOT(ReceiveScale(int,float,float,float)));
    }
}

void MainWindow::ExecuteCommand_Clip(){
    //TODO
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
    QMenu *file = menuBar()->addMenu(tr("&New"));
    file->addAction(openAction);
    QToolBar *toolBar = addToolBar(tr("&New"));
    toolBar->addAction(openAction);
    statusBar() ;
}

void MainWindow::on_pushButton_clicked()
{
    Canvascounter++;
    canvas = new  Canvas(Canvascounter);
    canvas->show();
}

//void MainWindow::keyPressEvent(QKeyEvent *event){
//    if(event->key()==Qt::Key_Up){
//        ui->textBrowser->setText("");
//        if(currentcommand>0)
//            ui->lineEdit->setText(CommandsLines[--currentcommand].command);
//        else
//            ui->lineEdit->setText("No previous command!");
//    }
//    if(event->key()==Qt::Key_Down){
//        ui->textBrowser->setText("");
//        if(currentcommand>=0&&currentcommand<commandCounter)
//            ui->lineEdit->setText(CommandsLines[++currentcommand].command);
//        else
//            ui->lineEdit->setText("No later command!");
//    }
//}
