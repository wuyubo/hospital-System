#include "print.h"
#include "ui_print.h"
extern QString did;
extern QString hnum0;
extern QString Medi;
extern QString dname;
extern QString tsuggest;
QStringList Medis;

Print::Print(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Print)
{
    ui->setupUi(this);
  //  QString s = QString::number(hnum, 10);//int to Qstring 10进制
    QDateTime time = QDateTime::currentDateTime();              //获取系统现在的时间
    QString ptime = time.toString("yyyyMMdd");     //hh:mm:ss ddd设置显示格式

    ui->hnumlineEdit->setText(hnum0);
    ui->datelineEdit_2->setText(ptime);
    ui->dnamelineEdit_5->setText(dname);
    ui->tmeditextEdit->setText(Medi);
    ui->tsuggtextEdit_2->setText(tsuggest);

    Csql.Dsearch(dname,"disease","dname","dtype,drank");
    ui->dranklineEdit_6->setText(Csql.model.record(0).value("drank").toString());
    Csql.model.setQuery("SELECT pid FROM hungnum WHERE hnum='"+hnum0+"' AND date='"+ptime+"'");
    QString s=Csql.model.record(0).value("pid").toString();
    ui->pidlineEdit_4->setText(s);
    Csql.Dsearch(s,"patientinf","pid","pname");
    ui->pnamelineEdit_3->setText(Csql.model.record(0).value("pname").toString());

    Csql.Dsearch(dname,"disease","dname","dtype,drank");
    ui->typelineEdit->setText(Csql.model.record(0).value("dtype").toString());
    ui->dranklineEdit_6->setText(Csql.model.record(0).value("drank").toString());
    //价格
    Medis=Medi.split("\n");
    QStringList Medis0;
    for(int i=0;i<Medis.count();i++)
    {
        Medis0=Medis[i].split(".");
        Medis[i]=Medis0[0];

    }

    int price=0;
    for(int i=0;i<Medis.count();i++)
    {
        Csql.Dsearch(Medis[i],"medicines","mid","mprice");
        price=price+Csql.model.record(0).value("mprice").toInt();
    }
    s = QString::number(price, 10);//int to Qstring 10进制

    ui->pricelineEdit->setText(s+".00");
}

Print::~Print()
{
    delete ui;   
}

void Print::on_printpushButton_clicked()
{
    for(int i=0;i<Medis.count()-1;i++)
    {
       Csql.Infupdate1("mcount-1","mcount",Medis[i],"mid","medicines");
       Csql.Infupdate1("mecount+1","mecount",Medis[i],"mid","medicines");
    }
    ui->pidlineEdit_4->setEnabled(false);
    ui->pnamelineEdit_3->setEnabled(false);
    ui->typelineEdit->setEnabled(false);
    ui->dranklineEdit_6->setEnabled(false);
    Csql.Infupdate1("pcount+1","pcount",ui->pidlineEdit_4->text(),"pid","patientinf");
    Csql.Infupdate1("dcount+1","dcount",did,"did");
    Csql.Infupdate1("dcount+1","dcount",dname,"dname","disease");
    Csql.Dsearch(did);
    QString dnames=Csql.model.record(0).value("dname").toString();

    Csql.Infadd("4",ui->pidlineEdit_4->text(),ui->pnamelineEdit_3->text(),dname,ui->typelineEdit->text(),
               ui->dranklineEdit_6->text(),Medi,dnames);

     Csql.Dsearch(ui->pidlineEdit_4->text(),"patientinf","pid","psex");
    Csql.Infadd("1",did,dnames,ui->pidlineEdit_4->text(),
                ui->pnamelineEdit_3->text(),
                Csql.model.record(0).value("psex").toString(),
                dname,ui->dranklineEdit_6->text(),Medi);
    ui->pnamelineEdit_3->setEnabled(true);
    ui->pidlineEdit_4->setEnabled(true);
    ui->typelineEdit->setEnabled(true);
    ui->dranklineEdit_6->setEnabled(true);
    QMessageBox::information(this,"提示","打印成功");
    close();
}

void Print::on_backpushButton_2_clicked()
{
    close();
}
