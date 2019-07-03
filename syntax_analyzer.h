#ifndef SYNTAX_ANALYZER_H
#define SYNTAX_ANALYZER_H

#include <QDialog>

namespace Ui {
class Syntax_Analyzer;
}

class Syntax_Analyzer : public QDialog
{
    Q_OBJECT

public:
    explicit Syntax_Analyzer(QWidget *parent = nullptr);
    ~Syntax_Analyzer();
    QVector<QString> vc;

private slots:
    void on_buttonBox_accepted();
    void analysis();
    void on_btn_exit_clicked();

    void on_btn_sntx_clicked();

    void on_btn_syntax_clicked();

private:
    Ui::Syntax_Analyzer *ui;
};

#endif // SYNTAX_ANALYZER_H
