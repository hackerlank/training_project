/********************************************************************************
** Form generated from reading UI file 'ui_about.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_ABOUT_H
#define UI_UI_ABOUT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Ui_about
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Ui_about)
    {
        if (Ui_about->objectName().isEmpty())
            Ui_about->setObjectName(QStringLiteral("Ui_about"));
        Ui_about->resize(240, 320);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Ui_about->sizePolicy().hasHeightForWidth());
        Ui_about->setSizePolicy(sizePolicy);
        Ui_about->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
        Ui_about->setModal(true);
        buttonBox = new QDialogButtonBox(Ui_about);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 270, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        retranslateUi(Ui_about);
        QObject::connect(buttonBox, SIGNAL(accepted()), Ui_about, SLOT(accept()));

        QMetaObject::connectSlotsByName(Ui_about);
    } // setupUi

    void retranslateUi(QDialog *Ui_about)
    {
        Ui_about->setWindowTitle(QApplication::translate("Ui_about", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Ui_about: public Ui_Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_ABOUT_H
