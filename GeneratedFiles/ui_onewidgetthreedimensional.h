/********************************************************************************
** Form generated from reading UI file 'onewidgetthreedimensional.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONEWIDGETTHREEDIMENSIONAL_H
#define UI_ONEWIDGETTHREEDIMENSIONAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qglmitkwidget.h"

QT_BEGIN_NAMESPACE

class Ui_OneWidgetThreeDimensional
{
public:
    QGridLayout *gridLayout;
    QGLMitkWidget *threeDimensionalViewer;

    void setupUi(QWidget *OneWidgetThreeDimensional)
    {
        if (OneWidgetThreeDimensional->objectName().isEmpty())
            OneWidgetThreeDimensional->setObjectName(QStringLiteral("OneWidgetThreeDimensional"));
        OneWidgetThreeDimensional->resize(400, 300);
        gridLayout = new QGridLayout(OneWidgetThreeDimensional);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        threeDimensionalViewer = new QGLMitkWidget(OneWidgetThreeDimensional);
        threeDimensionalViewer->setObjectName(QStringLiteral("threeDimensionalViewer"));

        gridLayout->addWidget(threeDimensionalViewer, 0, 0, 1, 1);


        retranslateUi(OneWidgetThreeDimensional);

        QMetaObject::connectSlotsByName(OneWidgetThreeDimensional);
    } // setupUi

    void retranslateUi(QWidget *OneWidgetThreeDimensional)
    {
        OneWidgetThreeDimensional->setWindowTitle(QApplication::translate("OneWidgetThreeDimensional", "OneWidgetThreeDimensional", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OneWidgetThreeDimensional: public Ui_OneWidgetThreeDimensional {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONEWIDGETTHREEDIMENSIONAL_H
