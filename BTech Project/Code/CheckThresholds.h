#pragma once
#ifndef CheckThresholds_h
#define CheckThresholds_h

template <typename TInputImage>
class CheckThresholds
{
public:
	int finalNoOfThresholds;
	float *finalThreshold;
	CheckThresholds(int noOfThresholds, float* threshold, float* binWidth, float* lowerBound, float *alpha);
};




#ifndef ITK_MANUAL_INSTANTIATION
#include "CheckThresholds.hxx"
#endif

#endif