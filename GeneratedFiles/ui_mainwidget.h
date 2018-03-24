/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QGLMitkWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_DICOMDIR;
    QAction *action_open;
    QAction *action_7;
    QAction *action_Ply;
    QAction *action_Stl;
    QAction *action_Raw;
    QAction *action_IM0;
    QAction *action_0;
    QAction *action_3;
    QAction *action_5;
    QAction *action_6;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_12;
    QAction *action_13;
    QAction *actionX_Y;
    QAction *actionX_Z;
    QAction *actionY_Z;
    QAction *action_15;
    QAction *action_16;
    QAction *action_17;
    QAction *action_19;
    QAction *action_20;
    QAction *action_save;
    QAction *action_machine;
    QAction *action_experiment;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_DataList;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *tab_Show;
    QSlider *horizontalSlider;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *tab_Tools;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_25;
    QLineEdit *lineEdit_4;
    QPushButton *open;
    QPushButton *leftRotate;
    QPushButton *rightRotate;
    QPushButton *vertical;
    QPushButton *horizontal;
    QPushButton *graycolor;
    QPushButton *hitogram;
    QPushButton *operator_2;
    QStackedWidget *stackedWidget;
    QGLMitkWidget *showwidget;
    QMenuBar *menuBar;
    QMenu *menu_D;
    QMenu *menu_R;
    QMenu *menu_S;
    QMenu *menu_4;
    QMenu *menu_V;
    QMenu *menu_3;
    QMenu *menu_W;
    QMenu *menu_H;
    QMenu *menu_C;
    QMenu *menu_P;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QStringLiteral("MainWidgetClass"));
        MainWidgetClass->resize(1367, 866);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWidgetClass->sizePolicy().hasHeightForWidth());
        MainWidgetClass->setSizePolicy(sizePolicy);
        MainWidgetClass->setMinimumSize(QSize(600, 0));
        action_1 = new QAction(MainWidgetClass);
        action_1->setObjectName(QStringLiteral("action_1"));
        action_2 = new QAction(MainWidgetClass);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_DICOMDIR = new QAction(MainWidgetClass);
        action_DICOMDIR->setObjectName(QStringLiteral("action_DICOMDIR"));
        action_open = new QAction(MainWidgetClass);
        action_open->setObjectName(QStringLiteral("action_open"));
        action_7 = new QAction(MainWidgetClass);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_Ply = new QAction(MainWidgetClass);
        action_Ply->setObjectName(QStringLiteral("action_Ply"));
        action_Stl = new QAction(MainWidgetClass);
        action_Stl->setObjectName(QStringLiteral("action_Stl"));
        action_Raw = new QAction(MainWidgetClass);
        action_Raw->setObjectName(QStringLiteral("action_Raw"));
        action_IM0 = new QAction(MainWidgetClass);
        action_IM0->setObjectName(QStringLiteral("action_IM0"));
        action_0 = new QAction(MainWidgetClass);
        action_0->setObjectName(QStringLiteral("action_0"));
        action_3 = new QAction(MainWidgetClass);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_5 = new QAction(MainWidgetClass);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWidgetClass);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_8 = new QAction(MainWidgetClass);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWidgetClass);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(MainWidgetClass);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_12 = new QAction(MainWidgetClass);
        action_12->setObjectName(QStringLiteral("action_12"));
        action_13 = new QAction(MainWidgetClass);
        action_13->setObjectName(QStringLiteral("action_13"));
        actionX_Y = new QAction(MainWidgetClass);
        actionX_Y->setObjectName(QStringLiteral("actionX_Y"));
        actionX_Z = new QAction(MainWidgetClass);
        actionX_Z->setObjectName(QStringLiteral("actionX_Z"));
        actionY_Z = new QAction(MainWidgetClass);
        actionY_Z->setObjectName(QStringLiteral("actionY_Z"));
        action_15 = new QAction(MainWidgetClass);
        action_15->setObjectName(QStringLiteral("action_15"));
        action_16 = new QAction(MainWidgetClass);
        action_16->setObjectName(QStringLiteral("action_16"));
        action_17 = new QAction(MainWidgetClass);
        action_17->setObjectName(QStringLiteral("action_17"));
        action_19 = new QAction(MainWidgetClass);
        action_19->setObjectName(QStringLiteral("action_19"));
        action_20 = new QAction(MainWidgetClass);
        action_20->setObjectName(QStringLiteral("action_20"));
        action_save = new QAction(MainWidgetClass);
        action_save->setObjectName(QStringLiteral("action_save"));
        action_machine = new QAction(MainWidgetClass);
        action_machine->setObjectName(QStringLiteral("action_machine"));
        action_experiment = new QAction(MainWidgetClass);
        action_experiment->setObjectName(QStringLiteral("action_experiment"));
        centralWidget = new QWidget(MainWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(11, 11, 491, 771));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab_DataList = new QWidget();
        tab_DataList->setObjectName(QStringLiteral("tab_DataList"));
        gridLayout_2 = new QGridLayout(tab_DataList);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableWidget = new QTableWidget(tab_DataList);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(480, 0));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(4);
        tableWidget->horizontalHeader()->setDefaultSectionSize(160);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);

        tabWidget->addTab(tab_DataList, QString());
        tab_Show = new QWidget();
        tab_Show->setObjectName(QStringLiteral("tab_Show"));
        horizontalSlider = new QSlider(tab_Show);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 50, 471, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(tab_Show);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 61, 16));
        pushButton = new QPushButton(tab_Show);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 90, 81, 28));
        lineEdit = new QLineEdit(tab_Show);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(312, 90, 111, 21));
        label_2 = new QLabel(tab_Show);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(431, 90, 41, 20));
        label_3 = new QLabel(tab_Show);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 72, 15));
        pushButton_2 = new QPushButton(tab_Show);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(372, 250, 101, 28));
        label_4 = new QLabel(tab_Show);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 200, 51, 16));
        label_5 = new QLabel(tab_Show);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 230, 51, 16));
        doubleSpinBox = new QDoubleSpinBox(tab_Show);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(70, 230, 111, 22));
        doubleSpinBox_2 = new QDoubleSpinBox(tab_Show);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(70, 200, 111, 22));
        tabWidget->addTab(tab_Show, QString());
        tab_Tools = new QWidget();
        tab_Tools->setObjectName(QStringLiteral("tab_Tools"));
        label_6 = new QLabel(tab_Tools);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 72, 15));
        label_7 = new QLabel(tab_Tools);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 260, 41, 16));
        label_8 = new QLabel(tab_Tools);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 100, 31, 16));
        label_9 = new QLabel(tab_Tools);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 100, 31, 16));
        label_10 = new QLabel(tab_Tools);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 100, 61, 16));
        label_11 = new QLabel(tab_Tools);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 190, 61, 16));
        label_12 = new QLabel(tab_Tools);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(140, 190, 51, 16));
        label_13 = new QLabel(tab_Tools);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(270, 190, 51, 16));
        label_14 = new QLabel(tab_Tools);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 100, 61, 16));
        label_15 = new QLabel(tab_Tools);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(260, 190, 61, 16));
        label_16 = new QLabel(tab_Tools);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 350, 31, 16));
        label_17 = new QLabel(tab_Tools);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(150, 350, 31, 16));
        label_18 = new QLabel(tab_Tools);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(280, 350, 31, 16));
        label_19 = new QLabel(tab_Tools);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(400, 350, 31, 16));
        label_20 = new QLabel(tab_Tools);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 460, 31, 16));
        label_21 = new QLabel(tab_Tools);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(150, 460, 31, 16));
        label_22 = new QLabel(tab_Tools);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 530, 61, 16));
        label_23 = new QLabel(tab_Tools);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 580, 41, 16));
        label_24 = new QLabel(tab_Tools);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 610, 41, 16));
        lineEdit_2 = new QLineEdit(tab_Tools);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 580, 113, 21));
        lineEdit_3 = new QLineEdit(tab_Tools);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 610, 113, 21));
        label_25 = new QLabel(tab_Tools);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(270, 580, 72, 15));
        lineEdit_4 = new QLineEdit(tab_Tools);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(350, 580, 113, 21));
        open = new QPushButton(tab_Tools);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(80, 10, 93, 28));
        leftRotate = new QPushButton(tab_Tools);
        leftRotate->setObjectName(QStringLiteral("leftRotate"));
        leftRotate->setGeometry(QRect(0, 70, 93, 28));
        rightRotate = new QPushButton(tab_Tools);
        rightRotate->setObjectName(QStringLiteral("rightRotate"));
        rightRotate->setGeometry(QRect(100, 70, 101, 28));
        vertical = new QPushButton(tab_Tools);
        vertical->setObjectName(QStringLiteral("vertical"));
        vertical->setGeometry(QRect(240, 70, 93, 28));
        horizontal = new QPushButton(tab_Tools);
        horizontal->setObjectName(QStringLiteral("horizontal"));
        horizontal->setGeometry(QRect(370, 70, 93, 28));
        graycolor = new QPushButton(tab_Tools);
        graycolor->setObjectName(QStringLiteral("graycolor"));
        graycolor->setGeometry(QRect(0, 160, 93, 28));
        hitogram = new QPushButton(tab_Tools);
        hitogram->setObjectName(QStringLiteral("hitogram"));
        hitogram->setGeometry(QRect(110, 160, 93, 28));
        operator_2 = new QPushButton(tab_Tools);
        operator_2->setObjectName(QStringLiteral("operator_2"));
        operator_2->setGeometry(QRect(240, 160, 93, 28));
        tabWidget->addTab(tab_Tools, QString());
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(550, 550, 611, 241));
        showwidget = new QGLMitkWidget(centralWidget);
        showwidget->setObjectName(QStringLiteral("showwidget"));
        showwidget->setGeometry(QRect(520, 30, 831, 771));
        MainWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1367, 26));
        menu_D = new QMenu(menuBar);
        menu_D->setObjectName(QStringLiteral("menu_D"));
        menu_R = new QMenu(menuBar);
        menu_R->setObjectName(QStringLiteral("menu_R"));
        menu_S = new QMenu(menuBar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_4 = new QMenu(menu_S);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_V = new QMenu(menuBar);
        menu_V->setObjectName(QStringLiteral("menu_V"));
        menu_3 = new QMenu(menu_V);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QStringLiteral("menu_W"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_C = new QMenu(menuBar);
        menu_C->setObjectName(QStringLiteral("menu_C"));
        menu_P = new QMenu(menuBar);
        menu_P->setObjectName(QStringLiteral("menu_P"));
        MainWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWidgetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWidgetClass->setStatusBar(statusBar);

        menuBar->addAction(menu_D->menuAction());
        menuBar->addAction(menu_C->menuAction());
        menuBar->addAction(menu_P->menuAction());
        menuBar->addAction(menu_R->menuAction());
        menuBar->addAction(menu_S->menuAction());
        menuBar->addAction(menu_V->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_D->addAction(action_DICOMDIR);
        menu_D->addSeparator();
        menu_D->addAction(action_machine);
        menu_D->addAction(action_experiment);
        menu_D->addSeparator();
        menu_D->addAction(action_open);
        menu_D->addAction(action_save);
        menu_S->addAction(action_8);
        menu_S->addAction(action_9);
        menu_S->addAction(action_10);
        menu_S->addAction(menu_4->menuAction());
        menu_4->addAction(action_12);
        menu_4->addAction(action_13);
        menu_V->addAction(action_0);
        menu_V->addAction(menu_3->menuAction());
        menu_3->addAction(action_3);
        menu_3->addAction(action_5);
        menu_3->addAction(action_6);
        menu_W->addAction(actionX_Y);
        menu_W->addAction(actionX_Z);
        menu_W->addAction(actionY_Z);
        menu_W->addSeparator();
        menu_W->addAction(action_15);
        menu_W->addAction(action_16);
        menu_W->addAction(action_17);
        menu_W->addSeparator();
        menu_W->addAction(action_19);
        menu_W->addAction(action_20);
        menu_H->addAction(action_1);
        menu_H->addAction(action_2);

        retranslateUi(MainWidgetClass);

        tabWidget->setCurrentIndex(2);
        stackedWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QApplication::translate("MainWidgetClass", "MainWidget", Q_NULLPTR));
        action_1->setText(QApplication::translate("MainWidgetClass", "\346\211\213\345\206\214(&M)", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWidgetClass", "\345\205\263\344\272\216(&A)", Q_NULLPTR));
        action_DICOMDIR->setText(QApplication::translate("MainWidgetClass", "\344\273\216DICOMDIR\350\257\273\345\217\226", Q_NULLPTR));
        action_open->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\205\245\346\225\260\346\215\256...", Q_NULLPTR));
        action_7->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\207\272\344\275\223\346\225\260\346\215\256", Q_NULLPTR));
        action_Ply->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\205\245\344\270\200\344\270\252Ply\346\226\207\344\273\266", Q_NULLPTR));
        action_Stl->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\205\245\344\270\200\344\270\252Stl\346\226\207\344\273\266", Q_NULLPTR));
        action_Raw->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\205\245\344\270\200\344\270\252Raw\346\226\207\344\273\266", Q_NULLPTR));
        action_IM0->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\205\245\344\270\200\344\270\252IM0\346\226\207\344\273\266", Q_NULLPTR));
        action_0->setText(QApplication::translate("MainWidgetClass", "\351\235\242\347\273\230\345\210\266", Q_NULLPTR));
        action_3->setText(QApplication::translate("MainWidgetClass", "CPU\344\275\223\347\273\230\345\210\266", Q_NULLPTR));
        action_5->setText(QApplication::translate("MainWidgetClass", "\345\237\272\344\272\216CUD\347\232\204\344\275\223\347\273\230\345\210\266", Q_NULLPTR));
        action_6->setText(QApplication::translate("MainWidgetClass", "GLSL\344\275\223\347\273\230\345\210\266", Q_NULLPTR));
        action_8->setText(QApplication::translate("MainWidgetClass", "\350\207\252\345\212\250\351\230\210\345\200\274\345\210\206\345\211\262", Q_NULLPTR));
        action_9->setText(QApplication::translate("MainWidgetClass", "GraphCut\345\210\206\345\211\262", Q_NULLPTR));
        action_10->setText(QApplication::translate("MainWidgetClass", "\345\214\272\345\237\237\347\224\237\351\225\277\345\210\206\345\211\262", Q_NULLPTR));
        action_12->setText(QApplication::translate("MainWidgetClass", "Snake\346\250\241\345\236\213", Q_NULLPTR));
        action_13->setText(QApplication::translate("MainWidgetClass", "\346\260\264\345\271\263\351\233\206\346\226\271\346\263\225", Q_NULLPTR));
        actionX_Y->setText(QApplication::translate("MainWidgetClass", "X-Y\345\210\207\347\211\207\350\247\206\345\233\276", Q_NULLPTR));
        actionX_Z->setText(QApplication::translate("MainWidgetClass", "X-Z\345\210\207\347\211\207\350\247\206\345\233\276", Q_NULLPTR));
        actionY_Z->setText(QApplication::translate("MainWidgetClass", "Y-Z\345\210\207\347\211\207\350\247\206\345\233\276", Q_NULLPTR));
        action_15->setText(QApplication::translate("MainWidgetClass", "\344\270\2122\344\270\2132\350\247\206\345\233\276", Q_NULLPTR));
        action_16->setText(QApplication::translate("MainWidgetClass", "\344\270\2121\344\270\2133\350\247\206\345\233\276", Q_NULLPTR));
        action_17->setText(QApplication::translate("MainWidgetClass", "\345\267\2463\345\217\2631\350\247\206\345\233\276", Q_NULLPTR));
        action_19->setText(QApplication::translate("MainWidgetClass", "\344\270\211\347\273\264\350\241\250\351\235\242\350\247\206\345\233\276", Q_NULLPTR));
        action_20->setText(QApplication::translate("MainWidgetClass", "\344\270\211\347\273\264\344\275\223\350\247\206\345\233\276", Q_NULLPTR));
        action_save->setText(QApplication::translate("MainWidgetClass", "\345\257\274\345\207\272\346\225\260\346\215\256...", Q_NULLPTR));
        action_machine->setText(QApplication::translate("MainWidgetClass", "\346\226\260\345\273\272\350\256\276\345\244\207...", Q_NULLPTR));
        action_experiment->setText(QApplication::translate("MainWidgetClass", "\346\226\260\345\273\272\345\256\236\351\252\214...", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWidgetClass", "\346\225\260\346\215\256\345\212\240\350\275\275\346\226\271\345\274\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWidgetClass", "\346\225\260\346\215\256\346\240\274\345\274\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWidgetClass", "\346\225\260\346\215\256\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWidgetClass", "\345\206\205\345\255\230\345\274\200\351\224\200", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWidgetClass", "In Core\347\275\221\346\240\274\346\225\260\346\215\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWidgetClass", "In Core\344\275\223\346\225\260\346\215\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWidgetClass", "Out of Core\347\275\221\346\240\274\346\225\260\346\215\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(3, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWidgetClass", "Out of Core\344\275\223\346\225\260\346\215\256", Q_NULLPTR));
        tableWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_DataList), QApplication::translate("MainWidgetClass", "\346\225\260\346\215\256\345\210\227\350\241\250", Q_NULLPTR));
        label->setText(QApplication::translate("MainWidgetClass", "\345\210\207\347\211\207\344\275\215\347\275\256", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWidgetClass", "\346\222\255\346\224\276", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWidgetClass", "\345\270\247/\347\247\222", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWidgetClass", "\347\252\227\345\256\275/\347\252\227\344\275\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWidgetClass", "\351\207\215\347\275\256\347\252\227\345\256\275\347\252\227\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWidgetClass", "\347\252\227\345\256\275\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWidgetClass", "\347\252\227\344\275\215\357\274\232", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_Show), QApplication::translate("MainWidgetClass", "\346\230\276\347\244\272", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWidgetClass", "\345\233\276\345\203\217\345\267\245\345\205\267", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWidgetClass", "\346\216\247\344\273\266", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWidgetClass", "\345\267\246\346\227\213", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWidgetClass", "\345\217\263\346\227\213", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWidgetClass", "\345\236\202\347\233\264\351\225\234\345\203\217", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWidgetClass", "\345\217\215\350\275\254\347\201\260\345\272\246", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWidgetClass", "\347\233\264\346\226\271\345\233\276", Q_NULLPTR));
        label_13->setText(QString());
        label_14->setText(QApplication::translate("MainWidgetClass", "\346\260\264\345\271\263\351\225\234\345\203\217", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWidgetClass", "\346\223\215\344\275\234\346\211\213\346\237\204", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWidgetClass", "\347\233\264\347\272\277", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWidgetClass", "\350\247\222\345\272\246", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWidgetClass", "\344\274\252\345\275\251", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWidgetClass", "\347\237\251\345\275\242", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWidgetClass", "\345\244\232\350\276\271\345\275\242", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWidgetClass", "\346\244\255\345\234\206", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWidgetClass", "\346\265\213\351\207\217\345\267\245\345\205\267", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWidgetClass", "\351\235\242\347\247\257\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWidgetClass", "\344\275\223\347\247\257\357\274\232", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWidgetClass", "\347\233\264\347\272\277\350\267\235\347\246\273\357\274\232", Q_NULLPTR));
        open->setText(QApplication::translate("MainWidgetClass", "\346\230\276\347\244\272", Q_NULLPTR));
        leftRotate->setText(QApplication::translate("MainWidgetClass", "leftRotate", Q_NULLPTR));
        rightRotate->setText(QApplication::translate("MainWidgetClass", "rightRotate", Q_NULLPTR));
        vertical->setText(QApplication::translate("MainWidgetClass", "vertical", Q_NULLPTR));
        horizontal->setText(QApplication::translate("MainWidgetClass", "horizontal", Q_NULLPTR));
        graycolor->setText(QApplication::translate("MainWidgetClass", "graycolor", Q_NULLPTR));
        hitogram->setText(QApplication::translate("MainWidgetClass", "hitogram", Q_NULLPTR));
        operator_2->setText(QApplication::translate("MainWidgetClass", "operator", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_Tools), QApplication::translate("MainWidgetClass", "\345\267\245\345\205\267", Q_NULLPTR));
        menu_D->setTitle(QApplication::translate("MainWidgetClass", "\345\274\200\345\247\213(&D)", Q_NULLPTR));
        menu_R->setTitle(QApplication::translate("MainWidgetClass", "\351\207\215\345\273\272(&R)", Q_NULLPTR));
        menu_S->setTitle(QApplication::translate("MainWidgetClass", "\345\210\206\345\211\262(&S)", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWidgetClass", "\346\264\273\345\212\250\350\275\256\345\273\223\346\250\241\345\236\213", Q_NULLPTR));
        menu_V->setTitle(QApplication::translate("MainWidgetClass", "\345\217\257\350\247\206\345\214\226(&V)", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWidgetClass", "\344\275\223\347\273\230\345\210\266", Q_NULLPTR));
        menu_W->setTitle(QApplication::translate("MainWidgetClass", "\347\252\227\345\217\243(&W)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWidgetClass", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_C->setTitle(QApplication::translate("MainWidgetClass", "\347\263\273\347\273\237(&C)", Q_NULLPTR));
        menu_P->setTitle(QApplication::translate("MainWidgetClass", "\351\242\204\345\244\204\347\220\206(&P)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
