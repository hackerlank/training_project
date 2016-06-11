#ifndef PROJECT_H
#define PROJECT_H

#include "objs/net.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Project : public AbstractData
{
public:
    Project(std::string name);
    Project(int id, std::string name, std::vector<Net*> *nets = new std::vector<Net*>());
    virtual ~Project();

    void addNet(Net* net);
    Net* getNet(int id) const;
    std::vector<Net *> *getNets() const;
    void removeNet(int id);

    std::string getName() const;

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);
private:
    virtual std::string getClassNodeName();

    std::vector<Net*> *nets;
    std::string owner;
    std::string commentary;

    //fazer
    //date
};
}

#endif // PROJECT_H
