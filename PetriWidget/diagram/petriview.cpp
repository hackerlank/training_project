#include "petriview.h"

#include <QTimeLine>

PetriView::PetriView(QWidget *parent)
    :QGraphicsView(parent)
{

    this->scene = new PetriScene(/*itemMenu*/nullptr, this);
    this->setScene(scene);
    //this->ui->graphicsView->setScene(this->scene);

    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);

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

    //this->createMenus();

    //right click : what to do.
    /*this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(showContextMenu(const QPoint&)));*/
}

PetriView::~PetriView()
{

}

PetriScene *PetriView::getScene() const
{
    return this->scene;
}

void PetriView::close()
{
    this->scene->clear();
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
    emit itemSelected(item);
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
/*
void PetriView::showContextMenu(const QPoint &pos)
{
    // for most widgets
    //QPoint globalPos = this->mapToGlobal(pos);//normal
    QPoint globalPos = this->viewport()->mapToGlobal(pos); //QAbstractScrollArea e derivados
    QAction* selectedMenuItem = nullptr;

    if(this->scene->selectedItems().size() > 0)
    {
        QGraphicsItem *item = this->scene->selectedItems().first();

        switch (item->type())
        {
        case IPetriItem::Type:
        {
            IPetriItem *pItem = qgraphicsitem_cast<IPetriItem*>(item);
            if(pItem->isTransition())
            {
                selectedMenuItem = menuTransition.exec(globalPos);

            }
            else if(pItem->isPlace())
            {
                selectedMenuItem = menuPlace.exec(globalPos);
            }
            break;
        }
        case IPetriArc::Type:
        {
            selectedMenuItem = menuArc.exec(globalPos);
            break;
        }
        default:
            //TODO tratar erro
            break;
        }
    }
    else
    {
        selectedMenuItem = menuNet.exec(globalPos);
    }

    if (selectedMenuItem)
    {
        // Escolheu algo
        //fazer algo
    }
    else
    {
        // nada foi escolhido
    }
}*/

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
/*
void PetriView::createMenus()
{
    //common
    QAction *deleteAction = new QAction(tr("_deleteItem"), this);
    deleteAction->setStatusTip(tr("_delete item from net"));
    //connect

    //menuArc
    QAction *showCardinality = new QAction(tr("_display the cardinality"), this);
    showCardinality->setStatusTip(tr("_Displays the arc's cardinality"));
    //connect
    menuArc.addAction(showCardinality);
    menuArc.addSeparator();
    menuArc.addAction(deleteAction);

    //menuNet
    QAction *matrixArcs = new QAction(tr("_matrix for the arcs"), this);
    matrixArcs->setStatusTip(tr("_pop matrix"));
    //copy cut paste clear undo
    //connect
    menuNet.addAction(matrixArcs);

    //menuPlace
    QAction *numberToken = new QAction(tr("_display tokens number"), this);
    numberToken->setStatusTip(tr("_displays or not token number"));
    //connect
    menuPlace.addAction(numberToken);
    menuPlace.addSeparator();
    menuPlace.addAction(deleteAction);

    //menuTransition
    QAction *rotateAction = new QAction(tr("_rotate"), this);
    rotateAction->setCheckable(true);
    rotateAction->setStatusTip(tr("_rotate transition"));
    connect(rotateAction, SIGNAL(triggered(bool)),
            this, SLOT(rotate()));

    menuTransition.addAction(rotateAction);
    menuTransition.addSeparator();
    menuTransition.addAction(deleteAction);
}*/

void PetriView::rotate()
{
    //TODO rotacionar transição
    QGraphicsItem *item = this->scene->selectedItems().first();
    item->setRotation(90);
}
