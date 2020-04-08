#pragma once
//Generate threshold data value for each region using minimum cross entropy
#ifndef ThresholdGeneration_h
#define ThresholdGeneration_h

#include <itkStatisticsImageFilter.h>

template <typename TInputImage>
class ThresholdGeneration
{
public:
	float *threshold;
	ThresholdGeneration(int noOfThresholds, float *endPoint, float *probDist);
};

#ifndef ITK_MANUAL_INSTANTIATION
#include "ThresholdGeneration.hxx"
#endif

#endif