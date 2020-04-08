// CPU_Reconstruction.cpp : Defines the entry point for the console application.
/* ImageByImageFDK
-single data set of projections is generated
-the data set is converted into individual projection files using ImageSeriesWriter
-each 2d input projection is read one by one
-and converted into 3d itk image using import image filter.
-the 3d itk image is given to ImageByImageFDKFilter. */

#include "stdafx.h"
#include "itkImage.h"
#include "stdio.h"
#include <rtkConstantImageSource.h>
#include "rtkImageByImageFDK.h"
#include "itkImageSeriesReader.h"
#include "itkImageFileWriter.h"
#include "itkNumericSeriesFileNames.h"
#include <itkVTKImageIOFactory.h>
#include "itkVTKImageIO.h"
#include "itkTIFFImageIO.h"
#include <itkTIFFImageIOFactory.h>
#include <itkPNGImageIOFactory.h>
#include "itkPNGImageIO.h"
#include "itkImportImageFilter.h"
#include <rtkSheppLoganPhantomFilter.h>
#include "itkImageSeriesWriter.h"
#include <chrono>
#include "itkMinimumMaximumImageCalculator.h"


int main()
{
	//step1: using this step we can create the shepplogan projections data set to apply our reconstruction algorithm. If we already have input set then, no need of step1 and step2, directly we can execute step-3 
	typedef float  PixelType;
	const unsigned int InputImageDimension = 2;
	const unsigned int OutputImageDimension = 3;

	typedef itk::Image< PixelType, InputImageDimension  >   InputImageType;
	typedef itk::Image< PixelType, OutputImageDimension >   OutputImageType;

	//accepts 2d input projections of .vtk,.tiff,.png formats
	itk::VTKImageIOFactory::RegisterOneFactory();
	itk::TIFFImageIOFactory::RegisterOneFactory();
	itk::PNGImageIOFactory::RegisterOneFactory();

	typedef  itk::ImageFileWriter< OutputImageType  > WriterType;
	typedef itk::NumericSeriesFileNames    NameGeneratorType;

	const unsigned int NumberOfProjectionImages = 360;											//need to be set by the user

	//generating projections
	// Constant image sources
	typedef rtk::ConstantImageSource< OutputImageType > ConstantImageSourceType;
	ConstantImageSourceType::PointType sourceOrigin;
	ConstantImageSourceType::SizeType sourceSize;
	ConstantImageSourceType::SpacingType sourceSpacing;

	ConstantImageSourceType::Pointer projectionsSource = ConstantImageSourceType::New();		//need to be set by the user
	sourceOrigin[0] = -512.;
	sourceOrigin[1] = -512.;
	sourceOrigin[2] = -512.;
	sourceSize[0] = 256;
	sourceSize[1] = 256;
	sourceSize[2] = NumberOfProjectionImages;
	sourceSpacing[0] = 4.;
	sourceSpacing[1] = 4.;
	sourceSpacing[2] = 4.;
	projectionsSource->SetOrigin(sourceOrigin);
	projectionsSource->SetSpacing(sourceSpacing);
	projectionsSource->SetSize(sourceSize);
	projectionsSource->SetConstant(0.);


	// Geometry object
	typedef rtk::ThreeDCircularProjectionGeometry GeometryType;
	GeometryType::Pointer geometry = GeometryType::New();
	for (unsigned int noProj = 0; noProj < NumberOfProjectionImages; noProj++)
		geometry->AddProjection(600., 1200., noProj*360. / NumberOfProjectionImages, 0, 0, 0, 0, 20, 15);

	// Shepp Logan projections filter
	typedef rtk::SheppLoganPhantomFilter<OutputImageType, OutputImageType> SLPType;
	SLPType::Pointer slp = SLPType::New();
	slp->SetInput(projectionsSource->GetOutput());
	slp->SetGeometry(geometry);
	slp->SetPhantomScale(116);
	TRY_AND_EXIT_ON_ITK_EXCEPTION(slp->Update());
	std::cout << "projections generated" << std::endl;

	//storing projections on to .vtk file
	std::string inputFilename;
	inputFilename = "projections.vtk";

	WriterType::Pointer writer = WriterType::New();
	writer->SetFileName(inputFilename);
	writer->SetInput(slp->GetOutput());
	TRY_AND_EXIT_ON_ITK_EXCEPTION(writer->Update());
	std::cout << "projections stored" << std::endl;//end of step1 

	//step2: extracting the above projection set into 360 individual files [.vtk or .tiff or.png]
	typedef itk::ImageFileReader< OutputImageType >   ReaderType;
	ReaderType::Pointer reader = ReaderType::New();
	reader->SetFileName(inputFilename);

	typedef itk::ImageSeriesWriter< OutputImageType, InputImageType > WriterTypeSeries;
	WriterTypeSeries::Pointer seriesWriter = WriterTypeSeries::New();
	seriesWriter->SetInput(reader->GetOutput());

	NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();

	std::string format = "PROJECTION";
	format += "%03d.";
	format += "vtk";   // filename extension can be set to .tiff, .png, .vtk
	nameGenerator->SetSeriesFormat(format.c_str());

	try
	{
		reader->Update();
	}
	catch (itk::ExceptionObject & excp)
	{
		std::cerr << "Exception thrown while reading the image" << std::endl;
		std::cerr << excp << std::endl;
	}

	OutputImageType::ConstPointer inputImage = reader->GetOutput();
	OutputImageType::RegionType   inputRegion = inputImage->GetLargestPossibleRegion();
	OutputImageType::IndexType    inputStart = inputRegion.GetIndex();
	OutputImageType::SizeType     inputSize = inputRegion.GetSize();

	const unsigned int firstSlice = inputStart[2];
	const unsigned int lastSlice = inputStart[2] + inputSize[2] - 1;
	nameGenerator->SetStartIndex(firstSlice);
	nameGenerator->SetEndIndex(lastSlice);
	nameGenerator->SetIncrementIndex(1);

	seriesWriter->SetFileNames(nameGenerator->GetFileNames());

	try
	{
		seriesWriter->Update();
	}
	catch (itk::ExceptionObject & excp)
	{
		std::cerr << "Exception thrown while reading the image" << std::endl;
		std::cerr << excp << std::endl;
	}//end of step2 

	 //step 3: applying Image by Image FDK reconstruction  algorithm
	 //NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();  //to read projection  std::string format = "cthead-8bit"; format += "%03d."; format += "tif";   // filename extension can be set to .tiff, .png, .vtk nameGenerator->SetSeriesFormat(format.c_str());
	typedef itk::ImageSeriesReader< InputImageType >  ReaderTypeSeries;

	ConstantImageSourceType::Pointer tomographySource = ConstantImageSourceType::New();						//need to be set by the user
	sourceOrigin[0] = -256.;//position of origin
	sourceOrigin[1] = -256.;
	sourceOrigin[2] = -256.;
	sourceSize[0] = 256;
	sourceSize[1] = 256;
	sourceSize[2] = 256;
	sourceSpacing[0] = 2.;//spacing between each pixel
	sourceSpacing[1] = 2.;
	sourceSpacing[2] = 2.;
	tomographySource->SetOrigin(sourceOrigin);
	tomographySource->SetSpacing(sourceSpacing);
	tomographySource->SetSize(sourceSize);
	tomographySource->SetConstant(0.);//fill with zeores

									  // Geometry object
	typedef rtk::ThreeDCircularProjectionGeometry GeometryType;

	// Image by Image FDK reconstruction 
	typedef rtk::ImageByImageFDK<OutputImageType, OutputImageType > FDKType;
	FDKType::Pointer feldkamp = FDKType::New();

	//Import Image Filter - it is mainly used to convert the 2d input projections into 3d itk image.
	typedef itk::ImportImageFilter<PixelType, OutputImageDimension >  ImportFilterType;
	ImportFilterType::Pointer importFilter = ImportFilterType::New();

	//the size,spacing,origin of input projections are set as input parameters for import image filter
	ImportFilterType::SizeType  projectionSize = projectionsSource->GetSize();
	projectionSize[2] = 1;  // size along Z
	ImportFilterType::IndexType start;
	start.Fill(0);
	ImportFilterType::RegionType region;
	region.SetIndex(start);
	region.SetSize(projectionSize);
	importFilter->SetRegion(region);

	importFilter->SetOrigin(projectionsSource->GetOrigin());

	importFilter->SetSpacing(projectionsSource->GetSpacing());

	const unsigned int numberOfPixels = projectionSize[0] * projectionSize[1] * projectionSize[2];

	InputImageType::IndexType index;
	InputImageType::PixelType pixelValue;

	//to process each input projection one by one
	for (int i = 0; i < NumberOfProjectionImages; i++)
	{
		//generate input projections file names
		NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();
		const unsigned int first = i;
		const unsigned int last = i;
		nameGenerator->SetSeriesFormat(format.c_str());
		nameGenerator->SetStartIndex(first);
		nameGenerator->SetEndIndex(last);
		nameGenerator->SetIncrementIndex(1);

		//read input projections
		ReaderTypeSeries::Pointer seriesReader = ReaderTypeSeries::New();
		seriesReader->SetImageIO(itk::VTKImageIO::New());
		seriesReader->SetFileNames(nameGenerator->GetFileNames());
		seriesReader->UpdateLargestPossibleRegion();

		//import 2d input to 3d itk image
		InputImageType::Pointer image = InputImageType::New();
		image = seriesReader->GetOutput();

		PixelType * localBuffer = new PixelType[numberOfPixels];
		PixelType * it = localBuffer;
		for (unsigned int z = 0; z < projectionSize[2]; z++)
		{
			for (unsigned int y = 0; y < projectionSize[1]; y++)
			{
				for (unsigned int x = 0; x < projectionSize[0]; x++)
				{
					index[0] = x;
					index[1] = y;
					pixelValue = image->GetPixel(index);
					*it++ = pixelValue;
				}
			}
		}
		const bool importImageFilterWillOwnTheBuffer = true;
		importFilter->SetImportPointer(localBuffer, numberOfPixels, importImageFilterWillOwnTheBuffer);

		//set geometry
		GeometryType::Pointer geometry = GeometryType::New();
		geometry->AddProjection(600., 1200., i*360. / NumberOfProjectionImages, 0, 0, 0, 0, 20, 15);

		//reconstruction
		//In the first iteration we give empty tomographySource asinput and in the following iterations, output of feldkamp is given as input so that we can pile up the contribution of each projection and get the final reconstructed object. 
		if (i == 0)
			feldkamp->SetInput(0, tomographySource->GetOutput());
		else
			feldkamp->SetInput(0, feldkamp->GetOutput());

		feldkamp->SetInput(1, importFilter->GetOutput());
		feldkamp->SetGeometry(geometry);
		TRY_AND_EXIT_ON_ITK_EXCEPTION(feldkamp->Update());
		//std::cout << "reconstruction updated:" << i << std::endl;

		//storing reconstructed object 
		if (i == (NumberOfProjectionImages - 1))
		{
			std::string outputReconstructionFilename;
			outputReconstructionFilename = "final_reconstruction.vtk";

			WriterType::Pointer outputWriter = WriterType::New();
			outputWriter->SetImageIO(itk::VTKImageIO::New());
			outputWriter->SetFileName(outputReconstructionFilename);
			outputWriter->SetInput(feldkamp->GetOutput());
			TRY_AND_EXIT_ON_ITK_EXCEPTION(outputWriter->Update());
			std::cout << "reconstruction stored" << std::endl;
		}

	}

	//Removing Negatives
	typedef itk::ImageFileReader<OutputImageType> ReaderType;
	ReaderType::Pointer outputReader = ReaderType::New();
	outputReader->SetFileName("final_reconstruction.vtk");
	outputReader->Update();

	typedef itk::MinimumMaximumImageCalculator <OutputImageType> ImageCalculatorFilterType;
	ImageCalculatorFilterType::Pointer imageCalculatorFilter = ImageCalculatorFilterType::New();
	imageCalculatorFilter->SetImage(outputReader->GetOutput());
	imageCalculatorFilter->Compute();
	std::cout << "minvalue=" << imageCalculatorFilter->GetMinimum() << " maxvalue=" << imageCalculatorFilter->GetMaximum();
	std::cout << "\n";

	OutputImageType::Pointer output = OutputImageType::New();
	output = outputReader->GetOutput();
	itk::ImageRegionIterator<OutputImageType> it(output, output->GetRequestedRegion());
	it.GoToBegin();
	int temp = 0;

	for (int z = 0; z < sourceSize[2]; z++)
	{
		for (int y = 0; y < sourceSize[1]; y++)
		{
			for (int x = 0; x < sourceSize[0]; x++)
			{
				temp++;
				OutputImageType::IndexType pixelIndex;
				pixelIndex[0] = x;
				pixelIndex[1] = y;
				pixelIndex[2] = z;
				OutputImageType::PixelType pixelValue1;
				pixelValue1 = output->GetPixel(pixelIndex);
				//std::cout << "val=" << pixelValue1 << std::endl;
				if (pixelValue1 < 0)
				{
				//std::cout << "yes";std::cout << "val=" << pixelValue1;std::cout << " entered";std::cout << " x=" << x;std::cout << " y=" << y;std::cout << " z=" << z;std::cout << " temp=" << temp << std::endl;
					output->SetPixel(pixelIndex, 0.0f);
					OutputImageType::PixelType pixelValue2;
					pixelValue2 = output->GetPixel(pixelIndex);
					//std::cout << "valafter=" << pixelValue2 << std::endl;
				}
			}
		}
	}
	imageCalculatorFilter->SetImage(output);
	imageCalculatorFilter->Compute();
	std::cout << "After removing negatives:\n";
	std::cout << "minvalue=" << imageCalculatorFilter->GetMinimum() << " maxvalue=" << imageCalculatorFilter->GetMaximum();

	std::string outputFilename;
	outputFilename = "output.vtk";

	WriterType::Pointer outputWriter = WriterType::New();
	outputWriter->SetImageIO(itk::VTKImageIO::New());
	outputWriter->SetFileName(outputFilename);
	outputWriter->SetInput(output);
	TRY_AND_EXIT_ON_ITK_EXCEPTION(outputWriter->Update());
	std::cout << "\n output stored \n" << std::endl;

	return 0;
}


