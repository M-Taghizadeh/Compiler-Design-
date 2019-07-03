/********************************************************************************
** Form generated from reading UI file 'syntax_analyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNTAX_ANALYZER_H
#define UI_SYNTAX_ANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Syntax_Analyzer
{
public:
    QPushButton *btn_exit;
    QLabel *label;
    QPushButton *btn_syntax;
    QLabel *label_3;
    QTextEdit *txte_string;
    QTextEdit *txte_stack;
    QTextEdit *txte_grammar;
    QTextEdit *txte;
    QLabel *label_2;

    void setupUi(QDialog *Syntax_Analyzer)
    {
        if (Syntax_Analyzer->objectName().isEmpty())
            Syntax_Analyzer->setObjectName(QString::fromUtf8("Syntax_Analyzer"));
        Syntax_Analyzer->resize(702, 693);
        btn_exit = new QPushButton(Syntax_Analyzer);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(550, 640, 131, 31));
        btn_exit->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        label = new QLabel(Syntax_Analyzer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 190, 47, 13));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        btn_syntax = new QPushButton(Syntax_Analyzer);
        btn_syntax->setObjectName(QString::fromUtf8("btn_syntax"));
        btn_syntax->setGeometry(QRect(100, 130, 141, 31));
        btn_syntax->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(Syntax_Analyzer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 10, 41, 31));
        label_3->setFont(font);
        txte_string = new QTextEdit(Syntax_Analyzer);
        txte_string->setObjectName(QString::fromUtf8("txte_string"));
        txte_string->setGeometry(QRect(340, 40, 341, 581));
        txte_string->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        txte_string->setReadOnly(true);
        txte_stack = new QTextEdit(Syntax_Analyzer);
        txte_stack->setObjectName(QString::fromUtf8("txte_stack"));
        txte_stack->setGeometry(QRect(30, 210, 61, 411));
        txte_stack->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 185);\n"
"font: 14pt \"Consolas\";\n"
""));
        txte_stack->setReadOnly(true);
        txte_grammar = new QTextEdit(Syntax_Analyzer);
        txte_grammar->setObjectName(QString::fromUtf8("txte_grammar"));
        txte_grammar->setGeometry(QRect(110, 210, 201, 411));
        txte_grammar->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        txte_grammar->setReadOnly(true);
        txte = new QTextEdit(Syntax_Analyzer);
        txte->setObjectName(QString::fromUtf8("txte"));
        txte->setGeometry(QRect(20, 40, 291, 81));
        txte->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";"));
        label_2 = new QLabel(Syntax_Analyzer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 185, 71, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Syntax_Analyzer);

        QMetaObject::connectSlotsByName(Syntax_Analyzer);
    } // setupUi

    void retranslateUi(QDialog *Syntax_Analyzer)
    {
        Syntax_Analyzer->setWindowTitle(QApplication::translate("Syntax_Analyzer", "Dialog", nullptr));
        btn_exit->setText(QApplication::translate("Syntax_Analyzer", "Exit", nullptr));
        label->setText(QApplication::translate("Syntax_Analyzer", "Stack", nullptr));
        btn_syntax->setText(QApplication::translate("Syntax_Analyzer", "Syntax Analyzer", nullptr));
        label_3->setText(QApplication::translate("Syntax_Analyzer", "String", nullptr));
        label_2->setText(QApplication::translate("Syntax_Analyzer", "Grammar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Syntax_Analyzer: public Ui_Syntax_Analyzer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNTAX_ANALYZER_H
