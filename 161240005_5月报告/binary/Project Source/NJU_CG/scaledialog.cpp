#include "scaledialog.h"
#include "ui_scaledialog.h"
ScaleDialog::ScaleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}


ScaleDialog::~ScaleDialog()
{
    delete ui;
}

void ScaleDialog::on_pushButton_clicked()
{
    id=ui->id_input->text().toInt();
    x=ui->x_input->text().toFloat();
    y=ui->y_input->text().toFloat();
    s=ui->s_input->text().toFloat();
    emit sendString(id,x,y,s);
    this->close();
}
