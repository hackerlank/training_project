#include "facade.h"

Facade::Facade()
{
    this->projects = new std::vector<spnp::Project*>();
    this->currentProject = nullptr;
}

Facade::~Facade()
{
    for(std::vector<spnp::Project*>::iterator it = this->projects->begin(); it != this->projects->end(); ++it)
    {
        //spnp::Project* p = (*it);
        delete (*it);
    }
    delete this->projects;
}

bool Facade::addProject(spnp::Project *p)
{
    for(auto it = this->projects->begin(); it != this->projects->end(); ++it)
    {
        spnp::Project* pp = (*it);
        if(pp->id == p->id && pp->getName() == p->getName())
            return false;
    }
    this->projects->push_back(p);
    return true;
}

bool Facade::removeProject(int id, std::string name)
{
    int size = this->projects->size();
    for(int i=0; i<size; ++i)
    {
        spnp::Project* p = this->projects->at(i);
        if(p->id == id && p->getName() == name)
        {
            this->projects->erase(this->projects->begin()+1);
            return true;
        }
    }
    return false;
}

spnp::Project* Facade::getProject(int id, std::string name)
{
    int size = this->projects->size();
    for(int i=0; i<size; ++i)
    {
        spnp::Project* p = this->projects->at(i);
        if(p->id == id && p->getName() == name)
        {
            return p;
        }
    }
    return nullptr;
}

bool Facade::updateProject(spnp::Project *p)
{
    //TODO verificar necessidade
}

