#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QDialog>

namespace Ui {
class Ui_about;
}

class Ui_about : public QDialog
{
    Q_OBJECT

public:
    explicit Ui_about(QWidget *parent = 0);
    ~Ui_about();

private:
    Ui::Ui_about *ui;
};

#endif // UI_ABOUT_H
