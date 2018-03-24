#pragma once

#include <QWidget>
#include "ui_loginwidget.h"
#include "mainwidget.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:
	LoginWidget(QWidget *parent = Q_NULLPTR);
	~LoginWidget();

public slots:
	void on_login_clicked();
	void on_register_clicked();

private:
	Ui::LoginWidget ui;
	MainWidget* mainWidget;
};
