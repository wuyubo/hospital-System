#include "systemlog.h"
#include <QApplication>

#include "logm.h"
#include "cmysql.h"
int bo=3;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      systemlog w;
    Management M;
    LogM logm;
    logm.show();
     if(bo==2)
           M.show();
     else if(bo==1) w.show();
    return a.exec();
}
