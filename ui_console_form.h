/********************************************************************************
** Form generated from reading UI file 'console_form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_FORM_H
#define UI_CONSOLE_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Console_Form
{
public:
    QTextEdit *txte_console;

    void setupUi(QWidget *Console_Form)
    {
        if (Console_Form->objectName().isEmpty())
            Console_Form->setObjectName(QString::fromUtf8("Console_Form"));
        Console_Form->setWindowModality(Qt::ApplicationModal);
        Console_Form->resize(650, 450);
        Console_Form->setMinimumSize(QSize(650, 450));
        Console_Form->setMaximumSize(QSize(650, 450));
        txte_console = new QTextEdit(Console_Form);
        txte_console->setObjectName(QString::fromUtf8("txte_console"));
        txte_console->setGeometry(QRect(0, -1, 651, 451));
        txte_console->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 170, 255);\n"
"font: 75 12pt \"Consolas\";"));

        retranslateUi(Console_Form);

        QMetaObject::connectSlotsByName(Console_Form);
    } // setupUi

    void retranslateUi(QWidget *Console_Form)
    {
        Console_Form->setWindowTitle(QApplication::translate("Console_Form", "Console", nullptr));
#ifndef QT_NO_TOOLTIP
        Console_Form->setToolTip(QApplication::translate("Console_Form", "Console", nullptr));
#endif // QT_NO_TOOLTIP
        txte_console->setPlaceholderText(QApplication::translate("Console_Form", "Compiler Design Console...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Console_Form: public Ui_Console_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_FORM_H
