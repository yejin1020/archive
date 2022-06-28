/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_mul;
    QPushButton *pushButton_9;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_root;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_7;
    QPushButton *pushButton_1;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_00;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_div;
    QPushButton *pushButton_close;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_first;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_second;
    QLabel *label_eq;
    QLineEdit *lineEdit_result;
    QLabel *label_op;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(160, 180, 471, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_minus = new QPushButton(gridLayoutWidget);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));

        gridLayout->addWidget(pushButton_minus, 3, 3, 1, 1);

        pushButton_plus = new QPushButton(gridLayoutWidget);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));

        gridLayout->addWidget(pushButton_plus, 1, 3, 1, 1);

        pushButton_mul = new QPushButton(gridLayoutWidget);
        pushButton_mul->setObjectName(QStringLiteral("pushButton_mul"));

        gridLayout->addWidget(pushButton_mul, 4, 3, 1, 1);

        pushButton_9 = new QPushButton(gridLayoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(gridLayoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_root = new QPushButton(gridLayoutWidget);
        pushButton_root->setObjectName(QStringLiteral("pushButton_root"));

        gridLayout->addWidget(pushButton_root, 3, 4, 1, 1);

        pushButton_sqrt = new QPushButton(gridLayoutWidget);
        pushButton_sqrt->setObjectName(QStringLiteral("pushButton_sqrt"));

        gridLayout->addWidget(pushButton_sqrt, 4, 4, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_1 = new QPushButton(gridLayoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        gridLayout->addWidget(pushButton_1, 1, 0, 1, 1);

        pushButton_clear = new QPushButton(gridLayoutWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        gridLayout->addWidget(pushButton_clear, 5, 0, 1, 1);

        pushButton_00 = new QPushButton(gridLayoutWidget);
        pushButton_00->setObjectName(QStringLiteral("pushButton_00"));

        gridLayout->addWidget(pushButton_00, 5, 1, 1, 1);

        pushButton_equal = new QPushButton(gridLayoutWidget);
        pushButton_equal->setObjectName(QStringLiteral("pushButton_equal"));

        gridLayout->addWidget(pushButton_equal, 5, 2, 1, 1);

        pushButton_div = new QPushButton(gridLayoutWidget);
        pushButton_div->setObjectName(QStringLiteral("pushButton_div"));

        gridLayout->addWidget(pushButton_div, 5, 3, 1, 1);

        pushButton_close = new QPushButton(gridLayoutWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        gridLayout->addWidget(pushButton_close, 5, 4, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(150, 50, 160, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_first = new QLineEdit(horizontalLayoutWidget);
        lineEdit_first->setObjectName(QStringLiteral("lineEdit_first"));

        horizontalLayout->addWidget(lineEdit_first);

        horizontalLayoutWidget_2 = new QWidget(Dialog);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(410, 50, 241, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_second = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_second->setObjectName(QStringLiteral("lineEdit_second"));

        horizontalLayout_2->addWidget(lineEdit_second);

        label_eq = new QLabel(horizontalLayoutWidget_2);
        label_eq->setObjectName(QStringLiteral("label_eq"));

        horizontalLayout_2->addWidget(label_eq);

        lineEdit_result = new QLineEdit(horizontalLayoutWidget_2);
        lineEdit_result->setObjectName(QStringLiteral("lineEdit_result"));

        horizontalLayout_2->addWidget(lineEdit_result);

        label_op = new QLabel(Dialog);
        label_op->setObjectName(QStringLiteral("label_op"));
        label_op->setGeometry(QRect(330, 80, 61, 20));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        pushButton_minus->setText(QApplication::translate("Dialog", "-", Q_NULLPTR));
        pushButton_plus->setText(QApplication::translate("Dialog", "+", Q_NULLPTR));
        pushButton_mul->setText(QApplication::translate("Dialog", "*", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Dialog", "09", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Dialog", "06", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Dialog", "05", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Dialog", "04", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Dialog", "03", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Dialog", "08", Q_NULLPTR));
        pushButton_root->setText(QApplication::translate("Dialog", "root", Q_NULLPTR));
        pushButton_sqrt->setText(QApplication::translate("Dialog", "^", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Dialog", "07", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("Dialog", "01", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("Dialog", "C", Q_NULLPTR));
        pushButton_00->setText(QApplication::translate("Dialog", "00", Q_NULLPTR));
        pushButton_equal->setText(QApplication::translate("Dialog", "=", Q_NULLPTR));
        pushButton_div->setText(QApplication::translate("Dialog", "/", Q_NULLPTR));
        pushButton_close->setText(QApplication::translate("Dialog", "close", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "02", Q_NULLPTR));
        label_eq->setText(QApplication::translate("Dialog", "=", Q_NULLPTR));
        label_op->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
