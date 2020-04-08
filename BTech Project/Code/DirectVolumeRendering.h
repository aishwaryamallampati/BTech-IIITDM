#pragma once
#ifndef DirectVolumeRendering_h
#define DirectVolumeRendering_h

#include <itkImage.h>
#include <itkHistogram.h>
#include <itkImageToVTKImageFilter.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>

#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkStructuredPointsReader.h>
#include <vtkMarchingCubes.h>
#include <vtkNamedColors.h>
#include <vtkPolyDataConnectivityFilter.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkSliderWidget.h>
#include <vtkPolyDataMapper.h>
#include <vtkSliderRepresentation2D.h>



vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer<vtkRenderer>::New();
vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();


template <typename TInputImage>
class DirectVolumeRendering
{
	typedef float MeasurementType;
	typedef itk::Statistics::Histogram< MeasurementType, itk::Statistics::DenseFrequencyContainer2 > HistogramType;
public:
	DirectVolumeRendering(typename TInputImage::Pointer inputVolume, int noOfThresholds, float* threshold, const char* inputFilename);
};

// This does the actual work.
// Callback for the interaction
class vtkSliderCallback : public vtkCommand
{
public:
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	static vtkSliderCallback *New()
	{
		return new vtkSliderCallback;
	}
	virtual void Execute(vtkObject *caller, unsigned long, void*)
	{
		vtkSliderWidget *sliderWidget = reinterpret_cast<vtkSliderWidget*>(caller);
		float val = (static_cast<vtkSliderRepresentation *>(sliderWidget->GetRepresentation())->GetValue());
		compositeOpacity->AddPoint(userThreshold[this->index], val);
		volumeProperty->SetScalarOpacity(compositeOpacity); // composite first.
		volume->SetProperty(volumeProperty);
		ren1->AddViewProp(volume);
		renWin->AddRenderer(ren1);
		renWin->Render();
		cout << "dataValue=" << userThreshold[this->index] << "\topacity value=" << val << "\n";
	}

	int index;				//corresponds to the index in userThreshold[] array

	void SetVals(float threshold[]) 
	{
		userThreshold = threshold;
	}

private:
	float *userThreshold;
};


#ifndef ITK_MANUAL_INSTANTIATION
#include "DirectVolumeRendering.hxx"
#endif

#endif