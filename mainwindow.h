#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "signup.h"
#include "home.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
    void on_lineEdit_2_textChanged(const QString &arg1);
    void enableMainWindow();


private:
    Ui::MainWindow *ui;
    SignUp *signup;
    Home *home;
};
#endif // MAINWINDOW_H
