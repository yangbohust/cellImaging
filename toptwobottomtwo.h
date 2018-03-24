#pragma once

#include <QWidget>
#include "ui_toptwobottomtwo.h"

class TopTwoBottomTwo : public QWidget
{
	Q_OBJECT

public:
	TopTwoBottomTwo(QWidget *parent = Q_NULLPTR);
	~TopTwoBottomTwo();

private:
	Ui::TopTwoBottomTwo ui;
};
