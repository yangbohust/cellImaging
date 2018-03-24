#pragma once

#include <QWidget>
#include "ui_onewidget.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class OneWidget : public QWidget
{
	Q_OBJECT

public:
	OneWidget(QWidget *parent = Q_NULLPTR);
	~OneWidget();

	void showImage(cv::Mat image);

private:
	Ui::OneWidget ui;
};
