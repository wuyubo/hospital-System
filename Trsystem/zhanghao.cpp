#include "zhanghao.h"
#include "ui_zhanghao.h"
extern QString did;

zhanghao::zhanghao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhanghao)
{
    ui->setupUi(this);
    ui->oldlineEdit->setEchoMode(QLineEdit::Password);
    ui->newlineEdit_2->setEchoMode(QLineEdit::Password);
    ui->newlineEdit_3->setEchoMode(QLineEdit::Password);
}

zhanghao::~zhanghao()
{
    delete ui;
}

void zhanghao::on_zh_fanhui_clicked()
{
    close();
}

void zhanghao::on_zh_queren_clicked()
{
    ui->oldlineEdit->setEnabled(false);
    ui->newlineEdit_2->setEnabled(false);
    ui->newlineEdit_3->setEnabled(false);
     Csql.Dsearch(did,"doctorinf","did","dpasswa");

     if(ui->oldlineEdit->text()==Csql.model.record(0).value("dpasswa").toString())
     {
         if(ui->newlineEdit_2->text().length()==6)
         {
             if(ui->newlineEdit_2->text()==ui->newlineEdit_3->text())
             {
                 Csql.Infupdate(ui->newlineEdit_3->text(),"dpasswa",did);
                 QMessageBox::information(this,"提示","修改成功");
                 close();
             }
             else QMessageBox::warning(this,"错误","两次输入不一");
         }
         else QMessageBox::warning(this,"提示","请输入六wei密码");//
     }
     else QMessageBox::warning(this,"错误","请输入正确原密码");
    ui->oldlineEdit->setEnabled(true);
    ui->newlineEdit_2->setEnabled(true);
    ui->newlineEdit_3->setEnabled(true);
}
