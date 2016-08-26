#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include"cmysql.h"

namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = 0);
    ~check();

private slots:


    void on_ch_queren_clicked();

    void on_ch_fanhui_clicked();

private:
    Ui::check *ui;
    Cmysql Csql;
};

#endif // CHECK_H
