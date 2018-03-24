#pragma once

#include <QWidget>
#include "ui_newexperimentwidget.h"

class NewExperimentWidget : public QWidget
{
	Q_OBJECT

public:
	NewExperimentWidget(QWidget *parent = Q_NULLPTR);
	~NewExperimentWidget();

public slots:
	void on_addRecord_clicked();

private:
	Ui::NewExperimentWidget ui;
};
