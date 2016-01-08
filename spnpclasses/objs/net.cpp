#include "net.h"

spnp::Net::Net():AbstractData()
{
    this->places = new std::vector<Place*>();
    this->transitions = new std::vector<ImmediateTransition*>();
    this->arcs = new std::vector<Arc*>();
}

spnp::Net::Net(std::string name, std::vector<Place *> *places,
               std::vector<ImmediateTransition *> *transitions, std::vector<Arc *> *arcs):AbstractData(name)
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
        //delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("fluid_place");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        FluidPlace* fp = new FluidPlace();
        fp->fromXML(*it);
        this->places->push_back(fp);
        //delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("timed_transition");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        TimedTransition* tt = new TimedTransition();
        tt->fromXML(*it);
        this->transitions->push_back(tt);
        //delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("transition");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        ImmediateTransition* t = new ImmediateTransition();
        t->fromXML(*it);
        this->transitions->push_back(t);
        //delete (*it);
    }
    delete v;

    v = xml->getChildrenByName("arc");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Arc* a = new Arc();
        a->fromXML(*it);
        this->arcs->push_back(a);
        //delete (*it);
    }
    delete v;
}

void spnp::Net::add(Place *p)
{
    this->places->push_back(p);
}

void spnp::Net::add(ImmediateTransition *t)
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

        if(place->id.compare(id) == 0)
        {
            places->erase(places->begin()+i);
            delete place;
            break;
        }
    }
}

void spnp::Net::removeTransition(std::string id)
{
    for(unsigned int i=0, total = this->transitions->size(); i<total; ++i)
    {
        spnp::ImmediateTransition *transition = this->transitions->at(i);
        if(transition->id.compare(id) == 0)
        {
            transitions->erase(transitions->begin()+i);
            delete transition;
            break;
        }
    }
}

void spnp::Net::removeArc(std::string id)
{
    for(unsigned int i=0, total = this->arcs->size(); i<total; ++i)
    {
        spnp::Arc *arc = this->arcs->at(i);
        if(arc->id.compare(id) == 0)
        {
            arcs->erase(arcs->begin()+i);
            delete arc;
            break;
        }
    }
}

spnp::Place *spnp::Net::getPlace(std::string id)
{
    for(unsigned int i=0, total = this->places->size(); i<total; ++i)
    {
        spnp::Place *place = this->places->at(i);
        if(place->id.compare(id) == 0)
            return (place);
    }
    return nullptr;
}

spnp::ImmediateTransition *spnp::Net::getTransition(std::string id)
{
    for(unsigned int i=0, total = this->transitions->size(); i<total; ++i)
    {
        spnp::ImmediateTransition* trans = this->transitions->at(i);
        std::string currentId = trans->id;
        if(currentId.compare(id) == 0)
            return trans;
    }
    return nullptr;
}

spnp::Arc *spnp::Net::getArc(std::string id)
{
    for(unsigned int i=0, total = this->arcs->size(); i<total; ++i)
    {
        spnp::Arc *arc = this->arcs->at(i);
        if(arc->id.compare(id) == 0)
            return arc;
    }
    return nullptr;
}

std::vector<spnp::Place *> *spnp::Net::getPlaces() const
{
    return this->places;
}

std::vector<spnp::ImmediateTransition *> *spnp::Net::getTransitions() const
{
    return this->transitions;
}

std::vector<spnp::Arc *> *spnp::Net::getArcs() const
{
    return this->arcs;
}

std::string spnp::Net::c_str(IData *data) const
{
    (void)data;
    std::stringstream ss;
    if(places->size()>0)
    {
        ss << "/* Place */\n";
        for (int i = 0, total = places->size(); i < total; ++i)
        {
            spnp::Place* place = places->at(i);
            ss << place->c_str();
        }
    }

    if(transitions->size()>0)
    {
        ss << "/* Transition */\n";
        for (int i = 0, total = transitions->size(); i < total; ++i)
        {
            spnp::ImmediateTransition* it = transitions->at(i);
            ss << it->c_str();
        }
    }

    return ss.str();
}

std::string spnp::Net::getClassNodeName()
{
    return "net";
}
