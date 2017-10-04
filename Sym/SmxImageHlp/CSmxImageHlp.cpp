#include "project.h"
#include "CSmxImageHlp.h"

STDMETHODIMP
CSmxImageHlp::Extract(IDisImg *Image, IDisSymMgr *SymbolManager)
{
	//
	// Snag the image name
	//
	CComBSTR bsName;
	HRESULT h = Image->GetImagePath(&bsName);
	if ( FAILED(h) )
		return h;

	astring NameA(bsName);	// convert to ASCII

	//
	// Get the image load address
	//
	DWORD ImageBase;
	h = Image->GetPreferredLoadAddress(&ImageBase);
	if ( FAILED(h) )
		return h;

	//
	// Initialize SymbolHlp
	//
	BOOL rc = SymInitialize( 
		::GetCurrentProcess(),  // arbitrary handle value
		NULL,					// symbol search path
		FALSE );				// (don't) invade process
	if (!rc)	{
		return E_FAIL;
	}
	SymSetOptions( SYMOPT_UNDNAME );

	//
	// Load the module
	//
	rc = SymLoadModule( ::GetCurrentProcess(), 0, NameA, NULL, ImageBase, 0 );
	if (!rc)	{
		return E_FAIL;
	}

	//
	// Get the module information
	//
	IMAGEHLP_MODULE	ImageModule;
	ImageModule.SizeOfStruct = sizeof(IMAGEHLP_MODULE);
	rc = SymGetModuleInfo( ::GetCurrentProcess(), ImageBase, &ImageModule );
	if (!rc)	{
		return E_FAIL;
	}

	//
	// Convert the imagehelp module information to
	// Dissect format, and add it to the SymbolManager
	//
	wstring ModuleNameW(ImageModule.ModuleName);
	wstring ModulePathW(ImageModule.LoadedImageName);

	MODULE_INFO	ModuleInfo;
	ModuleInfo.BaseAddress	= ImageModule.BaseOfImage;
	ModuleInfo.Size			= ImageModule.ImageSize;
	ModuleInfo.Name			= ::SysAllocString( ModuleNameW );
	ModuleInfo.DocString	= ::SysAllocString( ModulePathW );

	CComPtr<IModule> pIModule;
	h = SymbolManager->AddModule(&pIModule, &ModuleInfo);
	if (FAILED(h))
		return h;

	::SysFreeString( ModuleInfo.Name );
	::SysFreeString( ModuleInfo.DocString );

	//
	// Enumerate the symbols into the IModule
	//
	SymEnumerateSymbols( ::GetCurrentProcess(), ImageModule.BaseOfImage, EnumFunctions_Callback, (PVOID)pIModule );

	SymCleanup( ::GetCurrentProcess() );

	return S_OK;
}

//static
BOOL 
CALLBACK 
CSmxImageHlp::EnumFunctions_Callback(
	LPSTR SymbolName, 
	ULONG SymbolAddress, 
	ULONG SymbolSize, 
	PVOID UserContext)
{
	wstring SymbolNameW(SymbolName);
	IModule *pIModule = (IModule *)UserContext;

	SYMBOL_INFO	Symbol;
	Symbol.Name			= ::SysAllocString(SymbolNameW);
	Symbol.DocString	= NULL;
	Symbol.Address		= SymbolAddress;
	Symbol.Size			= SymbolSize;
	Symbol.SymKind		= SKIND_UNKNOWN;


	HRESULT h = pIModule->AddSymbol(NULL, &Symbol);
	if ( FAILED(h) )	{
		h = h;	// shit!
	}

	::SysFreeString(Symbol.Name);

	return TRUE;	// continue
}

