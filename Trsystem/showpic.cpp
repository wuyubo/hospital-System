#include "showpic.h"
QString showpic::getpic(QString picdress,QPushButton *picbutton)
{
    QImage* img=new QImage;
    img->load(picdress);
    QImage* imgScaled = new QImage;
    *imgScaled=img->scaled(picbutton->width(),
                           picbutton->height(),
                            Qt::IgnoreAspectRatio);

   picbutton->setIcon(QPixmap::fromImage(*imgScaled));
   picbutton->setIconSize(picbutton->size ());
   return picdress;
}

void showpic::showpict(QString picdress, QPushButton *picbutton)
{
    QImage* img=new QImage;
    img->load(picdress);
    QImage* imgScaled = new QImage;
    *imgScaled=img->scaled(picbutton->width(),
                           picbutton->height(),
                            Qt::IgnoreAspectRatio);

   picbutton->setIcon(QPixmap::fromImage(*imgScaled));
   picbutton->setIconSize(picbutton->size ());
}




