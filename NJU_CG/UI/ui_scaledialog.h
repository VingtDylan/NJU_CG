/********************************************************************************
** Form generated from reading UI file 'scaledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALEDIALOG_H
#define UI_SCALEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScaleDialog
{
public:
    QLabel *s;
    QLabel *id;
    QLabel *y;
    QPushButton *pushButton;
    QLineEdit *s_input;
    QLabel *x;
    QLineEdit *id_input;
    QLineEdit *y_input;
    QLineEdit *x_input;

    void setupUi(QDialog *ScaleDialog)
    {
        if (ScaleDialog->objectName().isEmpty())
            ScaleDialog->setObjectName(QString::fromUtf8("ScaleDialog"));
        ScaleDialog->resize(400, 300);
        s = new QLabel(ScaleDialog);
        s->setObjectName(QString::fromUtf8("s"));
        s->setGeometry(QRect(130, 120, 54, 12));
        id = new QLabel(ScaleDialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(130, 50, 54, 12));
        y = new QLabel(ScaleDialog);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(130, 150, 51, 20));
        pushButton = new QPushButton(ScaleDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 190, 75, 23));
        s_input = new QLineEdit(ScaleDialog);
        s_input->setObjectName(QString::fromUtf8("s_input"));
        s_input->setGeometry(QRect(150, 150, 113, 20));
        x = new QLabel(ScaleDialog);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(133, 80, 41, 20));
        id_input = new QLineEdit(ScaleDialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(150, 47, 113, 20));
        y_input = new QLineEdit(ScaleDialog);
        y_input->setObjectName(QString::fromUtf8("y_input"));
        y_input->setGeometry(QRect(150, 120, 113, 20));
        x_input = new QLineEdit(ScaleDialog);
        x_input->setObjectName(QString::fromUtf8("x_input"));
        x_input->setGeometry(QRect(150, 83, 113, 20));

        retranslateUi(ScaleDialog);

        QMetaObject::connectSlotsByName(ScaleDialog);
    } // setupUi

    void retranslateUi(QDialog *ScaleDialog)
    {
        ScaleDialog->setWindowTitle(QApplication::translate("ScaleDialog", "Dialog", nullptr));
        s->setText(QApplication::translate("ScaleDialog", "y:", nullptr));
        id->setText(QApplication::translate("ScaleDialog", "id", nullptr));
        y->setText(QApplication::translate("ScaleDialog", "s:", nullptr));
        pushButton->setText(QApplication::translate("ScaleDialog", "confirm", nullptr));
        x->setText(QApplication::translate("ScaleDialog", "x:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScaleDialog: public Ui_ScaleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALEDIALOG_H
