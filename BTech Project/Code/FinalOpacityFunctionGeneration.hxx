#pragma once
#ifndef FinalOpacityFunctionGeneration_hxx
#define FinalOpacityFunctionGeneration_hxx

#include "itkImageDuplicator.h"

template <typename TInputImage>
FinalOpacityFunctionGeneration<TInputImage>::FinalOpacityFunctionGeneration(typename TInputImage::Pointer image, float* binWidth, float* lowerBound, float *alpha)
{
	this->inputVolume = image;
	this->GenerateContour();
	this->GenerateFinalOpacityFunction(binWidth, lowerBound, alpha);
}

template <typename TInputImage>
void FinalOpacityFunctionGeneration<TInputImage>::GenerateContour()
{
	typedef itk::OtsuThresholdImageFilter <TInputImage, TInputImage> FilterType;
	FilterType::Pointer otsuFilter = FilterType::New();
	otsuFilter->SetInput(this->inputVolume);
	otsuFilter->Update(); // To compute threshold

	typedef itk::BinaryContourImageFilter <TInputImage, TInputImage > binaryContourImageFilterType;
	binaryContourImageFilterType::Pointer binaryContourFilter = binaryContourImageFilterType::New();
	binaryContourFilter->SetInput(otsuFilter->GetOutput());
	binaryContourFilter->Update(); // To compute contour

	this->contourVolume = otsuFilter->GetOutput();
}

template <typename TInputImage>
void FinalOpacityFunctionGeneration<TInputImage>::GenerateFinalOpacityFunction(float* binWidth, float* lowerBound, float *alpha)
{
	TInputImage::RegionType region = this->contourVolume->GetLargestPossibleRegion();
	TInputImage::SizeType dims = region.GetSize();

	typedef itk::ImageDuplicator <TInputImage> DuplicatorType;
	DuplicatorType::Pointer duplicator = DuplicatorType::New();
	duplicator->SetInputImage(this->inputVolume);
	duplicator->Update();

	this->dupVolume = duplicator->GetOutput();			//all pixels which are outside main boundary of the object are set to zero.

	for (int x = 0;x < dims[0];x++)
	{
		for (int y = 0;y < dims[1];y++)
		{
			for (int z = 0;z < dims[2];z++)
			{
				TInputImage::IndexType pixelIndex;
				pixelIndex[0] = x;
				pixelIndex[1] = y;
				pixelIndex[2] = z;
				TInputImage::PixelType temp = this->contourVolume->GetPixel(pixelIndex);
				if (temp != 0)
				{
					TInputImage::PixelType dataValue = this->inputVolume->GetPixel(pixelIndex);
					int index = roundf((dataValue - lowerBound[0]) / binWidth[0]);
					if (alpha[index] != 0)
					{
						alpha[index] = 0.8;
						this->dupVolume->SetPixel(pixelIndex, dataValue);
					}
					else
					{
						this->dupVolume->SetPixel(pixelIndex, 0.0f);
					}
				}
			}
		}
	}

	typedef itk::ImageFileWriter< TInputImage> WriterType;
	WriterType::Pointer writer = WriterType::New();
	writer->SetFileName("inputModified.vtk");
	writer->SetInput(this->dupVolume);
	writer->Update();
	cout << "inputModified written\n";

	ofstream allValues;
	allValues.open("finalValues.CSV");
	allValues << "dataValue" << "," << "alpha[v]" << "\n";
	for (int i = 0;i < (256);i++)
	{
		allValues << lowerBound[0] + i*binWidth[0] << "," << alpha[i] << "\n";
	}
	allValues.close();
}

#endif // FinalOpacityFunctionGeneration_hxx
