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

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_login_clicked())); //登陆按钮
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_register_clicked())); //注册按钮
}

LoginWidget::~LoginWidget()
{
}

void LoginWidget::on_login_clicked()
{
	//获取并设置用户名
	QString userName = ui.lineEdit->text();
	//获取并设置密码
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
