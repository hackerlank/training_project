/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReopen;
    QAction *actionOpen_a_model;
    QAction *actionClose;
    QAction *actionSave_project;
    QAction *actionSave_project_as;
    QAction *actionSave_model;
    QAction *actionPrinter_setup;
    QAction *actionPrint_the_project;
    QAction *actionPrint_current_model;
    QAction *actionPreferences;
    QAction *actionExit;
    QAction *actionLibrary;
    QAction *actionContents;
    QAction *actionMouse_bindings;
    QAction *actionAbout;
    QAction *actionProject;
    QAction *actionModel;
    QAction *actionProject_2;
    QAction *actionModel_2;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen_project;
    QMenu *menuModel_Editor;
    QMenu *menuAnalysis_Editor;
    QMenu *menuPlot;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(769, 389);
        actionReopen = new QAction(MainWindow);
        actionReopen->setObjectName(QStringLiteral("actionReopen"));
        actionOpen_a_model = new QAction(MainWindow);
        actionOpen_a_model->setObjectName(QStringLiteral("actionOpen_a_model"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave_project = new QAction(MainWindow);
        actionSave_project->setObjectName(QStringLiteral("actionSave_project"));
        actionSave_project_as = new QAction(MainWindow);
        actionSave_project_as->setObjectName(QStringLiteral("actionSave_project_as"));
        actionSave_model = new QAction(MainWindow);
        actionSave_model->setObjectName(QStringLiteral("actionSave_model"));
        actionPrinter_setup = new QAction(MainWindow);
        actionPrinter_setup->setObjectName(QStringLiteral("actionPrinter_setup"));
        actionPrint_the_project = new QAction(MainWindow);
        actionPrint_the_project->setObjectName(QStringLiteral("actionPrint_the_project"));
        actionPrint_current_model = new QAction(MainWindow);
        actionPrint_current_model->setObjectName(QStringLiteral("actionPrint_current_model"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLibrary = new QAction(MainWindow);
        actionLibrary->setObjectName(QStringLiteral("actionLibrary"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QStringLiteral("actionContents"));
        actionMouse_bindings = new QAction(MainWindow);
        actionMouse_bindings->setObjectName(QStringLiteral("actionMouse_bindings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionProject = new QAction(MainWindow);
        actionProject->setObjectName(QStringLiteral("actionProject"));
        actionModel = new QAction(MainWindow);
        actionModel->setObjectName(QStringLiteral("actionModel"));
        actionModel->setEnabled(false);
        actionProject_2 = new QAction(MainWindow);
        actionProject_2->setObjectName(QStringLiteral("actionProject_2"));
        actionModel_2 = new QAction(MainWindow);
        actionModel_2->setObjectName(QStringLiteral("actionModel_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 769, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuOpen_project = new QMenu(menuFile);
        menuOpen_project->setObjectName(QStringLiteral("menuOpen_project"));
        menuModel_Editor = new QMenu(menuBar);
        menuModel_Editor->setObjectName(QStringLiteral("menuModel_Editor"));
        menuAnalysis_Editor = new QMenu(menuBar);
        menuAnalysis_Editor->setObjectName(QStringLiteral("menuAnalysis_Editor"));
        menuPlot = new QMenu(menuBar);
        menuPlot->setObjectName(QStringLiteral("menuPlot"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuModel_Editor->menuAction());
        menuBar->addAction(menuAnalysis_Editor->menuAction());
        menuBar->addAction(menuPlot->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(menuOpen_project->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_project);
        menuFile->addAction(actionSave_project_as);
        menuFile->addAction(actionSave_model);
        menuFile->addSeparator();
        menuFile->addAction(actionPrinter_setup);
        menuFile->addAction(actionPrint_the_project);
        menuFile->addAction(actionPrint_current_model);
        menuFile->addSeparator();
        menuFile->addAction(actionPreferences);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew->addAction(actionProject);
        menuNew->addAction(actionModel);
        menuOpen_project->addAction(actionProject_2);
        menuOpen_project->addAction(actionModel_2);
        menuPlot->addAction(actionLibrary);
        menuHelp->addAction(actionContents);
        menuHelp->addSeparator();
        menuHelp->addAction(actionMouse_bindings);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionReopen->setText(QApplication::translate("MainWindow", "Reopen", 0));
        actionOpen_a_model->setText(QApplication::translate("MainWindow", "Open a model", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionSave_project->setText(QApplication::translate("MainWindow", "&Save project", 0));
        actionSave_project_as->setText(QApplication::translate("MainWindow", "Save project as...", 0));
        actionSave_model->setText(QApplication::translate("MainWindow", "Save model", 0));
        actionPrinter_setup->setText(QApplication::translate("MainWindow", "Printer setup", 0));
        actionPrint_the_project->setText(QApplication::translate("MainWindow", "Print the project", 0));
        actionPrint_current_model->setText(QApplication::translate("MainWindow", "Print current model", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionLibrary->setText(QApplication::translate("MainWindow", "Library", 0));
        actionContents->setText(QApplication::translate("MainWindow", "Contents", 0));
        actionMouse_bindings->setText(QApplication::translate("MainWindow", "Mouse bindings", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionProject->setText(QApplication::translate("MainWindow", "Project", 0));
        actionModel->setText(QApplication::translate("MainWindow", "Model", 0));
        actionProject_2->setText(QApplication::translate("MainWindow", "&Project", 0));
        actionModel_2->setText(QApplication::translate("MainWindow", "Model", 0));
        actionModel_2->setIconText(QApplication::translate("MainWindow", "&Model", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "&New", 0));
        menuOpen_project->setTitle(QApplication::translate("MainWindow", "&Open project", 0));
        menuModel_Editor->setTitle(QApplication::translate("MainWindow", "Model Editor", 0));
        menuAnalysis_Editor->setTitle(QApplication::translate("MainWindow", "Analysis Editor", 0));
        menuPlot->setTitle(QApplication::translate("MainWindow", "Plot", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
