#include "logm.h"
#include "ui_logm.h"
QString did="";
LogM::LogM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogM)
{
    ui->setupUi(this);
    ui->Epassword->setEchoMode(QLineEdit::Password);
    QDateTime time = QDateTime::currentDateTime();              //获取系统现在的时间
    QString ptime = time.toString("yyyy-MM-dd ddd");     //设置显示格式
    ui->timedlabel_4->setText(ptime);
    ui->lcdNumber->setDigitCount(8); //显示格式 hh:mm:ss
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat); //设置时间显示字体
    ui->lcdNumber->display(QTime::currentTime().toString("hh:mm:ss"));

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
}

LogM::~LogM()
{
    delete ui;
    Ma=new Management;
    connect(Ma,SIGNAL(Quit0()),this,SLOT(Re(QString a)));
}

void LogM::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    ui->lcdNumber->display(text);
}
void LogM::Re(QString a)
{
    ui->Edid->setText(a);
   // QMessageBox::information(this,"",a);
}
void LogM::on_Blog_clicked()
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
            if(Csql.model.record(0).value("dright").toString()=="yes")//检验是否为管理员
            {
                QMessageBox::StandardButton reply;
                reply=QMessageBox::question(this,"管理登录","登录管理界面?",QMessageBox::Yes | QMessageBox::No);//询问是否登录管理界面
                if(reply==QMessageBox::Yes)//登录管理界面
                {
                   Ma= new Management(this);
                   Ma->show();
                   did=ui->Edid->text();
                }
                else
                {

                   sy= new systemlog(this);
                   sy->show();
                   did=ui->Edid->text();

                };

            }
            else
            {
                sy= new systemlog(this);
                sy->show();
                did=ui->Edid->text();
              //  hide();

            }

        }
        else QMessageBox::warning(this,"警告","密码错误");
    }
    ui->Edid->setEnabled(true);
    ui->Epassword->setEnabled(true);
}

void LogM::on_Bexit_clicked()
{
    close();
}
