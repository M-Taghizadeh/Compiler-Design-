#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    QString console_text;//show console output in console form
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void newDocument();
    void open();
    void save();
    void saveAs();
    void exit();
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void selectFont();
    void setFontUnderline(bool underline);
    void setFontItalic(bool italic);
    void setFontBold(bool italic);
    void about();
    void dark_theme();
    void default_theme();
    void theme_blue();
    void theme_red();
    void theme_green();
    void theme_yellow();
    void on_btn_cg_clicked();
    void on_btn_lexical_clicked();
    int isIdentifier(string str);
    void check_id_definition_before_assign(QString str);
    void on_pushButton_clicked();
    void on_btn_syntx_clicked();
    void on_btnSyntx_clicked();
    void on_btnSyntx_pressed();
    void on_btn_syntax_clicked();
    void on_btn_sntx_clicked();

private:
    QString currentFile;
};

#endif // MAINWINDOW_H
