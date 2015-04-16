#include "project.h"

spnp::Project::Project(std::string name):AbstractData()
{
    this->nets = new std::vector<Net*>();
    this->name = name;
}

spnp::Project::Project(int id, std::string name, std::vector<Net *> *nets):AbstractData(id, name)
{
    this->nets = nets;
}

spnp::Project::~Project()
{
    for(auto it = nets->begin(); it != nets->end(); ++it)
        delete(*it);
    nets->clear();
    delete nets;
}

void spnp::Project::addNet(Net *net)
{
    this->nets->push_back(net);
}

spnp::Net *spnp::Project::getNet(int id) const
{
    for(auto it = this->nets->begin(); it != this->nets->end(); ++it)
    {
        if((*it)->id == id)
            return (*it);
    }
    return nullptr;
}

std::vector<spnp::Net*> *spnp::Project::getNets() const
{
    return this->nets;
}

void spnp::Project::removeNet(int id)
{
    for(unsigned int i=0; i< this->nets->size(); ++i)
    {
        if(nets->at(i)->id == id)
        {
            nets->erase(nets->begin()+i);
            break;
        }
    }
}

std::string spnp::Project::getName() const
{
    return this->name;
}

XMLNode *spnp::Project::toXML()
{
    XMLNode* node = AbstractData::toXML();
    node->setAttribute("owner", this->owner);
    node->setAttribute("commentary", this->commentary);
    for(auto it = nets->begin(); it != nets->end(); ++it)
    {
        node->addChild((*it)->toXML());
    }

    return node;
}

void spnp::Project::fromXML(XMLNode *xml)
{
    AbstractData::fromXML(xml);
    this->owner = xml->getAttributeS("owner");
    this->commentary = xml->getAttributeS("commentary");
    std::vector<XMLNode*> *v = xml->getChildrenByName("net");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Net* net = new Net();
        net->fromXML(*it);
        this->nets->push_back(net);
        delete (*it);
    }
    delete v;
}

std::string spnp::Project::getClassNodeName()
{
    return "project";
}

