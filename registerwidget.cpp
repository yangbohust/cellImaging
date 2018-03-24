#include "registerwidget.h"
#include "loginwidget.h"
#include <QDebug>
#include <QMessageBox>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

RegisterWidget::RegisterWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_ok_clicked())); //�ɹ�ע�ᰴť
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_cancel_clicked())); //ȡ��ע�ᰴť
}

RegisterWidget::~RegisterWidget()
{
}

void RegisterWidget::on_ok_clicked()
{
	QString userName = ui.lineEdit->text(); //��ȡ����ʼ���û���
	QString passWord = ui.lineEdit_2->text(); //��ȡ����ʼ������
	
	if (userName == "" | passWord == "")
	{
		qDebug() << "You can't register empty account!";
		return;
	}

	QSqlQuery query;
	query.exec("select * from user");
	while (query.next())
	{
		if (query.value(0) == userName)
		{
			qDebug() << "The user has existed!";
			return;
		}
	}

	//��imagedb��user���д������û�
	query.prepare("insert into user values (?,?)");
	query.addBindValue(userName);
	query.addBindValue(passWord);
	query.exec();

	//on_cancel_clicked(); //���ص�¼����

	qDebug() << "Register successfully~";
}

void RegisterWidget::on_cancel_clicked()
{
	this->close();
	LoginWidget* loginWidget = new LoginWidget;
	loginWidget->show();
}   