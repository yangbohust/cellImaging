#pragma once

#include <QWidget>
#include "ui_leftthreerightone.h"

class LeftThreeRightOne : public QWidget
{
	Q_OBJECT

public:
	LeftThreeRightOne(QWidget *parent = Q_NULLPTR);
	~LeftThreeRightOne();

private:
	Ui::LeftThreeRightOne ui;
};
