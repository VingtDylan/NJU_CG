#include "canvascommand.h"
#include "ui_canvascommand.h"

CanvasCommand::CanvasCommand(QString id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasCommand)
{
    ui->setupUi(this);
    setWindowTitle("CanvasCommand_"+id);
}

CanvasCommand::~CanvasCommand()
{
    delete ui;
}

void CanvasCommand::ReceiveListCommand(QString commandlists){
    ui->textBrowser->setText(commandlists);
}
