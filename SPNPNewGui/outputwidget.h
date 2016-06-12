#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QWidget>

namespace Ui {
class OutputWidget;
}

class OutputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OutputWidget(std::string id, QWidget *parent = 0);
    ~OutputWidget();

    void setText(std::string txt);
    std::string getId();
signals:
    void removed(std::string id);

private slots:
    void on_pushButton_clicked();

private:
    Ui::OutputWidget *ui;
    std::string id;
};

#endif // OUTPUTWIDGET_H
