#ifndef LOGM_H
#define LOGM_H

#include <QMainWindow>
#include "cmysql.h"
#include "management.h"
#include "systemlog.h"
#include "QMessageBox"
#include <QTimer>

namespace Ui {
class LogM;
}

class LogM : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogM(QWidget *parent = 0);
    ~LogM();

private slots:
    void Re(QString a);
    void on_Blog_clicked();
    void showTime();

    void on_Bexit_clicked();

private:
    Ui::LogM *ui;
    Cmysql Csql;
    Management *Ma;
    systemlog *sy;
    QTimer *timer;
};

#endif // LOGM_H
