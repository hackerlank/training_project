#include "netform.h"
#include "netviewplugin.h"

#include <QtPlugin>

NetViewPlugin::NetViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void NetViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool NetViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *NetViewPlugin::createWidget(QWidget *parent)
{
    return new NetForm(parent);
}

QString NetViewPlugin::name() const
{
    return QLatin1String("NetForm");
}

QString NetViewPlugin::group() const
{
    return QLatin1String("Petri Net");
}

QIcon NetViewPlugin::icon() const
{
    return QIcon(QLatin1String(":/net.ico"));
}

QString NetViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString NetViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool NetViewPlugin::isContainer() const
{
    return false;
}

QString NetViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"NetForm\" name=\"netForm\">\n</widget>\n");
}

QString NetViewPlugin::includeFile() const
{
    return QLatin1String("netform.h");
}

