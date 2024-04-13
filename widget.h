#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void AddMoney(int amount);
    void CheckAvailability();


private slots:
    void on_push10button_clicked();
    void on_push50button_clicked();
    void on_push100button_clicked();
    void on_push500button_clicked();
    void on_Buy_a_Coffee_clicked();
    void on_Buy_a_Tea_clicked();
    void on_Buy_a_Milk_clicked();
    void on_RESET_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
