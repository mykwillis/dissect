#ifndef _CSmxImageHlp_H
#define _CSmxImageHlp_H

#include "resource.h"

class CSmxImageHlp : 
	public IDisSmX,
	public CComObjectRoot,
	public CComCoClass<CSmxImageHlp, &CLSID_SmxImageHlp>
{
public:
	//
	// ATL Housekeeping
	//
	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_CSMXIMAGEHLP);

	BEGIN_COM_MAP(CSmxImageHlp)
		COM_INTERFACE_ENTRY(IDisSmX)
	END_COM_MAP()

	//
	// IDisSymMgr methods
	//
	STDMETHOD(Extract)(IDisImg *Image, IDisSymMgr *SymbolManager);

private:
	static BOOL CALLBACK EnumFunctions_Callback(LPSTR SymbolName, ULONG SymbolAddress, ULONG SymbolSize, PVOID UserContext);

};

#endif // _CSmxImageHlp_H