#include "grubcuts.h"

/*����ı�����ֵ*/
void GrubCuts::reset()
{
	if (!mask.empty())
		mask.setTo(Scalar::all(GC_BGD));
	bgdPxls.clear(); fgdPxls.clear();
	prBgdPxls.clear();  prFgdPxls.clear();

	isInitialized = false;
	rectState = NOT_SET;    //NOT_SET == 0  
	lblsState = NOT_SET;
	prLblsState = NOT_SET;
	iterCount = 0;
}

/*����ĳ�Ա������ֵ*/
void GrubCuts::setImageAndWinName(const Mat& _image, const string& _winName)
{
	if (_image.empty() || _winName.empty())
		return;
	image = &_image;
	winName = &_winName;
	mask.create(image->size(), CV_8UC1);
	reset();
}

/*��ʾ4���㣬һ�����κ�ͼ�����ݣ���Ϊ����Ĳ���ܶ�ط���Ҫ�õ�������������Ե����ó���*/
void GrubCuts::showImage() const
{
	if (image->empty() || winName->empty())
		return;

	Mat res;
	Mat binMask;
	if (!isInitialized)
		image->copyTo(res);
	else
	{
		getBinMask(mask, binMask);
		image->copyTo(res, binMask);  //�������λ��0����1�����ƣ�ֻ������ǰ���йص�ͼ�񣬱���˵���ܵ�ǰ�������ܵı���  
	}

	vector<Point>::const_iterator it;
	/*����4������ǽ�ѡ�е�4�����ò�ͬ����ɫ��ʾ����*/
	for (it = bgdPxls.begin(); it != bgdPxls.end(); ++it)  //���������Կ�����һ��ָ��  
		circle(res, *it, radius, BLUE, thickness);
	for (it = fgdPxls.begin(); it != fgdPxls.end(); ++it)  //ȷ����ǰ���ú�ɫ��ʾ  
		circle(res, *it, radius, RED, thickness);
	for (it = prBgdPxls.begin(); it != prBgdPxls.end(); ++it)
		circle(res, *it, radius, LIGHTBLUE, thickness);
	for (it = prFgdPxls.begin(); it != prFgdPxls.end(); ++it)
		circle(res, *it, radius, PINK, thickness);

	/*������*/
	if (rectState == IN_PROCESS || rectState == SET)
		rectangle(res, Point(rect.x, rect.y), Point(rect.x + rect.width, rect.y + rect.height), GREEN, 2);

	imshow(*winName, res);
}

/*�ò�����ɺ�maskͼ����rect�ڲ���3������ȫ��0*/
void GrubCuts::setRectInMask()
{
	assert(!mask.empty());
	mask.setTo(GC_BGD);   //GC_BGD == 0  
	rect.x = max(0, rect.x);
	rect.y = max(0, rect.y);
	rect.width = min(rect.width, image->cols - rect.x);
	rect.height = min(rect.height, image->rows - rect.y);
	(mask(rect)).setTo(Scalar(GC_PR_FGD));    //GC_PR_FGD == 3�������ڲ�,Ϊ���ܵ�ǰ����  
}

void GrubCuts::setLblsInMask(int flags, Point p, bool isPr)
{
	vector<Point> *bpxls, *fpxls;
	uchar bvalue, fvalue;
	if (!isPr) //ȷ���ĵ�  
	{
		bpxls = &bgdPxls;
		fpxls = &fgdPxls;
		bvalue = GC_BGD;    //0  
		fvalue = GC_FGD;    //1  
	}
	else    //���ʵ�  
	{
		bpxls = &prBgdPxls;
		fpxls = &prFgdPxls;
		bvalue = GC_PR_BGD; //2  
		fvalue = GC_PR_FGD; //3  
	}
	if (flags & BGD_KEY)
	{
		bpxls->push_back(p);
		circle(mask, p, radius, bvalue, thickness);   //�õ㴦Ϊ2  
	}
	if (flags & FGD_KEY)
	{
		fpxls->push_back(p);
		circle(mask, p, radius, fvalue, thickness);   //�õ㴦Ϊ3  
	}
}

/*�����Ӧ����������flagsΪCV_EVENT_FLAG�����*/
void GrubCuts::mouseClick(int event, int x, int y, int flags, void*)
{
	// TODO add bad args check  
	switch (event)
	{
	case CV_EVENT_LBUTTONDOWN: // set rect or GC_BGD(GC_FGD) labels  
	{
		bool isb = (flags & BGD_KEY) != 0,
			isf = (flags & FGD_KEY) != 0;
		if (rectState == NOT_SET && !isb && !isf)//ֻ���������ʱ  
		{
			rectState = IN_PROCESS; //��ʾ���ڻ�����  
			rect = Rect(x, y, 1, 1);
		}
		if ((isb || isf) && rectState == SET) //������alt������shift�����һ����˾��Σ���ʾ���ڻ�ǰ��������  
			lblsState = IN_PROCESS;
	}
	break;
	case CV_EVENT_RBUTTONDOWN: // set GC_PR_BGD(GC_PR_FGD) labels  
	{
		bool isb = (flags & BGD_KEY) != 0,
			isf = (flags & FGD_KEY) != 0;
		if ((isb || isf) && rectState == SET) //���ڻ����ܵ�ǰ��������  
			prLblsState = IN_PROCESS;
	}
	break;
	case CV_EVENT_LBUTTONUP:
		if (rectState == IN_PROCESS)
		{
			rect = Rect(Point(rect.x, rect.y), Point(x, y));   //���ν���  
			rectState = SET;
			setRectInMask();
			assert(bgdPxls.empty() && fgdPxls.empty() && prBgdPxls.empty() && prFgdPxls.empty());
			showImage();
		}
		if (lblsState == IN_PROCESS)   //�ѻ���ǰ�󾰵�  
		{
			setLblsInMask(flags, Point(x, y), false);    //����ǰ����  
			lblsState = SET;
			showImage();
		}
		break;
	case CV_EVENT_RBUTTONUP:
		if (prLblsState == IN_PROCESS)
		{
			setLblsInMask(flags, Point(x, y), true); //����������  
			prLblsState = SET;
			showImage();
		}
		break;
	case CV_EVENT_MOUSEMOVE:
		if (rectState == IN_PROCESS)
		{
			rect = Rect(Point(rect.x, rect.y), Point(x, y));
			assert(bgdPxls.empty() && fgdPxls.empty() && prBgdPxls.empty() && prFgdPxls.empty());
			showImage();    //���ϵ���ʾͼƬ  
		}
		else if (lblsState == IN_PROCESS)
		{
			setLblsInMask(flags, Point(x, y), false);
			showImage();
		}
		else if (prLblsState == IN_PROCESS)
		{
			setLblsInMask(flags, Point(x, y), true);
			showImage();
		}
		break;
	}
}

/*�ú�������grabcut�㷨�����ҷ����㷨���е����Ĵ���*/
int GrubCuts::nextIter()
{
	if (isInitialized)
		//ʹ��grab�㷨����һ�ε���������2Ϊmask��������maskλ�ǣ������ڲ�������Щ�����Ǳ��������Ѿ�ȷ���Ǳ���������еĵ㣬��maskͬʱҲΪ���  
		//������Ƿָ���ǰ��ͼ��  
		grabCut(*image, mask, rect, bgdModel, fgdModel, 1);
	else
	{
		if (rectState != SET)
			return iterCount;

		if (lblsState == SET || prLblsState == SET)
			grabCut(*image, mask, rect, bgdModel, fgdModel, 1, GC_INIT_WITH_MASK);
		else
			grabCut(*image, mask, rect, bgdModel, fgdModel, 1, GC_INIT_WITH_RECT);

		isInitialized = true;
	}
	iterCount++;

	bgdPxls.clear(); fgdPxls.clear();
	prBgdPxls.clear(); prFgdPxls.clear();

	return iterCount;
}

