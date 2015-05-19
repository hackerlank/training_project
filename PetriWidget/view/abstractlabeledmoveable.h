#ifndef LABELED_H
#define LABELED_H

#include "view/abstractmoveable.h"
#include "view/labelview.h"

class PW_PUBLIC AbstractLabeledMoveable : public AbstractMoveable
{
public:
    AbstractLabeledMoveable(PetriWidget *pWidget);
    ~AbstractLabeledMoveable();

    virtual void setName(std::string txt);
    void setLabelPosition(QPointF point);
private:
    LabelView* label;

};

#endif // LABELED_H
