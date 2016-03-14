#ifndef PNPARAMS_H
#define PNPARAMS_H

#include <QWidget>

namespace Ui {
class PNParams;
}

class PNParams : public QWidget
{
    Q_OBJECT

public:
    explicit PNParams(QWidget *parent = 0);
    ~PNParams();

private slots:
    void on_btAdicionar0_clicked();

    void on_btAdicionar1_clicked();

    void on_btAdicionar2_clicked();

private:
    Ui::PNParams *ui;
};

#endif // PNPARAMS_H
