#ifndef ROTATEDIALOG_H
#define ROTATEDIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class RotateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotateDialog(QWidget *parent = nullptr);
    ~RotateDialog();
signals:
    void sendString(int id,float x,float y,float r);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    int id;
    float x;
    float y;
    float r;
};

#endif // ROTATEDIALOG_H
