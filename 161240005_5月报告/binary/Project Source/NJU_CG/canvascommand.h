#ifndef CANVASCOMMAND_H
#define CANVASCOMMAND_H

#include <QWidget>

namespace Ui {
class CanvasCommand;
}

class CanvasCommand : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasCommand(QString id,QWidget *parent = nullptr);
    ~CanvasCommand();

private:
    Ui::CanvasCommand *ui;

private slots:
    void ReceiveListCommand(QString commandlists);
};

#endif // CANVASCOMMAND_H
