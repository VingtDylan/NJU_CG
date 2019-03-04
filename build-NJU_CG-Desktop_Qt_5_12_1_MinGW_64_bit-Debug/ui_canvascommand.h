/********************************************************************************
** Form generated from reading UI file 'canvascommand.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVASCOMMAND_H
#define UI_CANVASCOMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CanvasCommand
{
public:
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;

    void setupUi(QWidget *CanvasCommand)
    {
        if (CanvasCommand->objectName().isEmpty())
            CanvasCommand->setObjectName(QString::fromUtf8("CanvasCommand"));
        CanvasCommand->resize(400, 300);
        textBrowser = new QTextBrowser(CanvasCommand);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 50, 311, 221));
        textBrowser_2 = new QTextBrowser(CanvasCommand);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(90, 10, 231, 31));

        retranslateUi(CanvasCommand);

        QMetaObject::connectSlotsByName(CanvasCommand);
    } // setupUi

    void retranslateUi(QWidget *CanvasCommand)
    {
        CanvasCommand->setWindowTitle(QApplication::translate("CanvasCommand", "Form", nullptr));
        textBrowser_2->setHtml(QApplication::translate("CanvasCommand", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">All commands executed in this canvas</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CanvasCommand: public Ui_CanvasCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVASCOMMAND_H
