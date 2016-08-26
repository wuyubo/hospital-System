#ifndef DISEASE_H
#define DISEASE_H

#include <QDialog>
#include"cmysql.h"
#include <QMessageBox>

namespace Ui {
class Disease;
}

class Disease : public QDialog
{
    Q_OBJECT

public:
    explicit Disease(QWidget *parent = 0);
    ~Disease();

private slots:
    void on_OK_clicked();

    void on_NO_clicked();

private:
    Ui::Disease *ui;
};

#endif // DISEASE_H
