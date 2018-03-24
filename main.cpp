#include "mainwidget.h"
#include "loginwidget.h"
#include <QtWidgets/QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	////连接数据库
	//if (!createConnection())
	//	return 1;

	////设置启动界面
	//LoginWidget login;
	//login.show();

	MainWidget mainWidget;
	mainWidget.show();

	return a.exec();
}


