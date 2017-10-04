// ClassName.h : Declaration of the CClassName

#ifndef __CLASSNAME_H_
#define __CLASSNAME_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CClassName
class ATL_NO_VTABLE CClassName : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CClassName, &CLSID_ClassName>
{
public:
	CClassName()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CLASSNAME)

BEGIN_COM_MAP(CClassName)
	COM_INTERFACE_ENTRY(IClassName)
END_COM_MAP()

// IClassName
public:
};

//_CopyInterface<IClassName *>;
//CComIEnum<IClassName *>;
//CComEnum<IEnumIClassName, &IID_IClassName, IClassName *, _CopyInterface<IClassName *> >
//enumerator;

#endif //__CLASSNAME_H_
