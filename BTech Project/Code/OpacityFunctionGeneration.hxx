#pragma once
#ifndef OpacityFunctionGeneration_hxx
#define OpacityFunctionGeneration_hxx

template <typename TInputImage>
OpacityFunctionGeneration<TInputImage>::OpacityFunctionGeneration(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	this->max_g = -100000;
	this->min_g = 100000;
	this->max_h = -100000;
	this->min_h = 100000;
	
	this->CalculateMeanFirstDirectionalDerivative(histogram, binWidth, binMinimum);
	this->CalculateMeanSecondDirectionalDerivative(histogram, binWidth, binMinimum);
	this->CalculateOpacity(histogram);
	this->StoreAllValues(histogram, binWidth, binMinimum);
}

template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::CalculateMeanFirstDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	//calculation of g(v)
	this->g = (float*)calloc(histogram->GetSize(0), sizeof(float));
	for (int i = 0;i < (histogram->GetSize(0));i++)//dataValue Axis
	{
		float avg_sum = 0;
		for (int k = 0;k < (histogram->GetSize(2));k++)//secondDerivative Axis
		{
			float sum_g = 0;
			int freq_g = 0;
			for (int j = 0;j < (histogram->GetSize(1));j++)//gradientMagnitude Axis
			{
				HistogramType::IndexType index(Dimension);
				index[0] = i;
				index[1] = j;
				index[2] = k;
				int frequency = histogram->GetFrequency(index);
				if (frequency != 0)
				{
					freq_g = freq_g + frequency;
					sum_g = sum_g + (frequency*(binMinimum[1] + j*binWidth[1]));
				}
			}
			if (freq_g != 0)
			{
				avg_sum = avg_sum + (sum_g / freq_g);//fix i and k then iterate over j.
			}
		}
		//this->g[i] = (avg_sum / (histogram->GetSize(2)));//fix i and for all the averages over k find final average.
		this->g[i] = avg_sum;
		if (this->g[i] < this->min_g) //finding min_g
			this->min_g = this->g[i];
		if (this->g[i] > this->max_g) //finding max_g
			this->max_g = this->g[i];
	}

	cout << "\nPrinting g:" << "\n";
	#pragma omp parallel
	#pragma omp for
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "g[" << i << "]=" << this->g[i] << "\n";
	}
	cout << "max_g=" << this->max_g << " min_g=" << this->min_g << "\n";
}

template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::CalculateMeanSecondDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	//calculation of h(v)
	this->h = (float*)calloc((histogram->GetSize(0)), sizeof(float));
	for (int i = 0;i < (histogram->GetSize(0));i++)//dataValue Axis
	{
		float avg_sum = 0;
		for (int j = 0;j < (histogram->GetSize(1));j++)//gradientMagnitude Axis
		{
			float sum_h = 0;
			int freq_h = 0;
			for (int k = 0;k <(histogram->GetSize(2));k++)//secondDerivative Axis
			{
				HistogramType::IndexType index(Dimension);
				index[0] = i;
				index[1] = j;
				index[2] = k;
				int frequency = histogram->GetFrequency(index);
				if (frequency != 0)
				{
					freq_h = freq_h + frequency;
					sum_h = sum_h + (frequency*(binMinimum[2] + k*binWidth[2]));
				}
			}
			if (freq_h != 0)
			{
				avg_sum = avg_sum + (sum_h / freq_h);//fix i and k then iterate over j.
			}
		}
		//this->h[i] = (avg_sum / (histogram->GetSize(1)));//fix i and for all the averages over k find final average.
		this->h[i] = avg_sum;
		if (this->h[i] < this->min_h) //finding min_h
			this->min_h = this->h[i];
		if (this->h[i] > this->max_h) //finding max_h
			this->max_h = this->h[i];
	}

	cout << "\nPrinting h:" << "\n";
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "h[" << i << "]=" << this->h[i] << "\n";
	}
	cout << "max_h=" << this->max_h << " min_h=" << this->min_h << "\n";
}

/*template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::CalculateMeanFirstDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	//calculation of g(v)
	this->g = (float*)calloc(histogram->GetSize(0), sizeof(float));
	for (int i = 0;i < (histogram->GetSize(0));i++)//dataValue Axis
	{
		float avg_sum = 0.0;
		float sum_g = 0.0;
		int freq_g = 0.0;
		for (int k = 0;k < (histogram->GetSize(2));k++)//secondDerivative Axis
		{
			for (int j = 0;j < (histogram->GetSize(1));j++)//gradientMagnitude Axis
			{
				HistogramType::IndexType index(Dimension);
				index[0] = i;
				index[1] = j;
				index[2] = k;
				int frequency = histogram->GetFrequency(index);
				if (frequency != 0)
				{
					freq_g = freq_g + frequency;
					sum_g = sum_g + (frequency*((binMinimum[1] + j*binWidth[1])+(binWidth[1]/2)));
				}
			}
			/*if (freq_j != 0)
			{
				avg_sum = avg_sum + (sum_j / freq_j);//fix i and k then iterate over j.
				sum_k = sum_k + avg_sum*fre
			}*/
		/*}
		//this->g[i] = (avg_sum / (histogram->GetSize(2)));//fix i and for all the averages over k find final average.
		/*if (freq_g == 0)
		{
			this->g[i] = 0.1;						//just to remove the contribution of this g
			continue;
		}*/
		/*this->g[i] = (float)(sum_g / freq_g);
		//this->g[i] = (float)(this->g[i] / histogram->GetSize[2]);
		if (this->g[i] < this->min_g) //finding min_g
			this->min_g = this->g[i];
		if (this->g[i] > this->max_g) //finding max_g
			this->max_g = this->g[i];
	}

	cout << "\nPrinting g:" << "\n";
#pragma omp parallel
#pragma omp for
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "g[" << i << "]=" << this->g[i] << "\n";
	}
	cout << "max_g=" << this->max_g << " min_g=" << this->min_g << "\n";
}

template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::CalculateMeanSecondDirectionalDerivative(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	//calculation of h(v)
	this->h = (float*)calloc((histogram->GetSize(0)), sizeof(float));
	for (int i = 0;i < (histogram->GetSize(0));i++)//dataValue Axis
	{
		float avg_sum = 0.0;
		float sum_h = 0.0;
		int freq_h = 0.0;
		for (int j = 0;j < (histogram->GetSize(1));j++)//gradientMagnitude Axis
		{
			for (int k = 0;k <(histogram->GetSize(2));k++)//secondDerivative Axis
			{
				HistogramType::IndexType index(Dimension);
				index[0] = i;
				index[1] = j;
				index[2] = k;
				int frequency = histogram->GetFrequency(index);
				if (frequency != 0)
				{
					freq_h = freq_h + frequency;
					sum_h = sum_h + (frequency*((binMinimum[2] + k*binWidth[2]) + (binWidth[2]/2)));
				}
			}
			/*if (freq_h != 0)
			{
				avg_sum = avg_sum + (sum_h / freq_h);//fix i and k then iterate over j.
			}*/
		/*}
		//this->h[i] = (avg_sum / (histogram->GetSize(1)));//fix i and for all the averages over k find final average.
		/*if (freq_h == 0)
		{
			this->h[i] = 100000;						//just to remove the contribution of this h
			continue;
		}*/
		/*this->h[i] = (float)(sum_h / freq_h);
		
		if (this->h[i] < this->min_h) //finding min_h
			this->min_h = this->h[i];
		if (this->h[i] > this->max_h) //finding max_h
			this->max_h = this->h[i];
	}

	cout << "\nPrinting h:" << "\n";
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "h[" << i << "]=" << this->h[i] << "\n";
	}
	cout << "max_h=" << this->max_h << " min_h=" << this->min_h << "\n";
}*/

template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::CalculateOpacity(HistogramType::Pointer histogram)
{
	//calculation of sigma
	float e = 2.71828;
	float sigma = (2 * sqrtf(e) * max_g) / (max_h - min_h);
	cout << "sigma=" << sigma << "\n";

	//calculation of p(v)
	this->p = (float*)calloc((histogram->GetSize(0)), sizeof(float));
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		this->p[i] = -((((sigma)*(sigma))*this->h[i]) / (this->g[i]));
	}

	cout << "\nPrinting p:" << "\n";
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "p[" << i << "]=" << this->p[i] << "\n";
	}

	//calculation of alpha(v)
	this->alpha = (float*)calloc((histogram->GetSize(0)), sizeof(float));
	for (int i = 0;i <(histogram->GetSize(0));i++)
	{
		if ((this->p[i] <= sigma) && (this->p[i] >= -(sigma)))
		{
			this->alpha[i] = 0.6; // original version
		}	
		else
		{
			this->alpha[i] = 0.0;
		}
	}

	cout << "\nPrinting alpha:" << "\n";
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		cout << "alpha[" << i << "]=" << this->alpha[i] << "\n";
	}
}

template <typename TInputImage>
void OpacityFunctionGeneration<TInputImage>::StoreAllValues(HistogramType::Pointer histogram, float *binWidth, float *binMinimum)
{
	// storing all values  in excel
	ofstream allValues;
	allValues.open("allValues.CSV");
	allValues << "dataValue" << "," << "g[v]" << "," << "h[v]" << "," << "p[v]" << "," << "alpha[v]" << "\n";
	for (int i = 0;i < (histogram->GetSize(0));i++)
	{
		allValues << binMinimum[0] + i*binWidth[0] << "," << this->g[i] << "," << this->h[i] << "," << this->p[i] << "," << this->alpha[i] << "\n";
	}
	allValues.close();
}

#endif // OpacityFunctionGeneration_hxx