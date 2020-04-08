//Calculate first and second derivative of the input volume
#pragma once
#ifndef DirectionalDerivativesGeneration_h
#define DirectionalDerivativesGeneration_h

#include <itkImage.h>
#include <itkGradientMagnitudeImageFilter.h>
#include <itkLaplacianImageFilter.h>
#include "itkImageFileWriter.h"

template <typename TInputImage>
class DirectionalDerivativesGeneration
{
private:
	void GenerateFirstDirectionalDerivative(typename TInputImage::Pointer inputVolume);
	void GenerateSecondDirectionalDerivative(typename TInputImage::Pointer inputVolume);
public:
	typename TInputImage::Pointer firstDerivative;
	typename TInputImage::Pointer secondDerivative;

	DirectionalDerivativesGeneration(typename TInputImage::Pointer inputVolume);
};

#ifndef ITK_MANUAL_INSTANTIATION
#include "DirectionalDerivativesGeneration.hxx"
#endif

#endif

