#ifndef QGLMITKWIDGET_H
#define QGLMITKWIDGET_H

#include <QGLWidget>

class mitkSceneBase;
class mitkScene;
class mitkImageScene;

class QGLMitkWidget : public QGLWidget
{
	Q_OBJECT

public:
	QGLMitkWidget(QWidget *parent);
	virtual ~QGLMitkWidget();

	//传入MITK场景
	void SetMitkScene(mitkSceneBase *scene); 
	//取得当前内部的MITK场景
	mitkSceneBase* GetMitkScene(); 
	//在内部创建一个标准的mitkScene
	mitkScene* CreateMitkScene();
	//在内部创建一个标准的mitkImageScene
	mitkImageScene* CreateMitkImageScene();
	//显示帧率开关
	void ShowFrameRate(bool show = true){ m_showFrameRate = show; }

protected:
	//消息响应
	virtual void initializeGL();
	virtual void resizeGL(int width, int height);
	virtual void glDraw();
	virtual void paintGL();
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void wheelEvent(QWheelEvent *event);

private:
	void _initScene();
	void _removeScene();
	//真正的容器，声明为widget的一个成员，避免多继承
	class _MitkSceneContainer;
	_MitkSceneContainer *m_SceneContainer;
	//内部的场景
	mitkSceneBase *m_MitkScene;
	//当前显示帧率的状态
	bool m_showFrameRate;
	double m_fps;
};

#endif // QGLMITKWIDGET_H
