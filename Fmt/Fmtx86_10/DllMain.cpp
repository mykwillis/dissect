#include "project.h"
#include "resource.h"
#include "CInstructionFormatter.h"

//
// Include the private CLSIDs
//
#include <objbase.h>
#include <initguid.h> 
#include "guids.h"

//
// Include the necessary external interface GUIDs
//
#include "..\..\common\fmt_i.c"

//
// Declare the global class that handles registration, etc.
//
CComModule _Module;

//
// Declare object map of all class served by this module
//
BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_Fmtx86, CInstructionFormatter)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		_Module.Init(ObjectMap, hInstance);
		DisableThreadLibraryCalls(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
		_Module.Term();
	return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
	return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	// registers object, typelib and all interfaces in typelib
	// FALSE indicates that no typelib should be registered
	return _Module.RegisterServer(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	_Module.UnregisterServer();
#if _WIN32_WINNT >= 0x0400
//	UnRegisterTypeLib(LIBID_ATLTESTLib, 1, 0, LOCALE_USER_DEFAULT, SYS_WIN32);
#endif
	return S_OK;
}

