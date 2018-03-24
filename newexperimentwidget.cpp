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
	//model_e->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ʵ����")); // ����
	//model_e->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("�û�ID")); // ֻ�ܿ����Լ���ʵ���¼
	model_e->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("ʵ��ʱ��"));
	model_e->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("ʵ�����"));
	model_e->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("ʵ���豸���"));
	model_e->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("�ļ�·��"));
	model_e->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("�ɼ�ģʽ"));
	model_e->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("�ع�ʱ��"));
	model_e->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("����"));

	ui.tableView->setModel(model_e);
	ui.tableView->verticalHeader()->hide(); // �����������
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_addRecord_clicked())); // ��Ӽ�¼��ť
}

NewExperimentWidget::~NewExperimentWidget()
{
}

void NewExperimentWidget::on_addRecord_clicked(){
	QDateTime currentTime = QDateTime::currentDateTime(); // ��ȡϵͳʱ��
	QString currentDate = currentTime.toString("yyy.MM.dd hh:mm:ss ddd");
	QString object = ui.lineEdit->text(); // ���ò���ȡʵ�����
	QString fkm_id = ui.comboBox->currentText();// ��ȡʵ���豸���
	QString f_path = ui.lineEdit_2->text(); // ���ò���ȡʵ�����ݼ�����·��
	QString mode = ui.comboBox_2->currentText();// ��ȡ�ɼ�ģʽ
	QString exposure = ui.lineEdit_3->text(); // ���ò���ȡ�ع�ʱ��
	QString gain = ui.lineEdit_5->text(); // ���ò���ȡ����

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
