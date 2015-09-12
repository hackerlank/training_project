#include "petriproperties.h"
#include "ui_petriproperties.h"

#include "diagram/arcs/ipetriarc.h"
#include "diagram/items/ipetriitem.h"

PetriProperties::PetriProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriProperties)
{
    ui->setupUi(this);
}

PetriProperties::~PetriProperties()
{
    delete ui;
}

void PetriProperties::onItemSelected(QGraphicsItem *item)
{
    if(item->type() == IPetriItem::Type)
    {
        IPetriItem *other = qgraphicsitem_cast<IPetriItem *>(item);
        switch (other->petriType())
        {
        case IPetriItem::Place:
            this->ui->stackedWidget->setCurrentIndex(0);
            break;
        case IPetriItem::FPlace:
            this->ui->stackedWidget->setCurrentIndex(1);
            break;
        case IPetriItem::ITrans:
            this->ui->stackedWidget->setCurrentIndex(2);
            break;
        case IPetriItem::TTrans:
            this->ui->stackedWidget->setCurrentIndex(3);
            break;
        default:
            break;
        }
        this->setData(other->getData());
    }
    else if(item->type() == IPetriArc::Type)
    {
        IPetriArc *arc = qgraphicsitem_cast<IPetriArc *>(item);
        switch (arc->arcType())
        {
        case IPetriArc::Activator:
            this->ui->stackedWidget->setCurrentIndex(4);
            break;
        case IPetriArc::FActivator:
            this->ui->stackedWidget->setCurrentIndex(5);
            break;
        case IPetriArc::Inhibitor:
            this->ui->stackedWidget->setCurrentIndex(6);
            break;
        default:
            break;
        }
        this->setData(arc->getData());
    }

    //item->g
}

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::setData(spnp::IData *data)
{

}

void PetriProperties::on_le_itrans_name_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_itrans_prior_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}

void PetriProperties::on_le_itrans_guard_textEdited(const QString &arg1)
{
    //TODO
    (void)arg1;
}
