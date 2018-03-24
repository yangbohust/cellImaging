/*=========================================================================

  Program:   Medical Imaging Toolkit
  Date:      $Date: 2008-09-01 20:13:46 +0800 $
  Version:   $Version: 1.00 $
  Copyright: AI Lab, Institute of Automation, Chinese Academy of Sciences
  Last Modified by Xiang Dehui ,2008-7-25

=========================================================================*/
#ifndef __mitkVolumeRendererShearWarp_h
#define __mitkVolumeRendererShearWarp_h

#include "mitkVolumeRenderer.h"
#include "mitkVolumeShearFunction.h"
#include "mitkRCPtr.h"
#include "mitkEncodedGradientEstimator.h"
#include "mitkEncodedGradientShader.h"

// Macro for absolute x
//#define mitkAbsMacro(x)     (((x) > 0.0)?(x):(-(x)))
//#define mitkFloorMacro(x)   (((x) < 0.0)?((int)((x)-1.0)):((int)(x)))
//#define mitkCeilingMacro(x)   (((x) < 0.0)?((int)(x)):((int)((x)+1.0)))
//#define mitkRoundMacro(x)   (((x) < 0.0)?((int)((x)-0.5)):((int)((x)+0.5)))

///////////////////////////////////////////////////////////////////////////
class mitkMatrix;
/// mitkVolumeRendererShearWarp - a concrete volume renderer for rendering a volume
///////////////////////////////////////////////////////////////////////////
/// mitkVolumeRendererShearWarp is a concrete volume renderer for rendering a volume
/// using shear-warp technique.
/// \par
/// Our implemented algorithm references to:\n
/// [1]Lacroute P, Levoy M. Fast volume rendering using a shear-warp factorization of the viewing transformation. 
/// Computer Graphics Proceedings, 1994.\n
/// [2]Lacroute P. Fast volume rendering using a shear-warp factorization of the viewing transformation[R].
/// CSL-TR-95- 678,Stanford University,1995.\n
/// \par
/// However, this class just implements brute-force shear-warp algorithm, that is, 
/// it does not use run-length encoding technique as Lacroute. 
/// 
/// Its rendering speed is generally faster than mitkVolumeRendererRayCasting and 
/// mitkVolumeRendererSplatting, and the rendering effect is between them. 
/// 
/// The default perspective shearer is the object of mitkVolumeShearPerspective, 
/// and the default parallel shearer is the object of mitkVolumeShearParallel. 
/// Particular perspective and parallel shearers are also allowed by calling 
/// SetPerspectiveShearer() and SetParallelShearer().
///
/// Two rendering modes are alternative, one is integral mode, and the other
/// is MOP mode, you can switch the mode using SetModeIntegral() and SetModeMop().
class MITK_REGISTRATION2_API mitkVolumeRendererShearWarp : public mitkVolumeRenderer
{
public:
	MITK_TYPE(mitkVolumeRendererShearWarp, mitkVolumeRenderer)

	virtual void PrintSelf(ostream &os);

	mitkVolumeRendererShearWarp();

	///////////////////////////////////////////////////////////////////////////
	/// Internal method. Don't call it directly.
	///////////////////////////////////////////////////////////////////////////
	virtual int Render(mitkView *view, mitkVolumeModel *vol);

	///////////////////////////////////////////////////////////////////////////
	/// Set the gradient estimator used to estimate normals.
	/// \param gradest Represent the gradient estimator used to estimate normals.
	///////////////////////////////////////////////////////////////////////////
	void SetGradientEstimator(mitkEncodedGradientEstimator *gradest)
	{ 
		m_GradientEstimator = gradest; 
	}

	///////////////////////////////////////////////////////////////////////////
	/// Get the gradient estimator used to estimate normals.
	/// \return Return the gradient estimator used to estimate normals.
	///////////////////////////////////////////////////////////////////////////
	mitkEncodedGradientEstimator* GetGradientEstimator(){return m_GradientEstimator;}
	
	///////////////////////////////////////////////////////////////////////////
	/// Get the gradient shader.
	/// \return Return the gradient shader.
	///////////////////////////////////////////////////////////////////////////
	mitkEncodedGradientShader* GetEncodedGradientShader()
	{
		return m_GradientShader;
	}

	//////////////////////////////////////////////////////////////////////////
	/// Set perspective shearer to shear and composite the volume.
	/// \param shearer Represent the perspective shearer.
	//////////////////////////////////////////////////////////////////////////
	void SetPerspectiveShearer(mitkVolumeShearFunction *shearer);

	//////////////////////////////////////////////////////////////////////////
	/// Set Parallel shearer to shear and composite the volume.
	/// \param shearer Represent the Parallel shearer.
	//////////////////////////////////////////////////////////////////////////
	void SetParallelShearer(mitkVolumeShearFunction *shearer);

	//////////////////////////////////////////////////////////////////////////
	/// Get the perspective shearer.
	/// \return Return the current perspective shearer.
	//////////////////////////////////////////////////////////////////////////
	mitkVolumeShearFunction* GetPerspectiveShearer();
	
	//////////////////////////////////////////////////////////////////////////
	/// Get the Parallel shearer.
	/// \return Return the current Parallel shearer.
	//////////////////////////////////////////////////////////////////////////
    mitkVolumeShearFunction* GetParallelShearer();

	///////////////////////////////////////////////////////////////////////////
	/// Set the sample distance in the image plane.
	/// \param val Specify the sample distance in the image plane.
	///////////////////////////////////////////////////////////////////////////
	void SetImageSampleDistance(float val)
	{
		m_ImageSampleDistance = val;
	}

	///////////////////////////////////////////////////////////////////////////
	/// Get the sample distance in the image plane.
	/// \return Return the image sample distance in the image plane.
	///////////////////////////////////////////////////////////////////////////
	float GetImageSampleDistance() {return m_ImageSampleDistance;}

	///////////////////////////////////////////////////////////////////////////
	/// Get the minimum image sample distance in the image plane.
	/// \return Return the minimum sample distance in the image plane.
	///////////////////////////////////////////////////////////////////////////
	float GetMinimumImageSampleDistance(){return m_MinimumImageSampleDistance;}	

	///////////////////////////////////////////////////////////////////////////
	/// Get the maximum image sample distance in the image plane.
	/// \return Return the maximum sample distance in the image plane.
	///////////////////////////////////////////////////////////////////////////
	float GetMaximumImageSampleDistance(){return m_MaximumImageSampleDistance;}	
	
	///////////////////////////////////////////////////////////////////////////
	/// Get whether to auto-adjust the image sample distances.
	/// \return Return a value which indicates whether to auto-adjust 
	/// the sample distances (1 means true, 0 means false).
	///////////////////////////////////////////////////////////////////////////
	bool GetAutoAdjustImageSampleDistances(){return m_AutoAdjustImageSampleDistances;}

	///////////////////////////////////////////////////////////////////////////
	/// Set image sample distances auto-adjusting on.
	///////////////////////////////////////////////////////////////////////////
	void AutoAdjustImageSampleDistancesOn(){ m_AutoAdjustImageSampleDistances = true;}

	///////////////////////////////////////////////////////////////////////////
	/// Set image sample distances auto-adjusting off.
	///////////////////////////////////////////////////////////////////////////
	void AutoAdjustImageSampleDistancesOff(){ m_AutoAdjustImageSampleDistances = false;}
		
	///////////////////////////////////////////////////////////////////////////
	/// Get gradient magnitude scale.
	/// \return Return the gradient magnitude scale.
	///////////////////////////////////////////////////////////////////////////
	virtual float GetGradientMagnitudeScale();

	///////////////////////////////////////////////////////////////////////////
	/// Get gradient magnitude bias.
	/// \return Return the gradient magnitude bias.
	///////////////////////////////////////////////////////////////////////////
	virtual float GetGradientMagnitudeBias();

	//////////////////////////////////////////////////////////////////////////
	/// Set volume rendering mode to be integral projection.
	//////////////////////////////////////////////////////////////////////////
	void SetModeIntegral(){ m_Mode = INTEGRAL; }

	//////////////////////////////////////////////////////////////////////////
	/// Set volume rendering mode to be MOP(maximum opacity projection).
	/// \note Each image pixel stands for maximum opacity element in the ray 
	/// direction, and when opacity is linear with intensity, MOP is equal to 
	/// MIP(maximum intensity projection).
	//////////////////////////////////////////////////////////////////////////
	void SetModeMop(){ m_Mode = MOP; }

	//////////////////////////////////////////////////////////////////////////
	/// Get the volume rendering mode.
	/// \return 
	/// Return 0 if the volume rendering mode is integral projection.
	/// Return 1 if the volume rendering mode is MOP(maximum opacity projection).
	//////////////////////////////////////////////////////////////////////////
    int GetMode(){ return m_Mode; }

	//////////////////////////////////////////////////////////////////////////
	/// Set level-of-detail display.
	/// \param lod The status of level-of-detail.
	/// If lod is true, it will display level-of-detail volume rendering image, 
	/// that is, the image sampling rate is enlarged when the view is scaled 
	/// so that you will get a more detailed image. however, the rendering speed
	/// will be slowed accordingly.
	/// If lod is false, it will display volume rendering image with the same
	/// detail, that is, the image sampling rate will not be changed.
	/// \note In default, it renders volume without level-of-detail.
	//////////////////////////////////////////////////////////////////////////
	void SetLevelOfDetail(bool lod){ m_LOD = lod; }

protected:
	virtual ~mitkVolumeRendererShearWarp();

	void _updateShadingTables(mitkView *view, mitkVolumeModel *vol);	
	void _renderTexture(mitkVolumeModel *vol, mitkView *view, unsigned char *img);
	void _getTransformMatrix(mitkView *view, mitkVolumeModel *vol);
	int  _computeGridBounds(mitkVolumeModel *vol, mitkView *view);
	void _shear(mitkView *view, mitkVolumeModel *vol);
	void _getShearOrder(mitkView *view);
//	bool _cullVoxel(float x, float y, float z, float *clipPlane, int pCount);

	mitkRCPtr<mitkVolumeShearFunction>       m_ParallelShearer;
	mitkRCPtr<mitkVolumeShearFunction>       m_PerspectiveShearer;
	mitkRCPtr<mitkEncodedGradientEstimator>  m_GradientEstimator;
	mitkRCPtr<mitkEncodedGradientShader>     m_GradientShader;

	// Transformation information
	mitkMatrix *m_GridToWorld;
	mitkMatrix *m_ViewToGrid;
	mitkMatrix *m_ShearMatrix;
	mitkMatrix *m_InverseShearMatrix;
	mitkMatrix *m_ShearOnlyMatrix;

	// The distance between sample points along shear space.
	float m_ImageSampleDistance;
	float   m_MinimumImageSampleDistance;
	float   m_MaximumImageSampleDistance;	
	bool  m_AutoAdjustImageSampleDistances;
	float m_AdjustDistance;
	
	// This is the size of the intermediate image region in sheared space. 
    int m_GridSize[2];
	
	// This is the location in sheared space where the intermediate image region
	// is located.
	int m_GridOrigin[2];

	// This is the size of samples in intermediate image that we use for real display.
	int m_ImageSize[2];
	int m_OldImageSize[2];

	// This is the size of the allocated memory for image. This may be bigger
	// or smaller than Intermediate Image's full size - it will be bigger if necessary to 
	// ensure a power of 2, it will be smaller if the intermediate image region only covers 
	// a small region of the allocated memory.
	int m_ImageMemorySize[2];

	// This is allocated for final displayed image.
	unsigned char *m_Image;
		
	// This is allocated for compositing of sheared slices.
	float *m_CompositeBuffer;

    //shear related information.
	mitkShear *m_Shear;
	int m_Mode;
	enum
	{
		INTEGRAL,
		MOP
	};

	// information needed for interactive clipping. 
	bool m_DepthTest;
	bool *m_Clips;
	bool m_AutoReslice;

	// information needed for level-of-detail display.
	bool m_LOD;

private:
	mitkVolumeRendererShearWarp(const mitkVolumeRendererShearWarp&);
	void operator = (const mitkVolumeRendererShearWarp&);

};

#endif