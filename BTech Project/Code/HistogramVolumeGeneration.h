//Generate 3D histogram with data value, first derivative and second derivative magnitudes as X,Y,Z axes respectively 
//and frequency of a voxel in histogram gives us the frequency of a particular combination of (data value,first derivative, second derivative).
#pragma once
#ifndef HistogramVolumeGeneration_h
#define HistogramVolumeGeneration_h

#include <itkImage.h>
#include <fstream>
#include <itkStatisticsImageFilter.h>
#include <itkHistogram.h>
#include <iostream>
using namespace std;

#include "DirectionalDerivativesGeneration.h"

template <typename TInputImage>
class HistogramVolumeGeneration
{
private:
	typename TInputImage::Pointer inputVolume;
	typename TInputImage::Pointer firstDerivative;
	typename TInputImage::Pointer secondDerivative;

	void SetHistogramParameters(int *histogramSize);
	void ConstructHistogram();
public:
	//initializing histogram
	typedef float MeasurementType;
	typedef itk::Statistics::Histogram< MeasurementType, itk::Statistics::DenseFrequencyContainer2 > HistogramType;
	HistogramType::Pointer histogram = HistogramType::New();
	float binWidth[3];
	float lowerBound[3];

	HistogramVolumeGeneration(typename TInputImage::Pointer image, int *histogramSize);

};

#ifndef ITK_MANUAL_INSTANTIATION
#include "HistogramVolumeGeneration.hxx"
#endif

#endif