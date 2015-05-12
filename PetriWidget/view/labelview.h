#ifndef LABELVIEW_H
#define LABELVIEW_H

#include "petriwidget_global.h"
#include "objs/label.h"

#include <QGraphicsTextItem>

class PW_PUBLIC LabelView : public QGraphicsTextItem
{
public:
    LabelView(spnp::Label* label);
    ~LabelView();

    spnp::Label getLabel() const;
private:
    spnp::Label* label;
};

#endif // LABELVIEW_H
