#include "management.h"
#include "ui_management.h"
#include <QMenuBar>
#include <QToolBar>
#include <QMenu>
#include "logm.h"
#include <QList>
#include <QDateTime>
#include <QLineEdit>
int F=0;
bool Al=true;
extern int hnum;
extern QString did;

Management::Management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Management)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();              //获取系统现在的时间
    QString ptime = time.toString("yyyy-MM-dd ddd");     //设置显示格式
    ui->timedlabel_5->setText(ptime);


    ui->lcdNumber_2->setDigitCount(8); //显示格式 hh:mm:ss
    ui->lcdNumber_2->setSegmentStyle(QLCDNumber::Flat); //设置时间显示字体
    ui->lcdNumber_2->display(QTime::currentTime().toString("hh:mm:ss"));

    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

    ui->actionExit->setShortcut(QKeySequence::Close);//设置快捷键
    ui->actionExit->setStatusTip(tr("Quit"));
    ////////////连接菜单的//信号与槽函数
    connect(ui->actionExit,SIGNAL(triggered()),this, SLOT(Aquit()));//连接退出菜单信号
    connect(ui->actionBack,SIGNAL(triggered()),this, SLOT(BackMain()));
    connect(ui->actionChange_user,SIGNAL(triggered()),this,SLOT(Changeuser()));
    connect(ui->actionAdd_doctor_N,SIGNAL(triggered()),this,SLOT(addDoc()));
    connect(ui->actionAdd_diseases,SIGNAL(triggered()),this,SLOT(Adisease()));
    connect(ui->actionAdd_medicines,SIGNAL(triggered()),this,SLOT(AMedicine()));
    connect(ui->actionCalender,SIGNAL(triggered()),this,SLOT(on_B_riqi_clicked()));
    connect(ui->actionAbout_system,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_9_clicked()));
    connect(ui->actionInterDoc,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_3_clicked()));
    connect(ui->actionInterDis,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_4_clicked()));
    connect(ui->actionInterMed,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_6_clicked()));
    connect(ui->actionInterPat,SIGNAL(triggered()),this,SLOT(on_commandLinkButton_2_clicked()));
    connect(ui->deletedpushButton,SIGNAL(clicked()),this,SLOT(on_deletedipushButton_clicked()));
    connect(ui->deletempushButton,SIGNAL(clicked()),this,SLOT(on_deletedipushButton_clicked()));
    connect(ui->commandLinkButton_8,SIGNAL(clicked()),this,SLOT(Changeuser()));
    connect(ui->Dsearch,SIGNAL(editingFinished()),this,SLOT(on_DSpushButton_clicked()));

    //////////显示菜单

    /////////显示工具栏
   QToolBar *toolBar = addToolBar(tr("&系统"));
   QList<QAction*>  Qa;
   Qa<<ui->actionBack<<ui->actionInterDoc<<ui->actionInterPat<<ui->actionInterDis<<ui->actionInterMed<<ui->actionCalender<<ui->actionExit;
   toolBar->addActions(Qa);

   BackMain();

}

Management::~Management()
{
    delete ui;
}
void Management::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm:ss");
    ui->lcdNumber_2->display(text);
}
void Management::Aquit()
{  
    close();
}

void Management::BackMain()
{
    ui->widget_2_main->show();
    ui->Dgroup->close();
    ui->Dframe->close();
    ui->calendarframe->close();
    ui->scrollArea_today->close();
    ui->widget_today->close();
    ui->Swwidget->close();
}

///更改用户
void Management::Changeuser()
{
    changeuser c;
    c.setModal(true);
    c.exec();
}

//添加医生
void Management::addDoc()
{
    Adoctor ad;
    ad.setModal(true);
    ad.exec();
}
///添加病例
void Management::Adisease()
{
    Disease di;
    di.setModal(true);
    di.exec();
}
///添加药物
void Management::AMedicine()
{
    Medicine Me;
    Me.setModal(true);
    Me.exec();
}
///退出系统
void Management::on_commandLinkButton_7_clicked()
{
    close();
}
///医院状况查看
void Management::on_commandLinkButton_clicked()
{
    ui->widget_2_main->close();
    ui->calendarframe->close();
    ui->widget_today->show();
    ui->scrollArea_today->show();
    Csql.model.setQuery("SELECT id FROM patientinf");
    QString s = QString::number(Csql.model.rowCount(), 10);//int to Qstring 10进制

    ui->PcountE->setText(s);
    QDateTime time = QDateTime::currentDateTime();              //获取系统现在的时间
    QString ptime = time.toString("yyyyMMdd");
    ///值班医生
    Csql.Dsearch(did);
    ui->TDoc->horizontalHeader()->setStretchLastSection(true);
    ui->TDoc->setRowCount(Csql.model.rowCount());
    ui->TDoc->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->TDoc->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(0).value("did").toString()));
    QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(0).value("dname").toString()));
    ui->TDoc->setItem(0,0,item0);
    ui->TDoc->setItem(0,1,item1);
    ////病例排行
    Csql.model.setQuery("SELECT * FROM disease ORDER BY dcount DESC");
    ui->TDtableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->TDtableWidget->setRowCount(Csql.model.rowCount());
    ui->TDtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->TDtableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    ui->TDtableWidget->setColumnWidth(0,235);
    ui->TDtableWidget->setColumnWidth(1,78);
    ui->TDtableWidget->setColumnWidth(2,84);
    for(int i=0;i<Csql.model.rowCount();i++)
    {

       ////设置自动换行
       int H=20;
        if(Csql.model.record(i).value("dname").toString().length()/17>1||(Csql.model.record(i).value("dname").toString().length()%17!=0&&Csql.model.record(i).value("dname").toString().length()/17==1))
        {
              int M=Csql.model.record(i).value("dname").toString().length()/17+1;
               ui->TDtableWidget->setRowHeight(i,H*M);
         }
        else
             ui->TDtableWidget->setRowHeight(i,30);

        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("dname").toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("dtype").toString()));
        QTableWidgetItem *item2= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("drank").toString()));
        QTableWidgetItem *item3= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("dcount").toString()));

        ui->TDtableWidget->setItem(i,0,item0);
        ui->TDtableWidget->setItem(i,1,item1);
        ui->TDtableWidget->setItem(i,2,item2);
        ui->TDtableWidget->setItem(i,3,item3);



    }
    ////药品排行
    Csql.model.setQuery("SELECT * FROM medicines ORDER BY mecount DESC");

    ui->TMtableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->TMtableWidget_2->setRowCount(Csql.model.rowCount());
    ui->TMtableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->TMtableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    ui->TMtableWidget_2->setColumnWidth(1,160);
    for(int i=0;i<Csql.model.rowCount();i++)
    {



        ////设置自动换行
        int H=20;
        if(Csql.model.record(i).value("mname").toString().length()/11>1||(Csql.model.record(i).value("mname").toString().length()%11!=0&&Csql.model.record(i).value("mname").toString().length()/11==1))
        {
                  int M=Csql.model.record(i).value("mname").toString().length()/11+1;
                  ui->TMtableWidget_2->setRowHeight(i,H*M);
        }
        else
        {
            ui->TMtableWidget_2->setRowHeight(i,30);
        }
        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("mid").toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("mname").toString()));
        QTableWidgetItem *item2= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("mecount").toString()));
        QTableWidgetItem *item3= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value("mcount").toString()));

        ui->TMtableWidget_2->setItem(i,0,item0);
        ui->TMtableWidget_2->setItem(i,1,item1);
        ui->TMtableWidget_2->setItem(i,2,item2);
        ui->TMtableWidget_2->setItem(i,3,item3);

    }
}
////医生管理
void Management::on_commandLinkButton_3_clicked()
{
    F=0;
    if(!Al) on_backpushButton_clicked();
    ui->widget_2_main->close();//隐藏主界面
    ui->scrollArea_today->close();
    ui->calendarframe->close();
    ui->widget_today->close();
    ui->Swwidget->close();


    ui->Dgroup->show();//显示当前界面
    ui->Dframe->show();
    ui->ADpushButton->show();
    ui->ADpushButton->setText("添加医生");
    ui->Dsearch->clear();
    ///树查找设置
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("医生信息");
    ui->treeWidget->setColumnCount(1); //设置treeWiget 的列数

    addtreef("全科","doctorinf","ddepart","dname");
    addtreef("外科","doctorinf","ddepart","dname");
    addtreef("内科","doctorinf","ddepart","dname");
    addtreef("眼科","doctorinf","ddepart","dname");
    addtreef("妇科","doctorinf","ddepart","dname");

    addtreef("男科","doctorinf","ddepart","dname");

    /////显示总数
  //  Csql.model.setQuery("SELECT id FROM doctorinf");
    Csql.Tsearch();
    QString s = QString::number(Csql.model.rowCount(), 10);//int to Qstring 10进制
    ui->cout->setText(s);
    QFont ft;
    ft.setPointSize(16);
    ui->cout->setFont(ft);//设字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->cout->setPalette(pa);//颜色
    ///查找表的初始化
    ui->DStableWidget_3->clear();
    ui->DStableWidget_3->setRowCount(0);
    QStringList header;
    header<<"编号"<<"姓名";
    ui->DStableWidget_3->setHorizontalHeaderLabels(header);
    ////排行表
    header.clear();
    header<<"编号"<<"姓名"<<"科目"<<"治疗"<<"入职时间";
    ui->DtableWidget_3->setHorizontalHeaderLabels(header);
    ShowD("did","dname","ddepart","dcount","didate");

    ui->Dgroup->setTitle("查找医生");
    ui->allCout->setText("全体医生共有");
    ui->m->setText("men");
    ui->label_11->setText("医生资历排行");


}
///病例管理
void Management::on_commandLinkButton_4_clicked()
{
    F=1;
    if(!Al) on_backpushButton_clicked();
    ui->scrollArea_today->close();
    ui->widget_today->close();
    ui->calendarframe->close();
    ui->widget_2_main->close();
    ui->Swwidget->close();

    ui->Dgroup->show();
    ui->Dframe->show();
    ui->ADpushButton->show();
    ui->ADpushButton->setText("添加病例");
     ui->Dsearch->clear();
     ///树查找设置
     ui->treeWidget->clear();
     ui->treeWidget->setHeaderLabel("病例信息");
     ui->treeWidget->setColumnCount(1); //设置treeWiget 的列数

     addtreef("全科","disease","dtype","dname");
     addtreef("外科","disease","dtype","dname");
     addtreef("内科","disease","dtype","dname");
     addtreef("眼科","disease","dtype","dname");
     addtreef("妇科","disease","dtype","dname");
     addtreef("男科","disease","dtype","dname");
     /////显示总数
     Csql.Tsearch("disease","*","dcount");//
     QString s = QString::number(Csql.model.rowCount(), 10);//int to Qstring 10进制
     ui->cout->setText(s);
     QFont ft;
     ft.setPointSize(16);
     ui->cout->setFont(ft);//设字号
     QPalette pa;
     pa.setColor(QPalette::WindowText,Qt::red);
     ui->cout->setPalette(pa);//颜色

    ///查找表的初始化
    ui->DStableWidget_3->clear();
    ui->DStableWidget_3->setRowCount(0);
    QStringList header;
    header<<"名称"<<"科目";
    ui->DStableWidget_3->setHorizontalHeaderLabels(header);
    ////排行表
    header.clear();
    header<<"名称"<<"科目"<<"严重程度"<<"病例次数"<<"入库时间";
    ui->DtableWidget_3->setHorizontalHeaderLabels(header);
    ShowD("dname","dtype","drank","dcount","didate");

    ui->Dgroup->setTitle("查找病例");
    ui->allCout->setText("共有病例");
    ui->m->setText(" ");
    ui->label_11->setText("病例排行");
 }
///药库管理
void Management::on_commandLinkButton_6_clicked()
{
    F=2;
    if(!Al) on_backpushButton_clicked();
    ui->scrollArea_today->close();
    ui->calendarframe->close();
    ui->widget_today->close();
    ui->widget_2_main->close();
    ui->Swwidget->close();

    ui->Dgroup->show();
    ui->Dframe->show();
    ui->ADpushButton->show();
    ui->ADpushButton->setText("添加药品");
    ui->Dsearch->clear();
      ///树查找设置
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("病例信息");
    ui->treeWidget->setColumnCount(1); //设置treeWiget 的列数

    addtreef("全科","medicines","mtype","mname");
    addtreef("外科","medicines","mtype","mname");
    addtreef("内科","medicines","mtype","mname");
    addtreef("眼科","medicines","mtype","mname");
    addtreef("妇科","medicines","mtype","mname");
    addtreef("男科","medicines","mtype","mname");
     /////显示总数
     Csql.Tsearch("medicines","*","mcount"," ASC");
     QString s = QString::number(Csql.model.rowCount(), 10);//int to Qstring 10进制
     ui->cout->setText(s);
     QFont ft;
     ft.setPointSize(16);
     ui->cout->setFont(ft);//设字号
     QPalette pa;
     pa.setColor(QPalette::WindowText,Qt::red);
     ui->cout->setPalette(pa);//颜色
    ///查找表的初始化
    ui->DStableWidget_3->clear();
    ui->DStableWidget_3->setRowCount(0);
    QStringList header;
    header<<"编号"<<"药名";
    ui->DStableWidget_3->setHorizontalHeaderLabels(header);
    ////排行表
    header.clear();
    header<<"编号"<<"药名"<<"科目"<<"出库总数"<<"余量";
    ui->DtableWidget_3->setHorizontalHeaderLabels(header);
    ShowD("mid","mname","mtype","mecount","mcount");

    ui->Dgroup->setTitle("查找药品");
    ui->allCout->setText("药库共有药品");
    ui->m->setText(" ");
    ui->label_11->setText("药品余量警报排行");

}
////病人信息管理
void Management::on_commandLinkButton_2_clicked()
{
    F=3;
  if(!Al) on_backpushButton_clicked();

    ui->scrollArea_today->close();
    ui->widget_today->close();
    ui->calendarframe->close();
    ui->widget_2_main->close();
    ui->Swwidget->close();

    ui->Dgroup->show();
    ui->Dframe->show();
    ui->ADpushButton->close();
    ui->Dsearch->clear();
     ///树查找设置
   ui->treeWidget->clear();
   ui->treeWidget->setHeaderLabel("病例信息");
   ui->treeWidget->setColumnCount(1); //设置treeWiget 的列数

   addtreef("会员","patientinf","pvip","pname");
   addtreef("NO会员","patientinf","pvip","pname");
     /////显示总数
     Csql.Tsearch("patientinf","*","pcount");
     QString s = QString::number(Csql.model.rowCount(), 10);//int to Qstring 10进制
     ui->cout->setText(s);
     QFont ft;
     ft.setPointSize(16);
     ui->cout->setFont(ft);//设字号
     QPalette pa;
     pa.setColor(QPalette::WindowText,Qt::red);
     ui->cout->setPalette(pa);//颜色
    ///查找表的初始化
    ui->DStableWidget_3->clear();
    ui->DStableWidget_3->setRowCount(0);
    QStringList header;
    header<<"身份证号"<<"姓名";
    ui->DStableWidget_3->setHorizontalHeaderLabels(header);
    ////排行表
    header.clear();
    header<<"身份证号"<<"姓名"<<"会员"<<"看病总数"<<"登记时间";
    ui->DtableWidget_3->setHorizontalHeaderLabels(header);
    ShowD("pid","pname","pvip","pcount","pidate");

    ui->Dgroup->setTitle("查找病人");
    ui->allCout->setText("病库共有病人");
    ui->m->setText("li");
    ui->label_11->setText("重点病人关注");

}


///查找信息
void Management::on_DSpushButton_clicked()
{
    QString a,b;
    ui->Dsearch->setEnabled(false);
//    if(ui->Dsearch->text()=="") QMessageBox::information(this,"提醒","输入不能为空");
     if(F==0)
    {
        Csql.Dsearch2(ui->Dsearch->text(),"did","dname","doctorinf","did,dname");
        a="did";
        b="dname";
    }
    else if(F==1)
    {
        Csql.Dsearch2(ui->Dsearch->text());
        a="dname";
        b="dtype";
    }
    else if(F==2)
    {

        Csql.Dsearch2(ui->Dsearch->text(),"mid","mname","medicines","mid,mname");
        a="mid";
        b="mname";
    }
    else if(F==3)
    {
        Csql.Dsearch2(ui->Dsearch->text(),"pid","pname","patientinf","pid,pname");
        a="pid";
        b="pname";
    }

    if(Csql.model.record(0).value(a).toString()!="")
    {
        Searchs(a,b);
    }
    else if(ui->Dsearch->text()!="") QMessageBox::information(this,"提示","没有"+ui->Dsearch->text());
    ui->Dsearch->setEnabled(true);
}
//查找表的显示
void Management::Searchs(QString id,QString name)
{
    ui->DStableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->DStableWidget_3->setRowCount(Csql.model.rowCount());
    ui->DStableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->DStableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    for(int i=0;i<Csql.model.rowCount();i++)
    {
        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(id).toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(name).toString()));
        ui->DStableWidget_3->setItem(i,0,item0);
        ui->DStableWidget_3->setItem(i,1,item1);
    }
}
///排行表显示
void Management::ShowD(QString s1, QString s2, QString s3, QString s4, QString s5)
{
    ui->DtableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->DtableWidget_3->setRowCount(Csql.model.rowCount());
    ui->DtableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->DtableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    if(F==3)
    {
        ui->DtableWidget_3->setColumnWidth(0,170);
        ui->DtableWidget_3->setColumnWidth(1,110);
        ui->DtableWidget_3->setColumnWidth(2,60);
        ui->DtableWidget_3->setColumnWidth(3,87);

    }
    else
    {
        ui->DtableWidget_3->setColumnWidth(0,110);
        ui->DtableWidget_3->setColumnWidth(1,110);
        ui->DtableWidget_3->setColumnWidth(2,110);
        ui->DtableWidget_3->setColumnWidth(3,100);
    }
     if(F==1)
    {
        ui->DtableWidget_3->setColumnWidth(0,186);
        ui->DtableWidget_3->setColumnWidth(1,80);
    }
     else if(F==0||F==2)
     {
         ui->DtableWidget_3->setColumnWidth(0,110);
         ui->DtableWidget_3->setColumnWidth(1,110);
     }
    if(F==2)
    {
        ui->DtableWidget_3->setColumnWidth(1,160);
    }
    else if(F==0)
    {
        ui->DtableWidget_3->setColumnWidth(1,110);
    }
    for(int i=0;i<Csql.model.rowCount();i++)
    {

        if(F==1)
        {

            ////设置自动换行
            int H=20;
            if(Csql.model.record(i).value("dname").toString().length()/13>1||(Csql.model.record(i).value("dname").toString().length()%13!=0&&Csql.model.record(i).value("dname").toString().length()/13==1))
            {
                  int M=Csql.model.record(i).value("dname").toString().length()/13+1;
                  ui->DtableWidget_3->setRowHeight(i,H*M);
            }
         }
       else if(F==2)
        {

            ////设置自动换行
            int H=20;
            if(Csql.model.record(i).value("mname").toString().length()/11>1||(Csql.model.record(i).value("mname").toString().length()%11!=0&&Csql.model.record(i).value("mname").toString().length()/11==1))
            {
                  int M=Csql.model.record(i).value("mname").toString().length()/11+1;
                  ui->DtableWidget_3->setRowHeight(i,H*M);
            }
        }
        else
        {
            ui->DtableWidget_3->setRowHeight(i,30);
        }
        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s1).toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s2).toString()));
        QTableWidgetItem *item2= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s3).toString()));
        QTableWidgetItem *item3= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s4).toString()));
        QString date=Csql.model.record(i).value(s5).toString();
        if(F!=2)
        {
             date.insert(4,QString("/"));
             date.insert(7,QString("/"));
        }
        QTableWidgetItem *item4= new QTableWidgetItem(tr("%1").arg(date));
        ui->DtableWidget_3->setItem(i,0,item0);
        ui->DtableWidget_3->setItem(i,1,item1);
        ui->DtableWidget_3->setItem(i,2,item2);
        ui->DtableWidget_3->setItem(i,3,item3);
        ui->DtableWidget_3->setItem(i,4,item4);
    }
}
void Management::on_ADpushButton_clicked()
{
    if(F==0) addDoc();
    else if(F==1) Adisease();
    else if(F==2) AMedicine();
}


//设置只读
void Management::readonly(bool bo)
{
    ui->lineEditid->setReadOnly(bo);
    ui->lineEditname->setReadOnly(bo);
    ui->lineEditsex->setReadOnly(bo);
    ui->lineEditbirth->setReadOnly(bo);
    ui->lineEditpost->setReadOnly(bo);
    ui->lineEditdepart->setReadOnly(bo);
    ui->lineEditright->setReadOnly(bo);
    ui->lineEditdcount->setReadOnly(bo);
    ui->lineEditdate->setReadOnly(bo);
    ui->lineEditpay->setReadOnly(bo);
    ui->textEditdesc->setReadOnly(bo);

    ui->dnamelineEdit->setReadOnly(bo);
    ui->dtypelineEdit->setReadOnly(bo);
    ui->dranklineEdit->setReadOnly(bo);
    ui->dcountlineEdit->setReadOnly(bo);
    ui->didatelineEdit->setReadOnly(bo);
    ui->dsymptextEdit->setReadOnly(bo);
    ui->ddesctextEdit->setReadOnly(bo);

    ui->midlineEdit->setReadOnly(bo);
    ui->mnamelineEdit->setReadOnly(bo);
    ui->mtypelineEdit->setReadOnly(bo);
    ui->musageineEdit->setReadOnly(bo);
    ui->mcountlineEdit->setReadOnly(bo);
    ui->mpricelineEdit->setReadOnly(bo);
    ui->midatelineEdit->setReadOnly(bo);
    ui->mecountlineEdit->setReadOnly(bo);
    ui->mdesctextEdit->setReadOnly(bo);

    ui->pidlineEdit->setReadOnly(bo);
    ui->pnamelineEdit->setReadOnly(bo);
    ui->psexlineEdit->setReadOnly(bo);
    ui->pbirthlineEdit->setReadOnly(bo);
    ui->pviplineEdit->setReadOnly(bo);
    ui->pcountlineEdit->setReadOnly(bo);
    ui->pidatelineEdit->setReadOnly(bo);
    ui->pdrugtextEdit->setReadOnly(bo);
    ui->pihistextEdit->setReadOnly(bo);
}
void Management::updatetext(bool bo)
{


    ui->lineEditid->setEnabled(bo);
    ui->lineEditname->setEnabled(bo);
    ui->lineEditsex->setEnabled(bo);
    ui->lineEditbirth->setEnabled(bo);
    ui->lineEditpost->setEnabled(bo);
    ui->lineEditdepart->setEnabled(bo);
    ui->lineEditright->setEnabled(bo);
    ui->lineEditdcount->setEnabled(bo);
    ui->lineEditdate->setEnabled(bo);
    ui->lineEditpay->setEnabled(bo);
    ui->textEditdesc->setEnabled(bo);

  //  ui->dnamelineEdit->setEnabled(bo);
    ui->dtypelineEdit->setEnabled(bo);
    ui->dranklineEdit->setEnabled(bo);
    ui->dcountlineEdit->setEnabled(bo);
    ui->didatelineEdit->setEnabled(bo);
    ui->dsymptextEdit->setEnabled(bo);
    ui->ddesctextEdit->setEnabled(bo);

    ui->midlineEdit->setEnabled(bo);
   // ui->mnamelineEdit->setEnabled(bo);
    ui->mtypelineEdit->setEnabled(bo);
    ui->musageineEdit->setEnabled(bo);
    ui->mcountlineEdit->setEnabled(bo);
    ui->mpricelineEdit->setEnabled(bo);
    ui->midatelineEdit->setEnabled(bo);
    ui->mecountlineEdit->setEnabled(bo);
    ui->mdesctextEdit->setEnabled(bo);

    ui->pidlineEdit->setEnabled(bo);
    ui->pnamelineEdit->setEnabled(bo);
    ui->psexlineEdit->setEnabled(bo);
    ui->pbirthlineEdit->setEnabled(bo);
    ui->pviplineEdit->setEnabled(bo);
    ui->pcountlineEdit->setEnabled(bo);
    ui->pidatelineEdit->setEnabled(bo);
    ui->pdrugtextEdit->setEnabled(bo);
    ui->pihistextEdit->setEnabled(bo);
}
//修改信息按钮

void Management::on_alterButton_clicked()
{
    if(Al)
    {
      // readonly(false);
        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::red);
        if(F==0)
        {
            ui->deletedpushButton->close();
            ui->hisdpushButton_2->close();

            ui->lpost->setPalette(pa);//颜色
            ui->lpay->setPalette(pa);//颜色
            ui->ltesume->setPalette(pa);//颜色
            ui->lright->setPalette(pa);//颜色


            ui->lineEditpost->setReadOnly(false);
            ui->lineEditdepart->setReadOnly(false);
            ui->lineEditright->setReadOnly(false);
            ui->lineEditpay->setReadOnly(false);
            ui->textEditdesc->setReadOnly(false);

        }
        if(F==1)
        {
            ui->deletedipushButton->close();
            ui->lookprpushButton->close();

            ui->dilabel_17->setPalette(pa);//颜色
            ui->dilabel_18->setPalette(pa);//颜色

            ui->dsymptextEdit->setReadOnly(false);
            ui->ddesctextEdit->setReadOnly(false);
        }
        if(F==2)
        {

            ui->deletempushButton->close();

            ui->mlabel_23->setPalette(pa);//颜色
            ui->mlabel_24->setPalette(pa);//颜色
            ui->mlabel_26->setPalette(pa);//颜色
            ui->mcountlineEdit->setReadOnly(false);
            ui->mpricelineEdit->setReadOnly(false);
            ui->mdesctextEdit->setReadOnly(false);

        }
        if(F==3)
        {

            ui->hisppushButton->close();

            ui->plabel_32->setPalette(pa);//颜色
            ui->plabel_35->setPalette(pa);//颜色
            ui->plabel_36->setPalette(pa);//颜色
            ui->pviplineEdit->setReadOnly(false);
            ui->pdrugtextEdit->setReadOnly(false);
            ui->pihistextEdit->setReadOnly(false);
        }
        ui->alterButton->setText("确定修改");
        ui->backpushButton->setText("取消");

        Al=false;

    }
    else
    {
        updatetext(false);
        if(F==0)
        {
            //ui->lineEditdepart->textChanged();

            Csql.Infupdate(ui->lineEditpost->text(),"dpost",ui->lineEditid->text());
            Csql.Infupdate(ui->lineEditdepart->text(),"ddepart",ui->lineEditid->text());
            Csql.Infupdate(ui->lineEditright->text(),"dright",ui->lineEditid->text());
            Csql.Infupdate(ui->lineEditpay->text(),"dpay",ui->lineEditid->text());
            Csql.Infupdate(ui->textEditdesc->toPlainText(),"dresume",ui->lineEditid->text());
        }
        if(F==1)
        {
            Csql.Infupdate(ui->ddesctextEdit->toPlainText(),"ddesc",ui->dnamelineEdit->toPlainText(),"dname","disease");
            Csql.Infupdate(ui->dsymptextEdit->toPlainText(),"dsymp",ui->dnamelineEdit->toPlainText(),"dname","disease");
        }
        if(F==2)
        {
            Csql.Infupdate(ui->mpricelineEdit->text(),"mprice",ui->midlineEdit->text(),"mid","medicines");
            Csql.Infupdate(ui->mcountlineEdit->text(),"mcount",ui->midlineEdit->text(),"mid","medicines");
            Csql.Infupdate(ui->mdesctextEdit->toPlainText(),"mdesc",ui->midlineEdit->text(),"mid","medicines");
        }
        if(F==3)
        {
            Csql.Infupdate(ui->pviplineEdit->text(),"pvip",ui->pidlineEdit->text(),"pid","patientinf");
            Csql.Infupdate(ui->pdrugtextEdit->toPlainText(),"pdrug",ui->pidlineEdit->text(),"pid","patientinf");
            Csql.Infupdate(ui->pihistextEdit->toPlainText(),"pihis",ui->pidlineEdit->text(),"pid","patientinf");
        }
        updatetext(true);
        QMessageBox::information(this,"提示","修改成功");
        ui->deletedipushButton->show();
        ui->deletedpushButton->show();
        ui->deletempushButton->show();
        ui->lookprpushButton->show();
        ui->hisdpushButton_2->show();
        ui->hisppushButton->show();
        ui->alterButton->setText("修改信息");
        ui->backpushButton->setText("返回");
        Al=true;
        readonly(true);
    }
}
void Management::on_backpushButton_clicked()
{
    if(Al)
    {
        ui->Swwidget->close();
        ui->Dframe->show();
    }
    else
    {
        ui->deletedipushButton->show();
        ui->deletedpushButton->show();
        ui->deletempushButton->show();
        ui->lookprpushButton->show();
        ui->hisdpushButton_2->show();
        ui->hisppushButton->show();
        ui->alterButton->setText("修改信息");
        ui->backpushButton->setText("返回");
        Al=true;
        readonly(true);
    }
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);
    ui->lpost->setPalette(pa);//颜色
    ui->lpay->setPalette(pa);//颜色
    ui->ltesume->setPalette(pa);//颜色
    ui->lright->setPalette(pa);//颜色

    ui->dilabel_17->setPalette(pa);//颜色
    ui->dilabel_18->setPalette(pa);//颜色

    ui->plabel_32->setPalette(pa);//颜色
    ui->plabel_35->setPalette(pa);//颜色
    ui->plabel_36->setPalette(pa);//颜色

    ui->mlabel_23->setPalette(pa);//颜色
    ui->mlabel_24->setPalette(pa);//颜色
    ui->mlabel_26->setPalette(pa);//
}
///查看信息
void Management::inf(QString S)
{
    ui->Swwidget->show();
    ui->Dframe->close();
    ui->groupBoxdisease->close();
    ui->INFgroupBox->close();
    ui->patientgroupBox->close();
    ui->medicinesgroupBox->close();
    ui->hisgroupBox->close();

    readonly(true);
    if(F==0)
    {
        ui->INFgroupBox->show();
        Csql.Dsearch(S);
        ui->lineEditid->setText(Csql.model.record(0).value("did").toString());
        ui->lineEditname->setText(Csql.model.record(0).value("dname").toString());
        ui->lineEditsex->setText(Csql.model.record(0).value("dsex").toString());
        ui->lineEditbirth->setText(Csql.model.record(0).value("dbirth").toString());
        ui->lineEditpost->setText(Csql.model.record(0).value("dpost").toString());
        ui->lineEditdepart->setText(Csql.model.record(0).value("ddepart").toString());
        ui->lineEditright->setText(Csql.model.record(0).value("dright").toString());
        ui->lineEditdcount->setText(Csql.model.record(0).value("dcount").toString());
        QString date=Csql.model.record(0).value("didate").toString();
        date.insert(4,QString("/"));
        date.insert(7,QString("/"));
        ui->lineEditdate->setText(date);
        ui->lineEditpay->setText(Csql.model.record(0).value("dpay").toString());
        ui->textEditdesc->setText(Csql.model.record(0).value("dresume").toString());

        p.showpict(Csql.model.record(0).value("picdress").toString(),ui->picturepushButton);
    }
    if(F==1)
    {
        ui->groupBoxdisease->show();
        Csql.Dsearch1(S);
        ui->dnamelineEdit->setText(Csql.model.record(0).value("dname").toString());
        ui->dtypelineEdit->setText(Csql.model.record(0).value("dtype").toString());
        ui->dranklineEdit->setText(Csql.model.record(0).value("drank").toString());
        ui->dcountlineEdit->setText(Csql.model.record(0).value("dcount").toString());
        QString date=Csql.model.record(0).value("didate").toString();
        date.insert(4,QString("/"));
        date.insert(7,QString("/"));
        ui->didatelineEdit->setText(date);
        ui->dsymptextEdit->setText(Csql.model.record(0).value("dsymp").toString());
        ui->ddesctextEdit->setText(Csql.model.record(0).value("ddesc").toString());

    }
    if(F==2)
    {
        ui->medicinesgroupBox->show();
        Csql.Dsearch(S,"medicines","mid");
        ui->midlineEdit->setText(Csql.model.record(0).value("mid").toString());
        ui->mnamelineEdit->setText(Csql.model.record(0).value("mname").toString());
        ui->mtypelineEdit->setText(Csql.model.record(0).value("mtype").toString());
        ui->musageineEdit->setText(Csql.model.record(0).value("musage").toString());
        ui->mcountlineEdit->setText(Csql.model.record(0).value("mcount").toString());
        ui->mpricelineEdit->setText(Csql.model.record(0).value("mprice").toString());
        QString date=Csql.model.record(0).value("midate").toString();
        date.insert(4,QString("/"));
        date.insert(7,QString("/"));
        ui->midatelineEdit->setText(date);
        ui->mecountlineEdit->setText(Csql.model.record(0).value("mecount").toString());
        ui->mdesctextEdit->setText(Csql.model.record(0).value("mdesc").toString());
    }
    if(F==3)
    {
        ui->patientgroupBox->show();
        Csql.Dsearch(S,"patientinf","pid");
        ui->pidlineEdit->setText(Csql.model.record(0).value("pid").toString());
        ui->pnamelineEdit->setText(Csql.model.record(0).value("pname").toString());
        ui->psexlineEdit->setText(Csql.model.record(0).value("psex").toString());
        ui->pbirthlineEdit->setText(Csql.model.record(0).value("pbirth").toString());
        ui->pviplineEdit->setText(Csql.model.record(0).value("pvip").toString());
        ui->pcountlineEdit->setText(Csql.model.record(0).value("pcount").toString());
        QString date=Csql.model.record(0).value("pidate").toString();
        date.insert(4,QString("/"));
        date.insert(7,QString("/"));
        ui->pidatelineEdit->setText(date);
        ui->pdrugtextEdit->setText(Csql.model.record(0).value("pdrug").toString());
        ui->pihistextEdit->setText(Csql.model.record(0).value("pihis").toString());
    }

}
void Management::on_DStableWidget_3_cellDoubleClicked()
{
    QTableWidgetItem *item=ui->DStableWidget_3->item(ui->DStableWidget_3->currentRow(),0);
     p.showpict(":/new/prefix1/D:/360安全浏览器下载/新建文件夹/213291_094621027_2.jpg",ui->picturepushButton);
    inf(item->text());
}

///查看信息
void Management::on_DtableWidget_3_cellDoubleClicked()
{
    QTableWidgetItem *item=ui->DtableWidget_3->item(ui->DtableWidget_3->currentRow(),0);
     p.showpict(":/new/prefix1/D:/360安全浏览器下载/新建文件夹/213291_094621027_2.jpg",ui->picturepushButton);
    inf(item->text());
}
////添加树干
void Management::addtreef(QString name,QString tb,QString D,QString S)
{
    Csql.Dsearch(name,tb,D,S);
    QTreeWidgetItem *tree=new QTreeWidgetItem;
    tree->setText(0,name);
    ui->treeWidget->addTopLevelItem(tree);
    ///添加树枝，显示信息
    for(int i=0;i<Csql.model.rowCount();i++)
    {
        QTreeWidgetItem *treec=new QTreeWidgetItem;
        treec->setText(0,Csql.model.record(i).value(S).toString());
        tree->addChild(treec);
    }
}
//树的双击事件查看信息
void Management::on_treeWidget_doubleClicked()
{

    if(F==3)
    {
        if(ui->treeWidget->currentItem()->text(0)=="会员")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="NO会员")ui->Swwidget->close();
        else
        {
             inf(ui->treeWidget->currentItem()->text(0));

        }

    }
    else {
        if(ui->treeWidget->currentItem()->text(0)=="全科")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="外科")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="内科")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="眼科")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="妇科")ui->Swwidget->close();
        else if(ui->treeWidget->currentItem()->text(0)=="男科")ui->Swwidget->close();

        else
        {

             if(F==0)
             {
                 p.showpict(":/new/prefix1/D:/360安全浏览器下载/新建文件夹/213291_094621027_2.jpg",ui->picturepushButton);
                 Csql.Dsearch(ui->treeWidget->currentItem()->text(0),"doctorinf","dname","did");
                  inf(Csql.model.record(0).value("did").toString());
             }
             else
                inf(ui->treeWidget->currentItem()->text(0));

        }

    }
}
///删除信息
void Management::on_deletedipushButton_clicked()
{
    ui->midlineEdit->setEnabled(false);
    if(F==0)
    {
        Csql.Infdelete(ui->lineEditid->text());
        Csql.Infdelete(ui->lineEditid->text(),"did","doctorhis");

    }
    if(F==1)
    {
        Csql.Infdelete(ui->dnamelineEdit->toPlainText(),"dname","disease");
        Csql.Infdelete(ui->dnamelineEdit->toPlainText(),"tdname","trprojects");

    }
    if(F==2) Csql.Infdelete(ui->midlineEdit->text(),"mid","medicines");
    QMessageBox::information(this,"提示","删除成功");
    ui->midlineEdit->setEnabled(true);
    ui->Swwidget->close();
    ui->Dframe->show();
}
///查看医生工作纪录
void Management::on_hisdpushButton_2_clicked()
{
    ui->lineEditid->setEnabled(false);
    ui->lineEditname->setEnabled(false);
    ui->INFgroupBox->close();
    ui->alterButton->close();
    ui->hisgroupBox->show();
    ui->hisgroupBox->setTitle(ui->lineEditname->text()+"医生工作纪录");

    Csql.Tsearch("doctorhis","ddate,pname,psex,pdname,pdrank","ddate",ui->lineEditid->text(),"did");
    ui->histableWidget_3->setColumnCount(5);
    QStringList header;
    header<<"日期"<<"病人姓名"<<"病人性别"<<"诊病"<<"严重程度";
    ui->histableWidget_3->setHorizontalHeaderLabels(header);

    ShowH("ddate","pname","psex","pdname","pdrank");

    ui->lineEditid->setEnabled(true);
    ui->lineEditname->setEnabled(true);
}
///查看病史
void Management::on_hisppushButton_clicked()
{
    ui->pidlineEdit->setEnabled(false);
    ui->pnamelineEdit->setEnabled(false);
    ui->alterButton->close();
    ui->patientgroupBox->close();
    ui->hisgroupBox->show();
    ui->hisgroupBox->setTitle(ui->pnamelineEdit->text()+"-病史");

    Csql.Tsearch("patienthis","ddate,pdname,pdtype,pdrank,dname","ddate",ui->pidlineEdit->text(),"pid");

    ui->histableWidget_3->setColumnCount(5);
    QStringList header;
    header<<"日期"<<"诊病"<<"严重程度"<<"科目"<<"医生姓名";
    ui->histableWidget_3->setHorizontalHeaderLabels(header);
    ShowH("ddate","pdname","pdtype","pdrank","dname");
    ui->pidlineEdit->setEnabled(true);
    ui->pnamelineEdit->setEnabled(true);
}
///查看治疗方案
void Management::on_lookprpushButton_clicked()
{


    ui->groupBoxdisease->close();
    ui->alterButton->close();
    ui->hisgroupBox->show();
    ui->hisgroupBox->setTitle(ui->dnamelineEdit->toPlainText()+"-治疗方案");

    Csql.Tsearch("trprojects","*","tdname",ui->dnamelineEdit->toPlainText(),"tdname");

    ui->histableWidget_3->setColumnCount(2);
    QStringList header;
    header<<"治疗药单"<<"治疗建议";
    ui->histableWidget_3->setHorizontalHeaderLabels(header);
    ShowH("tdmedi","tsugg","","","");

}
//修改治疗方案
void Management::on_alterpropushButton_clicked()
{
    if(ui->alterpropushButton->text()=="修改方案")
    {
        ui->alterpropushButton->setText("确定修改");
        ui->hisbackpushButton->setText("取消");
        ui->histableWidget_3->setEditTriggers(QAbstractItemView::AllEditTriggers);//设置可读
    }
    else
    {
         ui->histableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
         QTableWidgetItem *item0=ui->histableWidget_3->item(0,0);
         QTableWidgetItem *item1=ui->histableWidget_3->item(0,1);
         Csql.Infupdate(item0->text(),"tdmedi",ui->dnamelineEdit->toPlainText(),"tdname","trprojects");
         Csql.Infupdate(item1->text(),"tsugg",ui->dnamelineEdit->toPlainText(),"tdname","trprojects");
         QMessageBox::information(this,"提示","修改成功");
         ui->alterpropushButton->setText("修改方案");
         ui->hisbackpushButton->setText("返回");
    }
}


void Management::on_hisbackpushButton_clicked()
{
    if(ui->hisbackpushButton->text()=="取消")
    {
        ui->alterpropushButton->setText("修改方案");
        ui->hisbackpushButton->setText("返回");
    }
    else
    {
        ui->hisgroupBox->close();
        ui->alterButton->show();

        if(F==0)
            ui->INFgroupBox->show();
        if(F==3)
            ui->patientgroupBox->show();
        if(F==1)
            ui->groupBoxdisease->show();
    }
}
///history表显示
void Management::ShowH(QString s1, QString s2, QString s3, QString s4, QString s5)
{
    ui->histableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->histableWidget_3->setRowCount(Csql.model.rowCount());
    ui->histableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置只读
    ui->histableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中方式
    for(int i=0;i<Csql.model.rowCount();i++)
    {
        ////设置自动换行
        int H=20;
        if(Csql.model.record(i).value("pdname").toString().length()/7>1)
        {
              int M=Csql.model.record(i).value("pdname").toString().length()/7+1;
              ui->histableWidget_3->setRowHeight(i,H*M);
        }

        QTableWidgetItem *item0= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s1).toString()));
        QTableWidgetItem *item1= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s2).toString()));
        QTableWidgetItem *item2= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s3).toString()));
        QTableWidgetItem *item3= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s4).toString()));
        QTableWidgetItem *item4= new QTableWidgetItem(tr("%1").arg(Csql.model.record(i).value(s5).toString()));
        if(F==1)
        {
            ui->histableWidget_3->setColumnWidth(0,310);
            ui->histableWidget_3->setRowHeight(0,360);
            ui->histableWidget_3->setRowHeight(1,360);
            ui->histableWidget_3->setItem(i,0,item0);
            ui->histableWidget_3->setItem(i,1,item1);
        }
        else
        {
            ui->histableWidget_3->setColumnWidth(0,100);
            ui->histableWidget_3->setColumnWidth(1,100);
            ui->histableWidget_3->setRowHeight(0,30);
            ui->histableWidget_3->setRowHeight(1,30);

            ui->histableWidget_3->setItem(i,0,item0);
            ui->histableWidget_3->setItem(i,1,item1);
            ui->histableWidget_3->setItem(i,2,item2);
            ui->histableWidget_3->setItem(i,3,item3);
            ui->histableWidget_3->setItem(i,4,item4);
        }
    }
}


///关于本系统
void Management::on_commandLinkButton_9_clicked()
{
    guanyu g;
    g.setModal(true);
    g.exec();
}
///医疗百科
void Management::on_doctorbookcommandLinkButton_10_clicked()
{
    QMessageBox::information(this,"医疗百科","此功能在开发中");
}

void Management::on_systemMcommandLinkButton_5_clicked()
{
    zhanghao z;
    z.setModal(true);
    z.exec();
}
////查看日历
void Management::on_B_riqi_clicked()
{
    ui->calendarframe->show();
    ui->widget_2_main->close();
    ui->Dgroup->close();
    ui->Dframe->close();

    ui->scrollArea_today->close();
    ui->widget_today->close();
    ui->Swwidget->close();

    QDateTime time = QDateTime::currentDateTime();    //获取系统现在的时间
    QString nowtime=time.toString("yyyy-MM-dd \n ddd");
    QFont ft;
    ft.setPointSize(25);
    ui->TimeL->setFont(ft);//设字号
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    ui->TimeL->setPalette(pa);//颜色
    ui->TimeL->setText("   今天  \n"+nowtime);
}
void Management::on_calendarWidget_clicked()
{
    QDateTime time = QDateTime::currentDateTime();    //获取系统现在的时间
    QString nowtime=time.toString("yyyy-MM-dd \n ddd");
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
void Management::on_CbackpushButton_clicked()
{
    ui->calendarframe->close();
    ui->widget_2_main->show();
}


void Management::on_commandLinkButton_5_clicked()
{
    systemlog *s;
    s= new systemlog(this);
    s->show();
     close();
}

