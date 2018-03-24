#include "onewidget.h"

OneWidget::OneWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

OneWidget::~OneWidget()
{
}

void OneWidget::showImage(cv::Mat image)
{
	ui.opencvViewer->displayImage(image);
}