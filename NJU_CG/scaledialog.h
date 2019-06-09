#ifndef SCALEDIALOG_H
#define SCALEDIALOG_H

#include <QDialog>

namespace Ui {
class ScaleDialog;
}

class ScaleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScaleDialog(QWidget *parent = nullptr);
    ~ScaleDialog();

signals:
    void sendString(int id,float x,float y,float s);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScaleDialog *ui;
    int id;
    float x;
    float y;
    float s;
};

#endif // SCALEDIALOG_H


