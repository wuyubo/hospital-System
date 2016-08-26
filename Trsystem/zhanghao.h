#ifndef ZHANGHAO_H
#define ZHANGHAO_H

#include <QDialog>
#include "cmysql.h"
#include <QMessageBox>
namespace Ui {
class zhanghao;
}

class zhanghao : public QDialog
{
    Q_OBJECT

public:
    explicit zhanghao(QWidget *parent = 0);
    ~zhanghao();

private slots:
    void on_zh_fanhui_clicked();

    void on_zh_queren_clicked();

private:
    Ui::zhanghao *ui;
    Cmysql Csql;
};

#endif // ZHANGHAO_H
