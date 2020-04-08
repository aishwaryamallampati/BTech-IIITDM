#pragma once
#ifndef CheckThresholds_hxx
#define CheckThresholds_hxx

template <typename TInputImage>
CheckThresholds<TInputImage>::CheckThresholds(int noOfThresholds, float* threshold, float* binWidth, float* lowerBound, float *alpha)
{
	int j = 0;
	finalThreshold = (float*)calloc((noOfThresholds), sizeof(float));
	cout << "Printing final threshold data values after check:\n";
	for (int i = 0; i < noOfThresholds;i++)
	{
		int index = roundf((threshold[i] - lowerBound[0]) / binWidth[0]);
		if (alpha[index] != 0)
		{
			this->finalThreshold[j] = threshold[i];
			cout << "finalthresh[" << j << "]=" << this->finalThreshold[j] << "\n";
			j = j + 1;
		}
	}
	this->finalNoOfThresholds = j;
}




#endif // MinimumCrossEntropyThresholding_hxx