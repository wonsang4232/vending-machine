#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    CheckAvailability();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::CheckAvailability() {
    int money = ui->lcdNumber->intValue();

    if (money < 100) {
        ui->Buy_a_Coffee->setEnabled(false);
        ui->Buy_a_Tea->setEnabled(false);
        ui->Buy_a_Milk->setEnabled(false);
    }

    else if (money < 150) {
        ui->Buy_a_Coffee->setEnabled(true);
        ui->Buy_a_Tea->setEnabled(false);
        ui->Buy_a_Milk->setEnabled(false);
    }

    else if (money < 200) {
        ui->Buy_a_Coffee->setEnabled(true);
        ui->Buy_a_Tea->setEnabled(true);
        ui->Buy_a_Milk->setEnabled(false);
    }

    else {
        ui->Buy_a_Coffee->setEnabled(true);
        ui->Buy_a_Tea->setEnabled(true);
        ui->Buy_a_Milk->setEnabled(true);
    }
}

void Widget::AddMoney(int amount) {
    int current = ui->lcdNumber->intValue();
    ui->lcdNumber->display(current + amount);
    CheckAvailability();
}

void Widget::on_push10button_clicked()
{
    AddMoney(10);
}

void Widget::on_push50button_clicked()
{
    AddMoney(50);
}

void Widget::on_push100button_clicked()
{
    AddMoney(100);
}

void Widget::on_push500button_clicked()
{
    AddMoney(500);
}

void Widget::on_Buy_a_Coffee_clicked()
{
    AddMoney(-100);
}

void Widget::on_Buy_a_Tea_clicked()
{
    AddMoney(-150);
}

void Widget::on_Buy_a_Milk_clicked()
{
    AddMoney(-200);
}

void Widget::on_RESET_clicked()
{
    int Charges = ui->lcdNumber->intValue();
    int C500, C100, C50, C10;

    C500 = Charges / 500;
    Charges -= C500 * 500;

    C100 = Charges / 100;
    Charges -= C100 * 100;

    C50 = Charges / 50;
    Charges -= C50 * 50;

    C10 = Charges / 10;

    QString msg = "Coin 500 : " + QString::number(C500) + "\n" + "Coin 100 : " + QString::number(C100) + "\n" + "Coin 50 : " + QString::number(C50) + "\n" + "Coin 10 : " + QString::number(C10) + "\n";

    QMessageBox MsgBox;
    MsgBox.information(this, "Remaining Money", msg);
}

