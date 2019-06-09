#ifndef CLIPDIALOG_H
#define CLIPDIALOG_H

#include <QDialog>

namespace Ui {
class ClipDialog;
}

class ClipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClipDialog(QWidget *parent = nullptr);
    ~ClipDialog();

signals:
    void sendString(int id,float x1,float y1,float x2,float y2,QString algorithm);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ClipDialog *ui;
    int id;
    float x1;
    float y1;
    float x2;
    float y2;
    QString algorithm;
};
#endif // CLIPDIALOG_H
