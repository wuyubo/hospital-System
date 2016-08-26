#ifndef SYSTEMLOG_H
#define SYSTEMLOG_H

#include <QMainWindow>
#include "cmysql.h"
#include "management.h"
#include "guanyu.h"
#include "beiwanglu.h"
#include "zhishiku.h"
#include "check.h"
#include "zhanghao.h"
#include "print.h"
#include <QMessageBox>
#include <QDateTime>
#include <QList>
#include <QToolBar>
#include <QList>
#include "showpic.h"
#include "riqi.h"
#include "changeuser.h"

namespace Ui {
class systemlog;
}

class systemlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit systemlog(QWidget *parent = 0);
    ~systemlog();
signals:
 //  void sentdname(QString dname);

private slots:
    void showTime();

    void backtomain();

    void on_B_tianjia_clicked();

    void on_B_quit_clicked();

    void on_B_guanyu_clicked();

    void on_B_beiwanglu_clicked();

    void on_B_zhishiku_clicked();

    void on_B_ziliao_clicked();

    void on_B_check_clicked();

    void on_B_zhanghao_clicked();

    void on_backpushButton_3_clicked();

    void on_zl_fanhui_clicked();

    void on_zl_queren_clicked();

    void on_pushButton_3_clicked();

    void on_hnpushButton_3_clicked();

    void on_SearchpushButton_clicked();

    void on_diseasetableWidget_cellDoubleClicked();

    void on_nextpushButton_clicked();

    void on_finishpushButton_clicked();

    void on_phistory_cellDoubleClicked();

    void on_commandLinkButton_2_clicked();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_commandLinkButton_clicked();

    void on_B_riqi_clicked();

    void on_CbackpushButton_clicked();

    void on_calendarWidget_clicked();

    void on_hungcountcommandLinkButton_3_clicked();

private:
    Ui::systemlog *ui;
    Cmysql Csql;
    //Management *M;
    QDateTime time;
    QString nowtime;
    QTimer *timer;
    void showdisease(QString s1, QString s2, QString s3, QString s4);
    void showhis();
    void showpatient(int i=0);

    void dupdate(bool bo);
};

#endif // SYSTEMLOG_H











