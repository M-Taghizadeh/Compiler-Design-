#include "myconsole.h"
#include "ui_myconsole.h"

MyConsole::MyConsole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyConsole)
{
    ui->setupUi(this);
}

MyConsole::~MyConsole()
{
    delete ui;
}
