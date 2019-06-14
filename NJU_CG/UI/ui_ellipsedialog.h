/********************************************************************************
** Form generated from reading UI file 'ellipsedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELLIPSEDIALOG_H
#define UI_ELLIPSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EllipseDialog
{
public:
    QLineEdit *id_input;
    QLineEdit *x_input;
    QLineEdit *y_input;
    QLineEdit *rx_input;
    QLineEdit *ry_input;
    QPushButton *pushButton;
    QLabel *id;
    QLabel *x;
    QLabel *y;
    QLabel *rx;
    QLabel *ry;

    void setupUi(QDialog *EllipseDialog)
    {
        if (EllipseDialog->objectName().isEmpty())
            EllipseDialog->setObjectName(QString::fromUtf8("EllipseDialog"));
        EllipseDialog->resize(400, 300);
        id_input = new QLineEdit(EllipseDialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(160, 50, 113, 20));
        x_input = new QLineEdit(EllipseDialog);
        x_input->setObjectName(QString::fromUtf8("x_input"));
        x_input->setGeometry(QRect(160, 80, 113, 20));
        y_input = new QLineEdit(EllipseDialog);
        y_input->setObjectName(QString::fromUtf8("y_input"));
        y_input->setGeometry(QRect(160, 110, 113, 20));
        rx_input = new QLineEdit(EllipseDialog);
        rx_input->setObjectName(QString::fromUtf8("rx_input"));
        rx_input->setGeometry(QRect(160, 140, 113, 20));
        ry_input = new QLineEdit(EllipseDialog);
        ry_input->setObjectName(QString::fromUtf8("ry_input"));
        ry_input->setGeometry(QRect(160, 170, 113, 20));
        pushButton = new QPushButton(EllipseDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 210, 75, 23));
        id = new QLabel(EllipseDialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(130, 53, 54, 12));
        x = new QLabel(EllipseDialog);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(135, 83, 54, 12));
        y = new QLabel(EllipseDialog);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(135, 115, 54, 12));
        rx = new QLabel(EllipseDialog);
        rx->setObjectName(QString::fromUtf8("rx"));
        rx->setGeometry(QRect(135, 145, 54, 12));
        ry = new QLabel(EllipseDialog);
        ry->setObjectName(QString::fromUtf8("ry"));
        ry->setGeometry(QRect(135, 173, 54, 12));

        retranslateUi(EllipseDialog);

        QMetaObject::connectSlotsByName(EllipseDialog);
    } // setupUi

    void retranslateUi(QDialog *EllipseDialog)
    {
        EllipseDialog->setWindowTitle(QApplication::translate("EllipseDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("EllipseDialog", "Confirm", nullptr));
        id->setText(QApplication::translate("EllipseDialog", "id", nullptr));
        x->setText(QApplication::translate("EllipseDialog", "x", nullptr));
        y->setText(QApplication::translate("EllipseDialog", "y", nullptr));
        rx->setText(QApplication::translate("EllipseDialog", "rx", nullptr));
        ry->setText(QApplication::translate("EllipseDialog", "ry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EllipseDialog: public Ui_EllipseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELLIPSEDIALOG_H
