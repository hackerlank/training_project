#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QFileDialog>

#include "saveloadfile.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->currentFile = "";

    this->restoreGeometry(AppSettings::Instance()->getGeometry());
    this->restoreState(AppSettings::Instance()->getState(), AppSettings::VERSION);
    this->ui->widget->setLocked(AppSettings::Instance()->isLocked());

    this->psf = new PathSetupForm(this);
    this->psf->setModal(true);

    this->npd = new NewProjectDialog(this);
    this->npd->setModal(true);

    this->od = new OptionsDialog(this);
    this->od->setModal(true);

    this->asd = new AnalysisSimulationDialog(this);
    this->asd->setModal(true);
    connect(this->asd, SIGNAL(startSimulation(std::string)),
            this, SLOT(startingSimulation(std::string)));

    connect(this->npd, SIGNAL(startNewProject(spnp::Project*)),
            this, SLOT(startNewProject(spnp::Project*)));

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

void MainWindow::startNewProject(spnp::Project* project)
{
    this->ui->widget->startProject(project);
    this->ui->action_preferences->setEnabled(true);
}

void MainWindow::on_action_Fechar_triggered()
{
    this->ui->widget->closeProject();
}

void MainWindow::on_actionSalvar_como_triggered()
{
    saveAs();
}

void MainWindow::on_action_Salvar_Projeto_triggered()
{
    save();
}

void MainWindow::save()
{
    if(currentFile.compare("") == 0)
    {
        saveAs();
    }
    else
    {
        std::string text = this->ui->widget->getCurrentProject()->toXML()->toString();
        printf(text.c_str());
        SaveLoadFile slf;
        slf.saveFile(this->currentFile, text);
    }
}

void MainWindow::on_action_Abrir_Projeto_triggered()
{
    load();
}

void MainWindow::saveAs()
{
    QString file = QFileDialog::getSaveFileName(this, tr("_salvar projeto"), QDir::currentPath(), tr("projetos (*.pnml)"));
    if(!file.isEmpty())
    {
        this->currentFile = file.toStdString();
        save();
    }
}

void MainWindow::load()
{
    QString file = QFileDialog::getOpenFileName(this, tr("_abrir projeto"), QDir::currentPath(), tr("projetos (*.pnml)"));
    if(!file.isEmpty())
    {
        this->currentFile = file.toStdString();
        //SaveLoadFile slf;
        //std::ifstream data = slf.loadIfFile(currentFile);
        XMLNode * node = XMLNode::fromString(currentFile);

        spnp::Project* proj = new spnp::Project();
        proj->fromXML(node);

        this->startNewProject(proj);

        delete node;
    }
}

#ifdef WINDOWS
QString MainWindow::pathToDosPath(QString file)
{
    int index = file.indexOf(' ');
    while(index>0)
    {
        int before = -1;
        for(int i =index; i>-1; --i)
        {
            if(file.at(i)=='/')
            {
                before = i;
                break;
            }
        }
        int after = -1;
        for(int i=index, total = file.size(); i<total; ++i)
        {
            if(file.at(i)=='/')
            {
                after = i-before;
                break;
            }
        }
        if(before > -1 && after > -1)
        {
            QString sub = file.mid(before+1, after-1);
            QString sub2 = sub.left(6)+"~1";
            file = file.replace(sub, sub2);
        }
        index = file.indexOf(' ');
    }
    return file;
}
#endif
void MainWindow::on_action_pathes_triggered()
{
    this->psf->show();
}

void MainWindow::on_action_preferences_triggered()
{
    this->od->show();
    spnp::Project* proj = this->ui->widget->getCurrentProject();
    if(proj != nullptr)
    {
        this->od->loadOptions(proj->getOptions());
    }
}

#include "saveloadfile.h"
#include "spnpwrapper.h"
void MainWindow::on_actionAnalisar_triggered()
{
    if(this->ui->widget->getCurrentProject() != nullptr)
    {
        spnp::Net *n = this->ui->widget->getCurrentProject()->getNets()->at(0);

        if(n!=nullptr)
        {
            this->asd->show();
            this->asd->setNetData(n);
        }
    }
}

void MainWindow::startingSimulation(std::string ascii)
{
    QString file = QFileDialog::getSaveFileName(this, tr("_criar arquivo"), QDir::currentPath(), tr("código-fonte(*.c)"));
#ifdef WINDOWS
    file = this->pathToDosPath(file);
#endif
    if(!file.isEmpty())
    {
        SaveLoadFile slf;
        slf.saveFile(file.toStdString(), ascii);

        std::string dir = AppSettings::Instance()->getSPNPFolder().toStdString();
        SPNPWrapper* w = new SPNPWrapper(dir
                                 #ifdef WINDOWS
                                         , dir+"/bin"
                                 #endif
                                         );
        w->work(file.left(file.length()-2).toStdString());
        delete w;
    }
}
