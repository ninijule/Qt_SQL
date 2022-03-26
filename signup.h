#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>


namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

signals:
    void enableMainWindow();

private slots:
    void on_registerButton_clicked();
    void enableFrameMainWindow();

private:
    Ui::SignUp *ui;


};

#endif // SIGNUP_H
