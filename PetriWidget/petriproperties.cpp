#include "petriproperties.h"
#include "ui_petriproperties.h"

#include "diagram/arcs/ipetriarc.h"

#include "diagram/items/placeitem.h"
#include "diagram/items/fplaceitem.h"

PetriProperties::PetriProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetriProperties)
{
    ui->setupUi(this);
    this->itemDataID = "";
    this->netData = nullptr;
    this->currentPetriItem = nullptr;

    this->mounting = false;
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
        this->loadNet();
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
            this->loadFPlace();
            break;
        case IPetriItem::ITrans:
            this->ui->stackedWidget->setCurrentIndex(2);
            this->loadITrans();
            break;
        case IPetriItem::TTrans:
            this->ui->stackedWidget->setCurrentIndex(3);
            this->loadTTrans();
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

void PetriProperties::setData(std::string itemId)
{
    this->itemDataID = itemId;
}

void PetriProperties::loadPlace()
{
    spnp::Place* place = this->netData->getPlace(this->itemDataID);
    this->ui->le_place_name->setText(QString::fromStdString(place->getName()));
    this->ui->le_place_tokens->setText(QString::fromStdString(place->getToken()));
}

void PetriProperties::loadFPlace()
{
    spnp::FluidPlace* fplace = static_cast<spnp::FluidPlace*>(this->netData->getPlace(this->itemDataID));
    this->ui->le_fplace_name->setText(QString::fromStdString(fplace->getName()));
    this->ui->le_fplace_tokens->setText(QString::fromStdString(fplace->getToken()));
    this->ui->le_fplace_break->setText(QString::fromStdString(fplace->getBreakValue()));
    this->ui->le_fplace_limit->setText(QString::fromStdString(fplace->getBoundValue()));
}

void PetriProperties::loadITrans()
{
    spnp::ImmediateTransition* itrans = this->netData->getTransition(this->itemDataID);
    this->ui->le_itrans_name->setText(QString::fromStdString(itrans->getName()));
    this->ui->le_itrans_guard->setText(QString::fromStdString(itrans->getGuard()));
    this->ui->le_itrans_prior->setText(QString::fromStdString(itrans->getPriority()));
    //TODO carregar o tipo de probabilidade
    switch (itrans->getProbType())
    {
    default:
    case spnp::ImmediateTransition::CONSTANT:
        this->ui->cb_itrans_prob->setCurrentIndex(0);
        break;
    case spnp::ImmediateTransition::PLACE_DEPENDENT:
    {
        this->ui->cb_itrans_prob->setCurrentIndex(1);
        QString data = QString::fromStdString(itrans->getPlaceId());
        int index = this->ui->cb_itrans_prob_place->findData(data);
        this->ui->cb_itrans_prob_place->setCurrentIndex(index);
        break;
    }
    case spnp::ImmediateTransition::FUNCTION:
        this->ui->cb_itrans_prob->setCurrentIndex(2);
        break;
    }
    this->ui->le_itrans_prob_value->setText(QString::fromStdString(itrans->getValue()));
}

void PetriProperties::loadTTrans()
{
    spnp::ImmediateTransition* itrans = static_cast<spnp::ImmediateTransition*>(this->netData->getTransition(this->itemDataID));
    //TODO update view
}

void PetriProperties::loadArc()
{

}

void PetriProperties::loadFArc()
{

}

void PetriProperties::loadNet()
{
    if(this->netData != nullptr)
    {
        this->ui->le_net_name->setText(QString::fromStdString(this->netData->getName()));
    }
}

/*
 * Edições de campos de propriedades
 *
 */

void PetriProperties::on_le_place_name_textEdited(const QString &arg1)
{
    spnp::Place* p = this->netData->getPlace(itemDataID);
    p->setName(arg1.toStdString());
    this->currentPetriItem->updateLabel(p);
}

void PetriProperties::on_le_place_tokens_textEdited(const QString &arg1)
{
    QString newValue = this->clearArg(arg1);
    spnp::Place* p = this->netData->getPlace(itemDataID);
    p->setToken(newValue.toStdString());
    PlaceItem *pi = qgraphicsitem_cast<PlaceItem*>(this->currentPetriItem);
    pi->updateToken(newValue);
}

void PetriProperties::on_le_itrans_name_textEdited(const QString &arg1)
{
    spnp::ImmediateTransition *it = this->netData->getTransition(itemDataID);
    it->setName(arg1.toStdString());
    this->currentPetriItem->updateLabel(it);
}

void PetriProperties::on_le_itrans_prior_textEdited(const QString &arg1)
{
    spnp::ImmediateTransition *it = this->netData->getTransition(itemDataID);
    it->setPriority(arg1.toStdString());
}

void PetriProperties::on_le_itrans_guard_textEdited(const QString &arg1)
{
    spnp::ImmediateTransition *it = this->netData->getTransition(itemDataID);
    it->setGuard(arg1.toStdString());
}

void PetriProperties::on_le_net_name_textEdited(const QString &arg1)
{
    this->netData->setName(arg1.toStdString());
}

void PetriProperties::on_le_fplace_name_textEdited(const QString &arg1)
{
    spnp::Place* p = this->netData->getPlace(itemDataID);
    p->setName(arg1.toStdString());
    this->currentPetriItem->updateLabel(p);
}

void PetriProperties::on_le_fplace_tokens_textEdited(const QString &arg1)
{
    QString newValue = this->clearArg(arg1);
    spnp::FluidPlace* p = static_cast<spnp::FluidPlace*>(this->netData->getPlace(itemDataID));
    p->setToken(newValue.toStdString());
    FPlaceItem *fpi = qgraphicsitem_cast<FPlaceItem*>(this->currentPetriItem);
    fpi->updateToken(newValue);
}

void PetriProperties::on_le_fplace_limit_textEdited(const QString &arg1)
{
    spnp::FluidPlace* p = static_cast<spnp::FluidPlace*>(this->netData->getPlace(itemDataID));
    p->setBoundValue(arg1.toStdString());
}

void PetriProperties::on_le_fplace_break_textEdited(const QString &arg1)
{
    spnp::FluidPlace* p = static_cast<spnp::FluidPlace*>(this->netData->getPlace(itemDataID));
    p->setBreakValue(arg1.toStdString());
}

void PetriProperties::on_le_itrans_prob_value_textEdited(const QString &arg1)
{
    int index = this->ui->cb_itrans_prob->currentIndex();

    spnp::ImmediateTransition* itrans = static_cast<spnp::ImmediateTransition*>(this->netData->getTransition(itemDataID));
    this->ui->cb_itrans_prob_place->setEnabled(false);
    switch (index)
    {
    case 0:
    case 2:
        itrans->setValue(arg1.toStdString());

        break;
    case 1://places

        break;
    default:
        break;
    }
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

void PetriProperties::on_le_ttrans_rate_textEdited(const QString &arg1)
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

void PetriProperties::fillITransPlacesNames()
{
    this->mounting = true;
    this->ui->cb_itrans_prob_place->clear();
    std::vector<spnp::Place*>* places = this->netData->getPlaces();
    if(places!=nullptr)
    {
        for(int i=0, total = places->size(); i< total; ++i)
        {
            spnp::Place* place = places->at(i);
            QString placeName = QString::fromStdString(place->getName());
            QVariant data(QString::fromStdString(place->id));
            this->ui->cb_itrans_prob_place->addItem(placeName, data);
        }
    }
    this->mounting = false;
}

void PetriProperties::on_cb_itrans_prob_currentTextChanged(const QString &arg1)
{
    (void)arg1;
    int index = this->ui->cb_itrans_prob->currentIndex();

    spnp::ImmediateTransition* itrans = static_cast<spnp::ImmediateTransition*>(this->netData->getTransition(itemDataID));
    this->ui->cb_itrans_prob_place->setEnabled(false);
    switch (index)
    {
    default:
    case 0:
        itrans->setProbType(spnp::ImmediateTransition::CONSTANT);
        break;
    case 1:
        itrans->setProbType(spnp::ImmediateTransition::PLACE_DEPENDENT);
        this->fillITransPlacesNames();
        this->ui->cb_itrans_prob_place->setEnabled(true);
        break;
    case 2:
        itrans->setProbType(spnp::ImmediateTransition::FUNCTION);
        break;
    }
}

void PetriProperties::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 2)
    {
        fillITransPlacesNames();
    }
}

void PetriProperties::on_cb_itrans_prob_place_currentTextChanged(const QString &arg1)
{
    (void)arg1;
    if(!mounting)
    {
        spnp::ImmediateTransition* itrans = static_cast<spnp::ImmediateTransition*>(this->netData->getTransition(itemDataID));
        QString data = this->ui->cb_itrans_prob_place->currentData().toString();
        itrans->setPlaceId(data.toStdString());
    }
}
