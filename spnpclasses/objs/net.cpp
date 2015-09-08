#include "net.h"

spnp::Net::Net():AbstractData()
{
    this->places = new std::vector<Place*>();
    this->transitions = new std::vector<Transition*>();
    this->arcs = new std::vector<Arc*>();
}

spnp::Net::Net(std::string name, std::vector<Place *> *places,
               std::vector<Transition *> *transitions, std::vector<Arc *> *arcs):AbstractData(name)
{
    this->places = places;
    this->transitions = transitions;
    this->arcs = arcs;
}

spnp::Net::~Net()
{
    for(int i=0, total = this->places->size(); i<total; ++i)
    {
        spnp::Place* _place = this->places->at(i);
        delete _place;
    }
    places->clear();
    delete places;

    /*for(auto it = transitions->begin(); it != transitions->end(); ++it)
        delete(*it);
    for(auto it = arcs->begin(); it != arcs->end(); ++it)
        delete(*it);*/

    //transitions->clear();
    //arcs->clear();

    //delete transitions;
    //delete arcs;
}

XMLNode *spnp::Net::toXML()
{
    XMLNode* node = AbstractData::toXML();
    for(auto it = places->begin(); it != places->end(); ++it)
    {
        node->addChild((*it)->toXML());
    }
    for(auto it = transitions->begin(); it != transitions->end(); ++it)
    {
        node->addChild((*it)->toXML());
    }
    for(auto it = arcs->begin(); it != arcs->end(); ++it)
    {
        node->addChild((*it)->toXML());
    }

    return node;
}

void spnp::Net::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    std::vector<XMLNode*> *v = xml->getChildrenByName("place");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Place* p = new Place();
        p->fromXML(*it);
        this->places->push_back(p);
        delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("fluid_place");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        FluidPlace* fp = new FluidPlace();
        fp->fromXML(*it);
        this->places->push_back(fp);
        delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("timed_transition");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        TimedTransition* tt = new TimedTransition();
        tt->fromXML(*it);
        this->transitions->push_back(tt);
        delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("transition");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Transition* t = new Transition();
        t->fromXML(*it);
        this->transitions->push_back(t);
        delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("arc");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Arc* a = new Arc();
        a->fromXML(*it);
        this->arcs->push_back(a);
        delete (*it);
    }
    delete v;
}

void spnp::Net::add(Place *p)
{
    this->places->push_back(p);
}

void spnp::Net::add(Transition *t)
{
    this->transitions->push_back(t);
}

void spnp::Net::add(Arc *a)
{
    this->arcs->push_back(a);
}

void spnp::Net::removePlace(std::string id)
{
    for(unsigned int i=0, total = this->places->size(); i<total; ++i)
    {
        spnp::Place *place = this->places->at(i);

        if(place->id.compare(id))
        {
            places->erase(places->begin()+i);
            break;
        }
    }
}

void spnp::Net::removeTransition(std::string id)
{
    for(unsigned int i=0, total = this->transitions->size(); i<total; ++i)
    {
        spnp::Transition *transition = this->transitions->at(i);
        if(transition->id.compare(id))
        {
            transitions->erase(transitions->begin()+i);
            break;
        }
    }
}

void spnp::Net::removeArc(std::string id)
{
    for(unsigned int i=0, total = this->arcs->size(); i<total; ++i)
    {
        spnp::Arc *arc = this->arcs->at(i);
        if(arc->id.compare(id))
        {
            arcs->erase(arcs->begin()+i);
            break;
        }
    }
}

spnp::Place *spnp::Net::getPlace(std::string id)
{
    for(unsigned int i=0, total = this->places->size(); i<total; ++i)
    {
        spnp::Place *place = this->places->at(i);
        if(place->id.compare(id))
            return (place);
    }
    return nullptr;
}

spnp::Transition *spnp::Net::getTransition(std::string id)
{
    for(unsigned int i=0, total = this->transitions->size(); i<total; ++i)
    {
        spnp::Transition* trans = this->transitions->at(i);
        if(trans->id.compare(id))
            return trans;
    }
    return nullptr;
}

spnp::Arc *spnp::Net::getArc(std::string id)
{
    for(unsigned int i=0, total = this->arcs->size(); i<total; ++i)
    {
        spnp::Arc *arc = this->arcs->at(i);
        if(arc->id.compare(id))
            return arc;
    }
    return nullptr;
}

std::vector<spnp::Place *> *spnp::Net::getPlaces() const
{
    return this->places;
}

std::vector<spnp::Transition *> *spnp::Net::getTransitions() const
{
    return this->transitions;
}

std::vector<spnp::Arc *> *spnp::Net::getArcs() const
{
    return this->arcs;
}

std::string spnp::Net::getClassNodeName()
{
    return "net";
}
