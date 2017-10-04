#ifndef _CLDR_H
#define _CLDR_H

#include "resource.h"

#define _MAX_IMAGES	20

class CLdr : 
	public IDisLdr,
	public CComObjectRoot,
	public CComCoClass<CLdr, &CLSID_Ldr>
{
public:
	//
	// ATL Housekeeping
	//
	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_CLDR);

	BEGIN_COM_MAP(CLdr)
		COM_INTERFACE_ENTRY(IDisLdr)
	END_COM_MAP()

	//
	// IDisLdr methods
	//
	STDMETHOD(Load)(BSTR bsName, IDisImg **ppImage);
	STDMETHOD(EnumImages)(IEnumImages **ppEnum);
	STDMETHOD(ConvertVirtualAddressToPtr)(IN DWORD Address, OUT DWORD *Ptr);
	CLdr();
	~CLdr();
private:
	int m_NumberOfImages;
	IDisImg *m_Images[_MAX_IMAGES];
};

#endif _CLDR_H