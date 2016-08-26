#include "cmysql.h"

Cmysql::Cmysql()
{
    connect();
}
//连接数据库
void Cmysql::connect()
{
    db = QSqlDatabase::addDatabase("QMYSQL"); // 使用mysql数据库驱动
    db.setHostName("121.42.190.117");
    db.setDatabaseName("trsystem"); // 数据库名称
    db.setUserName("root"); // 用户名
    db.setPassword("3113001629"); // 密码
    db.open(); // 尝试连接数据库
}
//医生信息和医生治疗病历查找
void Cmysql::Dsearch(QString did,QString tb,QString D,QString S)
{
    model.setQuery("SELECT "+S+" FROM "+tb+" WHERE "+D+"='"+did+"'");
}
//查找病状、治疗方案
void Cmysql::Dsearch1(QString ddesc, QString tb, QString N)
{
    model.setQuery("select * from "+tb+" where "+N+"='"+ddesc+"'");
}
//病因查找
void Cmysql::Dsearch2(QString dsymp, QString D, QString DN, QString tb,QString S)
{
    model.setQuery("SELECT "+S+" FROM "+tb+" WHERE "+D+" LIKE ('%"+dsymp+"%') OR ("+DN+" LIKE '%"+dsymp+"%')");
}
//查找病人信息、个人病历
void Cmysql::Psearch(QString pid, QString tb, QString P, QString S)
{
      model.setQuery("select "+S+" from "+tb+" where "+P+"='"+pid+"'");
}

//查找药物
void Cmysql::Msearch(QString mname, QString tb, QString M, QString S)
{
     model.setQuery("select "+S+" from "+tb+" where "+M+"='"+mname+"'");
}
///排序查找
void Cmysql::Tsearch(QString tb, QString S, QString D,QString T)
{
    model.setQuery("select "+S+" from "+tb+" ORDER BY "+D+T);
}
void Cmysql::Tsearch(QString tb, QString S, QString D,QString Wid,QString W,QString T)
{
    model.setQuery("select "+S+" from "+tb+" WHERE "+W+"='"+Wid+"' ORDER BY "+D+" "+T);
}

void Cmysql::Infadd(QString tb,QString a1, QString a2, QString a3, QString a4, QString a5, QString a6, QString a7, QString a8, QString a9, QString a11,QString a10, QString a12)
{
    QDateTime time = QDateTime::currentDateTime();              //获取系统现在的时间
    QString ptime = time.toString("yyyyMMdd");//hh:mm:ss ddd
    switch (tb.toInt()) {
    case 0:
        tb="doctorinf";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"','"+a5+"','"+a6+"','"+a7+"','"+a8+"','"+a9+"','"+a10+"','"+ptime+"','"+a12+"','"+a11+"')");
        break;
    case 1:
        tb="doctorhis";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+ptime+"','"+a3+"','"+a4+"','"+a5+"','"+a6+"','"+a7+"','"+a8+"')");
        break;
    case 2:
        tb="disease";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"','"+a5+"','"+a10+"','"+ptime+"')");
        break;
    case 3:
        tb="patientinf";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"','"+a5+"','"+a6+"','"+a7+"','"+a10+"','"+ptime+"')");
        break;
    case 4:
        tb="patienthis";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+ptime+"','"+a3+"','"+a4+"','"+a5+"','"+a6+"','"+a7+"')");
        break;
    case 5:
        tb="medicines";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"','"+a5+"','"+a6+"','"+a7+"','"+a10+"','"+ptime+"')");
        break;
    case 6:
        tb="trprojects";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"','"+a5+"')");
        break;
    case 7:
        tb="hungnum";
        model.setQuery("INSERT INTO "+tb+" VALUES (NULL,'"+a1+"','"+a2+"','"+a3+"','"+a4+"')");
        break;
    default:
        break;
    }
}
//删除信息
void Cmysql::Infdelete(QString id, QString S, QString tb1)
{
    QString tb2="doctorhis";
    model.setQuery("DELETE FROM "+tb1+" WHERE "+S+"='"+id+"'");
    if(tb1=="patientinf")
    {
        tb2="patienthis";
        model.setQuery("DELETE FROM "+tb2+" WHERE "+S+"='"+id+"'");
    }
    else model.setQuery("DELETE FROM "+tb2+" WHERE "+S+"='"+id+"'");
}
//更新信息
void Cmysql::Infupdate(QString up, QString U, QString P, QString S, QString tb)
{
    model.setQuery("UPDATE "+tb+" SET "+U+"='"+up+"' WHERE "+S+"='"+P+"'");
}
//更新信息
void Cmysql::Infupdate1(QString up, QString U, QString P, QString S, QString tb)
{
    model.setQuery("UPDATE "+tb+" SET "+U+"="+up+" WHERE "+S+"='"+P+"'");
}
