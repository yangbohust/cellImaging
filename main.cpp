#include "mainwidget.h"
#include "loginwidget.h"
#include <QtWidgets/QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	////�������ݿ�
	//if (!createConnection())
	//	return 1;

	////������������
	//LoginWidget login;
	//login.show();

	MainWidget mainWidget;
	mainWidget.show();

	return a.exec();
}


