#include "outputwidget.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

QSqlQueryModel* model_o = new QSqlQueryModel();

OutputWidget::OutputWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	model_o->setQuery("select fke_id, d_path, name, format, type, size from data");
	model_o->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("实验编号"));
	model_o->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("文件路径"));
	model_o->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("数据名称"));
	model_o->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("数据格式"));
	model_o->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("数据类型"));
	model_o->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("数据大小"));

	ui.tableView->setModel(model_o);
	ui.tableView->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // 添加记录按钮
}

OutputWidget::~OutputWidget()
{
}

void OutputWidget::on_addRecord_clicked(){
	QString d_path = ui.lineEdit->text(); // 设置并获取数据存储路径
	QString name = ui.lineEdit_2->text(); // 设置并获取数据名称
	QString type = ui.lineEdit_3->text(); // 设置并获取数据类型
	QString size = ui.lineEdit_4->text(); // 设置并获取数据大小
	QString format = ui.lineEdit_5->text(); // 设置并获取像素存储格式

	QSqlQuery query = model_o->query();
	query.prepare("insert into data values(:d_id, :fke_id, :d_path, :name, :format, :type, :size)");
	query.bindValue(":d_id", 0);
	query.bindValue(":fke_id", 2);
	query.bindValue(":d_path", d_path);
	query.bindValue(":name", name);
	query.bindValue(":format", format);
	query.bindValue(":type", type);
	query.bindValue(":size", size);

	bool ni = query.exec();
	if (!ni){
		QSqlError lastError = query.lastError();
		qDebug() << lastError.driverText() << "Insert failed!";
	}
	else{
		qDebug() << "Insert sucessfully~";
	}

	model_o->setQuery("select fke_id, d_path, name, format, type, size from data");
}