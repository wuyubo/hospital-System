#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QMainWindow>
#include <QAction>
#include "adoctor.h"
#include "disease.h"
#include "medicine.h"
#include "cmysql.h"
#include "zhanghao.h"
#include "systemlog.h"
#include "showpic.h"
#include "changeuser.h"
#include <QTimer>

#include <QTableWidgetItem>

namespace Ui {
class Management;
}

class Management : public QMainWindow
{
    Q_OBJECT

public:
    explicit Management(QWidget *parent = 0);
    ~Management();

private slots:
    void Aquit();
    void Changeuser();
    void addDoc();
    void BackMain();
    void Adisease();
    void AMedicine();
    void showTime();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_2_clicked();

    void on_DSpushButton_clicked();

    void on_ADpushButton_clicked();

    void on_DStableWidget_3_cellDoubleClicked();

    void on_backpushButton_clicked();

    void on_alterButton_clicked();

    void on_DtableWidget_3_cellDoubleClicked();

    void on_treeWidget_doubleClicked();

    void on_deletedipushButton_clicked();

    void on_hisdpushButton_2_clicked();

    void on_hisppushButton_clicked();

    void on_hisbackpushButton_clicked();

    void on_lookprpushButton_clicked();

    void on_commandLinkButton_9_clicked();

    void on_doctorbookcommandLinkButton_10_clicked();

    void on_systemMcommandLinkButton_5_clicked();



    void on_B_riqi_clicked();

    void on_calendarWidget_clicked();

    void on_CbackpushButton_clicked();

    void on_commandLinkButton_5_clicked();

    void on_alterpropushButton_clicked();

private:
    Ui::Management *ui;
    Cmysql Csql;
    Adoctor *ad;
    showpic p;
    QTimer *timer;
    //systemlog *sys;

    void Searchs(QString id,QString name);
    void ShowD(QString s1,QString s2,QString s3,QString s4,QString s5);
    void ShowH(QString s1,QString s2,QString s3,QString s4,QString s5);
    void readonly(bool bo);
    void updatetext(bool bo);
    void addtreef(QString name,QString tb,QString D,QString S);
    void inf(QString S);//查看资料
  //  void addtreec(QString name);
 //   QAction *quitAction;
 //   QAction *DoctorMa;
};

#endif // MANAGEMENT_H



