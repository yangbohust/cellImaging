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

//�� Matת��ΪQImage������QImage ��ÿһ���ж�������ֽڣ��ʲ��� RBG32 �����������ֽ�
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

//�ڿؼ�����ʾͼƬ��ʹ��opencv�Դ���resizeʹ�����ŵ��Ϳؼ���Сһ��
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

//��ͼ�¼�������
void QtOpencvViewer::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawImage(event->rect(), data, event->rect());
}

//�����¼�Ҳ���� opencv�Դ���resize
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