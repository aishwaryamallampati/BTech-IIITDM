#pragma once
#ifndef DirectionalDerivativesGeneration_hxx
#define DirectionalDerivativesGeneration_hxx

template <typename TInputImage>
DirectionalDerivativesGeneration<TInputImage>::DirectionalDerivativesGeneration(typename TInputImage::Pointer inputVolume)
{
	this->GenerateFirstDirectionalDerivative(inputVolume);
	this->GenerateSecondDirectionalDerivative(inputVolume);
}

template <typename TInputImage>
void DirectionalDerivativesGeneration<TInputImage>::GenerateFirstDirectionalDerivative(typename TInputImage::Pointer inputVolume)
{
	//gradient magnitude calculation
	typedef itk::GradientMagnitudeImageFilter<TInputImage, TInputImage >  GradientFilterType;
	GradientFilterType::Pointer gradientMagnitudeFilter = GradientFilterType::New();
	gradientMagnitudeFilter->SetInput(inputVolume);
	gradientMagnitudeFilter->Update();

	this->firstDerivative = gradientMagnitudeFilter->GetOutput();
}

template <typename TInputImage>
void DirectionalDerivativesGeneration<TInputImage>::GenerateSecondDirectionalDerivative(typename TInputImage::Pointer inputVolume)
{
	//second derivative magnitude calculation
	typedef itk::LaplacianImageFilter<TInputImage, TInputImage >  LaplacianFilterType;
	LaplacianFilterType::Pointer laplacianFilter = LaplacianFilterType::New();
	laplacianFilter->SetInput(inputVolume);
	laplacianFilter->Update();

	this->secondDerivative = laplacianFilter->GetOutput();
}

#endif // DirectionalDerivativesGeneration_hxx