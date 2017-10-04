#include "project.h"
#include "CDisassembler.h"
#include "guids.h"

HANDLE g_hModule = NULL;
ULONG	g_cComponents = 0;
ULONG	g_cServerLocks = 0;
BOOL
WINAPI
DllMain (HANDLE hModule, ULONG reason, LPVOID )
{
	if (reason == DLL_PROCESS_ATTACH)
		g_hModule = hModule;
	return TRUE;
}

STDAPI DllCanUnloadNow()
{
	if ( (g_cComponents == 0) && (g_cServerLocks == 0) )	{
		return S_OK;
	} else {
		return S_FALSE;
	}
}

class CFactory : public IClassFactory, public CUnknown
{
public:
	CFactory() : CUnknown(NULL)
	{ /* empty */ }

	DECLARE_IUNKNOWN

	STDMETHOD(NondelegatingQueryInterface)(const IID& iid, void ** ppv)
	{
		if (iid == IID_IClassFactory)	{
			return FinishQI(static_cast<IClassFactory *>(this), ppv);
		} else {
			return CUnknown::NondelegatingQueryInterface(iid, ppv);
		}

	}

	STDMETHOD(CreateInstance)(IUnknown *punkOuter, REFIID riid, void **ppv)
	{
		if (punkOuter != NULL)
			return CLASS_E_NOAGGREGATION;

		CDisassembler *pDis = new CDisassembler;
		return pDis->QueryInterface(riid, ppv);
	}

	STDMETHOD(LockServer)(BOOL b)
	{ if (b) g_cServerLocks++; else g_cServerLocks--; return S_OK; }
		
};

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void **ppv)
{
	if (clsid != CLSID_Disx86)
		return CLASS_E_CLASSNOTAVAILABLE;

	CFactory *pFactory = new CFactory;
	HRESULT hr = pFactory->QueryInterface(iid, ppv);
	pFactory->Release();	// safe, since QI will have upped count
	return hr;
}

STDAPI DllRegisterServer()
{
	//
	// ALERT: Register component here...
	//

	//
	// Register this component under the CATID_DisDisassembler key
	//
	ICatRegister *pIReg;
	HRESULT hr = CoCreateInstance (
			CLSID_StdComponentCategoriesMgr, NULL,
            CLSCTX_INPROC_SERVER, IID_ICatRegister,
            (void **)&pIReg);

	if ( FAILED(hr) )	{
		OutputDebugString("Disasm: Could not get ICatRegister\n");
		return hr;
	}

	hr = pIReg->RegisterClassImplCategories(
			CLSID_Disx86,
			1, 
			(GUID *)&CATID_DisDisassembler);

	if ( FAILED(hr) )	{
		OutputDebugString("Disasm: RegisterClassImplCategories failed\n");
	}

 	pIReg->Release();

	return S_OK;
}

STDAPI DllUnregisterServer()
{
	return S_OK;
}