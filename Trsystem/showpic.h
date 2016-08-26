#ifndef SHOWPIC_H
#define SHOWPIC_H
#include <qfiledialog.h> //文件窗口头文件
#include <qpushbutton.h>  //pushbutton头文件
class showpic
{
public:
    QString getpic(QString picdress,QPushButton *picbutton);//第一个参数为图片地址，第二个参数为需要显示图片的pushbutton的指针
    void showpict(QString picdress,QPushButton *picbutton);

};

#endif // SHOWPIC_H
