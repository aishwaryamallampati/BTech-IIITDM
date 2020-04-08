//calcution of p[v] ie postion value for each data value
#pragma once
#ifndef OpacityFunctionGeneration_h
#define OpacityFunctionGeneration_h

#include <itkImage.h>
#include <fstream>
#include <itkHistogram.h>
#include <iostream>
using namespace std;

template <typename TInputImage>
class OpacityFunctionGeneration
{
private:
	typedef float MeasurementType;
	typedef itk::Statistics::Histogram< MeasurementType, itk::Statistics::DenseFrequencyContainer2 > HistogramType;
	float *g;									//g[v]-to store average of first derivative
	float max_g;
	float min_g;
	float *h;									//h[v]-to store average of second derivative
	float max_h;
	float min_h;
	float *p;									//p[v]-to store opacity with respect to data value
	
	void CalculateMeanFirstDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum);
	void CalculateMeanSecondDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum);
	void CalculateOpacity(HistogramType::Pointer histogram);
	void StoreAllValues(HistogramType::Pointer histogram, float *binWidth, float *binMinimum);

public:
	float *alpha;					//aplha[v]-to store opacity based on boundary emphasis function
	OpacityFunctionGeneration(HistogramType::Pointer histogram, float *binWidth, float *binMinimum);
};

#ifndef ITK_MANUAL_INSTANTIATION
#include "OpacityFunctionGeneration.hxx"
#endif

#endif