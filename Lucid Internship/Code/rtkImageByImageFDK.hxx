#pragma once
/*=================================,========================================
*
*  Copyright RTK Consortium
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*         http://www.apache.org/licenses/LICENSE-2.0.txt
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*
*=========================================================================*/

#ifndef rtkImageByImageFDK_hxx
#define rtkImageByImageFDK_hxx

namespace rtk
{

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::ImageByImageFDK() :
		m_ProjectionSubsetSize(1)
		/*projection subset size is fixed to 1 as only one input projection is given for processing  */
	{
		this->SetNumberOfRequiredInputs(1);

		// Create each filter of the composite filter
		m_WeightFilter = WeightFilterType::New();
		m_RampFilter = RampFilterType::New();
		this->SetBackProjectionFilter(BackProjectionFilterType::New());

		//Permanent internal connections
		m_RampFilter->SetInput(m_WeightFilter->GetOutput());

		// Default parameters
		m_WeightFilter->InPlaceOn();

		// Default to one projection per subset when FFTW is not available
#if !defined(USE_FFTWD)
		if (typeid(TFFTPrecision).name() == typeid(double).name())
			m_ProjectionSubsetSize = 2;
#endif
#if !defined(USE_FFTWF)
		if (typeid(TFFTPrecision).name() == typeid(float).name())
			m_ProjectionSubsetSize = 2;
#endif
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::GenerateInputRequestedRegion()
	{
		typename Superclass::InputImagePointer inputPtr =
			const_cast< TInputImage * >(this->GetInput());
		if (!inputPtr)
			return;

		//SR: is this useful?
		m_BackProjectionFilter->SetInput(0, this->GetInput(0));
		m_BackProjectionFilter->SetInPlace(this->GetInPlace());
		m_WeightFilter->SetInput(this->GetInput(1));
		m_BackProjectionFilter->GetOutput()->SetRequestedRegion(this->GetOutput()->GetRequestedRegion());
		m_BackProjectionFilter->GetOutput()->PropagateRequestedRegion();
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::GenerateOutputInformation()
	{
		const unsigned int Dimension = this->InputImageDimension;

		// Run composite filter update
		m_BackProjectionFilter->SetInput(0, this->GetInput(0));
		m_BackProjectionFilter->SetInPlace(this->GetInPlace());
		m_WeightFilter->SetInput(this->GetInput(1));
		m_BackProjectionFilter->UpdateOutputInformation();

		// Update output information
		this->GetOutput()->SetOrigin(m_BackProjectionFilter->GetOutput()->GetOrigin());
		this->GetOutput()->SetSpacing(m_BackProjectionFilter->GetOutput()->GetSpacing());
		this->GetOutput()->SetDirection(m_BackProjectionFilter->GetOutput()->GetDirection());
		this->GetOutput()->SetLargestPossibleRegion(m_BackProjectionFilter->GetOutput()->GetLargestPossibleRegion());

	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::GenerateData()
	{
		const unsigned int Dimension = this->InputImageDimension;

		{
			m_PreFilterProbe.Start();
			m_WeightFilter->Update();
			m_PreFilterProbe.Stop();

			m_FilterProbe.Start();
			m_RampFilter->Update();
			m_FilterProbe.Stop();

			m_BackProjectionProbe.Start();
			m_BackProjectionFilter->Update();
			m_BackProjectionProbe.Stop();
		}

		this->GraftOutput(m_BackProjectionFilter->GetOutput());
		this->GenerateOutputInformation();
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	ThreeDCircularProjectionGeometry::Pointer
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::GetGeometry()
	{
		return this->m_WeightFilter->GetGeometry();
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::SetGeometry(const ThreeDCircularProjectionGeometry::Pointer _arg)
	{
		itkDebugMacro("setting GeometryPointer to " << _arg);
		if (this->GetGeometry() != _arg)
		{
			m_WeightFilter->SetGeometry(_arg);
			m_BackProjectionFilter->SetGeometry(_arg.GetPointer());
			this->Modified();
		}
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::PrintTiming(std::ostream& os) const
	{
		os << "FDKConeBeamReconstructionFilter timing:" << std::endl;
		os << "  Prefilter operations: " << m_PreFilterProbe.GetTotal()
			<< ' ' << m_PreFilterProbe.GetUnit() << std::endl;
		os << "  Ramp filter: " << m_FilterProbe.GetTotal()
			<< ' ' << m_FilterProbe.GetUnit() << std::endl;
		os << "  Backprojection: " << m_BackProjectionProbe.GetTotal()
			<< ' ' << m_BackProjectionProbe.GetUnit() << std::endl;
	}

	template<class TInputImage, class TOutputImage, class TFFTPrecision>
	void
		ImageByImageFDK<TInputImage, TOutputImage, TFFTPrecision>
		::SetBackProjectionFilter(const BackProjectionFilterPointer _arg)
	{
		itkDebugMacro("setting BackProjectionFilter to " << _arg);
		if (this->m_BackProjectionFilter != _arg)
		{
			this->m_BackProjectionFilter = _arg;
			m_BackProjectionFilter->SetInput(1, m_RampFilter->GetOutput());
			this->Modified();
		}
	}

} // end namespace rtk

#endif // rtkFDKConeBeamReconstructionFilter_hxx
