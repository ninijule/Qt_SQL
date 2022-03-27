#ifndef HOME_H
#define HOME_H

#include <QDialog>

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    void tableWidget();

};

#endif // HOME_H
