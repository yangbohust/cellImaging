#pragma once

#include <QWidget>
#include "ui_onewidgetthreedimensional.h"

#include "mitkScene.h"
#include "mitkVolumeModel.h"
#include "mitkSurfaceModel.h"
#include "mitkMarchingCubes.h"
#include "mitkGLSLMIPVRScene.h"
#include "mitkVolumeRendererShearWarp.h"

class OneWidgetThreeDimensional : public QWidget
{
	Q_OBJECT

public:
	OneWidgetThreeDimensional(QWidget *parent = Q_NULLPTR);
	~OneWidgetThreeDimensional();

	void showImage3D(mitkVolume* aVolume); //���ڷָ�������ʾ
	void showImage3D_marchingCubes(mitkVolume* aVolume); //�����
	void showImage3D_volumeRender1(mitkVolume* aVolume); //�����1
	void showImage3D_volumeRender2(mitkICVolume* aVolume); //�����2

private:
	Ui::OneWidgetThreeDimensional ui;

	mitkScene * m_scene;
	mitkGLSLMIPVRScene *m_sceneG;
	mitkSurfaceModel * m_surfaceModel;
	mitkVolumeModel * m_volumeModel;
};
