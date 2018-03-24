#include "toponebottomthree.h"

#include <mitkBinMarchingCubes.h> 
#include "mitkScene.h"
#include "mitkSurfaceModel.h"
#include "mitkMarchingCubes.h"

TopOneBottomThree::TopOneBottomThree(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

TopOneBottomThree::~TopOneBottomThree()
{

}
