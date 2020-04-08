#pragma once
//Splitting the data range into regions using accumulated probability distribution of the histogram
#ifndef PartitionGeneration_h
#define PartitionGeneration_h

#include <itkStatisticsImageFilter.h>

template <typename TInputImage>
class PartitionGeneration
{
private:
	typename TInputImage::Pointer inputVolume;
public:
	int noOfThresholds;
	float *endPoint;
	float *probDist;
	PartitionGeneration(typename TInputImage::Pointer image, int m);
};

#ifndef ITK_MANUAL_INSTANTIATION
#include "PartitionGeneration.hxx"
#endif

#endif