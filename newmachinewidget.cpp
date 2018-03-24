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
	model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ʵ���豸���"));
	model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("��Դ�ͺ�"));
	model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("̽�����ͺ�"));
	
	ui.tableView->setModel(model);
	ui.tableView->verticalHeader()->hide(); // �����������
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // ��Ӽ�¼��ť
}

NewMachineWidget::~NewMachineWidget()
{
}

void NewMachineWidget::on_addRecord_clicked(){
	// ���ò���ȡʵ����
	QString m_id = ui.lineEdit->text();
	// ���ò���ȡ��Դ���
	QString source = ui.lineEdit_2->text();
	// ���ò���ȡ̽�������
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
