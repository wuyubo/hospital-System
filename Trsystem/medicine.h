#ifndef MEDICINE_H
#define MEDICINE_H

#include <QDialog>
#include"cmysql.h"
#include <QMessageBox>

namespace Ui {
class Medicine;
}

class Medicine : public QDialog
{
    Q_OBJECT

public:
    explicit Medicine(QWidget *parent = 0);
    ~Medicine();

private slots:
    void on_no_clicked();

    void on_ok_clicked();

private:
    Ui::Medicine *ui;
    void MUpdate(bool bo);
};

#endif // MEDICINE_H
