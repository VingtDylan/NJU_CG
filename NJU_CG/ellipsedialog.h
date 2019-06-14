#ifndef ELLIPSEDIALOG_H
#define ELLIPSEDIALOG_H

#include <QDialog>

namespace Ui {
class EllipseDialog;
}

class EllipseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EllipseDialog(QWidget *parent = nullptr);
    ~EllipseDialog();
signals:
    void sendString(int id,float x,float y,float rx,float ry);

private slots:
    void on_pushButton_clicked();

private:
    Ui::EllipseDialog *ui;
    int id;
    float x;
    float y;
    float rx;
    float ry;
};

#endif // ELLIPSEDIALOG_H




