#ifndef ADOCTOR_H
#define ADOCTOR_H

#include <QDialog>
#include "cmysql.h"
#include "showpic.h"

namespace Ui {
class Adoctor;
}

class Adoctor : public QDialog
{
    Q_OBJECT

public:
    explicit Adoctor(QWidget *parent = 0);
    ~Adoctor();
signals:
   // void access();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Adoctor *ui;
    Cmysql Csql;
    void Aupdate(bool T);
    QString Empty();
};

#endif // ADOCTOR_H
