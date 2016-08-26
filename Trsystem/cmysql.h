#ifndef CMYSQL_H
#define CMYSQL_H
#include <QtSql/QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include<QMessageBox>
#include <QDateTime>
class Cmysql
{
private:
    QSqlDatabase db;
public:
    Cmysql();
    QSqlQueryModel model;
    void connect();////连接数据库函数
    //医生信息和医生治疗病历查找
    void Dsearch(QString did,QString tb="doctorinf",QString D="did",
                 QString S="*");
    //查找病状、治疗方案
    void Dsearch1(QString ddesc,QString tb="disease",QString N="dname");
    //病因查找和模糊查找
    void Dsearch2(QString dsymp,QString D="dsymp",QString DN="dname",
                  QString tb="disease",QString S="*");
    //查找病人信息、个人病历
    void Psearch(QString pid,QString tb="patienthis",QString P="pid",QString S="*");
    //查找药物
    void Msearch(QString mname,QString tb="medicines",QString M="mname",QString S="mprice");
    void Tsearch(QString tb="doctorinf",QString S="did,dname,ddepart,dcount,didate",
                 QString D="dcount",QString T=" DESC");
    void Tsearch(QString tb,QString S,QString D,QString Wid,QString W,QString T=" DESC");
    //添加信息
    void Infadd(QString tb="0",QString a1="",QString a2="",QString a3="",QString a4="",QString a5="",
                QString a6="",QString a7="",QString a8="",QString a9="",
                QString a11=" ",QString a10="0",QString a12="8000");
    //删除信息
    void Infdelete(QString id,QString S="did",QString tb1="doctorinf");
    //更新信息
    void Infupdate(QString up,QString U,QString P,QString S="did",QString tb="doctorinf");
    //更新信息
    void Infupdate1(QString up,QString U,QString P,QString S="did",QString tb="doctorinf");

};

#endif // CMYSQL_H
