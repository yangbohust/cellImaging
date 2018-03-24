/********************************************************************************
** Form generated from reading UI file 'toponebottomthree.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPONEBOTTOMTHREE_H
#define UI_TOPONEBOTTOMTHREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "QGLMitkWidget.h"

QT_BEGIN_NAMESPACE

class Ui_TopOneBottomThree
{
public:
    QGridLayout *gridLayout;
    QGLMitkWidget *threeDimentionalViewer;
    QWidget *twoDimentionalViewerX;
    QWidget *twoDimentionalViewerY;
    QWidget *twoDimentionalViewerZ;

    void setupUi(QWidget *TopOneBottomThree)
    {
        if (TopOneBottomThree->objectName().isEmpty())
            TopOneBottomThree->setObjectName(QStringLiteral("TopOneBottomThree"));
        TopOneBottomThree->resize(680, 746);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TopOneBottomThree->sizePolicy().hasHeightForWidth());
        TopOneBottomThree->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(TopOneBottomThree);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        threeDimentionalViewer = new QGLMitkWidget(TopOneBottomThree);
        threeDimentionalViewer->setObjectName(QStringLiteral("threeDimentionalViewer"));
        threeDimentionalViewer->setMinimumSize(QSize(0, 600));

        gridLayout->addWidget(threeDimentionalViewer, 0, 0, 1, 3);

        twoDimentionalViewerX = new QWidget(TopOneBottomThree);
        twoDimentionalViewerX->setObjectName(QStringLiteral("twoDimentionalViewerX"));

        gridLayout->addWidget(twoDimentionalViewerX, 1, 0, 1, 1);

        twoDimentionalViewerY = new QWidget(TopOneBottomThree);
        twoDimentionalViewerY->setObjectName(QStringLiteral("twoDimentionalViewerY"));

        gridLayout->addWidget(twoDimentionalViewerY, 1, 1, 1, 1);

        twoDimentionalViewerZ = new QWidget(TopOneBottomThree);
        twoDimentionalViewerZ->setObjectName(QStringLiteral("twoDimentionalViewerZ"));

        gridLayout->addWidget(twoDimentionalViewerZ, 1, 2, 1, 1);


        retranslateUi(TopOneBottomThree);

        QMetaObject::connectSlotsByName(TopOneBottomThree);
    } // setupUi

    void retranslateUi(QWidget *TopOneBottomThree)
    {
        TopOneBottomThree->setWindowTitle(QApplication::translate("TopOneBottomThree", "TopOneBottomThree", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TopOneBottomThree: public Ui_TopOneBottomThree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPONEBOTTOMTHREE_H
