#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "preferencesetupform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool isLocked();

private slots:
    void on_action_preferencias_triggered();

private:
    Ui::MainWindow *ui;
    PreferenceSetupForm *psf;
};

#endif // MAINWINDOW_H
