/*=========================================================================

  Program:   Medical Imaging Toolkit
  Date:      $Date: 2008-09-01 20:13:46 +0800 $
  Version:   $Version: 2.00 $
  Copyright: AI Lab, Institute of Automation, Chinese Academy of Sciences
  Last Modified by Xiang Dehui ,2008-7-25

=========================================================================*/
#ifndef __mitkVolumeShearFunction_h
#define __mitkVolumeShearFunction_h

#include "mitkObject.h"
#include "mitkGlobalRegistration2Framework.h"

#define SHEAR_FORWARD 0
#define SHEAR_BACKWARD 1

#define SHEAR_SLICEX 0
#define SHEAR_SLICEY 1
#define SHEAR_SLICEZ 2

#define SHEAR_OPACITY 0.98
#define SHEAR_ZERO 0.000001f

// Macro for absolute x
#define mitkAbsMacro(x)     (((x) > 0.0)?(x):(-(x)))
#define mitkFloorMacro(x)   (((x) < 0.0)?((int)((x)-1.0)):((int)(x)))
#define mitkCeilingMacro(x)   (((x) < 0.0)?((int)(x)):((int)((x)+1.0)))
#define mitkRoundMacro(x)   (((x) < 0.0)?((int)((x)-0.5)):((int)((x)+0.5)))

class mitkMatrix;
class mitkView;
class mitkVolumeModel;

struct mitkShear
{
//	float m_Color[4];

	//volume information
	int   m_ScalarDataType;
	void  *m_ScalarDataPointer;
	int   m_DataIncrement[3];
	int   m_DataSize[3];
	float m_DataSpacing[3];	
	
	//Shading
	int            m_Shading;	
	float          *m_RedDiffuseShadingTable;
	float          *m_GreenDiffuseShadingTable;
	float          *m_BlueDiffuseShadingTable;
	float          *m_RedSpecularShadingTable;
	float          *m_GreenSpecularShadingTable;
	float          *m_BlueSpecularShadingTable;		
	unsigned short *m_EncodedNormals;
	unsigned char  *m_GradientMagnitudes;	

	//Transfer Function
	int   m_TF_Dimension;
	int   m_TF_ScalarOpacityMaxX;
	int   m_TF_ScalarOpacityMaxY;	
	float *m_TF_ScalarOpacity;
	float *m_TF_GradientOpacity;
	float *m_TF_ScalarColorRed;
	float *m_TF_ScalarColorGreen;
	float *m_TF_ScalarColorBlue;
	float *m_TF_ScalarGradientMagnitudesOpacity; 

	//transformation matrix
    mitkMatrix *m_ShearMatrix;
	mitkMatrix *m_ShearOnlyMatrix;
	float m_Sx;
	float m_Sy;
	float m_Sz;

	// classification and interpolation information
	int   m_InterpolationType;		
	int   m_ClassificationMethod;

	//Integral, MIP and X-Ray option information
	int m_Mode;
	enum
	{
		INTEGRAL,
		MOP
	};
	
	// image related information
	int           *m_GridOrigin;
	int           *m_GridSize;
	int           *m_ImageSize;
	int           *m_ImageMemorySize;
	float         *m_CompositeBuffer;

	// shear order
	int m_SliceOrder;
	int m_XOrder;
	int m_YOrder;
	int m_ZOrder;

	//crop and clip information
    int   *m_CropBounds;
	float *m_ClipInformation;
    int   m_ClipCount;
	bool  m_NeedVoxelCull;

	//view and model information
	mitkView        *m_View;
	mitkVolumeModel *m_Vol;

	//Grid/Image sample distance
	float m_ImageSampleDistance;

};


/// mitkVolumeShearFunction - abstract class defines interface for volume shear
///////////////////////////////////////////////////////////////////////////
/// mitkVolumeShearFunction is an abstract class that defines interface for 
/// both parallel and perspective shear. The mitkVolumeRendererShearWarp class 
/// provides common information for shear, and then calls "Shear()" to implement
/// volume shear progress concretely.
class MITK_REGISTRATION2_API mitkVolumeShearFunction : public mitkObject
{
public:
	MITK_TYPE(mitkVolumeShearFunction, mitkObject)

	virtual void PrintSelf(ostream &os);

	///////////////////////////////////////////////////////////////////////
	/// The default constructor.
	///////////////////////////////////////////////////////////////////////
	mitkVolumeShearFunction();

	//////////////////////////////////////////////////////////////////////////
	/// Get the projection status of the class.
    /// \return 
	/// Return true, means that this class is used for parallel splatting.
	/// Return false, means that this class is used for perspective splatting.
	/// \note All of its subclasses must implement this virtual to indicate 
	/// its status.
	//////////////////////////////////////////////////////////////////////////
	virtual bool IsParallel(){ return true; }

	//////////////////////////////////////////////////////////////////////////
	/// The real function to splat the volume.
	/// \note All of its subclasses must implement this pure virtual to splat
	/// the volume.
	//////////////////////////////////////////////////////////////////////////
	virtual void Shear(mitkShear *shearInform) = 0;

protected:
	virtual ~mitkVolumeShearFunction();

private:
	mitkVolumeShearFunction(const mitkVolumeShearFunction&);
	void operator = (const mitkVolumeShearFunction&);

};

#endif