#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
	//创建数据库连接
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //加载数据库驱动
	db.setHostName("localhost"); //设置主机名
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("123456");

	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return false;
	}
	else
		return true;
}