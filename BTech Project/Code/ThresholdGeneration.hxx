#pragma once
#ifndef ThresholdGeneration_hxx
#define ThresholdGeneration_hxx

template <typename TInputImage>
ThresholdGeneration<TInputImage>::ThresholdGeneration(int noOfThresholds, float *endPoint,float *probDist)
{
	float *firstM0, *secondM0, *firstM1, *secondM1;
	firstM0 = (float*)calloc((65536), sizeof(float));
	secondM0 = (float*)calloc((65536), sizeof(float));
	firstM1 = (float*)calloc((65536), sizeof(float));
	secondM1 = (float*)calloc((65536), sizeof(float));
	this->threshold = (float*)calloc((noOfThresholds+1), sizeof(float));

	cout << "\nFinding thresholds.\n";
	for (int j = 0;j < noOfThresholds;j++)
	{
		float fMin = 0.0;
		float fMax = 0.0;

		fMin = endPoint[j];
		fMax = endPoint[j+1];

		float constant = 0;
		float minEntropy;
		//cout << "j=" << j << " fMin=" << fMin << " fMax=" << fMax << "\n";
		if (fMin == fMax)
		{
			this->threshold[j] = fMin;
			continue;
		}
		for (int t = (fMin + 1);t < fMax;t++)
		{
			if (t == (fMin + 1))
			{
				for (int i = fMin; i <t; i++)
				{
					firstM0[t] = firstM0[t] + probDist[i];
					firstM1[t] = firstM1[t] + i*probDist[i];
					constant = constant + i*probDist[i] * (std::log(i) / std::log(2.0));
					if (isnan(constant))
						constant = 0;
				}

				for (int i = t;i <= fMax;i++)
				{
					secondM0[t] = secondM0[t] + probDist[i];
					secondM1[t] = secondM1[t] + i*probDist[i];
					constant = constant + i*probDist[i] * (std::log(i) / std::log(2.0));
					if (isnan(constant))
						constant = 0;
				}
				minEntropy = constant - (firstM1[t] * ((std::log(firstM1[t]) / std::log(2.0)) - (std::log(firstM0[t]) / std::log(2.0)))) - (secondM1[t] * ((std::log(secondM1[t]) / std::log(2.0)) - (std::log(secondM0[t]) / std::log(2.0))));
				if (isnan(minEntropy))
					minEntropy = 1000;
				this->threshold[j] = t;
			}
			else
			{
				firstM0[t] = firstM0[t - 1] + probDist[t - 1];
				firstM1[t] = firstM1[t - 1] + (t - 1)*probDist[t - 1];
				secondM0[t] = secondM0[t - 1] - probDist[t - 1];
				secondM1[t] = secondM1[t - 1] - (t - 1)*probDist[t - 1];
				float temp = constant - (firstM1[t] * ((std::log(firstM1[t]) / std::log(2.0)) - (std::log(firstM0[t]) / std::log(2.0)))) - (secondM1[t] * ((std::log(secondM1[t]) / std::log(2.0)) - (std::log(secondM0[t]) / std::log(2.0))));
				if (!isnan(temp))
				{
					if (temp < minEntropy)
					{
						minEntropy = temp;
						this->threshold[j] = t;
					}
				}
			}
		}
		//cout << "j = " << j << " threshold[j]=" << this->threshold[j] << " minEntropy=" << minEntropy << "\n\n";
	}

	for (int i = 0;i < noOfThresholds;i++)
		cout << "threshold[" << i << "]=" << this->threshold[i] << "\n";
}
#endif // ThresholdGeneration_hxx