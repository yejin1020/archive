#include "dialog.h"
#include "./ui_dialog.h"
#include "qmath.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_00_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){            // ui의 연산자가 비어 있을 때
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "0");        // 첫 번째 피연산자에 0추가
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "0");    // 두 번째 피연산자에 0
        }

}

void Dialog::on_pushButton_1_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "1");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "1");
        }
}

void Dialog::on_pushButton_2_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "2");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "2");
        }
}


void Dialog::on_pushButton_3_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "3");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "3");
        }
}

void Dialog::on_pushButton_4_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "4");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "4");
        }
}

void Dialog::on_pushButton_5_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "5");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "5");
        }
}

void Dialog::on_pushButton_6_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "6");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "6");
        }
}

void Dialog::on_pushButton_7_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "7");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "7");
        }
}

void Dialog::on_pushButton_8_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "8");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "8");
        }

}

void Dialog::on_pushButton_9_clicked()
{
    if(QString::compare(ui->label_op->text(), "") == 0){
            ui->lineEdit_first->setText(ui->lineEdit_first->text() + "9");
        }
        else{
            ui->lineEdit_second->setText(ui->lineEdit_second->text() + "9");
        }

}


void Dialog::on_pushButton_plus_clicked()
{
    ui->label_op->setText("+");        // ui의 label_op의 내용을 +로 바꾼다

}

void Dialog::on_pushButton_minus_clicked()
{
    ui->label_op->setText("-");
}

void Dialog::on_pushButton_mul_clicked()
{
    ui->label_op->setText("*");
}

void Dialog::on_pushButton_div_clicked()
{
    ui->label_op->setText("/");
}

void Dialog::on_pushButton_root_clicked()
{
    ui->label_op->setText("√");
}


void Dialog::on_pushButton_sqrt_clicked()
{
    ui->label_op->setText("^");
}

void Dialog::on_pushButton_close_clicked()
{
    this->close();
}

void Dialog::on_pushButton_clear_clicked()
{
    ui->lineEdit_first->setText("");        // ui의 lineEdit_first의 내용을 ""으로 바꾼다.
        ui->label_op->setText("");
        ui->lineEdit_second->setText("");
        ui->lineEdit_result->setText("");

}

void Dialog::on_pushButton_equal_clicked()
{
    first = ui->lineEdit_first->text().toDouble();
        second = ui->lineEdit_second->text().toDouble();

        if(ui->label_op->text() == "+"){
            ui->lineEdit_result->setText(QString::number(first + second));
        }
        else if(ui->label_op->text() == "-"){
            ui->lineEdit_result->setText(QString::number(first - second));
        }
        else if(ui->label_op->text() == "*"){
            ui->lineEdit_result->setText(QString::number(first * second));
        }
        else if(ui->label_op->text() == "/"){
            ui->lineEdit_result->setText(QString::number(first / second));
        }
        else if(ui->label_op->text() == "^"){
            ui->lineEdit_result->setText(QString::number(qPow(first, second)));
        }
        else if(ui->label_op->text() == "√"){
            ui->lineEdit_result->setText(QString::number(qSqrt(first)));
        }


}
