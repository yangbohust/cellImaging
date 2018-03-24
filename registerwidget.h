#pragma once

#include <QWidget>
#include "ui_registerwidget.h"

class RegisterWidget : public QWidget
{
	Q_OBJECT

public:
	RegisterWidget(QWidget *parent = Q_NULLPTR);
	~RegisterWidget();

public slots:
	void on_ok_clicked();
	void on_cancel_clicked();

private:
	Ui::RegisterWidget ui;
};
