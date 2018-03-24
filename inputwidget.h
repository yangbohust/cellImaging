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
	void on_submit_clicked(); // 提交修改按钮槽函数
	void on_cancel_clicked(); // 撤销修改按钮槽函数
	void on_query_clicked(); // 查询按钮槽函数
	void on_viewAll_clicked(); // 显示全表按钮槽函数
	void on_ascending_clicked(); // 按升序排列按钮槽函数
	void on_descending_clicked(); // 按降序排列按钮槽函数
	void on_delete_clicked(); // 删除选中行按钮槽函数

private:
	Ui::InputWidget ui;

	int curIndex;
	QSqlTableModel* model;
};
