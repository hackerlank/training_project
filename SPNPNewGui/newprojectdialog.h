#ifndef NEWPROJECTDIALOG_H
#define NEWPROJECTDIALOG_H

#include <QDialog>
#include <QAbstractButton>

#include "objs/project.h"

namespace Ui {
class NewProjectDialog;
}

class NewProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewProjectDialog(QWidget *parent = 0);
    ~NewProjectDialog();

signals:
    //passar projeto
    void startNewProject(spnp::Project *project);

private slots:
    void on_bb_okcancel_clicked(QAbstractButton *button);

private:
    Ui::NewProjectDialog *ui;

    void createProject();
};

#endif // NEWPROJECTDIALOG_H
