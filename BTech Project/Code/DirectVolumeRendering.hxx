#pragma once
#ifndef DirectVolumeRendering_hxx
#define DirectVolumeRendering_hxx

template <typename TInputImage>
DirectVolumeRendering<TInputImage>::DirectVolumeRendering(typename TInputImage::Pointer inputVolume, int noOfThresholds, float* threshold, const char*  inputFilename)
{
	std::vector<vtkSmartPointer<vtkRenderWindowInteractor> > interactors;// to have differnt interactors for volume and transfer function

	int rows = (int)sqrt(noOfThresholds);
	int cols = (int)ceil(noOfThresholds / (float)rows);

	float rowWidth = 1.0 / rows;
	float colWidth = 1.0 / cols;

	float constant = 0.05;			//default opacity for all valid data values

	//one slider widget for each threshold data value so that user can set its opacity
	vtkSmartPointer<vtkRenderWindow> sliderRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> sliderRenderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	sliderRenderWindowInteractor->SetRenderWindow(sliderRenderWindow);
	vtkSmartPointer<vtkRenderer> sliderRenderer = vtkSmartPointer<vtkRenderer>::New();
	sliderRenderWindow->AddRenderer(sliderRenderer);

	std::vector<vtkSmartPointer<vtkSliderWidget>> sliderWidgets; //to have multiple slider widgets

	for (int i = 0;i < noOfThresholds;i++)
	{
		int iRow = i / cols;
		int iCol = i - (iRow * cols);

		vtkSmartPointer<vtkSliderCallback> callback = vtkSmartPointer<vtkSliderCallback>::New();
		callback->index = i;
		callback->SetVals(threshold);

		char text[10];
		sprintf(text, "%.2f", threshold[i]);

		vtkSmartPointer<vtkSliderRepresentation2D> sliderRep = vtkSmartPointer<vtkSliderRepresentation2D>::New();
		sliderRep->SetValue(constant);
		sliderRep->SetTitleText(text);
		sliderRep->GetPoint1Coordinate()->SetCoordinateSystemToNormalizedDisplay();
		sliderRep->GetPoint1Coordinate()->SetValue((iCol*colWidth) + (colWidth / noOfThresholds), iRow*rowWidth + (rowWidth / 2));
		sliderRep->GetPoint2Coordinate()->SetCoordinateSystemToNormalizedDisplay();
		sliderRep->GetPoint2Coordinate()->SetValue(((iCol + 1)*colWidth -(colWidth / noOfThresholds)), iRow*rowWidth + (rowWidth / 2));
		sliderRep->SetSliderLength(0.005);
		sliderRep->SetSliderWidth(0.03);
		sliderRep->SetEndCapLength(0.01);
		sliderRep->SetEndCapWidth(0.03);
		sliderRep->SetTubeWidth(0.005);

		vtkSmartPointer<vtkSliderWidget> sliderWidget = vtkSmartPointer<vtkSliderWidget>::New();
		sliderWidget->SetInteractor(sliderRenderWindowInteractor);
		sliderWidget->SetRepresentation(sliderRep);
		sliderWidget->SetAnimationModeToAnimate();
		sliderWidget->SetCurrentRenderer(sliderRenderer);
		sliderWidget->EnabledOn();
		sliderWidget->AddObserver(vtkCommand::InteractionEvent, callback);
		sliderWidgets.push_back(sliderWidget);

		sliderRenderWindow->Render();
	}
	interactors.push_back(sliderRenderWindowInteractor);

	//Direct Volume Rendering for complete volume
	typedef itk::ImageToVTKImageFilter< TInputImage > FilterType;			//converting itk data to vtk data
	FilterType::Pointer filter = FilterType::New();
	filter->SetInput(inputVolume);
	filter->Update();
	vtkSmartPointer<vtkImageData> vtkData = vtkSmartPointer<vtkImageData>::New();
	vtkData->ShallowCopy(filter->GetOutput());

	ren1->SetBackground(0.1, 0.4, 0.2);

	renWin->AddRenderer(ren1);

	renWin->SetSize(301, 300); // intentional odd and NPOT  width/height

	vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	iren->SetRenderWindow(renWin);

	renWin->Render(); // make sure we have an OpenGL context.

	vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
	volumeMapper->SetBlendModeToComposite(); // composite first
#if VTK_MAJOR_VERSION <= 5
	volumeMapper->SetInputConnection(imageData->GetProducerPort());
#else
	volumeMapper->SetInputData(vtkData);
#endif  
	volumeProperty->ShadeOff();
	volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);

	/*for (int j = 0;j < noOfThresholds;j++)
	{
		if (threshold[j] == 0)
			compositeOpacity->AddPoint(threshold[j], 0.0);
		else
			compositeOpacity->AddPoint(threshold[j], constant);
	}*/
	compositeOpacity->AddPoint(0, 0.0);
	for (int j = 0;j < noOfThresholds;j++)
	{
		if (threshold[j] == 0)
		{
			compositeOpacity->AddPoint(threshold[j], 0.0);
		}
		else if (j == 0)
		{
			compositeOpacity->AddPoint(threshold[j], 0.0);
			compositeOpacity->AddPoint(threshold[j], constant);
		}
		else if (j == (noOfThresholds - 1))
		{
			compositeOpacity->AddPoint(threshold[j], constant);
			compositeOpacity->AddPoint(threshold[j], 0);
		}
		else
		{
			compositeOpacity->AddPoint(threshold[j], constant);
		}		
	}
	compositeOpacity->AddPoint(65535, 0.0);
	volumeProperty->SetScalarOpacity(compositeOpacity); // composite first.

	vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
	color->AddRGBPoint(0.0, 0.0, 0.0, 1.0);
	color->AddRGBPoint(40.0, 1.0, 0.0, 0.0);
	color->AddRGBPoint(255.0, 1.0, 1.0, 1.0);
	volumeProperty->SetColor(color);

	volume->SetMapper(volumeMapper);
	volume->SetProperty(volumeProperty);
	
	ren1->AddViewProp(volume);
	ren1->ResetCamera();

	// Render composite. In default mode. For coverage.
	renWin->Render();

	// 3D texture mode. For coverage.
#if !defined(VTK_LEGACY_REMOVE) && !defined(VTK_OPENGL2)
	volumeMapper->SetRequestedRenderModeToRayCastAndTexture();
#endif // VTK_LEGACY_REMOVE
	renWin->Render();

	// Software mode, for coverage. It also makes sure we will get the same
	// regression image on all platforms.
	volumeMapper->SetRequestedRenderModeToRayCast();
	renWin->Render();

	interactors.push_back(iren);

	//interactors[1]->Start();

	//Display the volume corresponding to the threshold data values using Direct Volume Rendering
	vtkSmartPointer<vtkRenderWindow> thresholdsRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();

	vtkSmartPointer<vtkRenderWindowInteractor> thresholdsRenderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

	thresholdsRenderWindowInteractor->SetRenderWindow(thresholdsRenderWindow);
	interactors.push_back(thresholdsRenderWindowInteractor);

	for (int i = 0;i < noOfThresholds;i++)
	{
		vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer<vtkRenderer>::New();
		vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
		vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
		vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();

		int iRow = i / cols;
		int iCol = i - (iRow * cols);

		ren1->SetBackground(0.1, 0.4, 0.2);
		thresholdsRenderWindow->AddRenderer(ren1);
		ren1->SetViewport(iCol*colWidth, iRow*rowWidth, (iCol + 1)*colWidth, (iRow + 1)*rowWidth);

		thresholdsRenderWindow->Render(); // make sure we have an OpenGL context.

		vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
		volumeMapper->SetBlendModeToComposite(); // composite first
#if VTK_MAJOR_VERSION <= 5
		volumeMapper->SetInputConnection(imageData->GetProducerPort());
#else
		volumeMapper->SetInputData(vtkData);
#endif  
		volumeProperty->ShadeOff();
		volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);

		for (int j = 0;j < noOfThresholds;j++)
		{
			if (threshold[j] == 0 && i != 0)
				compositeOpacity->AddPoint(threshold[j], 0.0);
			else if (i == 0)
				compositeOpacity->AddPoint(threshold[j], 1);
			else if (j == i)
				compositeOpacity->AddPoint(threshold[j], 1);
			else
				compositeOpacity->AddPoint(threshold[j], 0.0);
		}
		/*compositeOpacity->AddPoint(0, 0.0);
		compositeOpacity->AddPoint(threshold[i], 0.0);
		compositeOpacity->AddPoint(threshold[i], 1.0);
		compositeOpacity->AddPoint(threshold[i+1], 1.0);
		compositeOpacity->AddPoint(threshold[i + 1], 0.0);
		compositeOpacity->AddPoint(65535, 0.0);*/

		volumeProperty->SetScalarOpacity(compositeOpacity); // composite first.

		vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
		color->AddRGBPoint(0.0, 0.0, 0.0, 1.0);
		color->AddRGBPoint(40.0, 1.0, 0.0, 0.0);
		color->AddRGBPoint(255.0, 1.0, 1.0, 1.0);
		volumeProperty->SetColor(color);

		volume->SetMapper(volumeMapper);
		volume->SetProperty(volumeProperty);
		ren1->AddViewProp(volume);
		ren1->ResetCamera();

		// Setup the text and add it to the renderer
		char text[10];
		sprintf(text, "%.2f", threshold[i]);
		vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
		textActor->SetInput(text);
		textActor->SetPosition2(10, 20);
		textActor->GetTextProperty()->SetFontSize(15);
		textActor->GetTextProperty()->SetColor(0.0, 0.0, 0.0);
		ren1->AddActor2D(textActor);

		// Render composite. In default mode. For coverage.
		thresholdsRenderWindow->Render();

		// 3D texture mode. For coverage.
#if !defined(VTK_LEGACY_REMOVE) && !defined(VTK_OPENGL2)
		volumeMapper->SetRequestedRenderModeToRayCastAndTexture();
#endif // VTK_LEGACY_REMOVE
		thresholdsRenderWindow->Render();

		// Software mode, for coverage. It also makes sure we will get the same
		// regression image on all platforms.
		volumeMapper->SetRequestedRenderModeToRayCast();
		thresholdsRenderWindow->Render();
	}
	interactors[2]->Start();

	/*//generate isosurfaces corresponding to threshold data values using iso surface extraction
	int extractLargest = 1;
	vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();

	// Load data
	vtkSmartPointer<vtkStructuredPointsReader> reader1 = vtkSmartPointer<vtkStructuredPointsReader>::New();
	reader1->SetFileName(inputFilename);

	vtkSmartPointer<vtkRenderWindow> isoSurfacesRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> isoSurfacesRenderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	isoSurfacesRenderWindowInteractor->SetRenderWindow(isoSurfacesRenderWindow);
	isoSurfacesRenderWindowInteractor->Initialize();
	interactors.push_back(isoSurfacesRenderWindowInteractor);

	for (int i = 0;i < noOfThresholds;i++)
	{
		// Create a 3D model using marching cubes
		vtkSmartPointer<vtkMarchingCubes> mc = vtkSmartPointer<vtkMarchingCubes>::New();
		mc->SetInputConnection(reader1->GetOutputPort());
		mc->ComputeNormalsOn();
		mc->ComputeGradientsOn();
		mc->SetValue(0, threshold[i]);  // second value acts as threshold

		// To remain largest region
		vtkSmartPointer<vtkPolyDataConnectivityFilter> confilter = vtkSmartPointer<vtkPolyDataConnectivityFilter>::New();
		confilter->SetInputConnection(mc->GetOutputPort());
		confilter->SetExtractionModeToLargestRegion();

		// Create a mapper
		vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
		if (extractLargest)
		{
			mapper->SetInputConnection(confilter->GetOutputPort());
		}
		else
		{
			mapper->SetInputConnection(mc->GetOutputPort());
		}
		mapper->ScalarVisibilityOff();    // utilize actor's property I set

		// Visualize
		vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
		actor->GetProperty()->SetColor(colors->GetColor3d("Flesh").GetData());
		actor->SetMapper(mapper);

		int iRow = i / cols;
		int iCol = i - (iRow * cols);

		// Setup the text and add it to the renderer
		char text[10];
		sprintf(text, "%.2f", threshold[i]);
		vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
		textActor->SetInput(text);
		textActor->SetPosition2(10, 20);
		textActor->GetTextProperty()->SetFontSize(15);
		textActor->GetTextProperty()->SetColor(0.0, 0.0, 0.0);

		vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
		renderer->AddActor(actor);
		renderer->SetBackground(colors->GetColor3d("Burlywood").GetData());
		renderer->GetActiveCamera()->SetViewUp(0.0, 0.0, 1.0);
		renderer->GetActiveCamera()->SetPosition(0.0, 1.0, 0.0);
		renderer->GetActiveCamera()->SetFocalPoint(0.0, 0.0, 0.0);
		renderer->ResetCamera();
		renderer->GetActiveCamera()->Azimuth(30.0);
		renderer->GetActiveCamera()->Elevation(30.0);
		renderer->AddActor2D(textActor);
		renderer->SetViewport(iCol*colWidth, iRow*rowWidth, (iCol + 1)*colWidth, (iRow + 1)*rowWidth);

		isoSurfacesRenderWindow->AddRenderer(renderer);
	}

	interactors[3]->Start();*/
    


}


#endif // DirectVolumeRendering_hxx