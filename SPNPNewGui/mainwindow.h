#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pathsetupform.h"
#include "newprojectdialog.h"
#include "optionsdialog.h"
#include "analysissimulationdialog.h"

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
    void on_action_sair_triggered();

    void on_action_Novo_Projeto_triggered();

    void startNewProject(spnp::Project* project);

    void on_action_Fechar_triggered();

    void on_actionSalvar_como_triggered();

    void on_action_Salvar_Projeto_triggered();

    void on_action_Abrir_Projeto_triggered();

    void on_action_pathes_triggered();

    void on_action_preferences_triggered();

    void on_actionAnalisar_triggered();

    void startingSimulation(std::string ascii);

private:
    Ui::MainWindow *ui;
    PathSetupForm *psf;
    NewProjectDialog *npd;
    OptionsDialog *od;
    AnalysisSimulationDialog *asd;

    void createMenus();
    void updateMenus();

    void save();
    void saveAs();
    void load();

    QAction* recentFileActs[AppSettings::MaxRecentFiles];

    std::string currentFile;
#ifdef WINDOWS
    QString pathToDosPath(QString file);
#endif
};

#endif // MAINWINDOW_H
