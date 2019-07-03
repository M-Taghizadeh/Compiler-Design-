#ifndef CONSOLE_FORM_H
#define CONSOLE_FORM_H

#include <QWidget>

namespace Ui {
class Console_Form;
}

class Console_Form: public QWidget
{
    Q_OBJECT

public:

    QString console_text;//show console output in console form
    explicit Console_Form(QWidget *parent = nullptr);
    ~Console_Form();

public:
    Ui::Console_Form *ui;
};

#endif // CONSOLE_FORM_H
