#include "ui_about.h"
#include "ui_ui_about.h"

Ui_about::Ui_about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ui_about)
{
    ui->setupUi(this);
}

Ui_about::~Ui_about()
{
    delete ui;
}
