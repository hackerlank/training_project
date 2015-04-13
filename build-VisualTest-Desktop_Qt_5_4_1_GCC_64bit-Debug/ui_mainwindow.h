/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionSave_project;
    QAction *actionSave_project_as;
    QAction *actionSave_model;
    QAction *actionPreferences;
    QAction *actionExit;
    QAction *actionLibrary;
    QAction *actionContents;
    QAction *actionNewProject;
    QAction *actionNewModel;
    QAction *actionOpenProject;
    QAction *actionOpenModel;
    QAction *actionAbout;
    QAction *actionAbout_SPNP;
    QAction *actionSetup;
    QAction *actionPrintProject;
    QAction *actionPrintModel;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QListWidget *listWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuOpen_project;
    QMenu *menuPrinter_setup;
    QMenu *menuModel_Editor;
    QMenu *menuAnalysis_Editor;
    QMenu *menuPlot;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(673, 409);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setAcceptDrops(true);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave_project = new QAction(MainWindow);
        actionSave_project->setObjectName(QStringLiteral("actionSave_project"));
        actionSave_project_as = new QAction(MainWindow);
        actionSave_project_as->setObjectName(QStringLiteral("actionSave_project_as"));
        actionSave_model = new QAction(MainWindow);
        actionSave_model->setObjectName(QStringLiteral("actionSave_model"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLibrary = new QAction(MainWindow);
        actionLibrary->setObjectName(QStringLiteral("actionLibrary"));
        actionContents = new QAction(MainWindow);
        actionContents->setObjectName(QStringLiteral("actionContents"));
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QStringLiteral("actionNewProject"));
        actionNewModel = new QAction(MainWindow);
        actionNewModel->setObjectName(QStringLiteral("actionNewModel"));
        actionNewModel->setEnabled(false);
        actionOpenProject = new QAction(MainWindow);
        actionOpenProject->setObjectName(QStringLiteral("actionOpenProject"));
        actionOpenModel = new QAction(MainWindow);
        actionOpenModel->setObjectName(QStringLiteral("actionOpenModel"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_SPNP = new QAction(MainWindow);
        actionAbout_SPNP->setObjectName(QStringLiteral("actionAbout_SPNP"));
        actionSetup = new QAction(MainWindow);
        actionSetup->setObjectName(QStringLiteral("actionSetup"));
        actionPrintProject = new QAction(MainWindow);
        actionPrintProject->setObjectName(QStringLiteral("actionPrintProject"));
        actionPrintModel = new QAction(MainWindow);
        actionPrintModel->setObjectName(QStringLiteral("actionPrintModel"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        listWidget = new QListWidget(splitter);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMinimumSize(QSize(100, 0));
        listWidget->setMaximumSize(QSize(150, 16777215));
        splitter->addWidget(listWidget);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 276, 328));
        scrollArea->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(scrollArea);
        scrollArea_2 = new QScrollArea(splitter);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setMinimumSize(QSize(150, 0));
        scrollArea_2->setMaximumSize(QSize(200, 16777215));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 181, 345));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        splitter->addWidget(scrollArea_2);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuOpen_project = new QMenu(menuFile);
        menuOpen_project->setObjectName(QStringLiteral("menuOpen_project"));
        menuPrinter_setup = new QMenu(menuFile);
        menuPrinter_setup->setObjectName(QStringLiteral("menuPrinter_setup"));
        menuModel_Editor = new QMenu(menuBar);
        menuModel_Editor->setObjectName(QStringLiteral("menuModel_Editor"));
        menuAnalysis_Editor = new QMenu(menuBar);
        menuAnalysis_Editor->setObjectName(QStringLiteral("menuAnalysis_Editor"));
        menuPlot = new QMenu(menuBar);
        menuPlot->setObjectName(QStringLiteral("menuPlot"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(listWidget, scrollArea);
        QWidget::setTabOrder(scrollArea, scrollArea_2);

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
        menuFile->addAction(menuPrinter_setup->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionPreferences);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew->addAction(actionNewProject);
        menuNew->addAction(actionNewModel);
        menuOpen_project->addAction(actionOpenProject);
        menuOpen_project->addAction(actionOpenModel);
        menuPrinter_setup->addAction(actionSetup);
        menuPrinter_setup->addSeparator();
        menuPrinter_setup->addAction(actionPrintProject);
        menuPrinter_setup->addAction(actionPrintModel);
        menuPlot->addAction(actionLibrary);
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionAbout_SPNP);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        toolBar->addAction(actionNewProject);
        toolBar->addAction(actionOpenProject);
        toolBar->addSeparator();
        toolBar->addAction(actionClose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SPNP - New Gui", 0));
        actionClose->setText(QApplication::translate("MainWindow", "&Close", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionSave_project->setText(QApplication::translate("MainWindow", "&Save project", 0));
        actionSave_project->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_project_as->setText(QApplication::translate("MainWindow", "Save project &as...", 0));
        actionSave_model->setText(QApplication::translate("MainWindow", "Save &model", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionLibrary->setText(QApplication::translate("MainWindow", "Library", 0));
        actionContents->setText(QApplication::translate("MainWindow", "&Contents", 0));
        actionNewProject->setText(QApplication::translate("MainWindow", "&Project", 0));
        actionNewProject->setIconText(QApplication::translate("MainWindow", "New project", 0));
#ifndef QT_NO_TOOLTIP
        actionNewProject->setToolTip(QApplication::translate("MainWindow", "New Project", 0));
#endif // QT_NO_TOOLTIP
        actionNewModel->setText(QApplication::translate("MainWindow", "&Model", 0));
        actionOpenProject->setText(QApplication::translate("MainWindow", "&Project", 0));
        actionOpenProject->setIconText(QApplication::translate("MainWindow", "Open project", 0));
#ifndef QT_NO_TOOLTIP
        actionOpenProject->setToolTip(QApplication::translate("MainWindow", "Open project", 0));
#endif // QT_NO_TOOLTIP
        actionOpenModel->setText(QApplication::translate("MainWindow", "Model", 0));
        actionOpenModel->setIconText(QApplication::translate("MainWindow", "&Model", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About New Gui", 0));
        actionAbout_SPNP->setText(QApplication::translate("MainWindow", "About &SPNP", 0));
        actionAbout_SPNP->setIconText(QApplication::translate("MainWindow", "About SPNP", 0));
#ifndef QT_NO_TOOLTIP
        actionAbout_SPNP->setToolTip(QApplication::translate("MainWindow", "About SPNP", 0));
#endif // QT_NO_TOOLTIP
        actionSetup->setText(QApplication::translate("MainWindow", "Printer setup...", 0));
        actionPrintProject->setText(QApplication::translate("MainWindow", "Project", 0));
        actionPrintModel->setText(QApplication::translate("MainWindow", "Model", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "a", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "b", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuNew->setTitle(QApplication::translate("MainWindow", "&New", 0));
        menuOpen_project->setTitle(QApplication::translate("MainWindow", "&Open project", 0));
        menuPrinter_setup->setTitle(QApplication::translate("MainWindow", "Printer setup", 0));
        menuModel_Editor->setTitle(QApplication::translate("MainWindow", "&Model Editor", 0));
        menuAnalysis_Editor->setTitle(QApplication::translate("MainWindow", "&Analysis Editor", 0));
        menuPlot->setTitle(QApplication::translate("MainWindow", "&Plot", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
