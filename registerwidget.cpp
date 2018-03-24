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

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_ok_clicked())); //成功注册按钮
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_cancel_clicked())); //取消注册按钮
}

RegisterWidget::~RegisterWidget()
{
}

void RegisterWidget::on_ok_clicked()
{
	QString userName = ui.lineEdit->text(); //获取并初始化用户名
	QString passWord = ui.lineEdit_2->text(); //获取并初始化密码
	
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

	//在imagedb的user表中创建新用户
	query.prepare("insert into user values (?,?)");
	query.addBindValue(userName);
	query.addBindValue(passWord);
	query.exec();

	//on_cancel_clicked(); //返回登录界面

	qDebug() << "Register successfully~";
}

void RegisterWidget::on_cancel_clicked()
{
	this->close();
	LoginWidget* loginWidget = new LoginWidget;
	loginWidget->show();
}   