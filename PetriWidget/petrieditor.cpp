#include "petrieditor.h"
#include "ui_petrieditor.h"

#include <QMenu>

PetriEditor::PetriEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriEditor)
{
    ui->setupUi(this);
    connect(this->ui->pd_design, SIGNAL(itemSelected(QGraphicsItem*)),
            this->ui->pp_prop, SLOT(onItemSelected(QGraphicsItem*)));

    this->project = nullptr;
    this->ui->lw_nets->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this->ui->lw_nets, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showContextMenuForListOfNets(QPoint)));
}

PetriEditor::~PetriEditor()
{
    this->closeProject();
    delete ui;
}

bool PetriEditor::isLocked()
{
    return this->ui->pd_design->isLocked();
}

void PetriEditor::setLocked(bool l)
{
    this->ui->pd_design->setLocked(l);
}

void PetriEditor::closeProject()
{
    this->ui->pd_design->close();
    this->ui->pd_design->setEnabled(false);
    this->setEnabled(false);
    this->ui->lw_nets->clear();
    //TODO verificar isso
    if(this->project != nullptr)
        delete this->project;
}

void PetriEditor::startProject(spnp::Project *project)
{
    this->closeProject();
    this->project = project;
    this->setEnabled(true);

    std::vector<spnp::Net*>* nets = project->getNets();
    this->loadNetIntoDesign(nets->at(0));
    for(unsigned int i=0; i<nets->size(); ++i)
    {
        spnp::Net* singleNet = nets->at(i);

        QListWidgetItem* newItem = new QListWidgetItem();
        newItem->setText(QString::fromStdString(singleNet->getName()));
        QVariant data(QString::fromStdString(singleNet->id));
        newItem->setData(Qt::UserRole, data);
        this->ui->lw_nets->addItem(newItem);
    }
}

void PetriEditor::on_lw_nets_itemClicked(QListWidgetItem *item)
{
    QString data = item->data(Qt::UserRole).toString();
    //removeNetFromList(data);
}

void PetriEditor::showContextMenuForListOfNets(const QPoint &p)
{
    QAction* addAction = new QAction(tr("Adicionar", "menu de contexto de lista de redes - add"), this);
    QAction* removeAction = new QAction(tr("Remover", "menu de contexto de lista de redes - remove"), this);

    QMenu contextMenu(tr("Context menu - net list"), this);
    contextMenu.addAction(addAction);
    contextMenu.addAction(removeAction);
    contextMenu.exec(mapToGlobal(p));
}

void PetriEditor::removeNetFromList(QString id)
{
    //TODO remover

}

void PetriEditor::loadNetIntoDesign(spnp::Net *net)
{
    this->ui->pd_design->close();
    this->ui->pd_design->setEnabled(true);
    this->ui->pd_design->load(net);
}
