#include "appsettings.h"

AppSettings* AppSettings::m_pInstance = nullptr;

AppSettings* AppSettings::Instance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new AppSettings();
    }

    return m_pInstance;
}

QString AppSettings::getSPNPFolder()
{
    return this->getValue(FOLDERS, SPNP_FOLDER).toString();
}

void AppSettings::setSPNPFolder(QString str)
{
    this->setValue(FOLDERS, SPNP_FOLDER, str);
}

QString AppSettings::getExamples()
{
    return this->getValue(FOLDERS, EXAMPLES).toString();
}

void AppSettings::setExamples(QString str)
{
    this->setValue(FOLDERS, EXAMPLES, str);
}

QString AppSettings::getGraphs()
{
    return this->getValue(FOLDERS, GRAPHS).toString();
}

void AppSettings::setGraphs(QString str)
{
    this->setValue(FOLDERS, GRAPHS, str);
}

bool AppSettings::isLocked()
{
    return this->getValue(SETTINGS, LOCKED).toBool();
}

void AppSettings::setLocked(bool b)
{
    this->setValue(SETTINGS, LOCKED, b);
}

QByteArray AppSettings::getGeometry()
{
    return this->getValue(SETTINGS, GEOMETRY).toByteArray();
}

void AppSettings::setGeometry(QByteArray ba)
{
    this->setValue(SETTINGS, GEOMETRY, ba);
}

QByteArray AppSettings::getState()
{
    return this->getValue(SETTINGS, STATE).toByteArray();
}

void AppSettings::setState(QByteArray ba)
{
    this->setValue(SETTINGS, STATE, ba);
}

AppSettings::AppSettings()
{
    this->settings = new QSettings("spnpNewGui.ini", QSettings::IniFormat);
    this->appGroups << "folders" << "settings";
    this->appGroupNames << "spnp_folder" << "locked" << "geometry" << "state" << "spnp_examples" << "spnp_graphs";
}

AppSettings::~AppSettings()
{
    delete this->settings;
}

QVariant AppSettings::getValue(AppSettings::AppGroup group, AppSettings::AppGroupNames variableName)
{
    this->settings->beginGroup(this->appGroups.at(group));
    QVariant out = this->settings->value(this->appGroupNames.at(variableName));
    this->settings->endGroup();
    return out;
}

void AppSettings::setValue(AppSettings::AppGroup group, AppSettings::AppGroupNames variableName, QVariant value)
{
    this->settings->beginGroup(this->appGroups.at(group));
    this->settings->setValue(this->appGroupNames.at(variableName), value);
    this->settings->endGroup();
    this->settings->sync();
}

const int AppSettings::VERSION = 1;
