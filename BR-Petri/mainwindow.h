#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include "diagram/petriscene.h"

class DiagramScene;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bt_normal_clicked();

    void on_bt_place_clicked();

    void on_bt_fplace_clicked();

    void on_bt_ttrans_clicked();

    void on_bt_itrans_clicked();

    void on_bt_arc_clicked();

    void on_bt_iarc_clicked();

    void on_bt_farc_clicked();

private:
    Ui::MainWindow *ui;

    //PetriScene* scene;

    QMenu *itemMenu;
};

#endif // MAINWINDOW_H
