#ifndef FACADE_H
#define FACADE_H

#include "petriwidget_global.h"
#include "objs/project.h"
#include <vector>

class PETRIWIDGET_PUBLIC Facade
{
public:
    Facade();
    ~Facade();

    bool addProject(spnp::Project* p);
    bool removeProject(int id, std::string name);
    spnp::Project* getProject(int id, std::string name);
    bool updateProject(spnp::Project* p);

private:
    std::vector<spnp::Project*> *projects;
    spnp::Project* currentProject;
};

#endif // FACADE_H
