#ifndef PROJECTFORM_H
#define PROJECTFORM_H

#include <QWidget>
//#include "objs/project.h"

namespace Ui {
class ProjectForm;
}

class ProjectForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectForm(QWidget *parent = 0);
    ~ProjectForm();

private:
    Ui::ProjectForm *ui;
    //spnp::Project *project;
};

#endif // PROJECTFORM_H
