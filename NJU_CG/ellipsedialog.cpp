#include "ellipsedialog.h"
#include "ui_ellipsedialog.h"

EllipseDialog::EllipseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EllipseDialog)
{
    ui->setupUi(this);
}

EllipseDialog::~EllipseDialog()
{
    delete ui;
}

void EllipseDialog::on_pushButton_clicked()
{
    id=ui->id_input->text().toInt();
    x=ui->x_input->text().toFloat();
    y=ui->y_input->text().toFloat();
    rx=ui->rx_input->text().toFloat();
    ry=ui->ry_input->text().toFloat();
    emit sendString(id,x,y,rx,ry);
    this->close();
}
