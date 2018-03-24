/********************************************************************************
** Form generated from reading UI file 'leftthreerightone.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTTHREERIGHTONE_H
#define UI_LEFTTHREERIGHTONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qglmitkwidget.h"

QT_BEGIN_NAMESPACE

class Ui_LeftThreeRightOne
{
public:
    QGridLayout *gridLayout;
    QWidget *twoDimentionalViewerX;
    QGLMitkWidget *threeDimentionalViewer;
    QWidget *twoDimentionalViewerY;
    QWidget *twoDimentionalViewerZ;

    void setupUi(QWidget *LeftThreeRightOne)
    {
        if (LeftThreeRightOne->objectName().isEmpty())
            LeftThreeRightOne->setObjectName(QStringLiteral("LeftThreeRightOne"));
        LeftThreeRightOne->resize(957, 690);
        gridLayout = new QGridLayout(LeftThreeRightOne);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        twoDimentionalViewerX = new QWidget(LeftThreeRightOne);
        twoDimentionalViewerX->setObjectName(QStringLiteral("twoDimentionalViewerX"));

        gridLayout->addWidget(twoDimentionalViewerX, 0, 0, 1, 1);

        threeDimentionalViewer = new QGLMitkWidget(LeftThreeRightOne);
        threeDimentionalViewer->setObjectName(QStringLiteral("threeDimentionalViewer"));
        threeDimentionalViewer->setMinimumSize(QSize(600, 0));

        gridLayout->addWidget(threeDimentionalViewer, 0, 1, 3, 1);

        twoDimentionalViewerY = new QWidget(LeftThreeRightOne);
        twoDimentionalViewerY->setObjectName(QStringLiteral("twoDimentionalViewerY"));

        gridLayout->addWidget(twoDimentionalViewerY, 1, 0, 1, 1);

        twoDimentionalViewerZ = new QWidget(LeftThreeRightOne);
        twoDimentionalViewerZ->setObjectName(QStringLiteral("twoDimentionalViewerZ"));

        gridLayout->addWidget(twoDimentionalViewerZ, 2, 0, 1, 1);


        retranslateUi(LeftThreeRightOne);

        QMetaObject::connectSlotsByName(LeftThreeRightOne);
    } // setupUi

    void retranslateUi(QWidget *LeftThreeRightOne)
    {
        LeftThreeRightOne->setWindowTitle(QApplication::translate("LeftThreeRightOne", "LeftThreeRightOne", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeftThreeRightOne: public Ui_LeftThreeRightOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTTHREERIGHTONE_H
