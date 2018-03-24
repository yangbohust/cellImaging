/********************************************************************************
** Form generated from reading UI file 'outputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTWIDGET_H
#define UI_OUTPUTWIDGET_H

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

class Ui_OutputWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;
    QTableView *tableView;

    void setupUi(QWidget *OutputWidget)
    {
        if (OutputWidget->objectName().isEmpty())
            OutputWidget->setObjectName(QStringLiteral("OutputWidget"));
        OutputWidget->resize(781, 641);
        label = new QLabel(OutputWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 490, 121, 17));
        label_2 = new QLabel(OutputWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 540, 81, 17));
        label_3 = new QLabel(OutputWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 600, 81, 17));
        lineEdit = new QLineEdit(OutputWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 490, 113, 23));
        lineEdit_2 = new QLineEdit(OutputWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 540, 113, 23));
        lineEdit_3 = new QLineEdit(OutputWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 600, 113, 23));
        label_4 = new QLabel(OutputWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 540, 81, 17));
        lineEdit_4 = new QLineEdit(OutputWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(490, 540, 113, 23));
        label_5 = new QLabel(OutputWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(400, 490, 121, 17));
        lineEdit_5 = new QLineEdit(OutputWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(520, 490, 113, 23));
        pushButton = new QPushButton(OutputWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(670, 590, 104, 32));
        tableView = new QTableView(OutputWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 761, 461));

        retranslateUi(OutputWidget);

        QMetaObject::connectSlotsByName(OutputWidget);
    } // setupUi

    void retranslateUi(QWidget *OutputWidget)
    {
        OutputWidget->setWindowTitle(QApplication::translate("OutputWidget", "OutputWidget", Q_NULLPTR));
        label->setText(QApplication::translate("OutputWidget", "\346\225\260\346\215\256\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("OutputWidget", "\346\225\260\346\215\256\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("OutputWidget", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("OutputWidget", "\346\225\260\346\215\256\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("OutputWidget", "\345\203\217\347\264\240\345\255\230\345\202\250\346\240\274\345\274\217\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("OutputWidget", "\346\267\273\345\212\240\350\256\260\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OutputWidget: public Ui_OutputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTWIDGET_H
