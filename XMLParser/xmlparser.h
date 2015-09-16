#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "xmlparser_global.h"

#include <vector>
#include <map>
#include <fstream>

class XMLPARSER_PUBLIC XMLNode
{
public:
    XMLNode();
    XMLNode(std::string name);
    ~XMLNode();

    std::vector<XMLNode *> *getChildrenByName(std::string childName);

    XMLNode* getChildAt(const unsigned int i) const;

    std::vector<XMLNode*> *getChildren();

    std::string toString();

    static XMLNode *fromString(std::string str);

    std::string getName() const;

    void setName(std::string name);

    std::string getContent() const;

    void setContent(std::string content);

    void addChild(XMLNode* node);

    void removeChildrenByName(std::string name);

    void removeChildAt(const unsigned int i);

    void setAttribute(std::string attName, std::string attValue);
    void setAttribute(std::string attName, int attValue);
    void setAttribute(std::string attName, long attValue);
    void setAttribute(std::string attName, long long attValue);
    void setAttribute(std::string attName, double attValue);
    void setAttribute(std::string attName, long double attValue);
    void setAttribute(std::string attName, float attValue);
    void setAttribute(std::string attName, bool attValue);

    void removeAttribute(std::string name);

    std::string getAttributeS(std::string name) const;
    int getAttributeI(std::string name);
    long getAttributeL(std::string name);
    long long getAttributeLL(std::string name);
    double getAttributeD(std::string name);
    long double getAttributeLD(std::string name);
    float getAttributeF(std::string name);
    bool getAttributeB(std::string name);

    static std::string xmlEscape(std::string xml);

    static std::string xmlUnescape(std::string xml);

private:
    std::vector<XMLNode*> *children;

    std::string name;

    std::string content;

    std::map<std::string, std::string> *attributes;

    std::string opening();
    std::string closing();

    std::string getAttributeByName(std::string name) const;

    static std::string stringReplace(std::string xml, std::vector<std::string> from, std::vector<std::string> to);

    static const std::vector<std::string> UNESCAPED;
    static const std::vector<std::string> ESCAPED;
};

#endif // XMLPARSER_H
