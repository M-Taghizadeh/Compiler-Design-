#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "console_form.h"
#include <QFile>
#include <QFontDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <qt_windows.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <iostream>
#include <QVector>
#include <QString>
#include <string.h>
#include <string>
#include <ctype.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>
#include <QDebug>
#include <iomanip>
#include <qstring.h>
#include <regex>
#include <QString>
#include <QStandardItemModel>
#include <syntax_analyzer.h>
#include <ui_console.h>
#include <QScrollBar>
using namespace std;

int top = 0 ;// top of stack
//initializing parser table according to grammar;
static string pars_table[6][9] = {
                                    {"#", "id", "+"  , "-"  , "*"  , "/"  , "("  , ")"  , "$"},
                                    {"E", "TR", "#"  , "#"  , "#"  , "#"  , "TR" , "#"  , "#"},
                                    {"R", "#" , "+TR", "-TR", "#"  , "#"  , "#"  , "ε"  , "ε"},
                                    {"T", "FW", "#"  , "#"  , "#"  , "#"  , "FW" , "#"  , "#"},
                                    {"W", "#" , "ε"  , "ε"  , "*FW", "/FW", "#"  , "ε"  , "ε"},
                                    {"F", "id", "#"  , "#"  , "#"  , "#"  , "(E)", "#"  , "#"}
                                 };//# is not define eny grammer

static QVector<QString> vcmath_statement;// for check by syntax analyzer;
static QString core_program;//core of program

int priority(QString expr_Operator, QString stack_Operator);//for convert infix to postfix
QVector<QString> infix_to_postfix(QString str);
QString check_negative_value(QString str);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::save);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveAs);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::exit);
    connect(ui->actionChange_Font, &QAction::triggered, this, &MainWindow::selectFont);
    connect(ui->actionUnderLine, &QAction::triggered, this, &MainWindow::setFontUnderline);
    connect(ui->actionItalic, &QAction::triggered, this, &MainWindow::setFontItalic);
    connect(ui->actionBold, &QAction::triggered, this, &MainWindow::setFontBold);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::cut);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::redo);
    connect(ui->actionAbout_Programmer, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actiontheme_default, &QAction::triggered, this, &MainWindow::default_theme);
    connect(ui->actiontheme_dark, &QAction::triggered, this, &MainWindow::dark_theme);
    connect(ui->actiontheme_red, &QAction::triggered, this, &MainWindow::theme_red);
    connect(ui->actiontheme_blue, &QAction::triggered, this, &MainWindow::theme_blue);
    connect(ui->actiontheme_green, &QAction::triggered, this, &MainWindow::theme_green);
    connect(ui->actiontheme_yellow, &QAction::triggered, this, &MainWindow::theme_yellow);

    //show sybmol table init:
    ui->symbol_table->setRowCount(10);
    ui->symbol_table->setColumnCount(2);
    QStringList header;
    header.push_back("Name");
    header.push_back("Type");
    ui->symbol_table->setHorizontalHeaderLabels(header);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDocument()
{
    currentFile.clear();
    ui->txte_cg->setText(QString());
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->txte_cg->setText(text);
    file.close();
}

void MainWindow::save()
{
    QString fileName;
    // If we don't have a filename from before, get one.
    if (currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "Save");
        currentFile = fileName;
    } else {
        fileName = currentFile;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->txte_cg->toPlainText();
    out << text;
    file.close();
}

void MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->txte_cg->toPlainText();
    out << text;
    file.close();
}

void MainWindow::exit()
{
    QCoreApplication::quit();
}

void MainWindow::copy()
{
#if QT_CONFIG(clipboard)
    ui->txte_cg->copy();
#endif
}

void MainWindow::cut()
{
#if QT_CONFIG(clipboard)
    ui->txte_cg->cut();
#endif
}

void MainWindow::paste()
{
#if QT_CONFIG(clipboard)
    ui->txte_cg->paste();
#endif
}

void MainWindow::undo()
{
     ui->txte_cg->undo();
}

void MainWindow::redo()
{
    ui->txte_cg->redo();
}

void MainWindow::selectFont()
{
    bool fontSelected;
    QFont font = QFontDialog::getFont(&fontSelected, this);
    if (fontSelected){
        ui->txte_cg->setFont(font);
        ui->txte_human_language->setFont(font);
    }
}

void MainWindow::setFontUnderline(bool underline)
{
    ui->txte_cg->setFontUnderline(underline);
}

void MainWindow::setFontItalic(bool italic)
{
    ui->txte_cg->setFontItalic(italic);
}

void MainWindow::setFontBold(bool bold)
{
    bold ? ui->txte_cg->setFontWeight(QFont::Bold) : ui->txte_cg->setFontWeight(QFont::Normal);
}

void MainWindow::about()
{
   QMessageBox msgbox;
   msgbox.setText("This Software Developed by Mohammad.Taghizadeh");
   msgbox.setIconPixmap(QPixmap("C:/Users/Zanis/Desktop/CompilerDesign/image/programmer.jpg"));
   msgbox.exec();
}

void MainWindow::dark_theme(){
    //header:
    ui->menuBar->setStyleSheet("background:rgb(127,127,127); color:white");
    ui->mainToolBar->setStyleSheet("background:rgb(190,190,190); color:red");

    //body:
    qApp->setStyleSheet("QMainWindow{background:rgb(55, 55, 55);}");

    //textedits:
    ui->txte_cg->setStyleSheet("background-color:rgb(45, 45, 45);color:rgb(0, 255, 0); font:10pt");
    ui->txte_human_language->setStyleSheet("background-color:rgb(45, 45, 45); color:rgb(0, 255, 0); font:12pt");
    ui->txte_lexical_error->setStyleSheet("background-color:rgb(45, 45, 45); color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color:rgb(127, 127, 127)");
    //btns:
    //ui->btn_cg->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_lexical->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_syntax->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_semantic->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
}

void MainWindow::default_theme(){

    //header:
    ui->menuBar->setStyleSheet("");
    ui->mainToolBar->setStyleSheet("");

    //body:
    qApp->setStyleSheet("");
    ui->txte_cg->setStyleSheet("font:10pt");
    ui->txte_human_language->setStyleSheet("font:12pt");
    ui->txte_lexical_error->setStyleSheet("color:rgb(255, 0, 0); color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color: rgb(216, 216, 216);");
}

void MainWindow::theme_red(){

    //header:
    ui->menuBar->setStyleSheet("background:rgb(152,12,19); color:white");
    ui->mainToolBar->setStyleSheet("background:rgb(255,55,61); color:red");

    //body:
    qApp->setStyleSheet("QMainWindow{background:rgb(152, 12, 19);}");

    //textedits:
    ui->txte_cg->setStyleSheet("background-color:rgb(242, 233, 189); font:10pt");
    ui->txte_human_language->setStyleSheet("background-color:rgb(242, 233, 189); font:12pt");
    ui->txte_lexical_error->setStyleSheet("background-color:rgb(242, 233, 189); color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color: rgb(216, 216, 216);");
}

void MainWindow::theme_blue(){

    //header:
    ui->menuBar->setStyleSheet("background:rgb(0,0,187); color:white");
    ui->mainToolBar->setStyleSheet("background:rgb(121,222,227); color:red");

    //body:
    qApp->setStyleSheet("QMainWindow{background:rgb(0, 0, 187);}");

    //textedits:
    ui->txte_cg->setStyleSheet("background-color:rgb(242, 233, 189); font:10pt");
    ui->txte_human_language->setStyleSheet("background-color:rgb(242, 233, 189); font:12pt");
    ui->txte_lexical_error->setStyleSheet("background-color:rgb(242, 233, 189); color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color: rgb(216, 216, 216);");
}

void MainWindow::theme_green(){

    //header:
    ui->menuBar->setStyleSheet("background:rgb(0,106,0); color:white");
    ui->mainToolBar->setStyleSheet("background:rgb(207,239,109); color:red");

    //body:
    qApp->setStyleSheet("QMainWindow{background:rgb(0,106,0);}");

    //textedits:
    ui->txte_cg->setStyleSheet("background-color:rgb(242, 233, 189); font:10pt");
    ui->txte_human_language->setStyleSheet("background-color:rgb(242, 233, 189); font:12pt");
    ui->txte_lexical_error->setStyleSheet("background-color:rgb(242, 233, 189);  color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color: rgb(216, 216, 216);");
}

void MainWindow::theme_yellow(){

    //header:
    ui->menuBar->setStyleSheet("background:rgb(255, 242, 0); color:red");
    ui->mainToolBar->setStyleSheet("background:rgb(239,228,176); color:red");

    //body:
    qApp->setStyleSheet("QMainWindow{background:rgb(255, 242, 0);}");

    //textedits:
    ui->txte_cg->setStyleSheet("background-color:rgb(242, 233, 189); font:10pt");
    ui->txte_human_language->setStyleSheet("background-color:rgb(242, 233, 189); font:12pt");
    ui->txte_lexical_error->setStyleSheet("background-color:rgb(242, 233, 189); color:rgb(255, 0, 0); font:12pt");

    //frame:
    ui->btn_frame->setStyleSheet("background-color: rgb(216, 216, 216);");
    //btns:
    //ui->btn_cg->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_lexical->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_syntax->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
    //ui->btn_semantic->setStyleSheet("background-color:rgb(63, 72, 204); color:White;");
}

void MainWindow::on_btn_cg_clicked()
{
    std::vector <QString> var;
    QString str = ui->txte_human_language->toPlainText();
    str = str.toLower();
    str = str+"#";
    str = str.replace(" ", "");
    str = str.replace("\n", ";");
    str = str.replace("#", ";#");
    cout<<str.toStdString();

    for(char ch = 'a'; ch!='{'; ch++){
        cout<<ch<<"-------------------------------------------------\n";
        QString sch;
        sch = ch;
        if(str.contains(ch)){
            var.push_back(sch);
        }
    }

    QString cg;
    cg = cg + "Program CodeGenerator;\n" +
              "Uses\n" +
              "  "+"System.SysUtils;\n";
    cg = cg + "Var\n";

    QString str_Var_Block;
    int i = 0;
    while(str.at(i)!="#"){
        QString str_not_define_by_value = "";
        QString str_Define_var;
        if(str.at(i)=="a"||str.at(i)=="b"||str.at(i)=="c"||str.at(i)=="d"){
            str_Define_var += str.at(i);
            str_Define_var += ":";
            i=i+1;

            if(str.at(i)=="="){
                i = i+1;
                int flag_real = 0;
                while(str.at(i)!=";"){
                    QString tmp = str.at(i);
                    if(str_Var_Block.contains(tmp+":real;")){
                        flag_real = 1;
                    }
                    if(tmp=="."){
                        flag_real=1;
                    }
                    if(tmp=="a"||tmp=="b"||tmp=="c"||tmp=="d"){
                        if(!str_Var_Block.contains(tmp+":integer;")&&!str_Var_Block.contains(tmp+":real;")){
                            if(tmp!=str.at(i-2)){
                                str_Var_Block += tmp+":integer;\n";
                            }
                        }
                    }

                    i=i+1;
                }
                if(flag_real==1){
                    str_Define_var+="real;";
                }
                else{
                    str_Define_var+="integer;";
                }

                //important:
                //No operation for repetitive value
                if(str_Var_Block.contains(str_Define_var)){
                    //NOP
                }

                else if(str_Define_var.contains("real")){
                    QString rmv_int_for_define_real = str_Define_var.at(0);
                    rmv_int_for_define_real += ":integer;\n";
                    str_Var_Block.remove(rmv_int_for_define_real);

                    str_Var_Block += str_Define_var+"\n";
                }
                else if(str_Define_var.contains("integer")){
                    QString define_real_in_yore = str_Define_var.at(0);
                    define_real_in_yore += ":real";
                    if(!str_Var_Block.contains(define_real_in_yore)){
                        str_Var_Block += str_Define_var+"\n";
                    }
                }
            }

            else {
                if(str_Var_Block.contains(str_Define_var+"integer;")||str_Var_Block.contains(str_Define_var+"real;")){
                    str_Define_var="";
                }
                else{
                    str_Define_var += "integer;";
                    str_Var_Block += str_Define_var+"\n";
                }
            }
        }

        i = i+1;
    }
    cg = cg + str_Var_Block+"\n";

    //program block:
    cg = cg + "begin\n";
    str = str.replace(";", ";\n");
    str = str.replace("=", ":=");
    str = str.replace("#", "");
    cg = cg + str;

    //output block:
    for(int i = 0; i<var.size(); i++){
        cg = cg + "Writeln"+"("+ var.at(i)+");\n";
    }
    cg = cg + "Readln;\nend. ";
    cg = cg.toLower();
    ui->txte_cg->setText(cg);
}

//keywords function:
int isKeyword(char buffer[]){
    char keywords[32][15] =
    {"char","const","double","float","integer","long","short", "system", "sysutils",
                            "var", "begin", "end", "uses", "program", "real", "readln" ,"writeln", ""};

    int i, flag = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

//identifier Function:
int MainWindow::isIdentifier(string str){
    int flag = 0;
    int isnumeric = 1;
    for(int i = 0; i<str.size(); i++){
        if(isalpha(str.at(i))){
            isnumeric = 0;
        }
    }
    if(isnumeric==1){
        return flag;//return 0;
    }
    str = str+'\0';
    char ch;
    int state = 1;
    int i = 0;
    int flag_end_of_loop = 0;
    while(flag_end_of_loop==0){

        //for two underline
        if(i<str.size()-1){
            if(str.at(i)=='_' && str.at(i+1)=='_'){
                //cout<<"error!!!"<<endl;
                QString error;
                error = ui->txte_lexical_error->toPlainText() + QString::fromStdString(str+" : Definition Not Correct") +"\n";
                ui->txte_lexical_error->setText(error);
                flag = 0;
                break;
            }
        }
        switch(state){
            case 1:{
                ch = str.at(i);

                if( ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e'||ch=='f'||ch=='g'||ch=='h'||ch=='i'||
                    ch=='j'||ch=='k'||ch=='l'||ch=='m'||ch=='n'||ch=='o'||ch=='p'||ch=='q'||ch=='r'||
                    ch=='s'||ch=='t'||ch=='u'||ch=='v'||ch=='w'||ch=='x'||ch=='y'||ch=='z'||ch=='A'||
                    ch=='B'||ch=='C'||ch=='D'||ch=='E'||ch=='F'||ch=='G'||ch=='H'||ch=='I'||ch=='J'||
                    ch=='K'||ch=='L'||ch=='M'||ch=='N'||ch=='O'||ch=='P'||ch=='Q'||ch=='R'||ch=='S'||
                    ch=='T'||ch=='U'||ch=='V'||ch=='W'||ch=='X'||ch=='Y'||ch=='Z'||ch=='_'
                   ){
                    state = 2;
                    i++;
                    break;
                }
                else{
                    flag_end_of_loop = 1;
                    //cout<<"error!!!"<<endl;
                    QString error;
                    error = ui->txte_lexical_error->toPlainText() + QString::fromStdString(str + " : Definition Not Correct") +"\n";
                    ui->txte_lexical_error->setText(error);
                    flag = 0;
                    break;
                }
            }
            case 2:{
                ch = str.at(i);
                if( ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e'||ch=='f'||ch=='g'||ch=='h'||ch=='i'||
                    ch=='j'||ch=='k'||ch=='l'||ch=='m'||ch=='n'||ch=='o'||ch=='p'||ch=='q'||ch=='r'||
                    ch=='s'||ch=='t'||ch=='u'||ch=='v'||ch=='w'||ch=='x'||ch=='y'||ch=='z'||ch=='A'||
                    ch=='B'||ch=='C'||ch=='D'||ch=='E'||ch=='F'||ch=='G'||ch=='H'||ch=='I'||ch=='J'||
                    ch=='K'||ch=='L'||ch=='M'||ch=='N'||ch=='O'||ch=='P'||ch=='Q'||ch=='R'||ch=='S'||
                    ch=='T'||ch=='U'||ch=='V'||ch=='W'||ch=='X'||ch=='Y'||ch=='Z'||ch=='0'||ch=='1'||
                    ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'||ch=='_'
                   ){
                    state = 2;
                    i++;
                    break;
                }
                else if(ch=='\0'){
                    flag_end_of_loop = 1;
                    //cout<<"Accept."<<endl;
                    flag = 1;
                    break;
                }
                else{
                    flag_end_of_loop = 1;
                    //cout<<"error!!!"<<endl;
                    QString error;
                    error = ui->txte_lexical_error->toPlainText() + QString::fromStdString(str+" : Definition Not Correct") +"\n";
                    ui->txte_lexical_error->setText(error);
                    flag = 0;
                    break;
                }
            }
        }
    }
    return  flag;
}

void MainWindow::check_id_definition_before_assign(QString str){

    str.replace(";\n", ";");
    str.replace("\n", "");

    //for var block:
    if(str.contains("var")){
        int i = 0;
        QString var_flag = str.at(i);
        if(i+2<str.size()){
            var_flag += str.at(i+1);
            var_flag += str.at(i+2);
        }
        while(var_flag!="var" && i+2<str.size()){
            if(i+2<str.size()){
                var_flag = str.at(i);
                var_flag += str.at(i+1);
                var_flag += str.at(i+2);
            }
            i++;
        }
        int size = str.size();
        string tmp = str.toStdString();
        tmp = tmp.substr(i+2, size);
        cout<<tmp;
        str = QString::fromStdString(tmp);
    }

    //error for this exmp : +a = b+c
    int c = 0;
    while(c<str.size()-2){
        QString define_id;
        define_id = str.at(c);
        c++;
        while(str.at(c) != ":"){
            define_id += str.at(c);
            c++;
        }
        while(str.at(c)!=";"){
            c++;
        }
        c++;

        //just check define id with this condiotion: (because +-/*, ... is tokenizer)
        if(define_id.contains(" ")||define_id.contains("+")||define_id.contains("-")||define_id.contains("*")||define_id.contains("/")||define_id.contains("(")||define_id.contains(")")||define_id.contains(".")){
            isIdentifier(define_id.toStdString());
        }
    }
}

void MainWindow::on_btn_lexical_clicked()
{
    //clean lexical error:
    ui->txte_lexical_error->setText("");
    vector<string> SYMBOL_TABLE_name;
    vector<string> SYMBOL_TABLE_type;
    //clean vcMathStatements:
    vcmath_statement.clear();

    char ch, buffer[20],b[30];

    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->txte_cg->setText(text.toLower());
    file.close();

    //convert qstring to string:
    string str_path = fileName.toStdString();
    fstream fin(str_path);
    fstream fin1(str_path);
    //read a fileno
    /*string line;
    while ( getline (fin,line) )
        {
          cout << line;
        }
    */

    int mark[1000]={0};
    int j=0,kc=0,ic=0,mc=0,nc=0,oc=0,aaa=0;
    vector<string>k;
    vector<string>id;
    vector<char>mop;
    vector<string>nu;
    vector<char>ot;
    string math_statement="";int math_statement_count = 0;int flag_there_is_statement = 0;

    //GET DELPHI CODE:
    QString delphi_source_code = "";
    while(!fin1.eof()){
        delphi_source_code.push_back(fin1.get());
    }
    //[FIND VAR BLOCK]
    QString var_block = "";
    delphi_source_code.replace("begin", ">");
    int step = 0;
    while(true){
        if(delphi_source_code.at(step)=='>'){
            break;
        }
        var_block.push_back(delphi_source_code.at(step));
        step++;
        if(step==delphi_source_code.size()-1){
            QMessageBox msg;
            msg.setText("Expected Begin Of Program");
            msg.exec();
            break;
        }
    }delphi_source_code.replace(">", "begin");
    cout<<"\nVAR BLOCK\n----------------------------\n";
    cout<<var_block.toStdString();
    cout<<"\n----------------------------\n";

    //[FIND CORE OF PROGRAM : ]
    core_program = "";
    delphi_source_code.replace("begin", "<");
    delphi_source_code.replace("writeln", ">");
    delphi_source_code.replace("end", "!");
    cout<<delphi_source_code.toStdString();
    step = 0;
    int flag_begin_of_program = 0;
    for (step = 0; step<delphi_source_code.size(); step++) {
        if(flag_begin_of_program==0){
            if(delphi_source_code.at(step)=='<'){
                flag_begin_of_program = 1;
            }
        }
        else{
            if(delphi_source_code.at(step)=='>'||delphi_source_code.at(step)=='!'){
                break;
            }
            core_program.push_back(delphi_source_code.at(step));
        }
    }delphi_source_code.replace("<", "begin");delphi_source_code.replace(">", "writeln");delphi_source_code.replace("!", "end");
    //core_program.replace(" ", "");
    cout<<"\nCORE PROGRAM\n----------------------------\n";
    cout<<core_program.toStdString();
    cout<<"\n----------------------------\n";


    while(!fin.eof()){
        ch = tolower(fin.get());
        if(flag_there_is_statement==1){
            math_statement.push_back(ch);
        }

        string tmp_str_ch_name="";
        string tmp_str_ch_type="";

        if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || /*ch=='.'||*/ ch == ' ' || ch == '\n' || ch == ';'){
            if(ch=='0' || ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9' || ch=='.')
                b[aaa++]=ch;
            if((ch == ' ' || ch == '\n' || ch == ';') && (aaa != 0)){

                b[aaa] = '\0';
                aaa = 0;
                char arr[30];
                strcpy(arr,b);
                nu.push_back(arr);
                tmp_str_ch_name = arr;
                tmp_str_ch_type = "Numerical Value";
                ++nc;
            }
        }

        QString seperators = "+-*/:=;.() \n";
        if(!seperators.contains(ch)){
            buffer[j++] = ch;
        }

        else if(seperators.contains(ch) && (j != 0)){
            buffer[j] = '\0';
            j = 0; //mean that buffer is clean
            if(isKeyword(buffer) == 1){
                k.push_back(buffer);
                tmp_str_ch_name = buffer;
                tmp_str_ch_type = "KeyWord";
                ++kc;
            }
            else{

                if(isIdentifier(buffer) == 1){
                    QString check_define_integer = buffer;
                    QString check_define_real = buffer;
                    QString check_define_Program = "program ";
                    check_define_integer += ":integer;";
                    check_define_real +=":real;";
                    check_define_Program +=buffer;check_define_Program+=";";
                    int check_flag = 0;
                    if(!var_block.contains("\n"+check_define_integer)&&!var_block.contains(";"+check_define_integer)){
                        check_flag=check_flag+1;
                    }
                    if(!var_block.contains("\n"+check_define_real)&&!var_block.contains(";"+check_define_real)){
                        check_flag=check_flag+1;
                    }
                    if(!var_block.contains(check_define_Program)){
                        check_flag=check_flag+1;
                    }
                    if(check_flag==3){
                        QString error_message = ui->txte_lexical_error->toPlainText()+QString::fromStdString(buffer) + "  Is Not Define In Variable Block!!!\n";
                        ui->txte_lexical_error->setText(error_message);
                    }
                    else if(mark[buffer[0]-'a']!=1){
                        id.push_back(buffer);
                        tmp_str_ch_name = buffer;
                        tmp_str_ch_type = "Identifier";
                        ++ic;
                    }
                }
            }
        }
        cout<<"ch : "<<ch<<endl;
        cout<<"ch name : "<<tmp_str_ch_name<<endl;
        cout<<"ch type : "<<tmp_str_ch_type<<endl;

        if(tmp_str_ch_name!="" && tmp_str_ch_type!=""){
            SYMBOL_TABLE_name.push_back(tmp_str_ch_name);
            SYMBOL_TABLE_type.push_back(tmp_str_ch_type);
        }

        if(ch=='+' || ch=='-'||ch=='*'||ch=='/'||ch=='='||ch==':'){
            mop.push_back(ch);mc++;

            string str_ch;
            str_ch.push_back(ch);
            SYMBOL_TABLE_name.push_back(str_ch);
            SYMBOL_TABLE_type.push_back("Operator");
            if(str_ch=="="){
                math_statement_count = math_statement_count+1;
                flag_there_is_statement = 1;
            }
        }
        if(ch=='.'||ch==';'||ch=='('||ch==')'){
            ot.push_back(ch);
            oc++;

            string str_ch;
            str_ch.push_back(ch);
            SYMBOL_TABLE_name.push_back(str_ch);
            SYMBOL_TABLE_type.push_back("Pretty");

            if(str_ch==";"){
                flag_there_is_statement = 0;
                if(math_statement!=""){
                    QString tmp = QString::fromStdString(math_statement);//for delete ' ' and ';' from end of math statement
                    tmp.replace(" ", "");
                    tmp.replace(";", "");
                    vcmath_statement.push_back(tmp);
                    math_statement = "";
                }
            }
        }


    }//end of while (file)

    fin.close();

    cout<<"math statements : \n";
    for (int i = 0; i<vcmath_statement.size(); i++) {
        cout<<vcmath_statement.at(i).toStdString()<<endl;
    }


    //<<for var block block>>:  difiniotion of id is like this: +a:integer
    check_id_definition_before_assign(var_block);
    //<<for core of program block>>: difiniotion of id is like this: +a:=12
    check_id_definition_before_assign(core_program);


//convert vectors to Qvectors :
    QVector<string> qvec_k = QVector<string>::fromStdVector(k);
    QVector<string> qvec_id = QVector<string>::fromStdVector(id);
    QVector<char> qvec_lo = QVector<char>::fromStdVector(mop);
    QVector<string> qvec_nu = QVector<string>::fromStdVector(nu);
    QVector<char> qvec_ot = QVector<char>::fromStdVector(ot);

//keywords:
    string str_keywords;
    for(int f=0;f<kc;++f){
        str_keywords.append(qvec_k.at(f)+"\n");
    }
    ui->txte_keyword->setText(QString::fromStdString(str_keywords));

//id:
    string str_id;
    for(int f=0;f<ic;++f){
        str_id.append(qvec_id.at(f)+"\n");
    }
    ui->txte_id->setText(QString::fromStdString(str_id));

//Math Operators:
    string str_operator;
    for(int f=0;f<mc;++f){
        str_operator += qvec_lo.at(f);
        str_operator += "\n";
    }
    ui->txte_operator->setText(QString::fromStdString(str_operator));

//Numerical values:
    string str_numerical_value;
    for(int f=0;f<nc;++f){
        str_numerical_value.append(qvec_nu.at(f));
        str_numerical_value.append(", ");
    }
    ui->txte_numerical->setText(QString::fromStdString(str_numerical_value));

//Pretty:
    string str_pretty;
    for(int f=0;f<oc;++f){
        str_pretty += qvec_ot.at(f);
        str_pretty +="\n";
    }
    ui->txte_pretty->setText(QString::fromStdString(str_pretty));

//Show Symbol Table:
    ui->symbol_table->setRowCount(SYMBOL_TABLE_name.size()+1);
    ui->symbol_table->setColumnCount(2);
    QStringList header;
    header.push_back("Name");
    header.push_back("Type");
    ui->symbol_table->setHorizontalHeaderLabels(header);

    for(int i = 0; i<SYMBOL_TABLE_name.size(); i++){
        QString name = QString::fromStdString(SYMBOL_TABLE_name.at(i));
        QString type = QString::fromStdString(SYMBOL_TABLE_type.at(i));

        ui->symbol_table->setItem(i+1, 0, new QTableWidgetItem(name));
        ui->symbol_table->setItem(i+1, 1, new QTableWidgetItem(type));
    }

}

//[SYNTAX ANALYZER]:
int cal_col(string token){
    for (int i = 0; i<9; i++) {
        if(token == pars_table[0][i]){
            return i;
        }
    }
    return -1;
}

int cal_row(string state){
    for (int i = 0; i<6; i++) {
        if(state == pars_table[i][0]){
            return i;
        }
    }
    return -1;
}

string reverse(string grammar){
    string tmp;
    for (int i = grammar.size()-1; i>=0; i--) {
        tmp.push_back(grammar[i]);
    }
    return tmp;
}

void show_parstable(){
    for (int i = 0; i<6; i++){
        for (int j = 0; j<12; j++) {
            cout<<pars_table[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void MainWindow::on_btn_sntx_clicked(){

    ui->txte_syntx_error->setText("");

    int number_of_statement = 0;
    int flag_current_syntx = 0;
    for(int num_of_statements; num_of_statements<vcmath_statement.size(); num_of_statements++){

        number_of_statement++;
        //show_parstable();
        ui->txte_stack->setText("");
        ui->txte_string->setText("");
        ui->txte_grammar->setText("");
        string str;
        string token;
        string state;
        vector<string> stack;

        str = vcmath_statement.at(num_of_statements).toStdString();
        str = check_negative_value(QString::fromStdString(str)).toStdString();
        str = str + "$";

        stack.push_back("$");
        stack.push_back("E");
        while(true){
            //for gui:=
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            this->repaint();

            string string_process = ui->txte_string->toPlainText().toStdString();
            string string_stack = "";
            string_process = string_process + str+"\n";
            for (int i = 0; i<stack.size(); i++) {
                string_stack = string_stack + stack.at(i)+"\n";
            }
            ui->txte_stack->setText(QString::fromStdString(string_stack));
            ui->txte_string->setText(QString::fromStdString(string_process));
            top = stack.size()-1;


            int chAt = 0;
            if(str.at(chAt)=='+'||str.at(chAt)=='-'||str.at(chAt)=='*'||str.at(chAt)=='/'||str.at(chAt)=='('||str.at(chAt)==')'||str.at(chAt)=='$'){
                token = str.at(chAt);
                chAt++;
            }
            else{
                while(true){
                    if(str.at(chAt)=='+'||str.at(chAt)=='-'||str.at(chAt)=='*'||str.at(chAt)=='/'||str.at(chAt)=='('||str.at(chAt)==')'||str.at(chAt)=='$'){
                        break;
                    }
                    else{
                        token = "id";
                        chAt++;
                    }
                }
            }
            state = stack.at(top);//state : top of stack include : (token and state)
            cout<<"token:"<<token<<endl;
            cout<<"state:"<<state<<endl;

            //end of while:
            if(token=="$" && state=="$"){
                QMessageBox msg;
                msg.setText("Syntax is Correct.");
                msg.exec();
                flag_current_syntx++;
                break;
            }

            int col = cal_col(token);
            int row = cal_row(state);

            //error(invalid input)
            if(col==-1){
                string syntax_error = ui->txte_syntx_error->toPlainText().toStdString();
                syntax_error += token+" not define in parse table..";
                ui->txte_syntx_error->setText(QString::fromStdString(syntax_error+"\n"));

                QMessageBox msg;
                msg.setText("Intput String is not Valid!!!!");
                msg.exec();

                break;
            }

            //pop from begin of string
            if(token == state){
                str = str.substr(chAt, str.size()-1);
                //pop from stack
                stack.erase(stack.end());
                ui->txte_grammar->setText(QString::fromStdString("Pop Token '"+token+"'"));
            }
            else if(token!=state && row == -1 ){
                //show erorr message:
                string syntax_error = ui->txte_syntx_error->toPlainText().toStdString();
                syntax_error += token+" not match with top of Stack : "+state+"..";
                ui->txte_syntx_error->setText(QString::fromStdString(syntax_error+"\n"));

                QMessageBox msg;
                msg.setText("error!!!\ntoken != state(top of stack)");
                msg.exec();
                break;
            }

            if(token != state){
                string str_grammar = pars_table[row][col];
                ui->txte_grammar->setText(QString::fromStdString(state+" ---> "+str_grammar));
                if(str_grammar=="#") {
                       QMessageBox msg;
                       msg.setText("Error!!!");
                       msg.exec();

                       //show erorr message:
                       string syntax_error = ui->txte_syntx_error->toPlainText().toStdString();
                       syntax_error += "Not Define Any Grammaar in Parse Table For Token : "+token+" and State : "+state+"..";
                       ui->txte_syntx_error->setText(QString::fromStdString(syntax_error+"\n"));
                       break;
                }

                if(str_grammar=="ε"){
                    cout<<"Reduce With ε";
                    stack.erase(stack.end());
                 }

                else{
                    if(str_grammar=="id"){
                        stack.erase(stack.end());
                        stack.push_back("id");
                    }
                    else{
                        str_grammar = reverse(str_grammar);
                        stack.erase(stack.end());
                        for (int k = 0; k<str_grammar.size(); k++) {
                            string tmp;
                            tmp.push_back(str_grammar.at(k));
                            stack.push_back(tmp);
                        }
                    }
                }
            }
        }//end of while;
    }//end of for;

    //"ALL STATEMENT HAVE CORRECT SYNTAX."
    if(number_of_statement==flag_current_syntx && ui->txte_lexical_error->toPlainText()==""){
        core_program.replace("\n", "");
        core_program.replace(" ", "");

        for (int i = 0; i<core_program.size(); i++) {
            QString id = core_program.at(i);
            QString value;
            int flag_value = 0;
            while(core_program.at(i)!=";"){
                if(flag_value==1){
                    value.push_back(core_program.at(i));
                }
                if(core_program.at(i)=="="){
                   flag_value = 1;
                }
                i++;
            }//cout<<id.toStdString()<<endl;cout<<value.toStdString()<<endl;

            int j = i;
            cout<<"i :"<<i<<endl;
            if(j<=core_program.size()-2){
                QString id_define = core_program.at(j);
                id_define+=core_program.at(j+1);
                while(id_define != id+":"){

                    cout<<"j :"<<j<<endl;
                    QString s = core_program.at(j);
                    if(s==id&&core_program.at(j+1)!=":"){

                        cout<<"ok j :"<<j<<endl;
                        string tmp , str_core_program;
                        str_core_program = core_program.toStdString();
                        tmp = str_core_program.substr(0, j);
                        tmp = tmp+"("+value.toStdString()+")";
                        tmp = tmp+str_core_program.substr(j+1,str_core_program.size());
                        core_program = QString::fromStdString(tmp);
                    }
                    if(j==core_program.size()-2){
                        break;
                    }
                    id_define  = core_program.at(j);
                    id_define += core_program.at(j+1);
                    j++;
                }

                //for a:=a+a+a+..+b
                j = j+2;//for ':' and '='
                if(id_define==id+":"){
                    QString tmp_assign_value_to_itself;
                    while(core_program.at(j)!=";"){
                        QString s = core_program.at(j);
                        if(s==id){
                            string str_core_program, tmp;
                            str_core_program = core_program.toStdString();
                            tmp = str_core_program.substr(0, j);
                            tmp = tmp+"("+value.toStdString()+")";
                            tmp = tmp+str_core_program.substr(j+1,str_core_program.size());
                            core_program = QString::fromStdString(tmp);
                        }
                        j++;
                    }
                }
            }
        }

        //if one of variable not initialize: default value is (zero)
        for (int i = 0 ; i<core_program.size(); i++) {
            if(core_program.at(i)=="="){
                while(core_program.at(i)!=";"){
                    if(core_program.at(i)=="a"||core_program.at(i)=="b"||core_program.at(i)=="c"||core_program.at(i)=="d"){
                        string str_core_program, tmp;
                        str_core_program = core_program.toStdString();
                        tmp = str_core_program.substr(0, i);
                        tmp = tmp+"0";
                        tmp = tmp+str_core_program.substr(i+1,str_core_program.size());
                        core_program = QString::fromStdString(tmp);
                    }
                    i++;
                }
            }
        }
        cout<<"\n[CORE OF PROGRAM]\n"<<core_program.toStdString()<<"\n\n"<<endl;
        core_program = check_negative_value(core_program);
        cout<<"\n[CORE OF PROGRAM]\n"<<core_program.toStdString()<<"\n\n"<<endl;


        QVector<QString> vc_core_program_id;
        QVector<QString> vc_core_program_value;
        for (int i = 0; i<core_program.size();i++) {
            if(core_program.at(i)=="a"||core_program.at(i)=="b"||core_program.at(i)=="c"||core_program.at(i)=="d"){
                vc_core_program_id.push_back(core_program.at(i));
            }
            QString val = "";
            if(core_program.at(i)=="="){
                i++;//for "="
                while(core_program.at(i)!=";"){
                    val += core_program.at(i);
                    i++;
                }
                vc_core_program_value.push_back(val);
            }
        }

        QVector<QString> vc_core_program_end_result_values;
        for (int i = 0; i<vc_core_program_value.size(); i++) {

            QString infix = vc_core_program_value.at(i);
            QString result  = infix_to_postfix(infix).at(0);
            QString Postfix = infix_to_postfix(infix).at(1);
            vc_core_program_end_result_values.push_back(result+"\n"+Postfix);
        }

        QString compiler_output = "";
        for(int i = 0; i<vc_core_program_id.size(); i++){
            compiler_output += vc_core_program_id.at(i)+" = ";
            compiler_output += vc_core_program_end_result_values.at(i)+"\n";
        }
        ui->txte_compiler_output->setText(compiler_output);

        QTextEdit *msg = new QTextEdit();
        msg->setText(compiler_output);
        msg->setStyleSheet("min-width:700 px; min-height:400; background-color: rgb(0, 0, 0); color: rgb(0, 255, 255); font-size:14px");
        msg->show();
    }
}

int priority(QString expr_Operator, QString stack_Operator){
    int flag = 0;   //if flag = 0 ---> push expr_operator into stack
                    //if flag = 1 ---> pop satck_operator from stack

    if(expr_Operator=="+"||expr_Operator=="-"){
        if(stack_Operator=="+"||stack_Operator=="-"){
            //pop
            flag = 1;
        }
        else if(stack_Operator=="*"||stack_Operator=="/"){
            //pop
            flag = 1;
        }
    }
    else if(expr_Operator=="*"||expr_Operator=="/"){
        if(stack_Operator=="+"||stack_Operator=="-"){
            //push
            flag = 0;
        }
        else if(stack_Operator=="*"||stack_Operator=="/"){
            //pop
            flag = 1;
        }
    }
    else if (expr_Operator=="(") {
        flag = 0;
    }
    else if (expr_Operator==")") {
        flag = 1;
    }

    return flag;
}

QVector<QString> infix_to_postfix(QString str){
    QVector<QString> end_result;

    str+="#";//for end of string
    QVector<QString> Postfix;
    QVector<QString> Stack;

    //Expression for more than 1 charachter like number
    QVector<QString> Expression;
    for (int i = 0; i<str.size(); i++) {
        QString tmp_expr = "";
        while(true){
            if(str.at(i)=="+"||str.at(i)=="-"||str.at(i)=="*"||str.at(i)=="/"||
               str.at(i)=="("||str.at(i)==")"||str.at(i)=="#"){
                if(tmp_expr!="")
                    Expression.push_back(tmp_expr);
                Expression.push_back(str.at(i));
                break;
            }
            else {
                tmp_expr+=str.at(i);
                i++;
            }
        }
    }
    Expression.removeLast();//for delete '#'
    for (int i = 0 ; i<Expression.size(); i++) {
        cout<<Expression.at(i).toStdString()<<endl;
    }

    Stack.push_back("$");
    for (int i = 0; i<Expression.size(); i++) {
        if(Expression.at(i)=="+"||Expression.at(i)=="-"||Expression.at(i)=="*"||
           Expression.at(i)=="/"||Expression.at(i)=="("||Expression.at(i)==")"){
            if(priority(Expression.at(i), Stack.last())==0){//0 : Push into stack
                Stack.push_back(Expression.at(i));
            }
            else{                                           //1 : pop from stack
                if(Expression.at(i)==")"){
                    while(Stack.at(Stack.size()-1)!="("){
                        Postfix += Stack.at(Stack.size()-1);
                        Stack.remove(Stack.size()-1);
                    }
                    Stack.remove(Stack.size()-1);//for delte '(' on top of stack
                }
                else{
                    Postfix += Stack.at(Stack.size()-1);
                    Stack.remove(Stack.size()-1);
                    i = i-1;
                }
            }
        }
        else{
            Postfix.push_back(Expression.at(i));
        }
    }
    for (int i = 0; i<Stack.size(); i++) {
        if(Stack.at(Stack.size()-1)!="$"){
            Postfix += Stack.at(Stack.size()-1);
            Stack.remove(Stack.size()-1);
        }
    }

    cout<<"Stack : ";
    for (int i = 0; i<Stack.size(); i++) {
        cout<<Stack.at(i).toStdString()<<"\t";
    }cout<<endl;

    cout<<"Infix   : "<<str.toStdString()<<endl;
    QString str_Postfix;
    cout<<"Postfix : ";
    str_Postfix = "[Postfix] \n";
    for (int i = 0; i<Postfix.size(); i++) {
        cout<<Postfix.at(i).toStdString()<<"\t";
        str_Postfix += Postfix.at(i) + "\t";
    }str_Postfix += "\n";
    cout<<endl;



    //[Calculate Math Statement With Postfix]:
    QVector<QString> cal_Stack;
    for (int i = 0; i<Postfix.size(); i++) {
        if(Postfix.at(i)=="+"||Postfix.at(i)=="-"||Postfix.at(i)=="*"||Postfix.at(i)=="/"){
            double result = 0;
            cout<<cal_Stack.at(cal_Stack.size()-2).toStdString()<<Postfix.at(i).toStdString()
               <<cal_Stack.at(cal_Stack.size()-1).toStdString()<<endl;

            if(Postfix.at(i)=="+"){
                result = cal_Stack.at(cal_Stack.size()-2).toDouble()+cal_Stack.at(cal_Stack.size()-1).toDouble();
            }
            else if(Postfix.at(i)=="-"){

                result = cal_Stack.at(cal_Stack.size()-2).toDouble()-cal_Stack.at(cal_Stack.size()-1).toDouble();
            }
            else if(Postfix.at(i)=="*"){

                result = cal_Stack.at(cal_Stack.size()-2).toDouble()*cal_Stack.at(cal_Stack.size()-1).toDouble();
            }
            else if(Postfix.at(i)=="/"){

                result = cal_Stack.at(cal_Stack.size()-2).toDouble()/cal_Stack.at(cal_Stack.size()-1).toDouble();
            }
            cal_Stack.remove(cal_Stack.size()-1);
            cal_Stack.remove(cal_Stack.size()-1);Postfix :
            cout<<"result : "<<result<<endl;
            cal_Stack.push_back(QString::fromStdString(to_string(result)));
        }
        else{
            cal_Stack.push_back(Postfix.at(i));
        }
    }

    cout<<"cal_Stack : ";
    for (int i = 0; i<cal_Stack.size(); i++) {
        cout<<cal_Stack.at(i).toStdString()<<"\t";
    }cout<<endl;

    end_result.push_back(cal_Stack.at(0));
    end_result.push_back(str_Postfix);
    return end_result;
}

QString check_negative_value(QString str){

    if(str.at(0)=="-"){
       QString tmp;
       tmp = "0";
       tmp = tmp+str;
       str = tmp;
    }

    str.replace("=----", "=");
    str.replace("=+++", "=");
    str.replace("=---", "=-");
    str.replace("+-", "-");
    str.replace("-+", "-");
    str.replace("--", "+");
    str.replace("++", "+");
    str.replace("(-", "(0-");
    str.replace("(+", "(");
    str.replace("=-", "=0-");
    str.replace("=+", "=");

    return str;
}

//THIS IS PRETTY: (FOR QT SIGNAL ERROR)
void MainWindow::on_btnSyntx_pressed(){}
void MainWindow::on_btnSyntx_clicked(){}
void MainWindow::on_btn_syntx_clicked(){}
void MainWindow::on_pushButton_clicked(){}
void MainWindow::on_btn_syntax_clicked(){}

