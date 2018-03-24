#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwidget.h"
#include "toponebottomthree.h"
#include "leftthreerightone.h"
#include "toptwobottomtwo.h"
#include "onewidget.h"
#include "onewidgetthreedimensional.h"
#include "grubcuts.h"
#include "inputwidget.h"
#include "newmachinewidget.h"
#include "newexperimentwidget.h"
#include "outputwidget.h"

class mitkScence;
class mitkSurfaceModel;

class MainWidget : public QMainWindow
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);
	~MainWidget();

private:
	Ui::MainWidgetClass ui;

	TopOneBottomThree * topOneBottomThree;
	LeftThreeRightOne * leftThreeRightOne;
	TopTwoBottomTwo * topTwoBottomTwo;
	OneWidget * oneWidget;
	OneWidgetThreeDimensional * oneWidgetThreeDimensional;
	GrubCuts gc;

	mitkScene *m_scene;
	mitkSurfaceModel *m_model;

public slots:
    void on_segmentation1_triggered();
	void on_segmentation2_triggered();
	void on_segmentation3_triggered();

	void on_left3right1_triggered();
	void on_top1bottom3_triggered();
	void on_top2bottom2_triggered();
	void on_twoDimentional_triggered();
	void on_threeDimentional_triggered();

	void on_marchingCubes_triggered();
	void on_volumeRender1_triggered();
	void on_volumeRender2_triggered();

	void on_open_triggered();
	void on_newMachine_triggered();
	void on_newExperiment_triggered();
	void on_output_triggered();
	void on_open_clicked();
	void on_leftRotate_clicked();
	void on_vertical_clicked();
	void on_rightRotate_clicked();

};

#endif // MAINWIDGET_H
