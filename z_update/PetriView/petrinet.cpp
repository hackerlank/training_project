#include "projectformplugin.h"
#include "netviewplugin.h"
#include "petrinet.h"

PetriNet::PetriNet(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new ProjectFormPlugin(this));
    m_widgets.append(new NetViewPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> PetriNet::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(petrinetplugin, PetriNet)
#endif // QT_VERSION < 0x050000
