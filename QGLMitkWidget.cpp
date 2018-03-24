#include "QGLMitkWidget.h"
#include "mitkImageScene.h"
#include "mitkPerformanceCounter.h"
#include <QMouseEvent>
#include <QWheelEvent>

class QGLMitkWidget::_MitkSceneContainer : public mitkSceneContainer
{
public:
	MITK_TYPE(_MitkSceneContainer, mitkSceneContainer)
		_MitkSceneContainer(QGLMitkWidget *widget)
	{
		//������Widget����ϵ
		m_widget = widget;
	}

	virtual void *GetWindowId()
	{
		return (void*)m_widget->winId();
	}

	virtual const int * GetSize()
	{
		//��QT�Ľӿ�ȡ�ÿؼ��Ĵ�С
		QSize size = m_widget->size();
		static int _size[2];
		_size[0] = size.width();
		_size[1] = size.height();
		return _size;
	}

	virtual int GetWidth()
	{
		QSize size = m_widget->size();
		return size.width();
	}

	virtual int GetHeight()
	{
		QSize size = m_widget->size();
		return size.height();
	}

	virtual void Update()
	{
		//������ָ��ݸ�widget
		m_widget->update();
	}

	virtual void MakeCurrent()
	{
		//��makeCurrentָ��ݸ�widget
		m_widget->makeCurrent();
	}

	virtual void SwapBuffers()
	{
		//��swapBuffersָ��ݸ�widget
		m_widget->swapBuffers();
	}

	virtual void MoveMouseTo(int, int)
	{

	}

protected:
	virtual ~_MitkSceneContainer(){}

private:
	QGLMitkWidget *m_widget;
};

//���¼���ĳ������г�ʼ��
void QGLMitkWidget::_initScene()
{
	if (m_MitkScene) //m_MitkScene
	{
		m_MitkScene->AddReference();
		makeCurrent();
		//��ԭ��һ��Scene������״̬����
		glPopAttrib();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		m_MitkScene->InitGL();
		m_MitkScene->ResizeGL(width(), height());
	}
}

//�Լ����Ƴ��ĳ������д���
void QGLMitkWidget::_removeScene()
{
	if (m_MitkScene)
	{
		makeCurrent();
		m_MitkScene->DestroyGL();
		m_MitkScene->RemoveReference();
	}
}

QGLMitkWidget::QGLMitkWidget(QWidget *parent) :QGLWidget(parent)
{
	makeCurrent();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	//��������������
	m_SceneContainer = new _MitkSceneContainer(this);
	m_MitkScene = NULL;

	//������ϳ�������ʱ��Ȼ����Ӧ
	this->setMouseTracking(true);
	m_fps = 0.0;
	m_showFrameRate = false;
}

QGLMitkWidget::~QGLMitkWidget()
{
	_removeScene();
	m_SceneContainer->Delete();
}

void QGLMitkWidget::SetMitkScene(mitkSceneBase *scene)
{
	_removeScene();
	m_MitkScene = scene;
	if (m_MitkScene)
		scene->SetContainer(m_SceneContainer);
	_initScene();
}

mitkSceneBase *QGLMitkWidget::GetMitkScene()
{
	return m_MitkScene;
}

mitkScene *QGLMitkWidget::CreateMitkScene()
{
	_removeScene();
	mitkScene *scene;
	m_MitkScene = scene = new mitkScene(m_SceneContainer);
	_initScene();
	return scene;
}

mitkImageScene *QGLMitkWidget::CreateMitkImageScene()
{
	_removeScene();
	mitkImageScene *iscene;
	m_MitkScene = iscene = new mitkImageScene(m_SceneContainer);
	_initScene();
	return iscene;
}

//����Ϣ���ݸ�Scene����
void QGLMitkWidget::initializeGL()
{
	//��ʼ��OpenGL
	if (m_MitkScene)m_MitkScene->InitGL();
}

void QGLMitkWidget::resizeGL(int width, int height)
{
	//�ı䴰�ڴ�С
	if (m_MitkScene) m_MitkScene->ResizeGL(width, height);
}

void QGLMitkWidget::glDraw()
{
	QGLWidget::glDraw();
}

void QGLMitkWidget::paintGL()
{
	if (m_MitkScene)
	{
		double timeBegin = GetTime();
		//����
		m_MitkScene->RenderGL();
		double timeEnd = GetTime();
		m_fps = 1000.0 / (timeEnd - timeBegin);
	}
	//��ʾ֡��
	if (m_showFrameRate)
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		renderText(30, 40, QString::number(m_fps) + "FPS", QFont("Arial", 20));
	}
}

//����ƶ�
void QGLMitkWidget::mouseMoveEvent(QMouseEvent *event)
{
	if (m_MitkScene)
	{
		bool ctrlKey = event->modifiers()&Qt::ControlModifier;
		bool shiftKey = event->modifiers()&Qt::ShiftModifier;
		int x = event->x();
		int y = event->y();
		m_MitkScene->OnMouseMove(ctrlKey, shiftKey, x, y);
	}
	QGLWidget::mousePressEvent(event);
}

//��갴��
void QGLMitkWidget::mousePressEvent(QMouseEvent *event)
{
	if (m_MitkScene)
	{
		bool ctrlKey = event->modifiers()&Qt::ControlModifier;
		bool shiftKey = event->modifiers()&Qt::ShiftModifier;
		int x = event->x();
		int y = event->y();
		switch (event->button())
		{
		case Qt::LeftButton:
			m_MitkScene->OnMouseDown(MITK_LEFTBUTTON, ctrlKey, shiftKey, x, y);
			break;
		case Qt::RightButton:
			m_MitkScene->OnMouseDown(MITK_RIGHTBUTTON, ctrlKey, shiftKey, x, y);
			break;
		case Qt::MidButton:
			m_MitkScene->OnMouseDown(MITK_MIDDLEBUTTON, ctrlKey, shiftKey, x, y);
			break;
		default:
			break;
		}
	}
	QGLWidget::mousePressEvent(event);
}

//����
void QGLMitkWidget::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_MitkScene)
	{
		bool ctrlKey = event->modifiers()&Qt::ControlModifier;
		bool shiftKey = event->modifiers()&Qt::ShiftModifier;
		int x = event->x();
		int y = event->y();
		switch (event->button())
		{
		case Qt::LeftButton:
			m_MitkScene->OnMouseDown(MITK_LEFTBUTTON, ctrlKey, shiftKey, x, y);
			break;
		case Qt::RightButton:
			m_MitkScene->OnMouseDown(MITK_RIGHTBUTTON, ctrlKey, shiftKey, x, y);
			break;
		case Qt::MidButton:
			m_MitkScene->OnMouseDown(MITK_MIDDLEBUTTON, ctrlKey, shiftKey, x, y);
			break;
		default:
			return;
		}
	}
	QGLWidget::mouseReleaseEvent(event);
}

void QGLMitkWidget::wheelEvent(QWheelEvent *event)
{
	if (m_MitkScene)
	{
		bool ctrlKey = event->modifiers()&Qt::ControlModifier;
		bool shiftKey = event->modifiers()&Qt::ShiftModifier;
		int x = event->x();
		int y = event->y();
		int delta = event->delta();
		m_MitkScene->OnMouseWheel(ctrlKey, shiftKey, x, y, delta);
	}
	QGLWidget::wheelEvent(event);
}


