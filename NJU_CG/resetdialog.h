#ifndef DIALOG_H_
#define RESET_DIALOG_H_

#include <QDialog>

namespace Ui {
    class Dialog;
}


class ResetDialog : public QDialog
{
    Q_OBJECT


public:
    explicit ResetDialog(QWidget *parent = nullptr);
    ~ResetDialog();
signals:
    void sendString(QString width,QString height);

private slots:
    void on_pushButton_clicked();


private:
    Ui::Dialog *ui;
    QString Params[2];
};


#endif // DIALOG_H
