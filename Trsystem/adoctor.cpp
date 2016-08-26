#include "adoctor.h"
#include "ui_adoctor.h"
#include<QMessageBox>
QString pic="";
Adoctor::Adoctor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adoctor)
{
    ui->setupUi(this);
}

Adoctor::~Adoctor()
{
    delete ui;
}
void Adoctor::Aupdate(bool T)
{
    ui->Adid->setEnabled(T);
    ui->Adname->setEnabled(T);
    ui->Abirth->setEnabled(T);
    ui->Adpost->setEnabled(T);

}
void Adoctor::on_pushButton_clicked()
{
   Aupdate(false);
  // QMessageBox::information(this,"ds",ui->comboBox->currentText());
   if(Empty()=="0")
   {
       Cmysql Csql;
      // Csql.connect();
       Csql.Infadd("0",ui->Adid->text(),ui->Adname->text(),ui->Cdsex->currentText(),ui->Abirth->text(),ui->Adpost->text(),ui->Cdepart->currentText(),ui->comboBox->currentText(),ui->Adesc->toPlainText(),"123456",pic);
     //  emit access();
      QMessageBox::information(this,"提示","添加成功");
       close();
   }
   else
   {
       if(Empty()=="请输入10wei编号") QMessageBox::warning(this,"警告",Empty());
       if(Empty()=="名字不能为空") QMessageBox::warning(this,"警告",Empty());
       if(Empty()=="请输入正确的出生年月格式") QMessageBox::warning(this,"警告",Empty());
       if(Empty()=="任职不能为空") QMessageBox::warning(this,"警告",Empty());
       if(Empty()=="专业科目不能为空") QMessageBox::warning(this,"警告",Empty());
   }
   Aupdate(true);
}

QString Adoctor::Empty()
{
    if(ui->Adid->text().length()!=10) return "请输入10wei编号";
    else if(ui->Adname->text()=="") return "名字不能为空";
    else if(ui->Abirth->text().length()!=7) return "请输入正确的出生年月格式如1993/02";
    else if(ui->Adpost->text()=="") return "任职不能为空";
    else if(ui->Cdepart->currentText()=="请选择科目") return "专业科目不能为空";
    else return "0";
}

void Adoctor::on_pushButton_2_clicked()
{
    close();
}

void Adoctor::on_pushButton_3_clicked()
{
    showpic p;
    pic=p.getpic(QFileDialog::getOpenFileName(this),ui->pushButton_3);
}
