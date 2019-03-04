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
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CanvasCommand)
    {
        if (CanvasCommand->objectName().isEmpty())
            CanvasCommand->setObjectName(QString::fromUtf8("CanvasCommand"));
        CanvasCommand->resize(723, 699);
        CanvasCommand->setAutoFillBackground(true);
        CanvasCommand->setStyleSheet(QString::fromUtf8(""));
        textBrowser_2 = new QTextBrowser(CanvasCommand);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(170, 110, 431, 231));
        QFont font;
        font.setPointSize(14);
        textBrowser_2->setFont(font);
        textBrowser_2->setFrameShape(QFrame::StyledPanel);
        textBrowser = new QTextBrowser(CanvasCommand);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(170, 310, 431, 231));
        textBrowser->setFont(font);
        textBrowser->setFrameShape(QFrame::StyledPanel);

        retranslateUi(CanvasCommand);

        QMetaObject::connectSlotsByName(CanvasCommand);
    } // setupUi

    void retranslateUi(QWidget *CanvasCommand)
    {
        CanvasCommand->setWindowTitle(QApplication::translate("CanvasCommand", "Form", nullptr));
        textBrowser_2->setHtml(QApplication::translate("CanvasCommand", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">All commands executed in this Canvas</span></p></body></html>", nullptr));
        textBrowser->setHtml(QApplication::translate("CanvasCommand", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CanvasCommand: public Ui_CanvasCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVASCOMMAND_H
