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

	//����MITK����
	void SetMitkScene(mitkSceneBase *scene); 
	//ȡ�õ�ǰ�ڲ���MITK����
	mitkSceneBase* GetMitkScene(); 
	//���ڲ�����һ����׼��mitkScene
	mitkScene* CreateMitkScene();
	//���ڲ�����һ����׼��mitkImageScene
	mitkImageScene* CreateMitkImageScene();
	//��ʾ֡�ʿ���
	void ShowFrameRate(bool show = true){ m_showFrameRate = show; }

protected:
	//��Ϣ��Ӧ
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
	//����������������Ϊwidget��һ����Ա�������̳�
	class _MitkSceneContainer;
	_MitkSceneContainer *m_SceneContainer;
	//�ڲ��ĳ���
	mitkSceneBase *m_MitkScene;
	//��ǰ��ʾ֡�ʵ�״̬
	bool m_showFrameRate;
	double m_fps;
};

#endif // QGLMITKWIDGET_H
