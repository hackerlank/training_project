#include "outputwidget.h"
#include "ui_outputwidget.h"

OutputWidget::OutputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutputWidget)
{
    ui->setupUi(this);
}

OutputWidget::~OutputWidget()
{
    delete ui;
}

void OutputWidget::setText(std::string txt)
{
    this->ui->lb_text->setText(QString::fromStdString(txt));
}

void OutputWidget::on_pushButton_clicked()
{

}
