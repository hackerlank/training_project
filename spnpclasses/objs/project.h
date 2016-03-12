#ifndef PROJECT_H
#define PROJECT_H

#include "objs/net.h"
#include "objs/parameter.h"
#include "objs/option.h"

namespace spnp
{
class SPNPCLASSES_PUBLIC Project : public AbstractData
{
public:
    Project(std::string name);
    Project(std::string name = "",  std::vector<Net*> *nets = new std::vector<Net*>(),
            std::string owner = "", std::string commentary = "", std::string date = "",
            Parameter *par = new Parameter(), Option *opt = new Option());
    virtual ~Project();

    void addNet(Net* net);
    Net* getNet(std::string id) const;
    std::vector<Net *> *getNets() const;
    void removeNet(std::string id);

    std::string getName() const;

    virtual XMLNode* toXML();
    virtual void fromXML(XMLNode *xml);

    virtual std::string c_str(IData* data=nullptr) const;

    Parameter *getParameters() const;
    Option *getOptions() const;
private:
    virtual std::string getClassNodeName();

    std::vector<Net*> *nets;
    std::string owner;
    std::string commentary;
    std::string date;
    Parameter *parameter;
    Option *option;
};
}

#endif // PROJECT_H
