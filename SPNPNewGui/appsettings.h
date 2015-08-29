#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>
#include <QStringList>

class AppSettings
{
public:
    static AppSettings* Instance();

    QString getSPNPFolder();
    void setSPNPFolder(QString str);

    QString getExamples();
    void setExamples(QString str);

    QString getGraphs();
    void setGraphs(QString str);

    bool isLocked();
    void setLocked(bool b);

    QByteArray getGeometry();
    void setGeometry(QByteArray ba);

    QByteArray getState();
    void setState(QByteArray ba);

    static const int VERSION;

private:
    enum AppGroup { FOLDERS, SETTINGS };
    QStringList appGroups;
    enum AppGroupNames { SPNP_FOLDER, LOCKED, GEOMETRY, STATE, EXAMPLES, GRAPHS };
    QStringList appGroupNames;

    AppSettings();
    ~AppSettings();
    AppSettings(AppSettings const&){}
    AppSettings& operator =(AppSettings const &){ }
    static AppSettings* m_pInstance;

    QSettings* settings;

    QVariant getValue(AppSettings::AppGroup group, AppSettings::AppGroupNames variableName);
    void setValue(AppSettings::AppGroup group, AppSettings::AppGroupNames variableName, QVariant value);
};

#endif // APPSETTINGS_H
