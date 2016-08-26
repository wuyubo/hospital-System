#ifndef PRINT_H
#define PRINT_H

#include <QWidget>
#include "cmysql.h"
#include "systemlog.h"
#include <QDateTime>
#include <QMessageBox>
namespace Ui {
class Print;
}

class Print : public QWidget
{
    Q_OBJECT

public:
    explicit Print(QWidget *parent = 0);
    ~Print();

private slots:
    void on_printpushButton_clicked();

    void on_backpushButton_2_clicked();

private:
    Ui::Print *ui;
    Cmysql Csql;

};

#endif // PRINT_H
