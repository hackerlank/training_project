#include "petriview.h"

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

