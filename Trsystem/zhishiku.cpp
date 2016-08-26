#include "zhishiku.h"
#include "ui_zhishiku.h"


zhishiku::zhishiku(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zhishiku)
{
    ui->setupUi(this);
}

zhishiku::~zhishiku()
{
    delete ui;
}

void zhishiku::on_zsk_queren_clicked()
{
    zhishiku zsk;
    zsk.setModal(true);
    zsk.exec();
}

void zhishiku::on_zsk_fanhui_clicked()
{
    close();
}
