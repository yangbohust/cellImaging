/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QStringLiteral("RegisterWidget"));
        RegisterWidget->resize(656, 504);
        lineEdit = new QLineEdit(RegisterWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 160, 113, 21));
        pushButton = new QPushButton(RegisterWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 280, 93, 28));
        lineEdit_2 = new QLineEdit(RegisterWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(310, 210, 113, 21));
        label_2 = new QLabel(RegisterWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 220, 72, 15));
        pushButton_2 = new QPushButton(RegisterWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 280, 93, 28));
        label = new QLabel(RegisterWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 160, 72, 15));

        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QApplication::translate("RegisterWidget", "RegisterWidget", Q_NULLPTR));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("RegisterWidget", "\347\241\256\345\256\232", Q_NULLPTR));
        lineEdit_2->setText(QString());
        label_2->setText(QApplication::translate("RegisterWidget", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("RegisterWidget", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
