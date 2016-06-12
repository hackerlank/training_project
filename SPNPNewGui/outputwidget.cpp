#include "outputwidget.h"
#include "ui_outputwidget.h"

OutputWidget::OutputWidget(std::string id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutputWidget)
{
    ui->setupUi(this);
    this->id = id;
}

OutputWidget::~OutputWidget()
{
    delete ui;
}

void OutputWidget::setText(std::string txt)
{
    this->ui->lb_text->setText(QString::fromStdString(txt));
}

std::string OutputWidget::getId()
{
    return this->id;
}

void OutputWidget::on_pushButton_clicked()
{
    emit removed(this->id);
}
