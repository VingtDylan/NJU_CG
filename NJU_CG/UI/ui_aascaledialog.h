/********************************************************************************
** Form generated from reading UI file 'aascaledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AASCALEDIALOG_H
#define UI_AASCALEDIALOG_H

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
    QLabel *id;
    QLineEdit *id_input;
    QLabel *y;
    QLineEdit *x_input;
    QLabel *x;
    QPushButton *pushButton;
    QLabel *s;
    QLineEdit *y_input;
    QLineEdit *s_input;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        id = new QLabel(Dialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(170, 55, 54, 12));
        id_input = new QLineEdit(Dialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(190, 50, 113, 20));
        y = new QLabel(Dialog);
        y->setObjectName(QString::fromUtf8("y"));
        y->setGeometry(QRect(175, 190, 51, 20));
        x_input = new QLineEdit(Dialog);
        x_input->setObjectName(QString::fromUtf8("x_input"));
        x_input->setGeometry(QRect(190, 100, 113, 20));
        x = new QLabel(Dialog);
        x->setObjectName(QString::fromUtf8("x"));
        x->setGeometry(QRect(175, 105, 54, 12));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 230, 75, 23));
        s = new QLabel(Dialog);
        s->setObjectName(QString::fromUtf8("s"));
        s->setGeometry(QRect(175, 145, 54, 12));
        y_input = new QLineEdit(Dialog);
        y_input->setObjectName(QString::fromUtf8("y_input"));
        y_input->setGeometry(QRect(190, 140, 113, 20));
        s_input = new QLineEdit(Dialog);
        s_input->setObjectName(QString::fromUtf8("s_input"));
        s_input->setGeometry(QRect(190, 190, 113, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        id->setText(QApplication::translate("Dialog", "id", nullptr));
        y->setText(QApplication::translate("Dialog", "s:", nullptr));
        x->setText(QApplication::translate("Dialog", "x:", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "confirm", nullptr));
        s->setText(QApplication::translate("Dialog", "y:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AASCALEDIALOG_H
