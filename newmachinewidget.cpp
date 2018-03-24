#include "newmachinewidget.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>

QSqlQueryModel* model = new QSqlQueryModel();

NewMachineWidget::NewMachineWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	model->setQuery("select * from machine");
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("实验设备编号"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("光源型号"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("探测器型号"));
	
	ui.tableView->setModel(model);
	ui.tableView->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // 添加记录按钮
}

NewMachineWidget::~NewMachineWidget()
{
}

void NewMachineWidget::on_addRecord_clicked(){
	// 设置并获取实验编号
	QString m_id = ui.lineEdit->text();
	// 设置并获取光源编号
	QString source = ui.lineEdit_2->text();
	// 设置并获取探测器编号
	QString detector = ui.lineEdit_3->text();
	
	QSqlQuery query = model->query();
	query.prepare("insert into machine values(?, ?, ?)");
	query.addBindValue(m_id);
	query.addBindValue(source);
	query.addBindValue(detector);
	query.exec();

	model->setQuery("select * from machine");

	qDebug() << "Add Record successful~";
}
