#pragma once

#include <QWidget>
#include "ui_outputwidget.h"

class OutputWidget : public QWidget
{
	Q_OBJECT

public:
	OutputWidget(QWidget *parent = Q_NULLPTR);
	~OutputWidget();

public slots:
	void on_addRecord_clicked();

private:
	Ui::OutputWidget ui;
};
