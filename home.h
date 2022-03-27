#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include "QSqlTableModel"

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private slots:
    void on_refreshButton_clicked();

    void on_disconnectButton_clicked();

private:
    Ui::Home *ui;
    void tableWidget();
    QSqlTableModel *mModel;

};

#endif // HOME_H
