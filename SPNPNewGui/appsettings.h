#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QSettings>
#include <QStringList>

class AppSettings
{
public:
    enum { MaxRecentFiles = 5 };

    static AppSettings* Instance();

    QString getSPNPFolder();
    void setSPNPFolder(const QString& str);

    QString getExamples();
    void setExamples(const QString& str);

    QString getGraphs();
    void setGraphs(const QString& str);

    bool isLocked();
    void setLocked(const bool b);

    QByteArray getGeometry();
    void setGeometry(const QByteArray& ba);

    QByteArray getState();
    void setState(const QByteArray& ba);

    QStringList getRecentFiles();
    void setRecentFile(const QString &fileName);

    static const int VERSION;

private:
    enum AppGroup { FOLDERS, SETTINGS, RECENT };
    QStringList appGroups;
    enum AppGroupNames { SPNP_FOLDER,
                         LOCKED, GEOMETRY, STATE,
                         EXAMPLES, GRAPHS,
                         RECENT_FILES };
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
