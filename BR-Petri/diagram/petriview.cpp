#include "petriview.h"

#include <QTimeLine>

PetriView::PetriView(QWidget *parent)
    :QGraphicsView(parent)
{
    this->scene = new PetriScene(/*itemMenu*/nullptr, this);
    this->setScene(scene);
    //this->ui->graphicsView->setScene(this->scene);

    connect(scene, SIGNAL(itemInserted(IPetriItem*)),
            this, SLOT(itemViewInserted(IPetriItem*)));
    connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)),
            this, SLOT(textViewInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
            this, SLOT(itemViewSelected(QGraphicsItem*)));

    this->_numScheduledScalings = 0;
}

PetriView::~PetriView()
{

}

PetriScene *PetriView::getScene() const
{
    return this->scene;
}

void PetriView::itemViewInserted(IPetriItem *item)
{
    //TODO aqui
    (void)item;
}

void PetriView::textViewInserted(QGraphicsTextItem *item)
{
    //TODO aqui
    (void)item;
}

void PetriView::itemViewSelected(QGraphicsItem *item)
{
    //TODO aqui
    (void)item;
}

void PetriView::scalingTime(qreal x)
{
    //TODO aqui
    (void)x;
    qreal factor = 1.0+ qreal(_numScheduledScalings) / 300.0;
    scale(factor, factor);
}

void PetriView::animFinished()
{
    if (_numScheduledScalings > 0)
        _numScheduledScalings--;
    else
        _numScheduledScalings++;
    sender()->~QObject();
}

void PetriView::wheelEvent(QWheelEvent *event)
{
    //scaleView(pow((double)2, -event->delta() / 240.0));

    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15; // see QWheelEvent documentation
    _numScheduledScalings += numSteps;
    if (_numScheduledScalings * numSteps < 0)
        _numScheduledScalings = numSteps;

    QTimeLine *anim = new QTimeLine(350, this);
    anim->setUpdateInterval(20);

    connect(anim, SIGNAL (valueChanged(qreal)), SLOT (scalingTime(qreal)));
    connect(anim, SIGNAL (finished()), SLOT (animFinished()));
    anim->start();
}

