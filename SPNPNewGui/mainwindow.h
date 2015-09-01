#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "preferencesetupform.h"
#include "newprojectdialog.h"

#include "appsettings.h"
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

    void on_action_sair_triggered();

    void on_action_Novo_Projeto_triggered();

    void startNewProject(spnp::Project* project);

    void on_action_Fechar_triggered();

private:
    Ui::MainWindow *ui;
    PreferenceSetupForm *psf;
    NewProjectDialog *npd;

    void createMenus();
    void updateMenus();

    QAction* recentFileActs[AppSettings::MaxRecentFiles];
};

#endif // MAINWINDOW_H
