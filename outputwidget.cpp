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
	model_o->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ʵ����"));
	model_o->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("�ļ�·��"));
	model_o->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("��������"));
	model_o->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("���ݸ�ʽ"));
	model_o->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("��������"));
	model_o->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("���ݴ�С"));

	ui.tableView->setModel(model_o);
	ui.tableView->verticalHeader()->hide(); // �����������
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // ��Ӽ�¼��ť
}

OutputWidget::~OutputWidget()
{
}

void OutputWidget::on_addRecord_clicked(){
	QString d_path = ui.lineEdit->text(); // ���ò���ȡ���ݴ洢·��
	QString name = ui.lineEdit_2->text(); // ���ò���ȡ��������
	QString type = ui.lineEdit_3->text(); // ���ò���ȡ��������
	QString size = ui.lineEdit_4->text(); // ���ò���ȡ���ݴ�С
	QString format = ui.lineEdit_5->text(); // ���ò���ȡ���ش洢��ʽ

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