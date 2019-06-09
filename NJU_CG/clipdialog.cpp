#include "clipdialog.h"
#include "ui_clipdialog.h"

ClipDialog::ClipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClipDialog)
{
    ui->setupUi(this);
}

ClipDialog::~ClipDialog()
{
    delete ui;
}

void ClipDialog::on_pushButton_clicked()
{
    id=ui->id_input->text().toInt();
    x1=ui->x1_input->text().toFloat();
    y1=ui->y1_input->text().toFloat();
    x2=ui->x2_input->text().toFloat();
    y2=ui->y2_input->text().toFloat();
    algorithm=ui->algorithm_input->text();
    emit sendString(id,x1,y1,x2,y2,algorithm);
    this->close();
}
