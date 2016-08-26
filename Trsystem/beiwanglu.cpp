#include "beiwanglu.h"
#include "ui_beiwanglu.h"
#include <QMessageBox>

QString Beiw="";
beiwanglu::beiwanglu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::beiwanglu)
{
    ui->setupUi(this);
    ui->textEdit->setText(Beiw);
}

beiwanglu::~beiwanglu()
{
    delete ui;
}

void beiwanglu::on_pushButton_clicked()
{
    close();
}

void beiwanglu::on_bwl_queren_clicked()
{

    if(ui->textEdit->toPlainText()!="")
    {
        Beiw=ui->textEdit->toPlainText();
        QMessageBox::information(this,"提示","保存成功");
    }
    else
        QMessageBox::information(this,"提示","请填写你的备忘录");
}
