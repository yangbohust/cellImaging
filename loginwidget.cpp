#include "loginwidget.h"
#include "registerwidget.h"
#include <QDebug>
#include <QMessageBox>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_login_clicked())); //��½��ť
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_register_clicked())); //ע�ᰴť
}

LoginWidget::~LoginWidget()
{
}

void LoginWidget::on_login_clicked()
{
	//��ȡ�������û���
	QString userName = ui.lineEdit->text();
	//��ȡ����������
	QString passWord = ui.lineEdit_2->text();

	QSqlQuery query;
	query.exec("select * from user");
	while (query.next()){
		if (query.value(0) == userName && query.value(1)==passWord)
		{
			this->close();
			mainWidget = new MainWidget;
			mainWidget->show();
			return;
		}		
	}
	qDebug() << "Username or password is error!";
}

void LoginWidget::on_register_clicked()
{
	this->close();
	RegisterWidget* registerWidget = new RegisterWidget;
	registerWidget->show();
}
