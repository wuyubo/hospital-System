#ifndef ZHISHIKU_H
#define ZHISHIKU_H

#include <QDialog>

namespace Ui {
class zhishiku;
}

class zhishiku : public QDialog
{
    Q_OBJECT

public:
    explicit zhishiku(QWidget *parent = 0);
    ~zhishiku();

private slots:
    void on_zsk_queren_clicked();

    void on_zsk_fanhui_clicked();

private:
    Ui::zhishiku *ui;
};

#endif // ZHISHIKU_H
