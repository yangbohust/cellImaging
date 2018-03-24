/********************************************************************************
** Form generated from reading UI file 'newexperimentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWEXPERIMENTWIDGET_H
#define UI_NEWEXPERIMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewExperimentWidget
{
public:
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *NewExperimentWidget)
    {
        if (NewExperimentWidget->objectName().isEmpty())
            NewExperimentWidget->setObjectName(QStringLiteral("NewExperimentWidget"));
        NewExperimentWidget->resize(775, 700);
        tableView = new QTableView(NewExperimentWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 10, 751, 471));
        label = new QLabel(NewExperimentWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 510, 81, 17));
        lineEdit = new QLineEdit(NewExperimentWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 510, 113, 23));
        label_2 = new QLabel(NewExperimentWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 610, 111, 17));
        pushButton = new QPushButton(NewExperimentWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(650, 650, 104, 32));
        comboBox = new QComboBox(NewExperimentWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 610, 97, 23));
        label_3 = new QLabel(NewExperimentWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 560, 121, 17));
        lineEdit_2 = new QLineEdit(NewExperimentWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 560, 113, 23));
        label_4 = new QLabel(NewExperimentWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 510, 91, 17));
        comboBox_2 = new QComboBox(NewExperimentWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(470, 510, 97, 23));
        label_5 = new QLabel(NewExperimentWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 560, 81, 17));
        lineEdit_3 = new QLineEdit(NewExperimentWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(470, 550, 113, 23));
        label_6 = new QLabel(NewExperimentWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 610, 81, 17));
        lineEdit_4 = new QLineEdit(NewExperimentWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(470, 610, 113, 23));
        label_7 = new QLabel(NewExperimentWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 660, 81, 17));
        lineEdit_5 = new QLineEdit(NewExperimentWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(430, 660, 113, 23));

        retranslateUi(NewExperimentWidget);

        QMetaObject::connectSlotsByName(NewExperimentWidget);
    } // setupUi

    void retranslateUi(QWidget *NewExperimentWidget)
    {
        NewExperimentWidget->setWindowTitle(QApplication::translate("NewExperimentWidget", "NewExperimentWidget", Q_NULLPTR));
        label->setText(QApplication::translate("NewExperimentWidget", "\345\256\236\351\252\214\345\257\271\350\261\241\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("NewExperimentWidget", "\345\256\236\351\252\214\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("NewExperimentWidget", "\346\267\273\345\212\240\350\256\260\345\275\225", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("NewExperimentWidget", "1", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("NewExperimentWidget", "\346\225\260\346\215\256\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("NewExperimentWidget", "\351\207\207\351\233\206\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("NewExperimentWidget", "alone", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("NewExperimentWidget", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("NewExperimentWidget", "\345\212\250\346\200\201\350\214\203\345\233\264\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("NewExperimentWidget", "\345\242\236\347\233\212\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewExperimentWidget: public Ui_NewExperimentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWEXPERIMENTWIDGET_H
