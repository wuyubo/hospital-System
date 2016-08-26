#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QDialog>
#include<QMessageBox>
#include "cmysql.h"

namespace Ui {
class changeuser;
}

class changeuser : public QDialog
{
    Q_OBJECT

public:
    explicit changeuser(QWidget *parent = 0);
    ~changeuser();

private slots:
    void on_Blog_clicked();

    void on_Bexit_clicked();

private:
    Ui::changeuser *ui; 
    Cmysql Csql;
};

#endif // CHANGEUSER_H
