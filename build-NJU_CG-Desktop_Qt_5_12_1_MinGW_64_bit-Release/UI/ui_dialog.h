/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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
    QLabel *width_label;
    QLabel *height_label;
    QLineEdit *width_input;
    QLineEdit *height_input;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        width_label = new QLabel(Dialog);
        width_label->setObjectName(QString::fromUtf8("width_label"));
        width_label->setGeometry(QRect(110, 115, 54, 12));
        height_label = new QLabel(Dialog);
        height_label->setObjectName(QString::fromUtf8("height_label"));
        height_label->setGeometry(QRect(107, 155, 54, 12));
        width_input = new QLineEdit(Dialog);
        width_input->setObjectName(QString::fromUtf8("width_input"));
        width_input->setGeometry(QRect(150, 110, 113, 20));
        height_input = new QLineEdit(Dialog);
        height_input->setObjectName(QString::fromUtf8("height_input"));
        height_input->setGeometry(QRect(150, 150, 113, 20));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 220, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        width_label->setText(QApplication::translate("Dialog", "width:", nullptr));
        height_label->setText(QApplication::translate("Dialog", "height:", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
