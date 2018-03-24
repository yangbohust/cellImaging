#ifndef TOPONEBOTTOMTHREE_H
#define TOPONEBOTTOMTHREE_H

#include <QWidget>
#include "ui_toponebottomthree.h"

#include <mitkVolume.h>
#include <mitkOoCVolume.h>

class mitkScene;
class mitkSurfaceModel;

class TopOneBottomThree : public QWidget
{
	Q_OBJECT

public:
	TopOneBottomThree(QWidget *parent = 0);
	~TopOneBottomThree();

private:
	Ui::TopOneBottomThree ui;

};

#endif // TOPONEBOTTOMTHREE_H
