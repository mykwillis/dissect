#include "project.h"
#include "CLdr.h"

CLdr::CLdr()
{
	for (int i=0;i<_MAX_IMAGES;i++)
		m_Images[0] = NULL;
	m_NumberOfImages = 0;
}
CLdr::~CLdr()
{
	for (int i=0;i<m_NumberOfImages;i++)	{
		m_Images[i]->Release();
		m_Images[i] = NULL;
	}
	m_NumberOfImages = 0;
}
STDMETHODIMP
CLdr::Load(BSTR bsName, IDisImg **ppImage)
{
	if ( m_NumberOfImages >= _MAX_IMAGES )
		return E_FAIL;

	// BUGBUG: of course, we have to implement this...
	HRESULT h = ::CoCreateInstance(CLSID_ImgPE, NULL, CLSCTX_ALL, IID_IDisImg, (void **)&m_Images[m_NumberOfImages]);
	if (FAILED(h))
		return E_FAIL;
	
	m_Images[m_NumberOfImages]->AddRef();
	*ppImage = m_Images[m_NumberOfImages];
	m_NumberOfImages++;

	return (*ppImage)->Load(bsName);
}

STDMETHODIMP
CLdr::EnumImages(IEnumImages **ppEnum)
{
	typedef CComEnum<IEnumImages, &IID_IEnumImages, IDisImg *, _CopyInterface<IDisImg> > CEnumImages;
	CComObject<CEnumImages> *Enum = new CComObject<CEnumImages>;
	Enum->Init(&m_Images[0], &m_Images[m_NumberOfImages], NULL, AtlFlagCopy);
	HRESULT hr = Enum->_InternalQueryInterface(IID_IEnumImages, (void**)ppEnum);
	if (FAILED(hr))
		delete Enum;
	
	return hr;
}

STDMETHODIMP
CLdr::ConvertVirtualAddressToPtr(IN DWORD Address, OUT DWORD *Ptr)
{
	//
	// loop through the images, returning when either one of the
	// images returns success, or we finish the list.
	//
	for (int i=0;i<m_NumberOfImages;i++)	{
		HRESULT hr = m_Images[i]->ConvertVAToPtr(Address, Ptr);
		if ( SUCCEEDED(hr) )
			return hr;
	}
	return E_FAIL;
}
