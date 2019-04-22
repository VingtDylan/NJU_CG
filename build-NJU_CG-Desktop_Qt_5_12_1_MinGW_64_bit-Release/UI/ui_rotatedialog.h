/********************************************************************************
** Form generated from reading UI file 'rotatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTATEDIALOG_H
#define UI_ROTATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *id_input;
    QLineEdit *y_input;
    QLineEdit *x_input;
    QLineEdit *r_input;
    QPushButton *pushButton;
    QLabel *id;
    QLabel *x;
    QLabel *y;
    QLabel *r;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        id_input = new QLineEdit(Dialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(180, 70, 113, 20));
        y_input = new QLineEdit(Dialog);
        y_input->setObjectName(QString::fromUtf8("y_input"));
        y_input->setGeometry(QRect(180, 150, 113, 20));
        x_input = new QLineEdit(Dialog);
        x_input->setObjectName(QString::fromUtf8("x_input"));
        x_input->setGeometry(QRect(180, 110, 113, 20));
        r_input = new QLineEdit(Dialog);
        r_input->setObjectName(QString::fromUtf8("r_input"));
        r_input->setGeometry(QRect(180, 190, 113, 20));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 230, 75, 23));
        id = new QLabel(Dialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(160, 75, 54, 12));
        x = new QLabel(Dialog);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(160, 112, 54, 12));
        y = new QLabel(Dialog);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(160, 190, 51, 20));
        r = new QLabel(Dialog);
        r->setObjectName(QString::fromUtf8("r"));
        r->setGeometry(QRect(160, 153, 54, 12));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "confirm", nullptr));
        id->setText(QApplication::translate("Dialog", "id", nullptr));
        x->setText(QApplication::translate("Dialog", "x:", nullptr));
        y->setText(QApplication::translate("Dialog", "r:", nullptr));
        r->setText(QApplication::translate("Dialog", "y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTATEDIALOG_H
