/********************************************************************************
** Form generated from reading UI file 'clipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPDIALOG_H
#define UI_CLIPDIALOG_H

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
    QLabel *x1;
    QLabel *y1;
    QLabel *x2;
    QLabel *y2;
    QLineEdit *id_input;
    QLineEdit *x1_input;
    QLineEdit *y1_input;
    QLineEdit *x2_input;
    QLineEdit *y2_input;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *algorithm_input;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        id = new QLabel(Dialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(110, 70, 54, 12));
        x1 = new QLabel(Dialog);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(110, 100, 54, 12));
        y1 = new QLabel(Dialog);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setGeometry(QRect(110, 130, 54, 12));
        x2 = new QLabel(Dialog);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(110, 160, 54, 12));
        y2 = new QLabel(Dialog);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setGeometry(QRect(110, 190, 54, 12));
        id_input = new QLineEdit(Dialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(130, 65, 113, 20));
        x1_input = new QLineEdit(Dialog);
        x1_input->setObjectName(QString::fromUtf8("x1_input"));
        x1_input->setGeometry(QRect(130, 97, 113, 20));
        y1_input = new QLineEdit(Dialog);
        y1_input->setObjectName(QString::fromUtf8("y1_input"));
        y1_input->setGeometry(QRect(130, 127, 113, 20));
        x2_input = new QLineEdit(Dialog);
        x2_input->setObjectName(QString::fromUtf8("x2_input"));
        x2_input->setGeometry(QRect(130, 157, 113, 20));
        y2_input = new QLineEdit(Dialog);
        y2_input->setObjectName(QString::fromUtf8("y2_input"));
        y2_input->setGeometry(QRect(130, 187, 113, 20));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 250, 75, 23));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 220, 54, 12));
        algorithm_input = new QLineEdit(Dialog);
        algorithm_input->setObjectName(QString::fromUtf8("algorithm_input"));
        algorithm_input->setGeometry(QRect(130, 217, 113, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        id->setText(QApplication::translate("Dialog", "id", nullptr));
        x1->setText(QApplication::translate("Dialog", "x1", nullptr));
        y1->setText(QApplication::translate("Dialog", "y1", nullptr));
        x2->setText(QApplication::translate("Dialog", "x2", nullptr));
        y2->setText(QApplication::translate("Dialog", "y2", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Confirm", nullptr));
        label->setText(QApplication::translate("Dialog", "algorithm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPDIALOG_H
