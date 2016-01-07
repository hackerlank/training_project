#include "project.h"

spnp::Project::Project(std::string name):AbstractData(name)
{
    this->nets = new std::vector<Net*>();
    this->name = name;
    this->owner = "";
    this->commentary = "";
    this->date = "";
}

spnp::Project::Project(std::string name, std::vector<Net *> *nets, std::string owner,
                       std::string commentary, std::string date):AbstractData(name)
{
    this->nets = nets;
    this->owner = owner;
    this->commentary = commentary;
    this->date = date;
}

spnp::Project::~Project()
{
    for(int i=0, total = this->nets->size(); i<total; ++i)
    {
        spnp::Net* currentNet = this->nets->at(i);
        delete currentNet;
    }
    nets->clear();
    delete nets;
}

void spnp::Project::addNet(Net *net)
{
    this->nets->push_back(net);
}

spnp::Net *spnp::Project::getNet(std::string id) const
{
    for(auto it = this->nets->begin(); it != this->nets->end(); ++it)
    {
        if((*it)->id.compare(id))
            return (*it);
    }
    return nullptr;
}

std::vector<spnp::Net*> *spnp::Project::getNets() const
{
    return this->nets;
}

void spnp::Project::removeNet(std::string id)
{
    for(unsigned int i=0, total = this->nets->size(); i < total; ++i)
    {
        if(nets->at(i)->id.compare(id))
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
    node->setAttribute("date", this->date);
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
    this->date = xml->getAttributeS("date");
    std::vector<XMLNode*> *v = xml->getChildrenByName("net");
    for(auto it = v->begin(); it != v->end(); ++it)
    {
        Net* net = new Net();
        net->fromXML(*it);
        this->nets->push_back(net);
    }
    delete v;
}

std::string spnp::Project::c_str() const
{
    throw;
}

std::string spnp::Project::getClassNodeName()
{
    return "project";
}

