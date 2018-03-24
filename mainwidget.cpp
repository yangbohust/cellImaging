#include "mainwidget.h"
#include "QDebug"
#include <QMessageBox>
#include <QStackedWidget>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "mitkobject.h"
#include <mitkVolume.h>
#include <mitkOoCVolume.h>
#include <mitkRawReader.h>
#include <mitkRawWriter.h> //raw���������
#include "mitkRegionGrowImageFilter.h" //���������㷨��ͷ�ļ�



#include"mitkScene.h"
#include"mitkSurfaceModel.h"
#include"mitkMarchingCubes.h"
#include"mitkRawReader.h"
#include<QFileDialog>
#include<QString>
#include<QInputDialog>
#include<mitkICVolume.h>
#include<mitkOoCVolume.h>
#include <mitkOoCTriangleMesh.h> 
#include <mitkBinMarchingCubes.h> 
#include <mitkMeshViewManipulatorStandard.h> 
#include <mitkLineWidgetModel3D.h> 

using namespace cv;
using namespace std;

MainWidget::MainWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QHBoxLayout * mainLayout = new QHBoxLayout(this); //ˮƽ����
	mainLayout->addWidget(ui.tabWidget);
	//mainLayout->addWidget(ui.stackedWidget); 

	topOneBottomThree = new TopOneBottomThree();
	oneWidget = new OneWidget();
	oneWidgetThreeDimensional = new OneWidgetThreeDimensional();
	topTwoBottomTwo = new TopTwoBottomTwo();
	leftThreeRightOne = new LeftThreeRightOne();
	ui.stackedWidget->addWidget(topOneBottomThree);	
	ui.stackedWidget->addWidget(oneWidget);	
	ui.stackedWidget->addWidget(oneWidgetThreeDimensional);	
	ui.stackedWidget->addWidget(topTwoBottomTwo);	
	ui.stackedWidget->addWidget(leftThreeRightOne);

	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

	ui.centralWidget->setLayout(mainLayout);

	connect(ui.action_open, SIGNAL(triggered()), this, SLOT(on_open_triggered()));
	connect(ui.action_machine, SIGNAL(triggered()), this, SLOT(on_newMachine_triggered()));
	connect(ui.action_experiment, SIGNAL(triggered()), this, SLOT(on_newExperiment_triggered()));
	connect(ui.action_save, SIGNAL(triggered()), this, SLOT(on_output_triggered()));

	connect(ui.action_8, SIGNAL(triggered()), this, SLOT(on_segmentation1_triggered()));  //�Զ���ֵ�ָ�
	connect(ui.action_9, SIGNAL(triggered()), this, SLOT(on_segmentation2_triggered()));  //GrabCut�ָ�
	connect(ui.action_10, SIGNAL(triggered()), this, SLOT(on_segmentation3_triggered()));  //���������ָ�

	connect(ui.action_15, SIGNAL(triggered()), this, SLOT(on_top2bottom2_triggered()));  
	connect(ui.action_16, SIGNAL(triggered()), this, SLOT(on_top1bottom3_triggered()));
	connect(ui.action_17, SIGNAL(triggered()), this, SLOT(on_left3right1_triggered()));
	connect(ui.actionX_Y, SIGNAL(triggered()), this, SLOT(on_twoDimentional_triggered()));
	connect(ui.actionX_Z, SIGNAL(triggered()), this, SLOT(on_twoDimentional_triggered()));
	connect(ui.actionY_Z, SIGNAL(triggered()), this, SLOT(on_twoDimentional_triggered()));
	connect(ui.action_19, SIGNAL(triggered()), this, SLOT(on_threeDimentional_triggered()));
	connect(ui.action_20, SIGNAL(triggered()), this, SLOT(on_threeDimentional_triggered()));

	connect(ui.action_0, SIGNAL(triggered()), this, SLOT(on_marchingCubes_triggered())); //�����ؽ�
	connect(ui.action_3, SIGNAL(triggered()), this, SLOT(on_volumeRender1_triggered()));
	connect(ui.action_5, SIGNAL(triggered()), this, SLOT(on_volumeRender2_triggered()));

	m_scene = ui.showwidget->CreateMitkScene();

	m_model = new mitkSurfaceModel;

	m_scene->AddModel(m_model);


}

MainWidget::~MainWidget()
{

}

void MainWidget::on_open_triggered()
{
	InputWidget * inputWidget = new InputWidget;
	inputWidget->show();
}

void MainWidget::on_newMachine_triggered()
{
	NewMachineWidget * newMachineWiget = new NewMachineWidget;
	newMachineWiget->show();
}

void MainWidget::on_newExperiment_triggered()
{
	NewExperimentWidget * newExperimentWiget = new NewExperimentWidget;
	newExperimentWiget->show();
}

void MainWidget::on_output_triggered()
{
	OutputWidget * outputWidget = new OutputWidget;
	outputWidget->show();
}

void MainWidget::on_left3right1_triggered()
{
	ui.stackedWidget->setCurrentWidget(leftThreeRightOne);
}

void MainWidget::on_top1bottom3_triggered()
{
	ui.stackedWidget->setCurrentWidget(topOneBottomThree);
}

void MainWidget::on_top2bottom2_triggered()
{
	ui.stackedWidget->setCurrentWidget(topTwoBottomTwo);
}
 
void MainWidget::on_twoDimentional_triggered()
{	
	ui.stackedWidget->setCurrentWidget(oneWidget);
}

void MainWidget::on_threeDimentional_triggered(){
	
	ui.stackedWidget->setCurrentWidget(oneWidgetThreeDimensional);
}

//Canny�ָ��㷨����Զ�άͼƬ
void MainWidget::on_segmentation1_triggered()
{
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	query.seek(1); //��λ��¼
	QString path = query.value(2).toString();

	//��QStringת��Ϊchar *
	QByteArray newPath = path.toLatin1();
	const char *filename = newPath.data();

	Mat img = imread(filename, 1);
	Mat grey;
	cvtColor(img, grey, CV_BGR2GRAY);
	Mat edges(img.size(), CV_8U);
	double threshold = 50;

	Canny(img, edges, threshold, threshold * 3, 3);

	on_twoDimentional_triggered();
	oneWidget->showImage(edges);
}

static void on_mouse(int event, int x, int y, int flags, void* param)
{
	GrubCuts gc;
	gc.mouseClick(event, x, y, flags, param);
}

//GrabCut�ָ�
void MainWidget::on_segmentation2_triggered()
{
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	string filename = "2.jpg";
	Mat image = imread(filename, 1);
	if (image.empty())
	{
		cout << "\n Durn, couldn't read image filename " << filename << endl;
	}

	const string winName = "image";
	cvNamedWindow(winName.c_str(), CV_WINDOW_AUTOSIZE);
	cvSetMouseCallback(winName.c_str(), on_mouse, 0);

	gc.setImageAndWinName(image, winName);
	gc.showImage();

	for (;;)
	{
		int c = cvWaitKey(0);
		switch ((char)c)
		{
		case '\x1b':
			cout << "Exiting ..." << endl;
			goto exit_main;
		case 'r':
			cout << endl;
			gc.reset();
			gc.showImage();
			break;
		case 'n':
			int iterCount = gc.getIterCount();
			cout << "<" << iterCount << "... ";
			int newIterCount = gc.nextIter();
			if (newIterCount > iterCount)
			{
				gc.showImage();
				cout << iterCount << ">" << endl;
			}
			else
				cout << "rect must be determined>" << endl;
			break;
		}
	}

exit_main:
	cvDestroyWindow(winName.c_str());
}

//���������ָ�
void MainWidget::on_segmentation3_triggered()
{
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	char OutputFile[] = "G:\\imagedb\\resultRG.raw"; //�洢�ָ�����·���ļ���

	int dataType = MITK_UNSIGNED_SHORT; //ͶӰ���ݵ����ͣ�Ĭ��Ϊ������,����Ϊunsigned short 
	int sliceWidth = 384, sliceHeight = 384, sliceNum = 384, sliceChannelNum = 1;
	float sliceSpacingX = 1, sliceSpacingY = 1, sliceSpacingZ = 1;
	int outWidth = 384, outHeight = 384, outSliceNum = 384;
	
	mitkRawReader * aReader = new mitkRawReader;
	aReader->SetWidth(sliceWidth);
	aReader->SetHeight(sliceHeight);
	aReader->SetImageNum(sliceNum);
	aReader->SetSpacingX(sliceSpacingX); //����X��Y��Z���������ؼ�࣬���ؽ�Ϊ�õ�����Ϣ����ʱ����Ϊ1mm
	aReader->SetSpacingY(sliceSpacingY);
	aReader->SetSpacingZ(sliceSpacingZ);
	aReader->SetChannelNum(sliceChannelNum); //��������ͨ����
	aReader->SetDataType(dataType); //����ͶӰ�������� 

	query.first(); //��λ��¼
	QString path = query.value(2).toString();
	//��QStringת��Ϊchar *
	QByteArray newPath = path.toLatin1();
	const char *filename = newPath.data();

	aReader->AddFileName(filename);

	if (aReader->Run())
	{
		mitkVolume * aVolume = aReader->GetOutput();

		//����ָ��㷨
		mitkRegionGrowImageFilter * filterRG = new mitkRegionGrowImageFilter;
		filterRG->SetInput(aVolume);
		filterRG->SetSeedPoint(2, 3, 4);
		//�������ƶ�����
		filterRG->SetMaxChangeValue(3.9);
		filterRG->SetMaxDifferentValue(2.0);
		//��������ָ����Ĳ���
		mitkVolume * m_RGVolume = filterRG->GetOutput(); //���������ָ��m_RGVolume
		m_RGVolume->SetWidth(outWidth); //���÷ָ���Ŀ��
		m_RGVolume->SetHeight(outHeight); //���÷ָ���ĸ߶�
		m_RGVolume->SetSliceNum(outSliceNum); //���÷ָ�����Ƭ��

		filterRG->Run();
		filterRG->Delete();
	
		on_threeDimentional_triggered();
		oneWidgetThreeDimensional->showImage3D(m_RGVolume);

		//����ָ���
		mitkRawWriter * aWriter = new mitkRawWriter;
		aWriter->SetInput(m_RGVolume);
		aWriter->AddFileName(OutputFile);
		aWriter->Run();
	}

	//�����ݿ��в����¼
	//query.exec("insert into test0(name,filepath,x,y,z,stage,belong) values ('mice','G:\\\imagedb\\\resultRG.raw',384,384,384,'segmentation3','mice')");

	qDebug() << "Segmentation Done!";
}

void MainWidget::on_marchingCubes_triggered(){
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	int dataType = MITK_UNSIGNED_INT;
	int sliceWidth = 384, sliceHeight = 384, sliceNum = 384, sliceChannelNum = 1;
	float sliceSpacingX = 1, sliceSpacingY = 1, sliceSpacingZ = 1;
	int outWidth = 384, outHeight = 384, outSliceNum = 384;

	mitkRawReader * aReader = new mitkRawReader;
	aReader->SetWidth(sliceWidth);
	aReader->SetHeight(sliceHeight);
	aReader->SetImageNum(sliceNum);
	aReader->SetSpacingX(sliceSpacingX); //����X��Y��Z���������ؼ�࣬���ؽ�Ϊ�õ�����Ϣ����ʱ����Ϊ1mm
	aReader->SetSpacingY(sliceSpacingY);
	aReader->SetSpacingZ(sliceSpacingZ);
	aReader->SetChannelNum(sliceChannelNum); //��������ͨ����
	aReader->SetDataType(dataType); //����ͶӰ�������� 

	query.first(); //��λ��¼
	QString path = query.value(2).toString();
	//��QStringת��Ϊchar *
	QByteArray newPath = path.toLatin1();
	const char * filename = newPath.data();

	aReader->AddFileName(filename);

	aReader->Run();
	mitkVolume * aVolume = aReader->GetOutput();
	aReader->Delete();

	on_threeDimentional_triggered();
	oneWidgetThreeDimensional->showImage3D_marchingCubes(aVolume);
}

void MainWidget::on_volumeRender1_triggered(){
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	int dataType = MITK_UNSIGNED_SHORT; //ͶӰ���ݵ����ͣ�Ĭ��Ϊ������,����Ϊunsigned short 
	int sliceWidth = 384, sliceHeight = 384, sliceNum = 384, sliceChannelNum = 1;
	float sliceSpacingX = 1, sliceSpacingY = 1, sliceSpacingZ = 1;
	int outWidth = 384, outHeight = 384, outSliceNum = 384;

	mitkRawReader * aReader = new mitkRawReader;
	aReader->SetWidth(sliceWidth);
	aReader->SetHeight(sliceHeight);
	aReader->SetImageNum(sliceNum);
	aReader->SetSpacingX(sliceSpacingX); //����X��Y��Z���������ؼ�࣬���ؽ�Ϊ�õ�����Ϣ����ʱ����Ϊ1mm
	aReader->SetSpacingY(sliceSpacingY);
	aReader->SetSpacingZ(sliceSpacingZ);
	aReader->SetChannelNum(sliceChannelNum); //��������ͨ����
	aReader->SetDataType(dataType); //����ͶӰ�������� 

	query.first(); //��λ��¼
	QString path = query.value(2).toString();
	//��QStringת��Ϊchar *
	QByteArray newPath = path.toLatin1();
	const char *filename = newPath.data();

	aReader->AddFileName(filename);
	aReader->Run();

	mitkVolume * aVolume = aReader->GetOutput();

	on_threeDimentional_triggered();
	oneWidgetThreeDimensional->showImage3D_volumeRender1(aVolume);

	aReader->Delete();
}

void MainWidget::on_volumeRender2_triggered(){
	//�������ݿ�����
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //�������ݿ�����
	db.setHostName("localhost"); //����������
	db.setPort(3306);
	db.setDatabaseName("imagedb");
	db.setUserName("root");
	db.setPassword("lan19950725");
	if (!db.open()){
		QMessageBox::critical(0, "Cannot open database.", "Unable to establish a database connection.", QMessageBox::Cancel);
		return;
	}

	QSqlQuery query;
	query.exec("select * from test0");
	while (query.next()){
		qDebug() << query.value(0).toInt()
			<< query.value(1).toString()
			<< query.value(2).toString()
			<< query.value(3).toInt()
			<< query.value(4).toInt()
			<< query.value(5).toInt()
			<< query.value(6).toString()
			<< query.value(7).toString();
	}

	int dataType = MITK_UNSIGNED_SHORT; //ͶӰ���ݵ����ͣ�Ĭ��Ϊ������,����Ϊunsigned short 
	int sliceWidth = 384, sliceHeight = 384, sliceNum = 384, sliceChannelNum = 1;
	float sliceSpacingX = 1, sliceSpacingY = 1, sliceSpacingZ = 1;
	int outWidth = 384, outHeight = 384, outSliceNum = 384;

	mitkRawReader * aReader = new mitkRawReader;
	aReader->SetWidth(sliceWidth);
	aReader->SetHeight(sliceHeight);
	aReader->SetImageNum(sliceNum);
	aReader->SetSpacingX(sliceSpacingX); //����X��Y��Z���������ؼ�࣬���ؽ�Ϊ�õ�����Ϣ����ʱ����Ϊ1mm
	aReader->SetSpacingY(sliceSpacingY);
	aReader->SetSpacingZ(sliceSpacingZ);
	aReader->SetChannelNum(sliceChannelNum); //��������ͨ����
	aReader->SetDataType(dataType); //����ͶӰ�������� 

	query.first(); //��λ��¼
	QString path = query.value(2).toString();
	//��QStringת��Ϊchar *
	QByteArray newPath = path.toLatin1();
	const char *filename = newPath.data();

	aReader->AddFileName(filename);

	if (aReader->Run())
	{
		mitkVolume * aVolume = aReader->GetOutput();
		mitkICVolume * icVolume = mitkICVolume::SafeDownCast(aVolume);

		on_threeDimentional_triggered();
		oneWidgetThreeDimensional->showImage3D_volumeRender2(icVolume);

		aReader->Delete();
	}
}


void MainWidget::on_open_clicked()
{

	char DISK_CACHE_PATH[] = "D:\\Cone Beam CT\\CT Construction\\mice_proj_data_arrangement\\miceproj_temp\\temp1\\";
	char DISK_CACHE_PATH_OUT[] = "D:\\Cone Beam CT\\CT Construction\\mice_proj_data_arrangement\\miceproj_temp\\temp2\\";

	int dataType = MITK_UNSIGNED_CHAR;//�ļ���mice_recon_result_uint8.raw�����ؽ��������������uint8:unsigned char�͵�
	int inchannelNum = 1;
	int inWidth = 384;
	int inHeigth = 384;
	int inSliceNum = 384;
	float sliceSpacingX = 1, sliceSpacingY = 1, sliceSpacingZ = 1;
	//mitkOoCVolume *aVolume = new mitkOoCVolume;
	mitkICVolume *aVolume = new mitkICVolume;
	//aVolume->SetPathOfDiskBuffer(DISK_CACHE_PATH);
	//aVolume->SetBufferedSliceNum(64);
	aVolume->SetWidth(inWidth);
	aVolume->SetHeight(inHeigth);
	aVolume->SetSliceNum(inSliceNum);
	aVolume->SetSpacingX(sliceSpacingX);
	aVolume->SetSpacingY(sliceSpacingY);
	aVolume->SetSpacingZ(sliceSpacingZ);
	aVolume->SetChannelNum(inchannelNum);
	aVolume->SetDataType(dataType);
	if (aVolume->Allocate())
	{
		unsigned char *p = new unsigned char[384 * 384];
		FILE *fid;
		const char *filename = "D:\\Cone Beam CT\\CT Construction\\mice_recon_result_data\\mice_recon_result_uint8_RegionGrow_cut_20_20.raw";
		if ((fid = fopen(filename, "rb")) == NULL)
		{
			printf("can't open file!\n");
		}
		for (int i = 0; i < inSliceNum; i++)
		{
			fread(p, sizeof(unsigned char), inWidth * inHeigth, fid);
			aVolume->WriteSliceData(i, p);
		}
		fclose(fid);
		delete p;
	}
	double minV, maxV;
	aVolume->GetMinMaxValue(minV, maxV);
	double thresh = 100.0;//�����ֵ��ʱû�����ã���

	mitkMarchingCubes *mc = new mitkMarchingCubes;
	//mitkBinMarchingCubes *mc = new mitkBinMarchingCubes;
	mc->SetInput(aVolume);
	mc->SetThreshold(thresh, maxV);
	//m_Mesh = mc->GetOutput();//mc->GetOutput()��mitkMesh*����
	//mc->SetBinData(aVolume);
	mc->Run();
	m_model->SetData(mc->GetOutput());


	float point0[3] = { 0, 0, 0 };
	float point1[3] = { 300, 200, 200 };

	mitkLineWidgetModel3D *lineModel = new mitkLineWidgetModel3D(point0, point1);
	m_scene->AddModel(lineModel);

	m_scene->Update();
}

static int leftRotate=0;
void MainWidget::on_leftRotate_clicked()
{

	if (leftRotate < 0)
		leftRotate = 360;
	leftRotate = leftRotate - 10;
	float rot[3];
	//float ax, ay, az, angle;
	//m_model->GetRotation(ax,ay,az,angle);
	//m_model->SetRotation(ax, ay, az, angle);
	m_model->GetRotation(rot);
	m_model->SetRotation(rot[0], leftRotate, rot[2]);
	m_scene->Update();
}

static int vertical=0;
void MainWidget::on_vertical_clicked()
{
	if (vertical > 360)
		vertical = 0;
	vertical = vertical + 10;
	float rot[3];
	m_model->GetRotation(rot);

	m_model->SetRotation(vertical, rot[1], rot[2]);
	m_scene->Update();
}

static int rightRotate = 0;
void MainWidget::on_rightRotate_clicked()
{

	if (rightRotate >0)
		rightRotate = 0;
	rightRotate = rightRotate - 10;
	float rot[3];
	//float ax, ay, az, angle;
	//m_model->GetRotation(ax,ay,az,angle);
	//m_model->SetRotation(ax, ay, az, angle);
	m_model->GetRotation(rot);
	m_model->SetRotation(rot[0], rightRotate, rot[2]);
	m_scene->Update();

}