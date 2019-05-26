#include "rotatedialog.h"
#include "ui_rotatedialog.h"
RotateDialog::RotateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


RotateDialog::~RotateDialog()
{
    delete ui;
}

void RotateDialog::on_pushButton_clicked()
{
    id=ui->id_input->text().toInt();
    x=ui->x_input->text().toFloat();
    y=ui->y_input->text().toFloat();
    r=ui->r_input->text().toFloat();
    emit sendString(id,x,y,r);
    this->close();
}
