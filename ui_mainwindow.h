/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_Programmer;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionNew;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionChange_Font;
    QAction *actiontheme_default;
    QAction *actiontheme_dark;
    QAction *actionUnderLine;
    QAction *actionItalic;
    QAction *actionBold;
    QAction *actiontheme_blue;
    QAction *actiontheme_red;
    QAction *actiontheme_green;
    QAction *actiontheme_yellow;
    QAction *actionSave_As;
    QWidget *centralWidget;
    QFrame *main_frame;
    QTextEdit *txte_human_language;
    QTextEdit *txte_cg;
    QLineEdit *lne_human_language;
    QLineEdit *lineEdit;
    QTabWidget *tab_compiler;
    QWidget *tab;
    QTextEdit *txte_lexical_error;
    QWidget *tab_2;
    QTextEdit *txte_syntx_error;
    QWidget *tab_8;
    QTextEdit *txte_compiler_output;
    QTableWidget *symbol_table;
    QFrame *btn_frame;
    QPushButton *btn_cg;
    QPushButton *btn_lexical;
    QPushButton *btn_sntx;
    QTabWidget *tabWidget_SymbolTable;
    QWidget *tab_3;
    QTextEdit *txte_keyword;
    QWidget *tab_4;
    QTextEdit *txte_id;
    QWidget *tab_5;
    QTextEdit *txte_pretty;
    QWidget *tab_6;
    QTextEdit *txte_operator;
    QWidget *tab_7;
    QTextEdit *txte_numerical;
    QLabel *label;
    QTextEdit *txte_string;
    QTextEdit *txte_stack;
    QLabel *label_3;
    QTextEdit *txte_grammar;
    QLabel *label_2;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuAbout;
    QMenu *menuFont;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1444, 720);
        MainWindow->setMinimumSize(QSize(1201, 720));
        MainWindow->setMaximumSize(QSize(16777215, 725));
        MainWindow->setDockNestingEnabled(false);
        actionAbout_Programmer = new QAction(MainWindow);
        actionAbout_Programmer->setObjectName(QString::fromUtf8("actionAbout_Programmer"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Programmer->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon3);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon4);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon7);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/redu.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionChange_Font = new QAction(MainWindow);
        actionChange_Font->setObjectName(QString::fromUtf8("actionChange_Font"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChange_Font->setIcon(icon10);
        actiontheme_default = new QAction(MainWindow);
        actiontheme_default->setObjectName(QString::fromUtf8("actiontheme_default"));
        actiontheme_default->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/theme_default.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_default->setIcon(icon11);
        actiontheme_dark = new QAction(MainWindow);
        actiontheme_dark->setObjectName(QString::fromUtf8("actiontheme_dark"));
        actiontheme_dark->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/theme_dark.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_dark->setIcon(icon12);
        actionUnderLine = new QAction(MainWindow);
        actionUnderLine->setObjectName(QString::fromUtf8("actionUnderLine"));
        actionUnderLine->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderLine->setIcon(icon13);
        actionItalic = new QAction(MainWindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon14);
        actionBold = new QAction(MainWindow);
        actionBold->setObjectName(QString::fromUtf8("actionBold"));
        actionBold->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBold->setIcon(icon15);
        actiontheme_blue = new QAction(MainWindow);
        actiontheme_blue->setObjectName(QString::fromUtf8("actiontheme_blue"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/theme_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_blue->setIcon(icon16);
        actiontheme_red = new QAction(MainWindow);
        actiontheme_red->setObjectName(QString::fromUtf8("actiontheme_red"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/theme_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_red->setIcon(icon17);
        actiontheme_green = new QAction(MainWindow);
        actiontheme_green->setObjectName(QString::fromUtf8("actiontheme_green"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/theme_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_green->setIcon(icon18);
        actiontheme_yellow = new QAction(MainWindow);
        actiontheme_yellow->setObjectName(QString::fromUtf8("actiontheme_yellow"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/theme_yellow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontheme_yellow->setIcon(icon19);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon20);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        main_frame = new QFrame(centralWidget);
        main_frame->setObjectName(QString::fromUtf8("main_frame"));
        main_frame->setEnabled(true);
        main_frame->setGeometry(QRect(0, 0, 1111111, 1111111));
        main_frame->setFrameShape(QFrame::StyledPanel);
        main_frame->setFrameShadow(QFrame::Raised);
        txte_human_language = new QTextEdit(main_frame);
        txte_human_language->setObjectName(QString::fromUtf8("txte_human_language"));
        txte_human_language->setGeometry(QRect(0, 40, 241, 371));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        txte_human_language->setFont(font);
        txte_human_language->setStyleSheet(QString::fromUtf8("font: 14pt \"Consolas\";"));
        txte_human_language->setFrameShape(QFrame::StyledPanel);
        txte_human_language->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_human_language->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_human_language->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        txte_cg = new QTextEdit(main_frame);
        txte_cg->setObjectName(QString::fromUtf8("txte_cg"));
        txte_cg->setGeometry(QRect(260, 40, 311, 441));
        QPalette palette;
        QBrush brush(QColor(0, 0, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        txte_cg->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        txte_cg->setFont(font1);
        txte_cg->setMouseTracking(false);
        txte_cg->setTabletTracking(false);
        txte_cg->setFocusPolicy(Qt::ClickFocus);
        txte_cg->setStyleSheet(QString::fromUtf8("font: 12pt \"Consolas\";\n"
"color: rgb(0, 0, 255);"));
        txte_cg->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_cg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_cg->setTabChangesFocus(false);
        lne_human_language = new QLineEdit(main_frame);
        lne_human_language->setObjectName(QString::fromUtf8("lne_human_language"));
        lne_human_language->setGeometry(QRect(0, 10, 241, 31));
        lne_human_language->setMaximumSize(QSize(381, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lne_human_language->setFont(font2);
        lne_human_language->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        lne_human_language->setAlignment(Qt::AlignCenter);
        lne_human_language->setReadOnly(true);
        lineEdit = new QLineEdit(main_frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 10, 311, 31));
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";\n"
""));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        tab_compiler = new QTabWidget(main_frame);
        tab_compiler->setObjectName(QString::fromUtf8("tab_compiler"));
        tab_compiler->setGeometry(QRect(50, 490, 1291, 161));
        tab_compiler->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        txte_lexical_error = new QTextEdit(tab);
        txte_lexical_error->setObjectName(QString::fromUtf8("txte_lexical_error"));
        txte_lexical_error->setGeometry(QRect(10, 10, 1261, 111));
        txte_lexical_error->setStyleSheet(QString::fromUtf8("font: 10pt \"Consolas\";\n"
"color: rgb(255, 0, 4);\n"
""));
        txte_lexical_error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_lexical_error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_lexical_error->setReadOnly(true);
        tab_compiler->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        txte_syntx_error = new QTextEdit(tab_2);
        txte_syntx_error->setObjectName(QString::fromUtf8("txte_syntx_error"));
        txte_syntx_error->setGeometry(QRect(10, 10, 1261, 111));
        txte_syntx_error->setStyleSheet(QString::fromUtf8("font: 10pt \"Consolas\";\n"
"color: rgb(255, 0, 4);\n"
""));
        txte_syntx_error->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_syntx_error->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_syntx_error->setReadOnly(true);
        tab_compiler->addTab(tab_2, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        txte_compiler_output = new QTextEdit(tab_8);
        txte_compiler_output->setObjectName(QString::fromUtf8("txte_compiler_output"));
        txte_compiler_output->setGeometry(QRect(10, 10, 1261, 111));
        txte_compiler_output->setStyleSheet(QString::fromUtf8("font: 10pt \"Consolas\";\n"
"color: rgb(0, 0, 255);\n"
"\n"
""));
        txte_compiler_output->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_compiler_output->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tab_compiler->addTab(tab_8, QString());
        symbol_table = new QTableWidget(main_frame);
        symbol_table->setObjectName(QString::fromUtf8("symbol_table"));
        symbol_table->setGeometry(QRect(590, 10, 241, 341));
        symbol_table->setStyleSheet(QString::fromUtf8("font: 8pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 127);"));
        btn_frame = new QFrame(main_frame);
        btn_frame->setObjectName(QString::fromUtf8("btn_frame"));
        btn_frame->setGeometry(QRect(0, 490, 51, 171));
        btn_frame->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 216, 216);"));
        btn_frame->setFrameShape(QFrame::StyledPanel);
        btn_frame->setFrameShadow(QFrame::Raised);
        btn_cg = new QPushButton(btn_frame);
        btn_cg->setObjectName(QString::fromUtf8("btn_cg"));
        btn_cg->setGeometry(QRect(10, 10, 31, 31));
        QFont font3;
        font3.setPointSize(11);
        btn_cg->setFont(font3);
        btn_cg->setAcceptDrops(false);
        btn_cg->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"color:\"red\";\n"
" border-color: red;"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/cg.png"), QSize(), QIcon::Selected, QIcon::On);
        btn_cg->setIcon(icon21);
        btn_cg->setIconSize(QSize(30, 35));
        btn_cg->setAutoDefault(false);
        btn_cg->setFlat(false);
        btn_lexical = new QPushButton(btn_frame);
        btn_lexical->setObjectName(QString::fromUtf8("btn_lexical"));
        btn_lexical->setGeometry(QRect(10, 60, 31, 31));
        btn_lexical->setFont(font3);
        btn_lexical->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color:\"red\";"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/lexical.png"), QSize(), QIcon::Selected, QIcon::On);
        btn_lexical->setIcon(icon22);
        btn_lexical->setIconSize(QSize(35, 35));
        btn_sntx = new QPushButton(btn_frame);
        btn_sntx->setObjectName(QString::fromUtf8("btn_sntx"));
        btn_sntx->setGeometry(QRect(10, 100, 31, 41));
        btn_sntx->setStyleSheet(QString::fromUtf8("color: rgb(102, 184, 255);\n"
"background-color: rgb(66, 142, 255);"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/syntx_analyzer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_sntx->setIcon(icon23);
        btn_sntx->setIconSize(QSize(50, 30));
        btn_sntx->setAutoRepeat(false);
        btn_sntx->setAutoDefault(false);
        btn_sntx->setFlat(true);
        tabWidget_SymbolTable = new QTabWidget(main_frame);
        tabWidget_SymbolTable->setObjectName(QString::fromUtf8("tabWidget_SymbolTable"));
        tabWidget_SymbolTable->setGeometry(QRect(580, 360, 331, 121));
        tabWidget_SymbolTable->setStyleSheet(QString::fromUtf8("font:7pt \"MS Shell Dlg 2\";"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        txte_keyword = new QTextEdit(tab_3);
        txte_keyword->setObjectName(QString::fromUtf8("txte_keyword"));
        txte_keyword->setGeometry(QRect(10, 10, 311, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Consolas"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        txte_keyword->setFont(font4);
        txte_keyword->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Consolas\";\n"
"color: rgb(255, 85, 0);"));
        tabWidget_SymbolTable->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        txte_id = new QTextEdit(tab_4);
        txte_id->setObjectName(QString::fromUtf8("txte_id"));
        txte_id->setGeometry(QRect(10, 10, 311, 71));
        txte_id->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Consolas\";\n"
"color: rgb(255, 85, 0);"));
        tabWidget_SymbolTable->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        txte_pretty = new QTextEdit(tab_5);
        txte_pretty->setObjectName(QString::fromUtf8("txte_pretty"));
        txte_pretty->setGeometry(QRect(10, 10, 311, 71));
        txte_pretty->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Consolas\";\n"
"color: rgb(255, 85, 0);"));
        tabWidget_SymbolTable->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        txte_operator = new QTextEdit(tab_6);
        txte_operator->setObjectName(QString::fromUtf8("txte_operator"));
        txte_operator->setGeometry(QRect(10, 10, 311, 71));
        txte_operator->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Consolas\";\n"
"color: rgb(255, 85, 0);"));
        tabWidget_SymbolTable->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        txte_numerical = new QTextEdit(tab_7);
        txte_numerical->setObjectName(QString::fromUtf8("txte_numerical"));
        txte_numerical->setGeometry(QRect(10, 10, 311, 71));
        txte_numerical->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Consolas\";\n"
"color: rgb(255, 85, 0);"));
        tabWidget_SymbolTable->addTab(tab_7, QString());
        label = new QLabel(main_frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(870, 10, 47, 13));
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8(""));
        txte_string = new QTextEdit(main_frame);
        txte_string->setObjectName(QString::fromUtf8("txte_string"));
        txte_string->setGeometry(QRect(1120, 30, 211, 451));
        txte_string->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Consolas\";"));
        txte_string->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_string->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txte_string->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        txte_string->setReadOnly(true);
        txte_string->setAcceptRichText(true);
        txte_stack = new QTextEdit(main_frame);
        txte_stack->setObjectName(QString::fromUtf8("txte_stack"));
        txte_stack->setGeometry(QRect(860, 30, 61, 311));
        txte_stack->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 247, 185);\n"
"font: 14pt \"Consolas\";\n"
""));
        txte_stack->setReadOnly(true);
        label_3 = new QLabel(main_frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1410, -55, 41, 31));
        label_3->setFont(font3);
        txte_grammar = new QTextEdit(main_frame);
        txte_grammar->setObjectName(QString::fromUtf8("txte_grammar"));
        txte_grammar->setGeometry(QRect(940, 30, 151, 451));
        txte_grammar->setStyleSheet(QString::fromUtf8("font: 11pt \"MS Shell Dlg 2\";"));
        txte_grammar->setReadOnly(true);
        label_2 = new QLabel(main_frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(990, 10, 71, 16));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(main_frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1180, 10, 91, 16));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8(""));
        txte_string->raise();
        tab_compiler->raise();
        txte_cg->raise();
        lne_human_language->raise();
        lineEdit->raise();
        txte_human_language->raise();
        symbol_table->raise();
        btn_frame->raise();
        tabWidget_SymbolTable->raise();
        label->raise();
        txte_stack->raise();
        label_3->raise();
        txte_grammar->raise();
        label_2->raise();
        label_4->raise();
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1444, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuFont = new QMenu(menuBar);
        menuFont->setObjectName(QString::fromUtf8("menuFont"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuFont->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCut);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addSeparator();
        menuEdit->addAction(actionPaste);
        menuView->addAction(actiontheme_default);
        menuView->addSeparator();
        menuView->addAction(actiontheme_dark);
        menuView->addSeparator();
        menuView->addAction(actiontheme_blue);
        menuView->addSeparator();
        menuView->addAction(actiontheme_red);
        menuView->addSeparator();
        menuView->addAction(actiontheme_green);
        menuView->addSeparator();
        menuView->addAction(actiontheme_yellow);
        menuAbout->addAction(actionAbout_Programmer);
        menuFont->addAction(actionChange_Font);
        menuFont->addSeparator();
        menuFont->addSeparator();
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRedo);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionChange_Font);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUnderLine);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionItalic);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBold);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCopy);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_default);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_dark);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_blue);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_red);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_green);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actiontheme_yellow);
        mainToolBar->addSeparator();
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);
        mainToolBar->addAction(actionAbout_Programmer);

        retranslateUi(MainWindow);

        tab_compiler->setCurrentIndex(0);
        btn_cg->setDefault(true);
        btn_lexical->setDefault(true);
        btn_sntx->setDefault(false);
        tabWidget_SymbolTable->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Compiler Design Project", nullptr));
        actionAbout_Programmer->setText(QApplication::translate("MainWindow", "About Programmer", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Save</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        actionChange_Font->setText(QApplication::translate("MainWindow", "Change Font", nullptr));
#ifndef QT_NO_SHORTCUT
        actionChange_Font->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actiontheme_default->setText(QApplication::translate("MainWindow", "theme_default", nullptr));
        actiontheme_dark->setText(QApplication::translate("MainWindow", "theme_dark", nullptr));
        actionUnderLine->setText(QApplication::translate("MainWindow", "UnderLine", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUnderLine->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionItalic->setText(QApplication::translate("MainWindow", "Italic", nullptr));
#ifndef QT_NO_SHORTCUT
        actionItalic->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionBold->setText(QApplication::translate("MainWindow", "Bold", nullptr));
#ifndef QT_NO_SHORTCUT
        actionBold->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_NO_SHORTCUT
        actiontheme_blue->setText(QApplication::translate("MainWindow", "theme_blue", nullptr));
        actiontheme_red->setText(QApplication::translate("MainWindow", "theme_red", nullptr));
        actiontheme_green->setText(QApplication::translate("MainWindow", "theme_green", nullptr));
        actiontheme_yellow->setText(QApplication::translate("MainWindow", "theme_yellow", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As..", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+S", nullptr));
#endif // QT_NO_SHORTCUT
        txte_human_language->setPlaceholderText(QApplication::translate("MainWindow", "Enter your commands..", nullptr));
        txte_cg->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        txte_cg->setPlaceholderText(QApplication::translate("MainWindow", "Delphi Source Code Generation..", nullptr));
        lne_human_language->setText(QApplication::translate("MainWindow", "Human Language", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "Code Generator", nullptr));
        txte_lexical_error->setPlaceholderText(QApplication::translate("MainWindow", "Compiler Output...", nullptr));
        tab_compiler->setTabText(tab_compiler->indexOf(tab), QApplication::translate("MainWindow", "Lexical Analyzer", nullptr));
        txte_syntx_error->setPlaceholderText(QApplication::translate("MainWindow", "Compiler Output...", nullptr));
        tab_compiler->setTabText(tab_compiler->indexOf(tab_2), QApplication::translate("MainWindow", "Syntax Analyzer", nullptr));
        txte_compiler_output->setPlaceholderText(QApplication::translate("MainWindow", "Compiler Output...", nullptr));
        tab_compiler->setTabText(tab_compiler->indexOf(tab_8), QApplication::translate("MainWindow", "Compiler Output", nullptr));
#ifndef QT_NO_TOOLTIP
        btn_cg->setToolTip(QApplication::translate("MainWindow", "Code Generator", nullptr));
#endif // QT_NO_TOOLTIP
        btn_cg->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_lexical->setToolTip(QApplication::translate("MainWindow", "Lexical Analyzer", nullptr));
#endif // QT_NO_TOOLTIP
        btn_lexical->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_sntx->setToolTip(QApplication::translate("MainWindow", "Syntax Analyzer", "Syntax Analyzer"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_ACCESSIBILITY
        btn_sntx->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        btn_sntx->setText(QString());
        tabWidget_SymbolTable->setTabText(tabWidget_SymbolTable->indexOf(tab_3), QApplication::translate("MainWindow", "KeyWord", nullptr));
        tabWidget_SymbolTable->setTabText(tabWidget_SymbolTable->indexOf(tab_4), QApplication::translate("MainWindow", "Identifier", nullptr));
        tabWidget_SymbolTable->setTabText(tabWidget_SymbolTable->indexOf(tab_5), QApplication::translate("MainWindow", "Pretty", nullptr));
        tabWidget_SymbolTable->setTabText(tabWidget_SymbolTable->indexOf(tab_6), QApplication::translate("MainWindow", "Operator", nullptr));
        tabWidget_SymbolTable->setTabText(tabWidget_SymbolTable->indexOf(tab_7), QApplication::translate("MainWindow", "Numerical Value", nullptr));
        label->setText(QApplication::translate("MainWindow", "Stack", nullptr));
        txte_string->setPlaceholderText(QString());
        label_3->setText(QApplication::translate("MainWindow", "String", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Grammar", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Input String", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
        menuFont->setTitle(QApplication::translate("MainWindow", "Font", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
