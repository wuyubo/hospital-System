#include "riqi.h"
#include "ui_riqi.h"
QString pdate="";

riqi::riqi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::riqi)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();    //获取系统现在的时间
    QString nowtime=time.toString("yyyy-MM-dd \n ddd");
    QFont ft;
    ft.setPointSize(16);
    ui->TimeL->setFont(ft);//设字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->TimeL->setPalette(pa);//颜色
    ui->TimeL->setText("   今天  \n"+nowtime);
}

riqi::~riqi()
{
    delete ui;
}

void riqi::on_pushButton_clicked()
{
    pdate = ui->calendarWidget->selectedDate().toString("yyyyMMdd");
    QDateTime time = QDateTime::currentDateTime();    //获取系统现在的时间
    QString nowtime=time.toString("yyyyMMdd");
    if(pdate.toInt()>=nowtime.toInt())
    {
        close();
    }
    else
    {
        pdate="";
        QMessageBox::information(this,"提示","请选择未来时间");
    }

}

void riqi::on_pushButton_2_clicked()
{
    pdate="";
    close();
}

void riqi::on_calendarWidget_clicked()
{
    QDateTime time = QDateTime::currentDateTime();    //获取系统现在的时间
    QString nowtime=time.toString("yyyy-MM-dd \n ddd");
    QString Times=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd \n ddd");
    QFont ft;
    ft.setPointSize(16);
    ui->TimeL->setFont(ft);//设字号
    QPalette pa;
    if(nowtime==Times)
    {
        pa.setColor(QPalette::WindowText,Qt::red);
        ui->TimeL->setPalette(pa);//颜色
        ui->TimeL->setText("   今天  \n"+nowtime);
    }
    else
    {
        pa.setColor(QPalette::WindowText,Qt::black);
        ui->TimeL->setPalette(pa);//颜色
        ui->TimeL->setText(Times);
    }
}
