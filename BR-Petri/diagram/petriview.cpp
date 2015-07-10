#include "petriview.h"

#include <QTimeLine>
#include <QMenu>

PetriView::PetriView(QWidget *parent)
    :QGraphicsView(parent)
{
    this->scene = new PetriScene(/*itemMenu*/nullptr, this);
    this->setScene(scene);
    //this->ui->graphicsView->setScene(this->scene);

    connect(scene, SIGNAL(itemInserted(IPetriItem*)),
            this, SLOT(petriItemInserted(IPetriItem*)));
    connect(scene, SIGNAL(arcInserted(IPetriArc*)),
            this, SLOT(petriArcInserted(IPetriArc*)));
    connect(scene, SIGNAL(textInserted(QGraphicsTextItem*)),
            this, SLOT(petriTextInserted(QGraphicsTextItem*)));
    connect(scene, SIGNAL(itemSelected(QGraphicsItem*)),
            this, SLOT(petriItemSelected(QGraphicsItem*)));
    connect(scene, SIGNAL(itemDeleted()),
            this, SLOT(petriItemDeleted()));


    this->_numScheduledScalings = 0;

    //right click : what to do.
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(showContextMenu(const QPoint&)));
}

PetriView::~PetriView()
{

}

PetriScene *PetriView::getScene() const
{
    return this->scene;
}

void PetriView::petriItemInserted(IPetriItem *item)
{
    //TODO aqui
    (void)item;
    this->scene->clearSelection();
    emit sceneClicked();
}

void PetriView::petriTextInserted(QGraphicsTextItem *item)
{
    //TODO aqui
    (void)item;
    this->scene->clearSelection();
    emit sceneClicked();
}

void PetriView::petriItemSelected(QGraphicsItem *item)
{
    //TODO aqui
    (void)item;
    //this->scene->clearSelection();
    emit sceneClicked();
}

void PetriView::petriItemDeleted()
{
    //TODO aqui
    this->scene->clearSelection();
    emit sceneClicked();
}

void PetriView::petriArcInserted(IPetriArc *arc)
{
    //TODO aqui
    (void) arc;
    this->scene->clearSelection();
    emit sceneClicked();
}

void PetriView::showContextMenu(const QPoint &pos)
{
    // for most widgets
    //QPoint globalPos = this->mapToGlobal(pos);//normal
    QPoint globalPos = this->viewport()->mapToGlobal(pos); //QAbstractScrollArea e derivados

    if(this->scene->selectedItems().size() > 0)
    {
        QGraphicsItem *item = this->scene->selectedItems().first();
        //TODO mover criação do menu para fora daqui (um para cada tipo: lugar, transição, arco e rede)
        QMenu myMenu;
        switch (item->type())
        {
        case IPetriItem::Type:
        {
            IPetriItem *pItem = qgraphicsitem_cast<IPetriItem*>(item);
            if(pItem->isTransition())
            {
                QAction *rotateAction = new QAction(tr("Rotate"), this);
                rotateAction->setStatusTip(tr("Rotate arc"));
                connect(rotateAction, SIGNAL(triggered(bool)),
                        this, SLOT(rotate()));
                myMenu.addAction(rotateAction);
            }
            break;
        }
        default:
            break;
        }

        /*myMenu.addAction(tr("Menu Item 1"));
        myMenu.addAction(tr("Menu Item 2"));
        myMenu.addAction(tr("Menu Item 3"));*/

        QAction* selectedMenuItem = myMenu.exec(globalPos);
        if (selectedMenuItem)
        {
            // Escolheu algo
            //fazer algo
        }
        else
        {
            // nada foi escolhido
        }
    }
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

void PetriView::rotate()
{
    //TODO
    QGraphicsItem *item = this->scene->selectedItems().first();
}
