#include "petriwidget.h"

#include "view/placeview.h"
#include "view/transitionview.h"

#include <QMenu>

PetriWidget::PetriWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    //ui->setupUi(this);
    updateIds();

    //this->createPlace(0,0);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);

    //setWindowTitle(tr("Elastic Nodes"));

    PlaceView* pv = new PlaceView(this);
    scene->addItem(pv);

    PlaceView* pv2 = new PlaceView(this);
    pv2->setX(22);
    pv2->setY(40);
    scene->addItem(pv2);

    TransitionView *tv = new TransitionView(this);
    tv->setX(10);
    tv->setY(20);
    scene->addItem(tv);

    this->currentState = spnp::CurrentState::ARROW;

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint&)),
            this, SLOT(showContextMenu(const QPoint&)));
}

PetriWidget::~PetriWidget()
{
    //delete ui;
}

void PetriWidget::createPlace(QMouseEvent *evt)
{
    /*int id = getNextPlace();
    std::string placeName = "p_"+std::to_string(id);
    spnp::Place *p = new spnp::Place(id, placeName, 0,
                                     new spnp::Label(id, placeName, evt, y),
                                     evt, y);
    this->netData.add(p);*/

}

void PetriWidget::createFluidPlace(QMouseEvent *evt)
{

}

void PetriWidget::createTimedTransition(QMouseEvent *evt)
{
    /*int id = getNextTransition();
    std::string transitionName = "t_"+std::to_string(id);
    spnp::Transition *t = new spnp::Transition(id, transitionName,"1", evt, y);

    this->netData.add(t);*/
}

void PetriWidget::createImmediateTransition(QMouseEvent *evt)
{

}

void PetriWidget::createArc(QMouseEvent *evt)
{
    /*int id = getNextArc();
    std::string arcName = "a_"+std::to_string(id);
    spnp::Arc *a = new spnp::Arc(id, arcName, evt, idT, fromPtoT);

    this->netData.add(a);*/
}

void PetriWidget::createInhibitor(QMouseEvent *evt)
{

}

void PetriWidget::removePlace(int id)
{
    this->netData.removePlace(id);
}

void PetriWidget::removeArc(int id)
{
    this->netData.removeArc(id);
}

void PetriWidget::removeTransition(int id)
{
    this->netData.removeTransition(id);
}

void PetriWidget::itemMoved()
{
    //atualizar posição dos arcos
}

void PetriWidget::reset()
{
    this->clear();
    this->updateIds();
}

void PetriWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void PetriWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

void PetriWidget::showContextMenu(const QPoint &pos)
{
    // for most widgets
    QPoint globalPos = this->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction(tr("Menu Item 1"));
    myMenu.addAction(tr("Menu Item 2"));
    myMenu.addAction(tr("Menu Item 3"));

    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {
        // something was chosen, do stuff
    }
    else
    {
        // nothing was chosen
    }
}

void PetriWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Plus:
        zoomIn();
        break;
    case Qt::Key_Minus:
        zoomOut();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

//http://www.qtcentre.org/threads/15004-QGraphicsView-Mouse-Events
void PetriWidget::mousePressEvent(QMouseEvent *event)
{
    Moveable* moveable = static_cast<Moveable*>(this->itemAt(event->pos()));
    if(moveable == nullptr) return;
    std::string type = moveable->getTypeName();

    if(event->button() == Qt::LeftButton)
    {
        switch(this->currentState)
        {
        case spnp::CurrentState::ARC:

            break;
        case spnp::CurrentState::INHIBITOR:

            break;
        case spnp::CurrentState::ARROW:
            QGraphicsView::mousePressEvent(event);
            break;
        case spnp::CurrentState::FPLACE:
        case spnp::CurrentState::ITRANS:
        case spnp::CurrentState::PLACE:
        case spnp::CurrentState::TTRANS:
            //do nothing
            break;
        default:
            throw std::runtime_error("mouse press < petriwidget.cpp");
        }
    }
}

void PetriWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Moveable* moveable = static_cast<Moveable*>(this->itemAt(event->pos()));
    if(moveable == nullptr) return;
    std::string type = moveable->getTypeName();

    if(event->button() == Qt::LeftButton)
    {
        switch(this->currentState)
        {
        case spnp::CurrentState::ARC:

            break;
        case spnp::CurrentState::ARROW:
            QGraphicsView::mouseReleaseEvent(event);
            break;
        case spnp::CurrentState::FPLACE:

            break;
        case spnp::CurrentState::INHIBITOR:

            break;
        case spnp::CurrentState::ITRANS:

            break;
        case spnp::CurrentState::PLACE:

            break;
        case spnp::CurrentState::TTRANS:
            this->createTimedTransition(event);
            break;
        default:
            throw std::runtime_error("mouse release < petriwidget.cpp");
        }
    }
    else if(event->button() == Qt::RightButton)
    {

    }
}

void PetriWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2, -event->delta() / 240.0));
}

void PetriWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}

void PetriWidget::updateIds()
{
    std::vector<spnp::Place*> *places = this->netData.getPlaces();
    int size = places->size();
    int maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Place *p = places->at(i);
        maxId = maxId > p->id ? maxId : p->id;
    }
    this->idPlace = maxId+1;

    std::vector<spnp::Transition*> *transitions = this->netData.getTransitions();
    size = transitions->size();
    maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Transition* t = transitions->at(i);
        maxId = maxId > t->id ? maxId : t->id;
    }
    this->idTransition = maxId+1;

    std::vector<spnp::Arc*> *arcs = this->netData.getArcs();
    size = arcs->size();
    maxId = 0;
    for(int i=0; i<size; ++i)
    {
        spnp::Arc* arc = arcs->at(i);
        maxId = maxId > arc->id ? maxId : arc->id;
    }
    this->idArc = maxId+1;
}

int PetriWidget::getNextPlace()
{
    return this->idPlace++;
}

int PetriWidget::getNextTransition()
{
    return this->idTransition++;
}

int PetriWidget::getNextArc()
{
    return this->idArc++;
}

void PetriWidget::clear()
{
    this->scene()->clear();
}

void PetriWidget::setCurrentState(spnp::CurrentState state)
{
    this->currentState = state;
}
