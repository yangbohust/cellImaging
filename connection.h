#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
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