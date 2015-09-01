#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->restoreGeometry(AppSettings::Instance()->getGeometry());
    this->restoreState(AppSettings::Instance()->getState(), AppSettings::VERSION);
    this->ui->widget->setLocked(AppSettings::Instance()->isLocked());

    this->psf = new PreferenceSetupForm(this);
    this->psf->setModal(true);

    this->npd = new NewProjectDialog(this);
    this->npd->setModal(true);

    connect(this->npd, SIGNAL(startNewProject(spnp::Project*)),
            this, SLOT(on_confirm_New_Project(spnp::Project*)));

    this->updateMenus();

    this->ui->widget->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->psf;
    delete this->npd;
}

bool MainWindow::isLocked()
{
    return this->ui->widget->isLocked();
}

void MainWindow::on_action_preferencias_triggered()
{
    this->psf->show();
}

void MainWindow::on_action_sair_triggered()
{
    this->close();
}

void MainWindow::createMenus()
{
    int max = AppSettings::MaxRecentFiles;
    for(int i=0; i < max; ++i)
    {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        //connect(recentFileActs[i], SIGNAL(triggered()),
          //      this, SLOT(openRecentFile()));

        this->ui->menu_Recente->addAction(recentFileActs[i]);
    }
}

void MainWindow::updateMenus()
{
    QStringList list = AppSettings::Instance()->getRecentFiles();

    //http://doc.qt.io/qt-5/qtwidgets-mainwindows-recentfiles-example.html
    //this->ui->action_Recente->
    //this->ui->action_Recente
}

void MainWindow::on_action_Novo_Projeto_triggered()
{
    this->npd->show();
}

void MainWindow::on_confirm_New_Project(spnp::Project *project)
{
    this->ui->widget->setEnabled(true);
    (void)project;
}
