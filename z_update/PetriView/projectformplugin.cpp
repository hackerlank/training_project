#include "projectform.h"
#include "projectformplugin.h"

#include <QtPlugin>

ProjectFormPlugin::ProjectFormPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void ProjectFormPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool ProjectFormPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *ProjectFormPlugin::createWidget(QWidget *parent)
{
    return new ProjectForm(parent);
}

QString ProjectFormPlugin::name() const
{
    return QLatin1String("ProjectForm");
}

QString ProjectFormPlugin::group() const
{
    return QLatin1String("Petri Net");
}

QIcon ProjectFormPlugin::icon() const
{
    return QIcon(QLatin1String(":/proj.ico"));
}

QString ProjectFormPlugin::toolTip() const
{
    return QLatin1String("");
}

QString ProjectFormPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool ProjectFormPlugin::isContainer() const
{
    return false;
}

QString ProjectFormPlugin::domXml() const
{
    return QLatin1String("<widget class=\"ProjectForm\" name=\"projectForm\">\n</widget>\n");
}

QString ProjectFormPlugin::includeFile() const
{
    return QLatin1String("projectform.h");
}

