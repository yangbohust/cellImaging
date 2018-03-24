#pragma once

#include <QWidget>
#include <QException>
#include <opencv2/core/core.hpp>

// 当图片不是灰度图或者 BGR 图像时抛出此异常
class UnsupportedFormatError : public QException
{
public:
	void raise() const { throw *this; }
	UnsupportedFormatError *clone() const { return new UnsupportedFormatError(*this); }
};

class QtOpencvViewer : public QWidget
{
	Q_OBJECT

public:
	QtOpencvViewer(QWidget *parent);
	~QtOpencvViewer();

	cv::Mat getBuffer();

public slots:
	void displayImage(const cv::Mat& img);

protected:
	void matToQImage(const cv::Mat3b &src, QImage &dest);
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

	QImage data;
	cv::Mat buffer;
};
