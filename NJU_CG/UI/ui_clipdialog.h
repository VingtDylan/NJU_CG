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

class Ui_ClipDialog
{
public:
    QLineEdit *algorithm_input;
    QPushButton *pushButton;
    QLabel *y2;
    QLabel *label;
    QLabel *x2;
    QLabel *y1;
    QLineEdit *y1_input;
    QLabel *id;
    QLineEdit *id_input;
    QLineEdit *x2_input;
    QLabel *x1;
    QLineEdit *x1_input;
    QLineEdit *y2_input;

    void setupUi(QDialog *ClipDialog)
    {
        if (ClipDialog->objectName().isEmpty())
            ClipDialog->setObjectName(QString::fromUtf8("ClipDialog"));
        ClipDialog->resize(400, 300);
        algorithm_input = new QLineEdit(ClipDialog);
        algorithm_input->setObjectName(QString::fromUtf8("algorithm_input"));
        algorithm_input->setGeometry(QRect(180, 180, 113, 20));
        pushButton = new QPushButton(ClipDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 210, 75, 23));
        y2 = new QLabel(ClipDialog);
        y2->setObjectName(QString::fromUtf8("y2"));
        y2->setGeometry(QRect(150, 153, 54, 12));
        label = new QLabel(ClipDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 185, 54, 12));
        x2 = new QLabel(ClipDialog);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(150, 125, 54, 12));
        y1 = new QLabel(ClipDialog);
        y1->setObjectName(QString::fromUtf8("y1"));
        y1->setGeometry(QRect(150, 94, 54, 12));
        y1_input = new QLineEdit(ClipDialog);
        y1_input->setObjectName(QString::fromUtf8("y1_input"));
        y1_input->setGeometry(QRect(180, 90, 113, 20));
        id = new QLabel(ClipDialog);
        id->setObjectName(QString::fromUtf8("id"));
        id->setGeometry(QRect(150, 35, 54, 12));
        id_input = new QLineEdit(ClipDialog);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(180, 30, 113, 20));
        x2_input = new QLineEdit(ClipDialog);
        x2_input->setObjectName(QString::fromUtf8("x2_input"));
        x2_input->setGeometry(QRect(180, 120, 113, 20));
        x1 = new QLabel(ClipDialog);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(150, 65, 54, 12));
        x1_input = new QLineEdit(ClipDialog);
        x1_input->setObjectName(QString::fromUtf8("x1_input"));
        x1_input->setGeometry(QRect(180, 60, 113, 20));
        y2_input = new QLineEdit(ClipDialog);
        y2_input->setObjectName(QString::fromUtf8("y2_input"));
        y2_input->setGeometry(QRect(180, 150, 113, 20));

        retranslateUi(ClipDialog);

        QMetaObject::connectSlotsByName(ClipDialog);
    } // setupUi

    void retranslateUi(QDialog *ClipDialog)
    {
        ClipDialog->setWindowTitle(QApplication::translate("ClipDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ClipDialog", "Confirm", nullptr));
        y2->setText(QApplication::translate("ClipDialog", "y2", nullptr));
        label->setText(QApplication::translate("ClipDialog", "algorithm", nullptr));
        x2->setText(QApplication::translate("ClipDialog", "x2", nullptr));
        y1->setText(QApplication::translate("ClipDialog", "y1", nullptr));
        id->setText(QApplication::translate("ClipDialog", "id", nullptr));
        x1->setText(QApplication::translate("ClipDialog", "x1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClipDialog: public Ui_ClipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPDIALOG_H
