#include "canvascommand.h"
#include "ui_canvascommand.h"

CanvasCommand::CanvasCommand(QString id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CanvasCommand)
{
    ui->setupUi(this);
    setWindowTitle("CanvasCommand_"+id);

    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(":/menu_icons/list").scaled(
                this->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));
    this->setPalette(palette);

    ui->textBrowser->viewport()->setAutoFillBackground(false);
    ui->textBrowser->setFrameStyle(QFrame::NoFrame);

    ui->textBrowser_2->viewport()->setAutoFillBackground(false);
    ui->textBrowser_2->setFrameStyle(QFrame::NoFrame);

}

CanvasCommand::~CanvasCommand()
{
    delete ui;
}

void CanvasCommand::ReceiveListCommand(QString commandlists){
    ui->textBrowser->setText(commandlists);
}
