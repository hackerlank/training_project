#include "preferencesetupform.h"
#include "ui_preferencesetupform.h"

#include "appsettings.h"

#include <QDir>
#include <QFileInfo>
#include <QMessageBox>

PreferenceSetupForm::PreferenceSetupForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferenceSetupForm)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->fileDialog = new QFileDialog(this);

    this->loadOptions();
}

PreferenceSetupForm::~PreferenceSetupForm()
{
    delete ui;
    delete this->fileDialog;
}

void PreferenceSetupForm::on_pb_spnp_clicked()
{
    QString _path = this->ui->le_spnp->text();
    if(_path.isEmpty())
    {
        _path =
        #ifdef WINDOWS
                "C:/";
        #elif LINUX
                "/home";
        #endif
    }
    QString path = this->fileDialog->getExistingDirectory(this, tr("_pasta do SPNP..."),
                                                          _path,
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    if(!path.isEmpty())
    {
        QStringList list;
        list << "Makerun.dos" << "init_spnp.bat";
        for(int i=0; i<list.length(); ++i)
        {
            QString str = list.at(i);
            QFileInfo fileInfo(path + QDir::separator() + str);
            if(!(fileInfo.exists() && fileInfo.isFile()))
            {
                this->showError(tr("_erro de caminho"), tr("_a pasta especificada não contém o spnp"));
                return;//TODO erro
            }
        }
        this->ui->le_spnp->setText(path);
    }
}

void PreferenceSetupForm::on_pb_examples_clicked()
{
    QString path = this->fileDialog->getExistingDirectory(this, tr("_pasta de exemplos do SPNP..."),
                                                      #ifdef WINDOWS
                                                          "C:\\",
                                                      #elif LINUX
                                                          "/home",
                                                      #endif
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    if(!path.isEmpty())
    {
        QDir dir(path);
        QStringList list;
        list = dir.entryList();
        bool rgl = false;
        bool srn = false;
        for(int i=0; i<list.length(); ++i)
        {
            QString str = list.at(i);
            if(str.contains(".rgl"))
            {
                rgl = true;
                continue;
            }
            if(str.contains(".srn"))
            {
                srn = true;
                continue;
            }
            if(rgl && srn)
            {
                break;
            }
        }
        if(rgl && srn)
            this->ui->le_examples->setText(path);
        else
        {
            this->showError(tr("_erro de caminho"), tr("_a pasta especificada não contém exemplos do spnp"));
        }
    }
}

void PreferenceSetupForm::on_pb_plots_clicked()
{
    QString path = this->fileDialog->getExistingDirectory(this, tr("_pasta de gráficos..."),
                                                      #ifdef WINDOWS
                                                          "C:\\",
                                                      #elif LINUX
                                                          "/home",
                                                      #endif
                                                          QFileDialog::ShowDirsOnly
                                                          | QFileDialog::DontResolveSymlinks);
    if(!path.isEmpty())
    {
        QDir dir(path);
        QStringList list;
        list = dir.entryList();
        bool dat = false;
        bool info = false;
        for(int i=0; i<list.length(); ++i)
        {
            QString str = list.at(i);
            if(str.contains(".dat"))
            {
                dat = true;
                continue;
            }
            if(str.contains(".info"))
            {
                info = true;
                continue;
            }
            if(dat && info)
            {
                break;
            }
        }
        if(dat && info)
            this->ui->le_plots->setText(path);
        else
        {
            this->showError(tr("_erro de caminho"), tr("_a pasta especificada não contém exemplos de gráficos do spnp"));
        }
    }
}

void PreferenceSetupForm::on_bb_ok_cancel_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton qab = this->ui->bb_ok_cancel->standardButton(button);
    switch (qab)
    {
    case QDialogButtonBox::Save:
        this->saveOptions();
        break;
    case QDialogButtonBox::Cancel:
        //nada
        break;
    case QDialogButtonBox::RestoreDefaults:
        this->loadOptions();
        break;
    default:
        break;
    }
}

void PreferenceSetupForm::loadOptions()
{
    this->ui->le_spnp->setText(AppSettings::Instance()->getSPNPFolder());
    this->ui->le_examples->setText(AppSettings::Instance()->getExamples());
    this->ui->le_plots->setText(AppSettings::Instance()->getGraphs());
}

void PreferenceSetupForm::saveOptions()
{
    QString spnp = this->ui->le_spnp->text();

    if(spnp.isEmpty())
    {
        this->showError(tr("_Erro"), tr("_preencha o caminho para o SPNP"));
    }
    else
    {
        AppSettings::Instance()->setSPNPFolder(spnp);
        AppSettings::Instance()->setExamples(this->ui->le_examples->text());
        AppSettings::Instance()->setGraphs(this->ui->le_plots->text());
    }
}

void PreferenceSetupForm::showError(QString title, QString message)
{
    QMessageBox box;
    box.critical(this, title, message);
    box.setFixedSize(500,200);
    box.show();
}
