#ifndef XMLNODE_H
#define XMLNODE_H

#include "spnpdb_global.h"
#include <vector>
#include <map>
#include <fstream>

class SPNPDB_PUBLIC XMLNode
{
public:
    XMLNode();
    XMLNode(std::string name);
    ~XMLNode();

    /** Retorna os filhos com o nome especificado
     * @brief getChildrenByName
     * @param childName
     * @return
     */
    std::vector<XMLNode *> *getChildrenByName(std::string childName);

    /** Retorna o filho específico
     * @brief getChildAt
     * @param i
     * @return
     */
    XMLNode* getChildAt(const unsigned int i) const;

    /** Retorna todos os filhos
     * @brief getChildren
     * @return
     */
    std::vector<XMLNode*> *getChildren();

    /** Converte em string
     * @brief toString
     * @return
     */
    std::string toString();

    /** Recebe dados de um string
     * @brief fromString
     * @param str
     */
    static XMLNode *fromString(std::ifstream &ifs);

    /** Retorna o nome do nó
     * @brief getName
     * @return
     */
    std::string getName() const;

    /** Modifica o nome do nó
     * @brief setName
     * @param name
     */
    void setName(std::string name);

    /** Retorna o conteúdo do nó
     * @brief getContent
     * @return
     */
    std::string getContent() const;

    /** Altera o conteúdo do nó
     * @brief setContent
     * @param content
     */
    void setContent(std::string content);

    /** Adiciona um nó filho
     * @brief addChild
     * @param node
     */
    void addChild(XMLNode* node);

    /** Remove os filhos com o nome específico
     * @brief removeChildrenByName
     * @param name
     */
    void removeChildrenByName(std::string name);

    /** Remove o filho na posição
     * @brief removeChildAt
     * @param i
     */
    void removeChildAt(const unsigned int i);

    /** Adiciona um atributo ao xml
     * @brief setAttribute
     * @param attName
     * @param attValue
     */
    void setAttribute(std::string attName, std::string attValue);
    void setAttribute(std::string attName, int attValue);
    void setAttribute(std::string attName, long attValue);
    void setAttribute(std::string attName, long long attValue);
    void setAttribute(std::string attName, double attValue);
    void setAttribute(std::string attName, long double attValue);
    void setAttribute(std::string attName, float attValue);
    void setAttribute(std::string attName, bool attValue);


    /** Remove um atributo específico
     * @brief removeAttribute
     * @param name
     */
    void removeAttribute(std::string name);

    /** Retorna o atributo de acordo com o nome
     * @brief getAttribute
     * @param name
     * @return
     */
    std::string getAttributeS(std::string name) const;
    int getAttributeI(std::string name);
    long getAttributeL(std::string name);
    long long getAttributeLL(std::string name);
    double getAttributeD(std::string name);
    long double getAttributeLD(std::string name);
    float getAttributeF(std::string name);
    bool getAttributeB(std::string name);

    /** Remove "<" e ">" para facilitar o parser
     * @brief xmlEscape
     * @param xml
     * @return
     */
    static std::string xmlEscape(std::string xml);

    /** Recupera o "<" e ">" para o original
     * @brief xmlUnescape
     * @param xml
     * @return
     */
    static std::string xmlUnescape(std::string xml);

private:
    /** Ponteiro para nós filhos
     * @brief children
     */
    std::vector<XMLNode*> *children;

    /** Nome desse nó
     * @brief name
     */
    std::string name;

    /** Conteúdo do nó
     * @brief content
     */
    std::string content;

    /** Atributos do nó
     * @brief attributes
     */
    std::map<std::string, std::string> *attributes;

    std::string opening();
    std::string closing();

    std::string getAttributeByName(std::string name) const;

    /** Troca todas as ocorrências de 'from' para 'to'
     * @brief stringReplace
     * @param xml
     * @param from
     * @param to
     * @return
     */
    static std::string stringReplace(std::string xml, std::vector<std::string> from, std::vector<std::string> to);

    static const std::vector<std::string> UNESCAPED;
    static const std::vector<std::string> ESCAPED;
};
#endif // XMLNODE_H
