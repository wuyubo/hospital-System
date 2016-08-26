#ifndef RIQI_H
#define RIQI_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class riqi;
}

class riqi : public QDialog
{
    Q_OBJECT

public:
    explicit riqi(QWidget *parent = 0);
    ~riqi();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_calendarWidget_clicked();

private:
    Ui::riqi *ui;
};

#endif // RIQI_H
