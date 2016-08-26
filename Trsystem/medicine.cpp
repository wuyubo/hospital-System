#include "medicine.h"
#include "ui_medicine.h"

Medicine::Medicine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Medicine)
{
    ui->setupUi(this);
}

Medicine::~Medicine()
{
    delete ui;
}

void Medicine::on_no_clicked()
{
    close();
}

void Medicine::on_ok_clicked()
{
   MUpdate(false);
   if(ui->Mid->text()=="") QMessageBox::warning(this,"警告","药品编号不能为空");
   else if(ui->Mname->text()=="")  QMessageBox::warning(this,"警告","药品名称不能为空");
   else if(ui->Mprice->text()=="")  QMessageBox::warning(this,"警告","药品单价不能为空");
   else if(ui->Mcout->text()=="")   QMessageBox::warning(this,"警告","入库数量不能为空");
   else
   {
       Cmysql Csql;
       Csql.Infadd("5",ui->Mid->text(),ui->Mname->text(),ui->cmtype->currentText(),ui->cusage->currentText(),ui->tdesc->toPlainText(),ui->Mprice->text(),ui->Mcout->text());
       QMessageBox::information(this,"提示","添加成功");
       close();
   }
   MUpdate(true);
}

void Medicine::MUpdate(bool bo)
{
    ui->Mid->setEnabled(bo);
    ui->Mname->setEnabled(bo);
    ui->Mprice->setEnabled(bo);
    ui->Mcout->setEnabled(bo);

}
