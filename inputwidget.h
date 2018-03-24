#pragma once

#include <QWidget>
#include "ui_inputwidget.h"
#include <QSqlTableModel>

class InputWidget : public QWidget
{
	Q_OBJECT

public:
	InputWidget(QWidget *parent = Q_NULLPTR);
	~InputWidget();

public slots:
	void on_submit_clicked(); // �ύ�޸İ�ť�ۺ���
	void on_cancel_clicked(); // �����޸İ�ť�ۺ���
	void on_query_clicked(); // ��ѯ��ť�ۺ���
	void on_viewAll_clicked(); // ��ʾȫ��ť�ۺ���
	void on_ascending_clicked(); // ���������а�ť�ۺ���
	void on_descending_clicked(); // ���������а�ť�ۺ���
	void on_delete_clicked(); // ɾ��ѡ���а�ť�ۺ���

private:
	Ui::InputWidget ui;

	int curIndex;
	QSqlTableModel* model;
};
