#ifndef BEIWANGLU_H
#define BEIWANGLU_H

#include <QDialog>

namespace Ui {
class beiwanglu;
}

class beiwanglu : public QDialog
{
    Q_OBJECT

public:
    explicit beiwanglu(QWidget *parent = 0);
    ~beiwanglu();

private slots:
    void on_pushButton_clicked();

    void on_bwl_queren_clicked();

private:
    Ui::beiwanglu *ui;
};

#endif // BEIWANGLU_H
