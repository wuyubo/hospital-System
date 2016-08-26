#include "disease.h"
#include "ui_disease.h"

Disease::Disease(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disease)
{
    ui->setupUi(this);
}

Disease::~Disease()
{
    delete ui;
}

void Disease::on_OK_clicked()
{
    ui->diname->setEnabled(false);
    if(ui->diname->text()=="") QMessageBox::warning(this,"警告","名称不能为空");
    else if(ui->tdisymb->toPlainText()=="") QMessageBox::warning(this,"警告","症状不能为空");
    else if(ui->tdmedic->toPlainText().split(".").count()%2!=0) QMessageBox::warning(this,"警告","药单输入有误");
    else
    {
        Cmysql Csql;
        Csql.Infadd("2",ui->diname->text(),ui->cditype->currentText(),ui->cdirank->currentText(),ui->tdisymb->toPlainText(),ui->tdidesc->toPlainText());
        Csql.Infadd("6",ui->diname->text(),ui->cditype->currentText(),ui->cdirank->currentText(),ui->tdmedic->toPlainText(),ui->tsugge->toPlainText());
        QMessageBox::information(this,"提示","添加成功");
        close();
    }
    ui->diname->setEnabled(true);
}

void Disease::on_NO_clicked()
{
    close();
}
