#ifndef PETRIPROPERTIES_H
#define PETRIPROPERTIES_H

#include <QWidget>
#include <QGraphicsItem>
#include "idata.h"
#include "objs/net.h"
#include "diagram/items/ipetriitem.h"

namespace Ui {
class PetriProperties;
}

class PetriProperties : public QWidget
{
    Q_OBJECT

public:
    explicit PetriProperties(QWidget *parent = 0);
    ~PetriProperties();

    void setCurrentNet(spnp::Net *net);

public slots:
    void onItemSelected(QGraphicsItem* item);

private slots:
    void on_le_place_name_textEdited(const QString &arg1);

    void on_le_place_tokens_textEdited(const QString &arg1);

    void on_le_itrans_name_textEdited(const QString &arg1);

    void on_le_itrans_prior_textEdited(const QString &arg1);

    void on_le_itrans_guard_textEdited(const QString &arg1);

private:
    Ui::PetriProperties *ui;

    void setData(std::string itemId);

    std::string itemDataID;
    spnp::Net *netData;
    IPetriItem* currentPetriItem;
    void loadPlace();
    QString clearArg(QString arg1);
};

#endif // PETRIPROPERTIES_H
