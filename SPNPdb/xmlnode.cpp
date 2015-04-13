#include "xmlnode.h"
#include <stack>
#include <sstream>
#include <iterator>

XMLNode::XMLNode()
{
    this->name = "-";
    this->children = new std::vector<XMLNode*>();
    this->attributes = new std::map<std::string, std::string>();
}

XMLNode::XMLNode(std::string name)
{
    this->name = name;
    this->children = new std::vector<XMLNode*>();
    this->attributes = new std::map<std::string, std::string>();
}

XMLNode::~XMLNode()
{
    for(XMLNode *n : *(this->children))
        delete n;

    delete this->children;
    delete this->attributes;
}

std::vector<XMLNode*> *XMLNode::getChildrenByName(std::string childName)
{
    std::vector<XMLNode*> *out = new std::vector<XMLNode*>();
    for(XMLNode *n : *(this->children))
    {
        if(n->getName() == childName)
        {
            out->push_back(n);
        }
    }
    return out;
}

XMLNode *XMLNode::getChildAt(const unsigned int i) const
{
    if(i < this->children->size())
        return this->children->at(i);
    return nullptr;
}

std::vector<XMLNode *> *XMLNode::getChildren()
{
    return this->children;
}

std::string XMLNode::toString()
{
    std::string out = "";
    out += this->opening();
    out += xmlEscape(getContent());
    for(XMLNode*n : *(this->children))
    {
        out += n->toString();
    }
    out+= this->closing();

    return out;
}

XMLNode *XMLNode::fromString(std::ifstream &ifs)
{
    //std::cout << ss.str() << std::endl;

    std::string line;
    XMLNode* currentNode = nullptr;
    std::stack<XMLNode*> *xmlStack = new std::stack<XMLNode*>();
    std::string currentContent = "";
    while(std::getline(ifs, line))
    {
        if(line.at(0) == '<')
        {
            //acabou de criar conteúdo, pode adicionar
            if(!currentContent.empty() && currentNode != nullptr)
            {
                //'desescapando' o conteúdo
                currentNode->setContent(xmlUnescape(currentContent));
                currentContent = "";
            }
            if(line.at(1) != '/')
            {
                //iniciou o nó
                /*if(currentNode != nullptr)
                {
                    xmlStack->push(currentNode);
                }*/

                //pega o nome
                line = line.substr(1, line.size()-2);
                std::stringstream ss(line);
                std::istream_iterator<std::string> begin(ss);
                std::istream_iterator<std::string> end;
                std::vector<std::string> vstrings(begin, end);

                //'desescapando' o nome
                XMLNode* xNode = new XMLNode(xmlUnescape(vstrings[0]));

                if(currentNode != nullptr)
                    currentNode->addChild(xNode);

                currentNode = xNode;
                xmlStack->push(currentNode);

                for(unsigned int i = 1; i< vstrings.size(); ++i)
                {
                    std::string tempStr = vstrings.at(i);
                    int equalsAt = tempStr.find('=');
                    std::string left = tempStr.substr(0,equalsAt);
                    std::string right = tempStr.substr(equalsAt+1);
                    right = right.substr(1, right.size()-2);
                    //'desescapando' os atributos
                    left = xmlUnescape(left);
                    right = xmlUnescape(right);
                    currentNode->setAttribute(left, right);
                }
            }
            else
            {
                //fechou o nó
                xmlStack->pop();
                if(!xmlStack->empty())
                    currentNode = xmlStack->top();
            }
        }
        else
        {
            //conteúdo textual do nó
            currentContent += line;
        }
    }
    //currentNode = xmlStack->top();
    //xmlStack->pop();
    delete xmlStack;
    return currentNode;
}

std::string XMLNode::getName() const
{
    return this->name;
}

void XMLNode::setName(std::string name)
{
    this->name = name;
}

std::string XMLNode::getContent() const
{
    return this->content;
}

void XMLNode::setContent(std::string content)
{
    this->content = content+"\n";
}

void XMLNode::addChild(XMLNode *node)
{
    this->children->push_back(node);
}

void XMLNode::removeChildrenByName(std::string name)
{
    int pos = 0;
    for(XMLNode* n : *(this->children))
    {
        if(n->getName() == name)
        {
            this->removeChildAt(pos);
            pos--;
        }
        pos++;
    }
}

void XMLNode::removeChildAt(const unsigned int i)
{
    if(i<this->children->size())
        this->children->erase(this->children->begin()+i);
}

void XMLNode::setAttribute(std::string attName, std::string attValue)
{
    this->attributes->insert(std::pair<std::string,std::string>(attName, attValue));
}

void XMLNode::setAttribute(std::string attName, int attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, long attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, long long attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, double attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, long double attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, float attValue)
{
    this->setAttribute(attName, std::to_string(attValue));
}

void XMLNode::setAttribute(std::string attName, bool attValue)
{
    this->setAttribute(attName, attValue ? "true" : "false");
}

void XMLNode::removeAttribute(std::string name)
{
    this->attributes->erase(name);
}

std::string XMLNode::getAttributeS(std::string name) const
{
    return this->getAttributeByName(name);
}

int XMLNode::getAttributeI(std::string name)
{
    return std::stoi(this->getAttributeByName(name));
}

long XMLNode::getAttributeL(std::string name)
{
    return std::stol(this->getAttributeByName(name));
}

long long XMLNode::getAttributeLL(std::string name)
{
    return std::stoll(this->getAttributeByName(name));
}

double XMLNode::getAttributeD(std::string name)
{
    return std::stod(this->getAttributeByName(name));
}

long double XMLNode::getAttributeLD(std::string name)
{
    return std::stold(this->getAttributeByName(name));
}

float XMLNode::getAttributeF(std::string name)
{
    return std::stof(this->getAttributeByName(name));
}

bool XMLNode::getAttributeB(std::string name)
{
    return name == "true";
}

std::string XMLNode::opening()
{
    std::string header = "<" + xmlEscape(getName());
    for(auto iter : *this->attributes)
        header += " " + xmlEscape(iter.first) + "='" + xmlEscape(iter.second) +"'";

    header += ">\n";

    return header;
}

std::string XMLNode::closing()
{
    std::string foot = "</" + xmlEscape(this->name) + ">\n";
    return foot;
}

std::string XMLNode::getAttributeByName(std::string name) const
{
    std::map<std::string, std::string>::iterator p;
    p = this->attributes->find(name);
    if(p == this->attributes->end()) return "";
    else return p->second;
}

std::string XMLNode::stringReplace(std::string xml, std::vector<std::string> from, std::vector<std::string> to)
{
    for(unsigned int i = 0; i<from.size(); ++i)
    {
        std::string s = from.at(i);
        std::string t = to.at(i);
        std::string::size_type n = 0;
        while ( ( n = xml.find( s, n ) ) != std::string::npos )
        {
            xml.replace( n, s.size(), t );
            n += t.size();
        }
    }
    return xml;
}

std::string XMLNode::xmlEscape(std::string xml)
{
    return stringReplace(xml, UNESCAPED, ESCAPED);
}

std::string XMLNode::xmlUnescape(std::string xml)
{
    return stringReplace(xml, ESCAPED, UNESCAPED);
}

const std::vector<std::string> XMLNode::UNESCAPED = { "<", ">" };
const std::vector<std::string> XMLNode::ESCAPED = { "&lt;", "&gt;" };
