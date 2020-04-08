//removing the data values whose p[v] is not between -sigma to +sigma
#pragma once
#ifndef FinalOpacityFunctionGeneration_h
#define FinalOpacityFunctionGeneration_h

#include "itkBinaryContourImageFilter.h"
#include "itkOtsuThresholdImageFilter.h"

template <typename TInputImage>
class FinalOpacityFunctionGeneration
{
private:
	typename TInputImage::Pointer inputVolume;
	typename TInputImage::Pointer contourVolume;
	
	void GenerateContour();
	void GenerateFinalOpacityFunction(float* binWidth, float* lowerBound, float *alpha);
public:
	typename TInputImage::Pointer dupVolume;
	FinalOpacityFunctionGeneration(typename TInputImage::Pointer image, float* binWidth, float* lowerBound, float *alpha);
};


#ifndef ITK_MANUAL_INSTANTIATION
#include "FinalOpacityFunctionGeneration.hxx"
#endif

#endif