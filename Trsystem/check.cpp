#include "check.h"
#include "ui_check.h"
#include <QMessageBox>

extern  int hnum;
extern QString pdate;
check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
    QString date=pdate;
    date.insert(4,QString("/"));
    date.insert(7,QString("/"));
    ui->pdatelineEdit->setText(date);
    ui->pdatelineEdit->setReadOnly(true);
}

check::~check()
{
    delete ui;

}


void check::on_ch_queren_clicked()
{
    ui->pidlineEdit->setEnabled(false);
    ui->pdatelineEdit->setEnabled(false);
    if(ui->pidlineEdit->text().length()!=18)
    {
        QMessageBox::warning(this,"警告","请输入正确的自身证号");
    }
    else
    {
        Csql.Dsearch(ui->pidlineEdit->text(),"patientinf","pid","pname");
        if(Csql.model.record(0).value("pname").toString()=="")
            QMessageBox::information(this,"提示","没有该病人的信息");
        else
        {
            QString num= QString::number(++hnum, 10);//int to Qstring 10进制
            Csql.Infadd("7",num,pdate,ui->pidlineEdit->text(),
                        ui->creturn->currentText());
            QMessageBox::information(this,"挂号成功","挂号吗为"+num);
            close();
        }
    }
    ui->pidlineEdit->setEnabled(true);
    ui->pdatelineEdit->setEnabled(true);
}

void check::on_ch_fanhui_clicked()
{
    pdate="";
    close();
}
