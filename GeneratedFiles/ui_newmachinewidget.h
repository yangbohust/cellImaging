/********************************************************************************
** Form generated from reading UI file 'newmachinewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMACHINEWIDGET_H
#define UI_NEWMACHINEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewMachineWidget
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;

    void setupUi(QWidget *NewMachineWidget)
    {
        if (NewMachineWidget->objectName().isEmpty())
            NewMachineWidget->setObjectName(QStringLiteral("NewMachineWidget"));
        NewMachineWidget->resize(776, 612);
        tableView = new QTableView(NewMachineWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 751, 501));
        pushButton = new QPushButton(NewMachineWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 570, 104, 32));
        label = new QLabel(NewMachineWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 540, 111, 17));
        lineEdit = new QLineEdit(NewMachineWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 540, 113, 23));
        label_2 = new QLabel(NewMachineWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 580, 81, 17));
        lineEdit_2 = new QLineEdit(NewMachineWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 580, 113, 23));
        label_3 = new QLabel(NewMachineWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 540, 81, 17));
        lineEdit_3 = new QLineEdit(NewMachineWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(450, 540, 113, 23));

        retranslateUi(NewMachineWidget);

        QMetaObject::connectSlotsByName(NewMachineWidget);
    } // setupUi

    void retranslateUi(QWidget *NewMachineWidget)
    {
        NewMachineWidget->setWindowTitle(QApplication::translate("NewMachineWidget", "NewMachineWidget", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NewMachineWidget", "\346\267\273\345\212\240\350\256\260\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("NewMachineWidget", "\345\256\236\351\252\214\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewMachineWidget", "\345\205\211\346\272\220\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("NewMachineWidget", "\346\216\242\346\265\213\345\231\250\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewMachineWidget: public Ui_NewMachineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMACHINEWIDGET_H
