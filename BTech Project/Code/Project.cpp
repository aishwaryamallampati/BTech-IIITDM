// Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vtkAutoInit.h> 
VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkRenderingContextOpenGL2);

#include <itkImageFileReader.h>
#include <itkVTKImageIOFactory.h>

#include "HistogramVolumeGeneration.h"
#include "OpacityFunctionGeneration.h"
#include "PartitionGeneration.h"
#include "FinalOpacityFunctionGeneration.h"
#include "ThresholdGeneration.h"
#include "CheckThresholds.h"
#include "DirectVolumeRendering.h"

typedef float  PixelType;
const unsigned int Dimension = 3;
typedef itk::Image< PixelType, Dimension  > ImageType;
int main()
{
	itk::VTKImageIOFactory::RegisterOneFactory();

	int histogramSize[3];				//need to be set by the user
	histogramSize[0] = 256;  // number of bins for the data value axis
	histogramSize[1] = 256;  // number of bins for the firstDerivative axis
	histogramSize[2] = 256;  // number of bins for the secondDerivative axis

	//Reading 3d input .vtk file
	std::string inputFilename;
	//inputFilename = "bigpapaya-kovidct2-Rescaled.vtk"; //Use MCET for this input as the volume size is huge
	inputFilename = "input3.vtk";

	typedef itk::ImageFileReader< ImageType >   ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(inputFilename);

	ImageType::Pointer data = ImageType::New();
	data = reader->GetOutput();
	const char *cstr = inputFilename.c_str();

	class HistogramVolumeGeneration<ImageType> *HistVolGen = new HistogramVolumeGeneration<ImageType>(data, histogramSize);
	class OpacityFunctionGeneration<ImageType>* OpacFunGen = new OpacityFunctionGeneration<ImageType>(HistVolGen->histogram, HistVolGen->binWidth, HistVolGen->lowerBound);
	//class FinalOpacityFunctionGeneration<ImageType>* FinalOpacGen = new FinalOpacityFunctionGeneration<ImageType>(data, HistVolGen->binWidth, HistVolGen->lowerBound, OpacFunGen->alpha);

	int m = 50;					//data range of the input is split into m regions
	//class PartitionGeneration<ImageType>* GenPartition = new PartitionGeneration<ImageType>(FinalOpacGen->dupVolume, m);
	class PartitionGeneration<ImageType>* GenPartition = new PartitionGeneration<ImageType>(data, m);
	class ThresholdGeneration<ImageType>* GenThreshold = new ThresholdGeneration<ImageType>(GenPartition->noOfThresholds, GenPartition->endPoint, GenPartition->probDist);

	//class CheckThresholds<ImageType>*check = new CheckThresholds<ImageType>(GenPartition->noOfThresholds, GenThreshold->threshold, HistVolGen->binWidth, HistVolGen->lowerBound, OpacFunGen->alpha);

	//class DirectVolumeRendering<ImageType>* DirVolRen = new DirectVolumeRendering<ImageType>(FinalOpacGen->dupVolume, check->finalNoOfThresholds, check->finalThreshold, cstr);
	class DirectVolumeRendering<ImageType>* DirVolRen = new DirectVolumeRendering<ImageType>(data, GenPartition->noOfThresholds, GenThreshold->threshold, cstr);

    return 0;
}

