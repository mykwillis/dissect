#ifndef _CPEImage_H
#define _CPEImage_H

#include "resource.h"

#ifndef NO_IMAGEHLP
#	include <imagehlp.h>
#endif

#define BUILDPTR( cast, ptr, addvalue) (cast)( (DWORD)(ptr)+(DWORD)(addvalue))
#define IMAGE_NUMBEROF_ALIGN_FLAGS	8
#define	IMAGE_SCN_ALIGN_MASK	0x00F00000

typedef struct {
	char *pszName;
	char *pszDescription;
} IMAGE_DATA_DIRECTORY_NAMES;

typedef struct {
	DWORD	dwValue;
	char *pszName;
	char *pszDescription;
} IMAGE_SCN_FLAG_NAMES;

typedef struct tagEXPORTED_FUNCTION {
	WORD	wOrdinal;	// the real ordinal value of this export
	PVOID	pEntry;		// pointer to function's entry point
	DWORD	dwImageOff;	// the RVA of entry point
	PSTR	pszName[256];// name of exported function (may be MODULE!123 style)
	DWORD	dwFlags;

	void clear(void) {
		memset(this, 0, sizeof(this));
	}

	tagEXPORTED_FUNCTION() {
		clear();
	}
} EXPORTED_FUNCTION, *PEXPORTED_FUNCTION;

#define EXPORTED_FUNCTION_BY_NAME	0x1	// function exported by name


// callback function type for EnumImportModules()
typedef void (*PFUNC_CPE_ENUM_IMPORT_MODULES)
	(PIMAGE_IMPORT_DESCRIPTOR pDesc, DWORD dwExtra);

// callback function type for EnumDataDirectories()
typedef void (*PFUNC_CPE_ENUM_DATA_DIRECTORIES )
	(PIMAGE_DATA_DIRECTORY pDataDir, DWORD dwDir, DWORD dwExtra);

// callback function type for EnumSections()
typedef void (*PFUNC_CPE_ENUM_SECTIONS )
	(PIMAGE_SECTION_HEADER pSectionHeader, DWORD dwExtra);

// callback function type for EnumImportThunkData()
typedef void (*PFUNC_CPE_ENUM_THUNK_DATA )
	(PIMAGE_THUNK_DATA pDesc, DWORD dwExtra);

// callback function type for EnumExports()
typedef void (*PFUNC_CPE_ENUM_EXPORTS )
	(PEXPORTED_FUNCTION pExFunc, DWORD dwExtra);

class CPEImage :
	public IDisImg, 
	public CComObjectRoot,
	public CComCoClass<CPEImage, &CLSID_ImgPE>
{
private:
	// the PIMAGE_DOS_HEADER is at the beginning of every loaded
	// and on-disk Win32 module.
	PIMAGE_DOS_HEADER	m_pDosHeader;

	// pDosHeader + pDosHeader->e_lfanew points to the *real* header
	// for a Win32 module.
	PIMAGE_NT_HEADERS	m_pNtHeaders;

		// This value (actually within the pNtHeaders structure) contains
		// PE\0\0 for a Win32 executable.
		DWORD	m_dwSignature;

		// the pFileHeader is actually within the pNtHeaders
		// structure above.  This contains basic info about the file.
		PIMAGE_FILE_HEADER	m_pFileHeader;

		// the pOptionalHeader is where most of the interesting pointers
		// from the module are.  This structure is also contained within
		// the pNtHeaders structure.
		PIMAGE_OPTIONAL_HEADER	m_pOptionalHeader;

			// The NumberOfRvaAndSizes field of the pOptionalHeader structure.
			// this is the number of entries in the following array.
			DWORD	m_dwNumDataDirectories;

			// the pDataDirectory points to the array of structures that
			// contain the RVA and sizes of important chunks of the module.
			PIMAGE_DATA_DIRECTORY	m_pDataDirectory;

	// Immediately following the pNtHeaders structure is an array of
	// IMAGE_SECTION_HEADERS.  the number of elements is given by
	// pNtHeaders->FileHeader.NumberOfSections
	PIMAGE_SECTION_HEADER	m_pSectionHeaders;
	
	// pNtHeaders->FileHeader.NumberOfSections
	DWORD m_dwNumSectionHeaders;

	// number of import modules is calculated first time needed
	DWORD m_dwNumImportModules;
	
	// number of imports is calculated first time needed
	DWORD m_dwNumImports;

	struct	{
		UINT	bIsValid: 1;	// module has been successfully loaded/mapped
	} m_flags;

public:
	DECLARE_CLASSFACTORY();

	DECLARE_REGISTRY_RESOURCEID(IDR_CPEIMAGE);

	BEGIN_COM_MAP(CPEImage)
		COM_INTERFACE_ENTRY(IDisImg)
	END_COM_MAP()


public:
	//
	// Construction/Destruction
	//
	CPEImage();
	CPEImage(const char *pszModuleName)
	{ _clear(); MapDiskImage(pszModuleName); }
	~CPEImage();
	BOOL	MapDiskImage(const char *pszFileName);


	//
	// IDisImage methods
	//
	STDMETHOD(Load)(BSTR bstrName)
	{
		astring name(bstrName);
		BOOL rc = MapDiskImage(name);
		return rc? S_OK : E_FAIL;
	}

	STDMETHOD(GetImagePath)(BSTR *pbsPath)
	{
		if ( ! isValid() )	{
			return E_FAIL;
		}
		else	{
			int s = MultiByteToWideChar(CP_ACP, 0, ModuleName(), -1, NULL, 0);
			wchar_t *path = new wchar_t[s];
			MultiByteToWideChar(CP_ACP, 0, ModuleName(), -1, path, s);
			*pbsPath = ::SysAllocString(path);
			delete [] path;
			return S_OK;
		}
	}
		

	STDMETHOD(ConvertRVAToPtr)(DWORD dwRVA, PDWORD pdwPtr)
	{
		*pdwPtr = (DWORD)ConvertRVAToPtr(dwRVA);
		if (*pdwPtr) return S_OK; else return E_FAIL;
	}

	STDMETHOD(ConvertVAToPtr)(DWORD dwVA, PDWORD pdwPtr)
	{
		*pdwPtr = (DWORD) ConvertVirtualAddressToPtr(dwVA);
		if (*pdwPtr) return S_OK; else return E_FAIL;
	}

	STDMETHOD(ConvertPtrToVA)(DWORD dwPtr, PDWORD pdwVA)
	{	dwPtr; pdwVA; return E_FAIL;	}

	STDMETHOD(GetEntryPointPtr)(PDWORD pdwEntry)
	{ 
		return ConvertRVAToPtr( OptionalHeader()->AddressOfEntryPoint, pdwEntry );
	}
	STDMETHOD(GetPreferredLoadAddress)(PDWORD pdwVA)
	{ 
		*pdwVA = OptionalHeader()->ImageBase;
		return S_OK;
	}


	STDMETHOD(EnumImports)(IDisEnumImports **ppEnum);
	STDMETHOD(EnumExports)(IDisEnumExports **ppEnum);
	STDMETHOD(EnumSections)(IEnumSections **ppEnum);

	//
	// Enumeration methods
	//
	DWORD EnumSections(PFUNC_CPE_ENUM_SECTIONS pFunc, DWORD dwExtra) const;
	DWORD EnumDataDirectories(PFUNC_CPE_ENUM_DATA_DIRECTORIES pFunc, DWORD dwExtra) const;
	DWORD EnumExports(PFUNC_CPE_ENUM_EXPORTS pFunc, DWORD dwExtra) const;
	DWORD EnumImportModules(PFUNC_CPE_ENUM_IMPORT_MODULES pFunc, DWORD dwExtra) const;
	DWORD EnumImportThunkData(PIMAGE_IMPORT_DESCRIPTOR pDesc, PFUNC_CPE_ENUM_THUNK_DATA pFunc, DWORD dwExtra) const;
	

	// Convert an image-relative virtual address to a dereferencable pointer
	PVOID ConvertRVAToPtr(DWORD dwRVA) const;

	// Convert a file-relative offset to a dereferencable pointer
	PVOID ConvertFOToPtr(DWORD dwFO) const;

	// Convert a preferred virtual address to a dereferencable pointer
	PVOID ConvertVirtualAddressToPtr(DWORD dwVA) const;

	// Convert a preferred virtual address to an RVA
	DWORD ConvertVirtualAddressToRVA(DWORD dwVA) const;

	// Convert a preferred virtual address to an RVA
	DWORD ConvertRVAToVirtualAddress(DWORD dwVA) const;

	//
	// Section header access
	//

	// Get section header by zero-based index
	PIMAGE_SECTION_HEADER	SectionHeader(DWORD idx) const
	{
		if (idx > m_dwNumSectionHeaders || idx < 0 )
			return NULL;
		return &m_pSectionHeaders[idx];
	}

	// Get section header by name (i.e., ".text")
	PIMAGE_SECTION_HEADER	GetSectionHeader(PCSTR pName);

	// Get section header for the section that contains
	// the given file-relative virtual address.
	PIMAGE_SECTION_HEADER GetContainingSectionHeader(DWORD dwRVA) const;
	
	// Get import descriptor for a module, given its name
	PIMAGE_IMPORT_DESCRIPTOR GetImportDescriptor(PCSTR pszName);

	//
	// File field access
	//
	DWORD	ImageBase() const
	{ return OptionalHeader()->ImageBase; }

	DWORD	ImageBasePointer() const
	{ return (DWORD) DosHeader(); }

	PCSTR	ModuleName() const
	{ return (PCSTR) m_pszName; }

	PIMAGE_DOS_HEADER	DosHeader() const
	{	return m_pDosHeader;	}

	PIMAGE_NT_HEADERS	NtHeaders() const
	{	return m_pNtHeaders;	}

	PIMAGE_FILE_HEADER	FileHeader() const
	{	return m_pFileHeader;	}

	PIMAGE_OPTIONAL_HEADER	OptionalHeader() const
	{	return m_pOptionalHeader;	}

	DWORD NumDataDirectories() const
	{	return m_dwNumDataDirectories;	}

	DWORD	NumSectionHeaders() const
	{	return m_dwNumSectionHeaders;	}

	DWORD	NumImportModules()
	{	if (!m_dwNumImportModules) _GetNumImportModules();
		return m_dwNumImportModules;
	}

	DWORD	NumImports()
	{	if (!m_dwNumImports) _GetNumImports();
		return m_dwNumImports;
	}


	DWORD	GetEntryPoint(void) const
	{	return OptionalHeader()->AddressOfEntryPoint; }

	// returns a pointer to the IMAGE_DATA_DIRECTORY for the directory
	// specified (idx should be one of the IMAGE_DIRECTORY_ENTRY_XXX
	// values from winnt.h)
	PIMAGE_DATA_DIRECTORY	DataDirectory(DWORD idx) const
	{
		if (idx > m_dwNumDataDirectories || idx < 0 )
			return NULL;
		return &m_pDataDirectory[idx];
	}

	//
	// File Attributes
	//
	BOOL	isValid() const
	{ return m_flags.bIsValid;	}
	
	BOOL	isDiskFile() const
	{ return TRUE; }

	static IMAGE_DATA_DIRECTORY_NAMES 
		ImageDataDirectoryNames[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
	static IMAGE_SCN_FLAG_NAMES
		ImageScnFlagNames[];
	static IMAGE_SCN_FLAG_NAMES
		ImageScnAlignFlagNames[IMAGE_NUMBEROF_ALIGN_FLAGS];


private:
	void _clear(void);

	// If we are mapping a disk image, we make a memory-mapped
	// file to look around easier.
	HANDLE	m_hFile;		// HANDLE from CreateFile
	HANDLE	m_hFileMapping;	// HANDLE from CreateFileMapping
	PVOID	m_pViewOfFile;	// pointer from MapViewOfFile

	PIMAGE_DOS_HEADER	MapViewOfFile(const char *pszFileName);
	BOOL				UnmapViewOfFile(void);
	BOOL				FixupGlobals(void);

	DWORD	m_errno;
	PTSTR	m_pszName;

	DWORD _GetNumImportModules(void);
	DWORD _GetNumImports(void);

};

#define CPE_SYSERR	1		// system error
#define CPE_INVAL	2		// invalid parameter
#define CPE_INIT	3		// object not initialized properly

#endif // _CPEImage_H
