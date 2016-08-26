#include "changeuser.h"
#include "ui_changeuser.h"
extern QString did;
changeuser::changeuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeuser)
{
    ui->setupUi(this);
    ui->Epassword->setEchoMode(QLineEdit::Password);
}

changeuser::~changeuser()
{
    delete ui;
}

void changeuser::on_Blog_clicked()
{
    ui->Edid->setEnabled(false);
    ui->Epassword->setEnabled(false);
    if(ui->Edid->text()=="") QMessageBox::warning(this,"警告","编号不能为空");
    else
    {

        Csql.Dsearch(ui->Edid->text());//查找医生信息
        if(Csql.model.record(0).value("did").toString()=="") QMessageBox::warning(this,"警告","不存在该编号");//检验编号
        else if(ui->Epassword->text()==Csql.model.record(0).value("dpasswa").toString())//检验密码
        {
            did=ui->Edid->text();
            close();
        }
        else QMessageBox::warning(this,"警告","密码错误");
    }
    ui->Edid->setEnabled(true);
    ui->Epassword->setEnabled(true);
}

void changeuser::on_Bexit_clicked()
{
    close();
}
