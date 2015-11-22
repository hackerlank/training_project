#include "petriproperties.h"
#include "ui_petriproperties.h"

#include "diagram/arcs/ipetriarc.h"

#include "diagram/items/placeitem.h"

PetriProperties::PetriProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriProperties)
{
    ui->setupUi(this);
    this->itemDataID = "";
    this->netData = nullptr;
    this->currentPetriItem = nullptr;
}

PetriProperties::~PetriProperties()
{
    delete ui;
}

void PetriProperties::setCurrentNet(spnp::Net *net)
{
    this->netData = net;
}

void PetriProperties::onItemSelected(QGraphicsItem *item)
{
    if(item == nullptr)
    {
        this->ui->stackedWidget->setCurrentIndex(7);
        this->itemDataID = "";
    }
    else if(item->type() == IPetriItem::Type)
    {
        IPetriItem *other = qgraphicsitem_cast<IPetriItem *>(item);
        this->currentPetriItem = other;
        this->setData(other->getPetriItemId());
        switch (other->petriType())
        {
        case IPetriItem::Place:
            this->ui->stackedWidget->setCurrentIndex(0);
            this->loadPlace();
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
    }
    else if(item->type() == IPetriArc::Type)
    {
        IPetriArc *arc = qgraphicsitem_cast<IPetriArc *>(item);
        this->setData(arc->getArcId());

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
    }
}

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    spnp::Place* p = this->netData->getPlace(itemDataID);
    if(p != nullptr)
    {
        p->setName(arg1.toStdString());
    }
    this->currentPetriItem->updateLabel(p);
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    QString newValue = this->clearArg(arg1);
    spnp::Place* p = this->netData->getPlace(itemDataID);
    if(p != nullptr)
    {
        p->setToken(newValue.toStdString());
    }
    PlaceItem *pi = qgraphicsitem_cast<PlaceItem*>(this->currentPetriItem);
    pi->updateToken(newValue);
}

void PetriProperties::setData(std::string itemId)
{
    this->itemDataID = itemId;
}

void PetriProperties::loadPlace()
{
    spnp::Place* place = this->netData->getPlace(this->itemDataID);
    if(place != nullptr)
    {
        this->ui->le_place_name->setText(QString::fromStdString(place->getName()));
        this->ui->le_place_tokens->setText(QString::fromStdString(place->getToken()));
    }
}

void PetriProperties::on_le_itrans_name_textEdited(const QString &arg1)
{
    spnp::ImmediateTransition *it = this->netData->getTransition(itemDataID);
    if(it != nullptr)
    {
        it->setName(arg1.toStdString());
    }
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

void PetriProperties::on_le_net_name_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_fplace_name_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_fplace_tokens_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_fplace_limit_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_fplace_break_textEdited(const QString &arg1)
{

}

void PetriProperties::on_cb_itrans_prob_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_le_itrans_prob_value_textEdited(const QString &arg1)
{

}

void PetriProperties::on_cb_itrans_prob_place_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_le_ttrans_name_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_ttrans_guard_textEdited(const QString &arg1)
{

}

void PetriProperties::on_le_ttrans_prior_textEdited(const QString &arg1)
{

}

void PetriProperties::on_cb_ttrans_distr_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_pte_ttrans_distr_textChanged()
{

}

void PetriProperties::on_le_ttrans_rate_textEdited(const QString &arg1)
{

}

void PetriProperties::on_cb_ttrans_rate_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_cb_ttrans_place_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_cb_ttrans_pol_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_cb_ttrans_afected_currentTextChanged(const QString &arg1)
{

}

void PetriProperties::on_rb_arc_const_toggled(bool checked)
{

}

void PetriProperties::on_le_arc_mult_textEdited(const QString &arg1)
{

}

QString PetriProperties::clearArg(QString arg1)
{
    QString newValue = arg1;
    return newValue.remove(QRegExp("\001"));
}
