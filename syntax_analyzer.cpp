#include "syntax_analyzer.h"
#include "ui_syntax_analyzer.h"
#include <QString>
#include <vector>
#include <mainwindow.h>
#include <qmessagebox.h>

Syntax_Analyzer::Syntax_Analyzer(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Syntax_Analyzer)
{
    ui->setupUi(this);
}

Syntax_Analyzer::~Syntax_Analyzer()
{
    delete ui;
}

void Syntax_Analyzer::on_btn_syntax_clicked()
{
    ui->txte_stack->setText(vc.at(0));
}


