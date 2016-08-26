#ifndef ZILIAO_H
#define ZILIAO_H

#include <QDialog>

namespace Ui {
class ziliao;
}

class ziliao : public QDialog
{
    Q_OBJECT

public:
    explicit ziliao(QWidget *parent = 0);
    ~ziliao();

private slots:
    void on_zl_queren_clicked();

    void on_zl_fanhui_clicked();

private:
    Ui::ziliao *ui;
};

#endif // ZILIAO_H
