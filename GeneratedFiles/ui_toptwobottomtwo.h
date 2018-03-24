/********************************************************************************
** Form generated from reading UI file 'toptwobottomtwo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPTWOBOTTOMTWO_H
#define UI_TOPTWOBOTTOMTWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qglmitkwidget.h"

QT_BEGIN_NAMESPACE

class Ui_TopTwoBottomTwo
{
public:
    QGridLayout *gridLayout;
    QGLMitkWidget *threeDimentionalViewer;
    QWidget *twoDimentionalViewerY;
    QWidget *twoDimentionalViewerX;
    QWidget *twoDimentionalViewerZ;

    void setupUi(QWidget *TopTwoBottomTwo)
    {
        if (TopTwoBottomTwo->objectName().isEmpty())
            TopTwoBottomTwo->setObjectName(QStringLiteral("TopTwoBottomTwo"));
        TopTwoBottomTwo->resize(625, 491);
        gridLayout = new QGridLayout(TopTwoBottomTwo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        threeDimentionalViewer = new QGLMitkWidget(TopTwoBottomTwo);
        threeDimentionalViewer->setObjectName(QStringLiteral("threeDimentionalViewer"));

        gridLayout->addWidget(threeDimentionalViewer, 0, 0, 1, 1);

        twoDimentionalViewerY = new QWidget(TopTwoBottomTwo);
        twoDimentionalViewerY->setObjectName(QStringLiteral("twoDimentionalViewerY"));

        gridLayout->addWidget(twoDimentionalViewerY, 1, 0, 1, 1);

        twoDimentionalViewerX = new QWidget(TopTwoBottomTwo);
        twoDimentionalViewerX->setObjectName(QStringLiteral("twoDimentionalViewerX"));

        gridLayout->addWidget(twoDimentionalViewerX, 0, 1, 1, 1);

        twoDimentionalViewerZ = new QWidget(TopTwoBottomTwo);
        twoDimentionalViewerZ->setObjectName(QStringLiteral("twoDimentionalViewerZ"));

        gridLayout->addWidget(twoDimentionalViewerZ, 1, 1, 1, 1);


        retranslateUi(TopTwoBottomTwo);

        QMetaObject::connectSlotsByName(TopTwoBottomTwo);
    } // setupUi

    void retranslateUi(QWidget *TopTwoBottomTwo)
    {
        TopTwoBottomTwo->setWindowTitle(QApplication::translate("TopTwoBottomTwo", "TopTwoBottomTwo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TopTwoBottomTwo: public Ui_TopTwoBottomTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPTWOBOTTOMTWO_H
