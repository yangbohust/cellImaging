/********************************************************************************
** Form generated from reading UI file 'inputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTWIDGET_H
#define UI_INPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *data;
    QTableView *tableView;
    QWidget *experiment;
    QTableView *tableView_2;
    QWidget *machine;
    QTableView *tableView_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_3;
    QComboBox *comboBox_3;

    void setupUi(QWidget *InputWidget)
    {
        if (InputWidget->objectName().isEmpty())
            InputWidget->setObjectName(QStringLiteral("InputWidget"));
        InputWidget->resize(1057, 730);
        tabWidget = new QTabWidget(InputWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 821, 591));
        data = new QWidget();
        data->setObjectName(QStringLiteral("data"));
        tableView = new QTableView(data);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 811, 561));
        tabWidget->addTab(data, QString());
        experiment = new QWidget();
        experiment->setObjectName(QStringLiteral("experiment"));
        tableView_2 = new QTableView(experiment);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(0, 0, 811, 561));
        tabWidget->addTab(experiment, QString());
        machine = new QWidget();
        machine->setObjectName(QStringLiteral("machine"));
        tableView_3 = new QTableView(machine);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(0, 0, 811, 561));
        tabWidget->addTab(machine, QString());
        pushButton_4 = new QPushButton(InputWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(880, 180, 131, 32));
        pushButton_5 = new QPushButton(InputWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(880, 130, 131, 32));
        pushButton_6 = new QPushButton(InputWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(880, 80, 131, 32));
        pushButton_8 = new QPushButton(InputWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(880, 230, 131, 32));
        pushButton_9 = new QPushButton(InputWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(710, 630, 104, 32));
        pushButton_10 = new QPushButton(InputWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(710, 680, 104, 32));
        label = new QLabel(InputWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 630, 81, 17));
        comboBox = new QComboBox(InputWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 630, 97, 23));
        label_2 = new QLabel(InputWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 630, 81, 17));
        comboBox_2 = new QComboBox(InputWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(450, 630, 97, 23));
        pushButton_11 = new QPushButton(InputWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(880, 320, 131, 32));
        pushButton_12 = new QPushButton(InputWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(880, 370, 131, 32));
        pushButton_13 = new QPushButton(InputWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(880, 430, 131, 32));
        pushButton_14 = new QPushButton(InputWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(880, 480, 131, 32));
        label_3 = new QLabel(InputWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 680, 81, 17));
        comboBox_3 = new QComboBox(InputWidget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(450, 680, 97, 23));

        retranslateUi(InputWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InputWidget);
    } // setupUi

    void retranslateUi(QWidget *InputWidget)
    {
        InputWidget->setWindowTitle(QApplication::translate("InputWidget", "InputWidget", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(data), QApplication::translate("InputWidget", "\346\225\260\346\215\256\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(experiment), QApplication::translate("InputWidget", "\345\256\236\351\252\214\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(machine), QApplication::translate("InputWidget", "\350\256\276\345\244\207\350\241\250", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("InputWidget", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("InputWidget", "\346\222\244\351\224\200\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("InputWidget", "\346\217\220\344\272\244\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("InputWidget", "\345\257\274\345\205\245\351\200\211\344\270\255\350\241\214", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("InputWidget", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("InputWidget", "\346\230\276\347\244\272\345\205\250\350\241\250", Q_NULLPTR));
        label->setText(QApplication::translate("InputWidget", "\345\256\236\351\252\214ID\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("InputWidget", "\345\256\236\351\252\214\350\256\276\345\244\207\357\274\232", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("InputWidget", "\346\214\211ID\345\215\207\345\272\217\346\216\222\345\210\227", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("InputWidget", "\346\214\211ID\351\231\215\345\272\217\346\216\222\345\210\227", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("InputWidget", "\346\214\211\346\227\266\351\227\264\345\215\207\345\272\217\346\216\222\345\210\227", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("InputWidget", "\346\214\211\346\227\266\351\227\264\351\231\215\345\272\217\346\216\222\345\210\227", Q_NULLPTR));
        label_3->setText(QApplication::translate("InputWidget", "\345\256\236\351\252\214\345\257\271\350\261\241\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InputWidget: public Ui_InputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWIDGET_H
