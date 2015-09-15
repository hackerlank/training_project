#include "newprojectdialog.h"
#include "ui_newprojectdialog.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
    this->ui->de_date->setDate(QDate::currentDate());
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

void NewProjectDialog::on_bb_okcancel_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton qab = this->ui->bb_okcancel->standardButton(button);
    switch (qab)
    {
    case QDialogButtonBox::Ok:
        this->createProject();
        break;
    case QDialogButtonBox::Cancel:
        //nada
        break;
    default:
        break;
    }
}

void NewProjectDialog::createProject()
{
    std::vector<spnp::Net*>* nets = new std::vector<spnp::Net*>();
    spnp::Net* net = new spnp::Net(this->ui->le_mod_name->text().toStdString());

    nets->push_back(net);

    spnp::Project* project = new spnp::Project(this->ui->le_proj_name->text().toStdString(),
                                  nets, this->ui->le_owner->text().toStdString(),
                                  this->ui->pte_comments->toPlainText().toStdString(),
                                  this->ui->de_date->date().toString().toStdString());



    emit this->startNewProject(project);
}
