#include "ziliao.h"
#include "ui_ziliao.h"
#include "mainwindow.h"

ziliao::ziliao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ziliao)
{
    ui->setupUi(this);
}

ziliao::~ziliao()
{
    delete ui;
}

void ziliao::on_zl_queren_clicked()
{
    ziliao zl;
    zl.setModal(true);
    zl.exec();
}

void ziliao::on_zl_fanhui_clicked()
{

}
