#include "systemlog.h"
#include "ui_systemlog.h"
#include "QMessageBox"

 int hnum=0;
 QString hnum0="";
 QString Medi;
 QString dname;
 QString tsuggest;
 static int n=0;//已诊病人数

extern QString did;
extern QString pdate;

systemlog::systemlog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::systemlog)
{
    ui->setupUi(this);
    time = QDateTime::currentDateTime();              //获取系统现在的时间
    nowtime = time.toString("yyyy-MM-dd ddd");     //设置显示格式

    ui->timedlabel_6->setText(nowtime);


    ui->lcdNumber_3->setDigitCount(8); //显示格式 hh:mm:ss
    ui->lcdNumber_3->setSegmentStyle(QLCDNumber::Flat); //设置时间显示字体
    ui->lcdNumber_3->display(QTime::currentTime().toString("hh:mm:ss"));

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

    QToolBar *toolBar = addToolBar(tr("&系统"));
    QList<QAction*>  Qa;
    Qa<<ui->action<<ui->action_2<<ui->action_3<<ui->action_4<<ui->action_5<<ui->actionCelender<<ui->action_9;
    toolBar->addActions(Qa);
///////连接信号与槽
    connect(ui->SlineEdit,SIGNAL(returnPressed()),this,SLOT(on_SearchpushButton_clicked()));
    connect(ui->action,SIGNAL(triggered()),this,SLOT(backtomain()));
    connect(ui->action_4,SIGNAL(triggered()),this,SLOT(on_B_check_clicked()));
    connect(ui->action_5,SIGNAL(triggered()),this,SLOT(on_B_ziliao_clicked()));
    connect(ui->action_6,SIGNAL(triggered()),this,SLOT(on_B_zhanghao_clicked()));
    connect(ui->action_7,SIGNAL(triggered()),this,SLOT(on_B_guanyu_clicked()));
    connect(ui->action_8,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_clicked()));
    connect(ui->action_9,SIGNAL(triggered()),this,SLOT(on_B_quit_clicked()));
    connect(ui->actionCelender,SIGNAL(triggered()),this,SLOT(on_B_riqi_clicked()));

    backtomain();

}

systemlog::~systemlog()
{
    delete ui;
}
void systemlog::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    ui->lcdNumber_3->display(text);
}
void systemlog::backtomain()
{
    ui->phisframe->close();
    ui->Apatientframe->close();
    ui->doctorframe->close();
    ui->calendarframe->close();
    ui->mainframe->show();
    ui->SearchtextEdit_5->setText("");

    ////获得今天挂号人数
     time = QDateTime::currentDateTime();
    nowtime =time.toString("yyyyMMdd");
    Csql.Tsearch("hungnum","hnum,date,pid,hret","hnum",nowtime,"date"," ASC");
    hnum=Csql.model.rowCount();
    QFont ft;
    ft.setPointSize(18);
    ui->hunglabel_29->setFont(ft);//设字号
    ui->hungslabel_29->setFont(ft);//设字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->hunglabel_29->setPalette(pa);//颜色
    ui->hungslabel_29->setPalette(pa);//颜色
    ui->hunglabel_29->setText(" 挂号共有 "+QString::number(Csql.model.rowCount(),10)+" ");
  //  if(n==hnum-1)
    //    ui->hungslabel_29->setText(" 未就诊有 "+QString::number(Csql.model.rowCount()-n-1,10)+" ");
    //else
        ui->hungslabel_29->setText(" 未就诊有 "+QString::number(Csql.model.rowCount()-n,10)+" ");

}
void systemlog::on_hungcountcommandLinkButton_3_clicked()
{
    backtomain();
}
///关于系统
void systemlog::on_B_guanyu_clicked()
{
    guanyu g;
    g.setModal(true);
    g.exec();
}
///查看日历
void systemlog::on_B_riqi_clicked()
{
    ui->calendarframe->show();
    ui->phisframe->close();
    ui->Apatientframe->close();
    ui->doctorframe->close();
    ui->mainframe->close();
    time = QDateTime::currentDateTime();    //获取系统现在的时间
    nowtime=time.toString("yyyy-MM-dd \n ddd");
    QFont ft;
    ft.setPointSize(25);
    ui->TimeL->setFont(ft);//设字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->TimeL->setPalette(pa);//颜色
    ui->TimeL->setText("   今天  \n"+nowtime);

}
void systemlog::on_calendarWidget_clicked()
{
    QString Times=ui->calendarWidget->selectedDate().toString("yyyy-MM-dd \n ddd");
    QFont ft;
    ft.setPointSize(25);
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
void systemlog::on_CbackpushButton_clicked()
{
    ui->calendarframe->close();
    ui->mainframe->show();
}

///更改用户
void systemlog::on_commandLinkButton_clicked()
{
    changeuser c;
    c.setModal(true);
    c.exec();
}
///退出系统
void systemlog::on_B_quit_clicked()
{
    close();
}
///备忘录
void systemlog::on_B_beiwanglu_clicked()
{
    beiwanglu b;
    b.setModal(true);
    b.exec();
}
///知识卡
void systemlog::on_B_zhishiku_clicked()
{
    zhishiku z;
    z.setModal(true);
    z.exec();
}
///挂号
void systemlog::on_B_tianjia_clicked()
{
    riqi r;
    r.setModal(true);
    r.exec();
    if(pdate!="")
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"登记病人","初次在本院就诊？");
        if(reply==QMessageBox::Yes)
        {
            ui->phisframe->close();
            ui->doctorframe->close();
            ui->mainframe->close();
            ui->calendarframe->close();
            ui->Apatientframe->show();
            ui->pidlineEdit->clear();
            QString date=pdate;
            date.insert(4,QString("/"));
            date.insert(7,QString("/"));
            ui->pdatelineEdit->setText(date);
            ui->pdatelineEdit->setReadOnly(true);
        }
        else
        {
            check c;
            c.setModal(true);
            c.exec();
        }
    }
}
void systemlog::on_action_2_triggered()
{
    riqi r;
    r.setModal(true);
    r.exec();
    if(pdate!="")
    {
        ui->phisframe->close();
        ui->doctorframe->close();
        ui->mainframe->close();
        ui->calendarframe->close();
        ui->Apatientframe->show();
        ui->pidlineEdit->clear();

        QString date=pdate;
        date.insert(4,QString("/"));
        date.insert(7,QString("/"));
        ui->pdatelineEdit->setText(date);
        ui->pdatelineEdit->setReadOnly(true);
    }
}
void systemlog::on_action_3_triggered()
{
    riqi r;
    r.setModal(true);
    r.exec();
    if(pdate!="")
    {
        check c;
        c.setModal(true);
        c.exec();
    }
}


///挂号
void systemlog::on_hnpushButton_3_clicked()
{
    ui->pidlineEdit->setEnabled(false);
    ui->pnamelineEdit_2->setEnabled(false);
    ui->pbirthlineEdit_4->setEnabled(false);
    if(ui->pidlineEdit->text().length()!=18)
        QMessageBox::warning(this,"警告","请输入正确的自身证号");
    else if(ui->pnamelineEdit_2->text()=="")
        QMessageBox::warning(this,"警告","名字不能为空");
    else if(ui->pbirthlineEdit_4->text().length()!=7)
        QMessageBox::warning(this,"警告","请输入正确的出生年月格式");
    else
    {
        //添加病人信息
        Csql.Infadd("3",ui->pidlineEdit->text(),ui->pnamelineEdit_2->text(),
                    ui->C_sex->currentText(),ui->pbirthlineEdit_4->text(),
                    ui->pdrugtextEdit->toPlainText(),
                    ui->pihistextEdit_2->toPlainText(),"no");
        QString num= QString::number(++hnum, 10);//int to Qstring 10进制
        //添加挂号信息
        Csql.Infadd("7",num,pdate,ui->pidlineEdit->text(),
                    ui->C_retrun->currentText());
        QMessageBox::information(this,"挂号成功","挂号吗为"+num);
        backtomain();
        ///清除
        ui->pnamelineEdit_2->clear();
        ui->pbirthlineEdit_4->clear();
        ui->pdrugtextEdit->clear();
        ui->pihistextEdit_2->clear();
    }

    ui->pidlineEdit->setEnabled(true);
    ui->pnamelineEdit_2->setEnabled(true);
    ui->pbirthlineEdit_4->setEnabled(true);
}

///挂号取消
void systemlog::on_backpushButton_3_clicked()
{
    ui->mainframe->show();
    ui->Apatientframe->close();
    pdate="";
}
///开始就诊
void systemlog::on_B_check_clicked()
{

      ui->doctorframe->close();
      ui->mainframe->close();
      ui->calendarframe->close();
      ui->Apatientframe->close();
      ui->phisframe->show();
      ui->pushButton_3->setText("返回");
      ////显示病例排行
      Csql.Tsearch("disease","*","dcount");
      showdisease("dname","dtype","drank","dsymp");
      ////获得今天挂号人数
      nowtime =time.toString("yyyyMMdd");
      Csql.Tsearch("hungnum","hnum,date,pid,hret","hnum",
                   nowtime,"date"," ASC");
      hnum=Csql.model.rowCount();
      ///显示病人信息
      if(n<hnum)
        showpatient(n);

      else
      {
          if(n==0)
             QMessageBox::information(this,"提示","今天没有病人预约就诊");
          else
             QMessageBox::information(this,"提示","今天就诊完成");
      }
}
///显示病人信息
void systemlog::showpatient(int i)
{


    ui->preturnlineEdit1->setText(Csql.model.record(i).value("hret").toString());
    ui->phlineEdit1->setText(Csql.model.record(i).value("hnum").toString());

    Csql.Dsearch(Csql.model.record(i).value("pid").toString(),
                 "patientinf","pid","pid,pname,psex,pbirth,pdrug,pihis");
    ui->pnamelineEdit_51->setText(Csql.model.record(0).value("pname").toString());
    ui->psexlineEdit1->setText(Csql.model.record(0).value("psex").toString());
    ui->pbirthlineEdit_61->setText(Csql.model.record(0).value("pbirth").toString());
    ui->pdrugtextEdit_41->setText(Csql.model.record(0).value("pdrug").toString());
    ui->pihistextEdit_31->setText(Csql.model.record(0).value("pihis").toString());
    ///显示病人病史
    Csql.Tsearch("patienthis","ddate,pdname","ddate",Csql.model.record(0).value("pid").toString(),"pid");
    showhis();
}
////下一位就诊
void systemlog::on_nextpushButton_clicked()
{

    ui->tmedicinetextEdit->clear();
    ui->tsuggtextEdit_2->clear();
    if(n!=hnum)
        n++;
    if(n==hnum)
    {
        QMessageBox::information(this,"提示","已完成今天最后一wei病人");
        //清除
        ui->preturnlineEdit1->clear();
        ui->phlineEdit1->clear();
        ui->pnamelineEdit_51->clear();
        ui->psexlineEdit1->clear();
        ui->pbirthlineEdit_61->clear();
        ui->pdrugtextEdit_41->clear();
        ui->pihistextEdit_31->clear();
        ui->phistory->clear();
        ui->tmedicinetextEdit->clear();
        ui->tsuggtextEdit_2->clear();
    }
    else
    {
        Csql.Tsearch("hungnum","hnum,pid,hret","hnum",nowtime,"date"," ASC");
        showpatient(n);
    }
}
///显示病人病史
void systemlog::showhis()
{
    ui->phistory->horizontalHeader()->setStretchLastSection(true);
    ui->phistory->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    ui->phistory->setRowCount(Csql.model.rowCount());
    ui->phistory->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    for(int row=0;row<Csql.model.rowCount();++row)
    {
        ////设置自动换行
        int H=20;
        if(Csql.model.record(row).value("pdname").toString().length()/7>1||(Csql.model.record(row).value("pdname").toString().length()%7!=0&&Csql.model.record(row).value("pdname").toString().length()/7==1))
         {
            int M=Csql.model.record(row).value("pdname").toString().length()/7+1;
            ui->phistory->setRowHeight(row,H*M);
         }

        QString ptime=Csql.model.record(row).value("ddate").toString();

        ptime.insert(4,QString("/"));
        ptime.insert(7,QString("/"));

        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(ptime));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(row).value("pdname").toString()));

        ui->phistory->setItem(row,0,item0);
        ui->phistory->setItem(row,1,item1);
    }
}
///查看病史
void systemlog::on_phistory_cellDoubleClicked()
{

}

////病症查询
void systemlog::on_SearchpushButton_clicked()
{

    ui->SlineEdit->setEnabled(false);
    if(ui->SlineEdit->text()!="")
        ui->SearchtextEdit_5->insertPlainText(QString::fromLatin1("%1%2\n").arg("", ui->SlineEdit->text()));
    QStringList searchD=ui->SearchtextEdit_5->toPlainText().split("\n");////分列textedit的每个行为字符串
    ///获取光标所在的行数
    QTextCursor tc = ui->SearchtextEdit_5->textCursor();
    tc.select(QTextCursor::LineUnderCursor);
    int currentrow = tc.blockNumber();
    QString S="SELECT * FROM disease WHERE dsymp LIKE '%"+searchD[0]+"%'";
    QString f=" ";
    for(int i=1;i<currentrow;i++)
    {
        f=" AND dsymp LIKE '%"+searchD[i]+"%'";
        S=S+f;
    }
  //  QMessageBox::information(this,"dd",S);
    Csql.model.setQuery(S);
    showdisease("dname","dtype","drank","dsymp");
    ui->SlineEdit->clear();
    ui->SlineEdit->setEnabled(true);
}
///查询表格显示
void systemlog::showdisease(QString s1, QString s2, QString s3, QString s4)
{
    ui->diseasetableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->diseasetableWidget->setRowCount(Csql.model.rowCount());
    ui->diseasetableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->diseasetableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    ui->diseasetableWidget->setColumnWidth(0,128);
    ui->diseasetableWidget->setColumnWidth(1,65);
    ui->diseasetableWidget->setColumnWidth(2,77);
    for(int i=0;i<Csql.model.rowCount();i++)
    {
        ////设置自动换行
        int H=20;
        if(Csql.model.record(i).value("dsymp").toString().length()/18>1||Csql.model.record(i).value("dname").toString().length()/7>1||(Csql.model.record(i).value("dname").toString().length()%7!=0&&Csql.model.record(i).value("dname").toString().length()/7==1)
                ||(Csql.model.record(i).value("dsymp").toString().length()%18!=0&&Csql.model.record(i).value("dsymp").toString().length()/18==1))
         {
            int M=(Csql.model.record(i).value("dsymp").toString().length()/18+1)>(Csql.model.record(i).value("dname").toString().length()/9+1)? (Csql.model.record(i).value("dsymp").toString().length()/18+1):(Csql.model.record(i).value("dname").toString().length()/7+1);
            ui->diseasetableWidget->setRowHeight(i,H*M);
         }
        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s1).toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s2).toString()));
        QTableWidgetItem *item2= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s3).toString()));
        QTableWidgetItem *item3= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s4).toString()));
        ui->diseasetableWidget->setItem(i,0,item0);
        ui->diseasetableWidget->setItem(i,1,item1);
        ui->diseasetableWidget->setItem(i,2,item2);
        ui->diseasetableWidget->setItem(i,3,item3);
    }
}
/////确诊
void systemlog::on_diseasetableWidget_cellDoubleClicked()
{
    QTableWidgetItem *item=ui->diseasetableWidget->item(ui->diseasetableWidget->currentRow(),0);
    dname=item->text();
    Csql.Dsearch(dname,"trprojects","tdname","tdmedi,tsugg");
    tsuggest=Csql.model.record(0).value("tsugg").toString();
    ui->tsuggtextEdit_2->setText(tsuggest);//治疗建议
   ///药单
    ui->tmedicinetextEdit->clear();
    ui->tmedicinetextEdit->setText(Csql.model.record(0).value("tdmedi").toString());


    ///更新病人病史
    nowtime=time.toString("yyyyMMdd");
    Csql.model.setQuery("SELECT pid FROM hungnum WHERE hnum='"+ui->phlineEdit1->text()+"' AND date='"+nowtime+"'");
    QString pi=Csql.model.record(0).value("pid").toString();
    Csql.model.setQuery("SELECT * FROM patienthis WHERE pid='"+pi+"' AND pdname='"+dname+"' ORDER BY ddate DESC");
    if(Csql.model.record(0).value("pdname").toString()!="")
        showhis();
    else
    {
        Csql.Tsearch("patienthis","ddate,pdname","ddate",pi,"pid");
        showhis();
    }
}
///打印处方
void systemlog::on_finishpushButton_clicked()
{

    Medi=ui->tmedicinetextEdit->toPlainText();
    if(Medi=="")
        QMessageBox::information(this,"提示","请先确诊");
    else
    {
        hnum0=ui->phlineEdit1->text();
        Print *pr;
        pr=new Print(this);
        pr->show();
        if(n==hnum-1)
        {
            n++;
            ui->pushButton_3->setText("完成就诊");
        }
    }

}


///就诊取消
void systemlog::on_pushButton_3_clicked()
{

    if(ui->pushButton_3->text()=="完成就诊")
    {
        //清除
        ui->preturnlineEdit1->clear();
        ui->phlineEdit1->clear();
        ui->pnamelineEdit_51->clear();
        ui->psexlineEdit1->clear();
        ui->pbirthlineEdit_61->clear();
        ui->pdrugtextEdit_41->clear();
        ui->pihistextEdit_31->clear();
        ui->phistory->clear();
        ui->tmedicinetextEdit->clear();
        ui->tsuggtextEdit_2->clear();
    }
   backtomain();
}


///医生资料
void systemlog::on_B_ziliao_clicked()
{
    ui->mainframe->close();
    ui->Apatientframe->close();
    ui->phisframe->close();
    ui->doctorframe->show();
    dupdate(false);
    Csql.Dsearch(did);
    ui->didlineEdit_12->setText(Csql.model.record(0).value("did").toString());
    ui->dnamelineEdit_8->setText(Csql.model.record(0).value("dname").toString());
    ui->dbirthlineEdit_11->setText(Csql.model.record(0).value("dbirth").toString());
    ui->ddepartlineEdit_9->setText(Csql.model.record(0).value("ddepart").toString());
    ui->drightlineEdit_7->setText(Csql.model.record(0).value("dright").toString());
    ui->dpasswordlineEdit_10->setText(Csql.model.record(0).value("dpasswa").toString());
    ui->dpostlineEdit->setText(Csql.model.record(0).value("dpost").toString());
    ui->dpaylineEdit->setText(Csql.model.record(0).value("dpay").toString());
    ui->dsexlineEdit->setText(Csql.model.record(0).value("dsex").toString());
    ui->dresumetextEdit_6->setText(Csql.model.record(0).value("dresume").toString());
    showpic p;
    p.showpict(Csql.model.record(0).value("picdress").toString(),ui->picturepushButton);
    dupdate(true);

}
void systemlog::dupdate(bool bo)
{
    ui->didlineEdit_12->setEnabled(bo);
    ui->dnamelineEdit_8->setEnabled(bo);
    ui->dbirthlineEdit_11->setEnabled(bo);
    ui->ddepartlineEdit_9->setEnabled(bo);
    ui->drightlineEdit_7->setEnabled(bo);
    ui->dpasswordlineEdit_10->setEnabled(bo);
    ui->dpostlineEdit->setEnabled(bo);
    ui->dpaylineEdit->setEnabled(bo);
    ui->dsexlineEdit->setEnabled(bo);
}
///医生资料返回
void systemlog::on_zl_fanhui_clicked()
{
    ui->mainframe->show();
    ui->doctorframe->close();
}

////修改密码
void systemlog::on_B_zhanghao_clicked()
{
    zhanghao z;
    z.setModal(true);
    z.exec();
}
////修改密码
void systemlog::on_zl_queren_clicked()
{
    zhanghao z;
    z.setModal(true);
    z.exec();
}
//进入管理系统
void systemlog::on_commandLinkButton_2_clicked()
{
    Csql.Dsearch(did);
    if(Csql.model.record(0).value("dright").toString()=="yes")
    {
        Management *M;
        M=new Management(this);
        M->show();
        close();
    }
    else
    {
        QMessageBox::warning(this,"警告","你没有管理员权限");
    }
}



