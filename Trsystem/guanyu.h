#ifndef GUANYU_H
#define GUANYU_H

#include <QDialog>

namespace Ui {
class guanyu;
}

class guanyu : public QDialog
{
    Q_OBJECT

public:
    explicit guanyu(QWidget *parent = 0);
    ~guanyu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::guanyu *ui;
};

#endif // GUANYU_H
