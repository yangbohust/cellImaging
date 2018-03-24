#include "qtopencvviewer.h"
#include <QResizeEvent>
#include <QPaintEvent>
#include <QPainter>

#include <opencv2/imgproc/imgproc.hpp>

QtOpencvViewer::QtOpencvViewer(QWidget *parent)
	: QWidget(parent)
{
}

QtOpencvViewer::~QtOpencvViewer()
{
}

cv::Mat QtOpencvViewer::getBuffer()
{
	return buffer;
}

//将 Mat转换为QImage，由于QImage 的每一行有多余对齐字节，故采用 RBG32 来消除多余字节
void QtOpencvViewer::matToQImage(const cv::Mat3b &src, QImage& dest)
{
	for (int y = 0; y < src.rows; ++y) {
		const cv::Vec3b *srcrow = src[y];
		QRgb *destrow = (QRgb*)dest.scanLine(y);
		for (int x = 0; x < src.cols; ++x) {
			destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
		}
	}
}

//在控件上显示图片，使用opencv自带的resize使其缩放到和控件大小一致
void QtOpencvViewer::displayImage(const cv::Mat &img)
{
	QSize sz = data.size();
	if (img.channels() == 3) {
		buffer = img.clone();
	}
	else if (img.channels() == 1) {
		cv::cvtColor(img, buffer, CV_GRAY2RGB);
	}
	else {
		throw UnsupportedFormatError();
	}
	cv::Mat resized;
	if (!sz.isEmpty()) {
		cv::resize(buffer, resized, cv::Size(sz.width(), sz.height()));
		matToQImage(resized, data);
		update();
	}
}

//绘图事件处理函数
void QtOpencvViewer::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawImage(event->rect(), data, event->rect());
}

//缩放事件也采用 opencv自带的resize
void QtOpencvViewer::resizeEvent(QResizeEvent *event)
{
	if (data.size() != event->size()) {
		cv::Mat resized;
		data = QImage(event->size(), QImage::Format_RGB32);
		if (!buffer.empty() && !event->size().isEmpty()) {
			cv::resize(buffer, resized, cv::Size(event->size().width(),
				event->size().height()));
			matToQImage(resized, data);
		}
	}
	QWidget::resizeEvent(event);
}