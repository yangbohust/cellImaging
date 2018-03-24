#include "newexperimentwidget.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

QSqlQueryModel* model_e = new QSqlQueryModel();

NewExperimentWidget::NewExperimentWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	model_e->setQuery("select time, object, fkm_id, f_path, mode, exposure, gain from experiment");
	//model_e->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("实验编号")); // 自增
	//model_e->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("用户ID")); // 只能看见自己的实验记录
	model_e->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("实验时间"));
	model_e->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("实验对象"));
	model_e->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("实验设备编号"));
	model_e->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("文件路径"));
	model_e->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("采集模式"));
	model_e->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("曝光时间"));
	model_e->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("增益"));

	ui.tableView->setModel(model_e);
	ui.tableView->verticalHeader()->hide(); // 隐藏左边那列
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 均分填充表头

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // 添加记录按钮
}

NewExperimentWidget::~NewExperimentWidget()
{
}

void NewExperimentWidget::on_addRecord_clicked(){
	QDateTime currentTime = QDateTime::currentDateTime(); // 获取系统时间
	QString currentDate = currentTime.toString("yyy.MM.dd hh:mm:ss ddd");
	QString object = ui.lineEdit->text(); // 设置并获取实验对象
	QString fkm_id = ui.comboBox->currentText();// 获取实验设备编号
	QString f_path = ui.lineEdit_2->text(); // 设置并获取实验数据集保存路径
	QString mode = ui.comboBox_2->currentText();// 获取采集模式
	QString exposure = ui.lineEdit_3->text(); // 设置并获取曝光时间
	QString gain = ui.lineEdit_5->text(); // 设置并获取增益

	QSqlQuery query = model_e->query();
	query.prepare("insert into experiment values(:e_id, :fku_id, :time, :object, :fkm_id, :f_path, :mode, :exposure, :gain)");
	query.bindValue(":e_id", 3);
	query.bindValue(":fku_id", "solan");
	query.bindValue(":time", currentDate);
	query.bindValue(":object", object);
	query.bindValue(":fkm_id", fkm_id);
	query.bindValue(":f_path", f_path);
	query.bindValue(":mode", mode);
	query.bindValue(":exposure", exposure);
	query.bindValue(":gain", gain);

	bool ni = query.exec();
	if (!ni){
		QSqlError lastError = query.lastError();
		qDebug() << lastError.driverText() << "Insert failed!";
	}else{
		qDebug() << "Insert sucessfully~";
	}

	model_e->setQuery("select time, object, fkm_id, f_path, mode, exposure, gain from experiment");
}
