#include "onewidgetthreedimensional.h"
#include <QInputDialog>

OneWidgetThreeDimensional::OneWidgetThreeDimensional(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

OneWidgetThreeDimensional::~OneWidgetThreeDimensional()
{
}

//Bug：无法显示任何图像
void OneWidgetThreeDimensional::showImage3D(mitkVolume* aVolume)
{
	//创建Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//加入Image Model
	m_surfaceModel = new mitkSurfaceModel;
	m_scene->AddModel(m_surfaceModel);

	double minV, maxV;
	aVolume->GetMinMaxValue(minV, maxV);
	//取得阈值
	//double thresh = QInputDialog::getDouble(this, "Marching Cubes", "Input Threshold:");
	//表面重建	
	mitkMarchingCubes *mc = new mitkMarchingCubes;
	mc->SetInput(aVolume);
	//mc->SetThreshold(thresh, maxV);
	mc->SetThreshold(0.5, maxV);
	mc->Run();

	//为模型设置数据
	m_surfaceModel->SetData(mc->GetOutput());
	m_scene->Update();

	m_scene->Delete();
}

//Bug：设置阈值之后就会内存报错
void OneWidgetThreeDimensional::showImage3D_marchingCubes(mitkVolume* aVolume)
{	
	//创建Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//加入Image Model
	m_surfaceModel = new mitkSurfaceModel;
	m_scene->AddModel(m_surfaceModel);
	
	double minV, maxV;
	aVolume->GetMinMaxValue(minV, maxV);
	//取得等值面阈值
	double thresh = QInputDialog::getDouble(this,"Marching Cubes","Input Threshold:");
	//表面重建
	mitkMarchingCubes *mc = new mitkMarchingCubes;
	mc->SetInput(aVolume);
	//mc->SetThreshold(thresh,maxV);
	mc->SetThreshold(65535.888, maxV);
	mc->Run();
	
	//为模型设置数据
	m_surfaceModel->SetData(mc->GetOutput());	
	m_scene->Update();
	
	m_scene->Delete();	
}

//Bug：内存出错，地址访问冲突
void OneWidgetThreeDimensional::showImage3D_volumeRender1(mitkVolume* aVolume)
{
	//创建Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//加入Image Model
	m_volumeModel = new mitkVolumeModel;
	m_scene->AddModel(m_volumeModel);

	//为模型设置数据
	m_volumeModel->SetData(aVolume);
	m_scene->Update();
	
	//设置传递函数
	mitkVolumeProperty * prop = m_volumeModel->GetProperty();
	mitkTransferFunction1D * sotf = prop->GetScalarOpacity();
	sotf->SetMax(255, 0.2f);
	sotf->AddPoint(50, 0.0f);

	mitkColorTransferFunction * sctf = prop->GetScalarColor();
	sctf->SetMax(255, 1.0f, 1.0f, 1.0f);
}

//Bug:SetMitkScene()出错
void OneWidgetThreeDimensional::showImage3D_volumeRender2(mitkICVolume* aVolume){
	m_sceneG = new mitkGLSLMIPVRScene;
	ui.threeDimensionalViewer->SetMitkScene(m_scene);
	m_sceneG->SetData(aVolume);
}
