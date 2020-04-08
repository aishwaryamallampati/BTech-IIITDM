#pragma once
#ifndef PartitionGeneration_hxx
#define PartitionGeneration_hxx

template <typename TInputImage>
PartitionGeneration<TInputImage>::PartitionGeneration(typename TInputImage::Pointer image, int m)
{
	this->inputVolume = image;

	typedef itk::StatisticsImageFilter<TInputImage> StatisticsImageFilterType;
	StatisticsImageFilterType::Pointer statisticsImageFilter = StatisticsImageFilterType::New();
	statisticsImageFilter->SetInput(this->inputVolume);
	statisticsImageFilter->Update();
	float inputVolumeMin = statisticsImageFilter->GetMinimum();
	float inputVolumeMax = statisticsImageFilter->GetMaximum();
	cout << "inputVolumeMin:" << inputVolumeMin << "\t inputVolumeMax:" << inputVolumeMax << "\n";

	this->endPoint = (float*)calloc((m+1), sizeof(float));
	for (int i = 0;i <= m;i++)
	{
		this->endPoint[i] = roundf(i*((inputVolumeMax - inputVolumeMin) / m));
		//cout << "endPoint[" << i << "]=" << endPoint[i] << "\n";
	}

	TInputImage::RegionType region = this->inputVolume->GetLargestPossibleRegion();
	TInputImage::SizeType dims = region.GetSize();
	std::cout << "dims: " << dims << std::endl;

	float *freq;
	freq = (float*)calloc((65536), sizeof(float));

	for (int x = 0;x < dims[0];x++)												//calculation of frequency
	{
		for (int y = 0;y < dims[1];y++)
		{
			for (int z = 0;z < dims[2];z++)
			{
				TInputImage::IndexType pixelIndex;
				pixelIndex[0] = x;
				pixelIndex[1] = y;
				pixelIndex[2] = z;

				TInputImage::PixelType dataValue = this->inputVolume->GetPixel(pixelIndex);
				int dV = round(dataValue);
				freq[dV] = freq[dV] + 1;
			}
		}
	}

	float size = dims[0] * dims[1] * dims[2];
	this->probDist = (float*)calloc((65536), sizeof(float));
	float accProbDist[200] = { 0.0 };

	//segmenting the image into partitions
	for (int i = 0; i <m;i++)
	{
		for (int j = this->endPoint[i];j < this->endPoint[i + 1];j++)
		{
			this->probDist[j] = (freq[j] / size);
			accProbDist[i] = accProbDist[i] + this->probDist[j];
		}
		if (accProbDist[i] < (1.0 / (m + 2)))
		{
			//cout << "start=" << endPoint[i] << " end=" << endPoint[i + 1] << " acc=" << accProbDist[i] << " Not accepted\n";
			int j = ((this->endPoint[i + 1]) - 1);
			while (accProbDist[i] < (1.0 / (m + 2)) && (j<inputVolumeMax))
			{
				j = j + 1;
				this->probDist[j] = (freq[j] / size);
				accProbDist[i] = accProbDist[i] + this->probDist[j];
			}
			this->endPoint[i + 1] = j + 1;
			//cout << "start=" << endPoint[i] << " end=" << endPoint[i + 1] << " acc=" << accProbDist[i] << " accepted\n";
			int count = 0;
			for (int p = i + 2;p <= m;p++)
			{
				if (this->endPoint[p] < this->endPoint[i + 1])
				{
					this->endPoint[p] = -1;
					count = count + 1;
				}
			}
			//cout << "count = " << count << "\n";
			if (count != 0)
			{
				for (int q = i + 2 + count;q <= m;q++)
				{
					this->endPoint[q - count] = this->endPoint[q];
				}
				m = m - count;
			}
		}
	}
	//printing the end points of regions
	for (int i = 0; i <= m;i++)
	{
		cout << "endPoint[" << i << "]=" << this->endPoint[i] << "\n";
	}
	this->noOfThresholds = (m);
}

#endif // PartitionGeneration_hxx