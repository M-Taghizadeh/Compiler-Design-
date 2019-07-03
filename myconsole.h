#ifndef MYCONSOLE_H
#define MYCONSOLE_H

#include <QDialog>

namespace Ui {
class MyConsole;
}

class MyConsole : public QDialog
{
    Q_OBJECT

public:
    explicit MyConsole(QWidget *parent = nullptr);
    ~MyConsole();

private:
    Ui::MyConsole *ui;
};

#endif // MYCONSOLE_H
