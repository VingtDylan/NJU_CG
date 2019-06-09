/********************************************************************************
** Form generated from reading UI file 'myclipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLIPDIALOG_H
#define UI_MYCLIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_MyClipDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;

    void setupUi(QDialog *MyClipDialog)
    {
        if (MyClipDialog->objectName().isEmpty())
            MyClipDialog->setObjectName(QString::fromUtf8("MyClipDialog"));
        MyClipDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(MyClipDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(MyClipDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 40, 69, 22));

        retranslateUi(MyClipDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MyClipDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MyClipDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MyClipDialog);
    } // setupUi

    void retranslateUi(QDialog *MyClipDialog)
    {
        MyClipDialog->setWindowTitle(QApplication::translate("MyClipDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyClipDialog: public Ui_MyClipDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIPDIALOG_H
