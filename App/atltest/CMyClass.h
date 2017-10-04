#ifndef _CMYCLASS_H
#define _CMYCLASS_H
#include "resource.h"       // main symbols
extern "C" {
extern const GUID IID_IMyClass;
extern const CLSID CLSID_MyClass;
};

interface IMyClass : public IUnknown {
	STDMETHOD(Foo)() PURE;
};

class CMyClass : 
	public IMyClass, 
	public CComObjectRoot,
	public CComCoClass<CMyClass, &CLSID_MyClass>
{
public:

	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_MYCLASS)

	BEGIN_COM_MAP(CMyClass)
		COM_INTERFACE_ENTRY(IMyClass)
	END_COM_MAP()

	STDMETHOD(Foo)() { ::MessageBox(NULL, "Hi", "Howdy", MB_OK); return S_OK;}
};

#endif // CMTCLASS

