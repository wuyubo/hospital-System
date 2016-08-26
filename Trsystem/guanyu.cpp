#include "guanyu.h"
#include "ui_guanyu.h"

guanyu::guanyu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::guanyu)
{
    ui->setupUi(this);
}

guanyu::~guanyu()
{
    delete ui;
}

void guanyu::on_pushButton_clicked()
{
    close();
}

void guanyu::on_pushButton_2_clicked()
{
    close();
}
