/********************************************************************************
** Form generated from reading UI file 'onewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEWIDGET_H
#define UI_ONEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qtopencvviewer.h"

QT_BEGIN_NAMESPACE

class Ui_OneWidget
{
public:
    QGridLayout *gridLayout;
    QtOpencvViewer *opencvViewer;

    void setupUi(QWidget *OneWidget)
    {
        if (OneWidget->objectName().isEmpty())
            OneWidget->setObjectName(QStringLiteral("OneWidget"));
        OneWidget->resize(400, 300);
        gridLayout = new QGridLayout(OneWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        opencvViewer = new QtOpencvViewer(OneWidget);
        opencvViewer->setObjectName(QStringLiteral("opencvViewer"));

        gridLayout->addWidget(opencvViewer, 0, 0, 1, 1);


        retranslateUi(OneWidget);

        QMetaObject::connectSlotsByName(OneWidget);
    } // setupUi

    void retranslateUi(QWidget *OneWidget)
    {
        OneWidget->setWindowTitle(QApplication::translate("OneWidget", "OneWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OneWidget: public Ui_OneWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEWIDGET_H
