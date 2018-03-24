#pragma once

#include <QWidget>
#include "ui_newmachinewidget.h"

class NewMachineWidget : public QWidget
{
	Q_OBJECT

public:
	NewMachineWidget(QWidget *parent = Q_NULLPTR);
	~NewMachineWidget();

public slots:
	void on_addRecord_clicked();

private:
	Ui::NewMachineWidget ui;
};
