#include "inputwidget.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

InputWidget::InputWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	model = new QSqlTableModel[3];
	curIndex = ui.tabWidget->currentIndex();

	model[0].setTable("data"); // 为模型指定数据表
	model[0].select(); // 使用select()函数进行查询
	model[0].setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置编辑策略：调用submitAll()或者revertAll()之后改变被应用
	ui.tableView->setModel(&model[0]);
	ui.tableView->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头
	
	model[1].setTable("experiment");
	model[1].select();
	model[1].setEditStrategy(QSqlTableModel::OnManualSubmit);
	ui.tableView_2->setModel(&model[1]);
	ui.tableView_2->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头

	model[2].setTable("machine");
	model[2].select();
	model[2].setEditStrategy(QSqlTableModel::OnManualSubmit);
	ui.tableView_3->setModel(&model[2]);
	ui.tableView_3->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头
}

InputWidget::~InputWidget()
{
}

// 提交修改
void InputWidget::on_submit_clicked(){
	model[curIndex].database().transaction();
	if (model[curIndex].submitAll()){
		if (model[curIndex].database().commit())
			QMessageBox::information(this, tr("tableModel"), tr("数据修改成功！"));
	}
	else{
		model[curIndex].database().rollback(); // 回滚
		QMessageBox::warning(this, tr("tableModel"), tr("数据库错误：%1").arg(model[curIndex].lastError().text()), QMessageBox::Ok);
	}
}

// 撤销修改
void InputWidget::on_cancel_clicked(){
	model[curIndex].revertAll();
}

// 查询按钮，进行筛选
void InputWidget::on_query_clicked(){
	QString id = ui.comboBox->currentText();
	QString machine = ui.comboBox_2->currentText();
	QString object = ui.comboBox_3->currentText();

	model[curIndex].setFilter(QString("id = '%1'").arg(id));
	model[curIndex].select();
}

// 显示全表
void InputWidget::on_viewAll_clicked(){
	model[curIndex].setTable("data");
	model[curIndex].select();
}

// 按id升序排列
void InputWidget::on_ascending_clicked(){
	model[curIndex].setSort(0, Qt::AscendingOrder);
	model[curIndex].select();
}

// 按id降序排列
void InputWidget::on_descending_clicked(){
	model[curIndex].setSort(0, Qt::DescendingOrder);
	model[curIndex].select();
}

// 删除选中行
void InputWidget::on_delete_clicked(){
	int curRow = ui.tableView->currentIndex().row(); // 获取选中行
	model[curIndex].removeRow(curRow); // 删除该行

	int ok = QMessageBox::warning(this, tr("删除当前行！"), tr("你确定删除当前行吗？"), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No){
		model[curIndex].revertAll();
	}
	else{
		model[curIndex].submitAll();
	}
}
