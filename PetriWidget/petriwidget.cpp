#include "petriwidget.h"


#include "placeview.h"

PetriWidget::PetriWidget(QWidget *parent) :
    QGraphicsView(parent)
{
    //ui->setupUi(this);
    updateIds();

    this->createPlace(0,0);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);

    //scale(qreal(0.8), qreal(0.8));

    setWindowTitle(tr("Elastic Nodes"));

    PlaceView* pv = new PlaceView(this);
    scene->addItem(pv);

    PlaceView* pv2 = new PlaceView(this);
    pv2->setX(22);
    pv2->setY(40);
    scene->addItem(pv2);
}

PetriWidget::~PetriWidget()
{
    //delete ui;
}

void PetriWidget::createPlace(int x, int y)
{
    int id = getNextPlace();
    std::string placeName = "p_"+std::to_string(id);
    spnp::Place *p = new spnp::Place(id, placeName, 0,
                                     new spnp::Label(id, placeName, x, y),
                                     x, y);
    this->netData.add(p);

}

void PetriWidget::createTransition(int x, int y)
{
    int id = getNextTransition();
    std::string transitionName = "t_"+std::to_string(id);
    spnp::Transition *t = new spnp::Transition(id, transitionName,"1", x, y);

    this->netData.add(t);
}

void PetriWidget::createArc(int idP, int idT, bool fromPtoT)
{
    int id = getNextArc();
    std::string arcName = "a_"+std::to_string(id);
    spnp::Arc *a = new spnp::Arc(id, arcName, idP, idT, fromPtoT);

    this->netData.add(a);
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

void PetriWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void PetriWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
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
