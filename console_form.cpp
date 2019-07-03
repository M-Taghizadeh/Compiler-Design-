#include "console_form.h"
#include "ui_console_form.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

Console_Form::Console_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Console_Form)
{
    ui->setupUi(this);
    cout<<this->console_text.toStdString();
    ui->txte_console->setText(console_text);
}

Console_Form::~Console_Form()
{
    delete ui;
}
