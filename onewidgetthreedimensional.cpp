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

//Bug���޷���ʾ�κ�ͼ��
void OneWidgetThreeDimensional::showImage3D(mitkVolume* aVolume)
{
	//����Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//����Image Model
	m_surfaceModel = new mitkSurfaceModel;
	m_scene->AddModel(m_surfaceModel);

	double minV, maxV;
	aVolume->GetMinMaxValue(minV, maxV);
	//ȡ����ֵ
	//double thresh = QInputDialog::getDouble(this, "Marching Cubes", "Input Threshold:");
	//�����ؽ�	
	mitkMarchingCubes *mc = new mitkMarchingCubes;
	mc->SetInput(aVolume);
	//mc->SetThreshold(thresh, maxV);
	mc->SetThreshold(0.5, maxV);
	mc->Run();

	//Ϊģ����������
	m_surfaceModel->SetData(mc->GetOutput());
	m_scene->Update();

	m_scene->Delete();
}

//Bug��������ֵ֮��ͻ��ڴ汨��
void OneWidgetThreeDimensional::showImage3D_marchingCubes(mitkVolume* aVolume)
{	
	//����Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//����Image Model
	m_surfaceModel = new mitkSurfaceModel;
	m_scene->AddModel(m_surfaceModel);
	
	double minV, maxV;
	aVolume->GetMinMaxValue(minV, maxV);
	//ȡ�õ�ֵ����ֵ
	double thresh = QInputDialog::getDouble(this,"Marching Cubes","Input Threshold:");
	//�����ؽ�
	mitkMarchingCubes *mc = new mitkMarchingCubes;
	mc->SetInput(aVolume);
	//mc->SetThreshold(thresh,maxV);
	mc->SetThreshold(65535.888, maxV);
	mc->Run();
	
	//Ϊģ����������
	m_surfaceModel->SetData(mc->GetOutput());	
	m_scene->Update();
	
	m_scene->Delete();	
}

//Bug���ڴ������ַ���ʳ�ͻ
void OneWidgetThreeDimensional::showImage3D_volumeRender1(mitkVolume* aVolume)
{
	//����Image Scene
	m_scene = ui.threeDimensionalViewer->CreateMitkScene();
	//����Image Model
	m_volumeModel = new mitkVolumeModel;
	m_scene->AddModel(m_volumeModel);

	//Ϊģ����������
	m_volumeModel->SetData(aVolume);
	m_scene->Update();
	
	//���ô��ݺ���
	mitkVolumeProperty * prop = m_volumeModel->GetProperty();
	mitkTransferFunction1D * sotf = prop->GetScalarOpacity();
	sotf->SetMax(255, 0.2f);
	sotf->AddPoint(50, 0.0f);

	mitkColorTransferFunction * sctf = prop->GetScalarColor();
	sctf->SetMax(255, 1.0f, 1.0f, 1.0f);
}

//Bug:SetMitkScene()����
void OneWidgetThreeDimensional::showImage3D_volumeRender2(mitkICVolume* aVolume){
	m_sceneG = new mitkGLSLMIPVRScene;
	ui.threeDimensionalViewer->SetMitkScene(m_scene);
	m_sceneG->SetData(aVolume);
}
