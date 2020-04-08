#pragma once
#ifndef HistogramVolumeGeneration_hxx
#define HistogramVolumeGeneration_hxx

template <typename TInputImage>
HistogramVolumeGeneration<TInputImage>::HistogramVolumeGeneration(typename TInputImage::Pointer image, int *histogramSize)
{
	this->inputVolume = image;
	class DirectionalDerivativesGeneration<TInputImage>*  DirDerGen = new DirectionalDerivativesGeneration<TInputImage>(this->inputVolume);
	this->firstDerivative = (DirDerGen->firstDerivative);
	this->secondDerivative = (DirDerGen->secondDerivative);
	
	this->SetHistogramParameters(histogramSize);
	this->ConstructHistogram();
}

template <typename TInputImage>
void HistogramVolumeGeneration<TInputImage>::SetHistogramParameters(int *histogramSize)
{
	HistogramType::SizeType size(Dimension);												//need to be set by the user
	size[0] = histogramSize[0];
	size[1] = histogramSize[1];
	size[2] = histogramSize[2];

	/*Calculation of max and min values*/
	typedef itk::StatisticsImageFilter<TInputImage> StatisticsImageFilterType;
	StatisticsImageFilterType::Pointer statisticsImageFilter = StatisticsImageFilterType::New();

	statisticsImageFilter->SetInput(this->inputVolume);
	statisticsImageFilter->Update();
	float inputVolumeMin = statisticsImageFilter->GetMinimum();
	float inputVolumeMax = statisticsImageFilter->GetMaximum();
	cout << "inputVolumeMin:" << inputVolumeMin << "\t inputVolumeMax:" << inputVolumeMax << "\n";

	statisticsImageFilter->SetInput(this->firstDerivative);
	statisticsImageFilter->Update();
	float firstDerivativeMin = statisticsImageFilter->GetMinimum();
	float firstDerivativeMax = statisticsImageFilter->GetMaximum();
	cout << "firstDerivativeMin:" << firstDerivativeMin << "\t firstDerivativeMax:" << firstDerivativeMax << "\n";

	statisticsImageFilter->SetInput(this->secondDerivative);
	statisticsImageFilter->Update();
	float secondDerivativeMin = statisticsImageFilter->GetMinimum();
	float secondDerivativeMax = statisticsImageFilter->GetMaximum();
	cout << "secondDerivativeMin:" << secondDerivativeMin << "\t secondDerivativeMax:" << secondDerivativeMax << "\n";

	/*Set binMinimum and binMaximum*/
	HistogramType::MeasurementVectorType binMinimum(Dimension);
	HistogramType::MeasurementVectorType binMaximum(Dimension);

	binMinimum[0] = inputVolumeMin;
	binMinimum[1] = firstDerivativeMin;
	binMinimum[2] = secondDerivativeMin;
	binMaximum[0] = inputVolumeMax;
	binMaximum[1] = firstDerivativeMax;
	binMaximum[2] = secondDerivativeMax;

	this->histogram->SetMeasurementVectorSize(Dimension);
	this->histogram->Initialize(size, binMinimum, binMaximum);

	this->binWidth[0] = ((binMaximum[0] - binMinimum[0]) / size[0]);		//for use in other classes
	this->binWidth[1] = ((binMaximum[1] - binMinimum[1]) / size[1]);
	this->binWidth[2] = ((binMaximum[2] - binMinimum[2]) / size[2]);

	this->lowerBound[0] = binMinimum[0];								   //for use in other classes
	this->lowerBound[1] = binMinimum[1];
	this->lowerBound[2] = binMinimum[2];
}

template <typename TInputImage>
void HistogramVolumeGeneration<TInputImage>::ConstructHistogram()
{
	TInputImage::RegionType region = inputVolume->GetLargestPossibleRegion();
	TInputImage::SizeType dims = region.GetSize();
	std::cout << "dims: " << dims << std::endl;

	int num = dims[0] * dims[1] * dims[2];

	int i = 0;

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
				TInputImage::PixelType dataValue = this->inputVolume->GetPixel(pixelIndex);
				TInputImage::PixelType gradientValue = this->firstDerivative->GetPixel(pixelIndex);
				TInputImage::PixelType secondDerivativeValue = this->secondDerivative->GetPixel(pixelIndex);

				HistogramType::MeasurementVectorType mv(Dimension);
				mv[0] = dataValue;
				mv[1] = gradientValue;
				mv[2] = secondDerivativeValue;
				HistogramType::IndexType resultingIndex(Dimension);
				this->histogram->GetIndex(mv, resultingIndex);
				int freq = this->histogram->GetFrequency(resultingIndex);
				this->histogram->SetFrequencyOfIndex(resultingIndex, freq + 1);
				i++;
			}
		}
	}
	cout << "dimension of input volume:" << dims[0] << " " << dims[1] << " " << dims[2] << endl;
	cout << "total frequency:" << this->histogram->GetTotalFrequency() << "\n";
}


#endif // HistogramVolumeGeneration_hxx