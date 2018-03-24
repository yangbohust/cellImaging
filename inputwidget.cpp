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

	model[0].setTable("data"); // Ϊģ��ָ�����ݱ�
	model[0].select(); // ʹ��select()�������в�ѯ
	model[0].setEditStrategy(QSqlTableModel::OnManualSubmit); // ���ñ༭���ԣ�����submitAll()����revertAll()֮��ı䱻Ӧ��
	ui.tableView->setModel(&model[0]);
	ui.tableView->verticalHeader()->hide(); // �����������
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ
	
	model[1].setTable("experiment");
	model[1].select();
	model[1].setEditStrategy(QSqlTableModel::OnManualSubmit);
	ui.tableView_2->setModel(&model[1]);
	ui.tableView_2->verticalHeader()->hide(); // �����������
	ui.tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ

	model[2].setTable("machine");
	model[2].select();
	model[2].setEditStrategy(QSqlTableModel::OnManualSubmit);
	ui.tableView_3->setModel(&model[2]);
	ui.tableView_3->verticalHeader()->hide(); // �����������
	ui.tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // ��������ͷ
}

InputWidget::~InputWidget()
{
}

// �ύ�޸�
void InputWidget::on_submit_clicked(){
	model[curIndex].database().transaction();
	if (model[curIndex].submitAll()){
		if (model[curIndex].database().commit())
			QMessageBox::information(this, tr("tableModel"), tr("�����޸ĳɹ���"));
	}
	else{
		model[curIndex].database().rollback(); // �ع�
		QMessageBox::warning(this, tr("tableModel"), tr("���ݿ����%1").arg(model[curIndex].lastError().text()), QMessageBox::Ok);
	}
}

// �����޸�
void InputWidget::on_cancel_clicked(){
	model[curIndex].revertAll();
}

// ��ѯ��ť������ɸѡ
void InputWidget::on_query_clicked(){
	QString id = ui.comboBox->currentText();
	QString machine = ui.comboBox_2->currentText();
	QString object = ui.comboBox_3->currentText();

	model[curIndex].setFilter(QString("id = '%1'").arg(id));
	model[curIndex].select();
}

// ��ʾȫ��
void InputWidget::on_viewAll_clicked(){
	model[curIndex].setTable("data");
	model[curIndex].select();
}

// ��id��������
void InputWidget::on_ascending_clicked(){
	model[curIndex].setSort(0, Qt::AscendingOrder);
	model[curIndex].select();
}

// ��id��������
void InputWidget::on_descending_clicked(){
	model[curIndex].setSort(0, Qt::DescendingOrder);
	model[curIndex].select();
}

// ɾ��ѡ����
void InputWidget::on_delete_clicked(){
	int curRow = ui.tableView->currentIndex().row(); // ��ȡѡ����
	model[curIndex].removeRow(curRow); // ɾ������

	int ok = QMessageBox::warning(this, tr("ɾ����ǰ�У�"), tr("��ȷ��ɾ����ǰ����"), QMessageBox::Yes, QMessageBox::No);
	if (ok == QMessageBox::No){
		model[curIndex].revertAll();
	}
	else{
		model[curIndex].submitAll();
	}
}
