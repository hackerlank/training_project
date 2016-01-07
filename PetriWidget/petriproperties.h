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

    void on_le_net_name_textEdited(const QString &arg1);

    void on_le_fplace_name_textEdited(const QString &arg1);

    void on_le_fplace_tokens_textEdited(const QString &arg1);

    void on_le_fplace_limit_textEdited(const QString &arg1);

    void on_le_fplace_break_textEdited(const QString &arg1);

    void on_le_itrans_prob_value_textEdited(const QString &arg1);

    void on_le_ttrans_name_textEdited(const QString &arg1);

    void on_le_ttrans_guard_textEdited(const QString &arg1);

    void on_le_ttrans_prior_textEdited(const QString &arg1);

    void on_le_ttrans_rate_textEdited(const QString &arg1);

    void on_rb_arc_const_toggled(bool checked);

    void on_le_arc_mult_textEdited(const QString &arg1);

private:
    Ui::PetriProperties *ui;

    void setData(std::string itemId);

    std::string itemDataID;
    spnp::Net *netData;
    IPetriItem* currentPetriItem;
    void loadPlace();
    void loadFPlace();
    void loadITrans();
    void loadTTrans();
    void loadArc();
    void loadFArc();
    void loadNet();
    QString clearArg(QString arg1);
};

#endif // PETRIPROPERTIES_H
