#include "resetdialog.h"
#include "ui_resetdialog.h"
ResetDialog::ResetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


ResetDialog::~ResetDialog()
{
    delete ui;
}

void ResetDialog::on_pushButton_clicked()
{
    Params[0] = ui->width_input->text();
    Params[1] = ui->height_input->text();
    emit sendString(Params[0],Params[1]);
    this->close();
}
