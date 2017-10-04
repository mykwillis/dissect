#include "project.h"
#include "CPEImage.h"

/*
From winnt.h:

typedef struct _IMAGE_OPTIONAL_HEADER {
    //
    // Standard fields.
    //
	// C	=	Count
				An ordinal.
	// BC	=	Byte Count
				A size expressed in bytes
	// VA	=	Virtual Address
				A raw pointer, assuming the preferred load address of the module
				is used to map it.  If the preferred load address is not available,
				this would have to be adjusted by the shift_delta
	// RVA	=	Relative Virtual Address
				An offset relative to the beginning of the image in memory.  Since
				only sections are mapped, this is an offset from the beginning of 
				the first section.  If the file is being worked with on disk,
				section alignment issues will have to be considered when converting
				this value to a pointer.
	// FO	=	File Offset
				An offset in bytes from the beginning of the file.  pure and simple,
				no delta or anything involved.

    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;			// RVA: Entry point of code
    DWORD   BaseOfCode;						// RVA:	Base of code section
    DWORD   BaseOfData;						// RVA: Base of data section

    //
    // NT additional fields.
    //

	DWORD   ImageBase;						// VA: Preferred load address
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;					// BC: size of address space to reserve for image's sections
    DWORD   SizeOfHeaders;					// BC: size of headers before sections begin
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;			// C: number of elements in following array
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;

//
// Directory format.
//
typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16

#define IMAGE_DIRECTORY_ENTRY_EXPORT         0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT         1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE       2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION      3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY       4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC      5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG          6   // Debug Directory
#define IMAGE_DIRECTORY_ENTRY_COPYRIGHT      7   // Description String
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR      8   // Machine Value (MIPS GP)
#define IMAGE_DIRECTORY_ENTRY_TLS            9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG   10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT  11   // Bound Import Directory in headers
#define IMAGE_DIRECTORY_ENTRY_IAT           12   // Import Address Table
*/

/*
#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
            DWORD   PhysicalAddress;	// in .OBJ
            DWORD   VirtualSize;		// in .EXE, this is supposed to be the rounded up
										// size of the section, but MS linkers screw up and
										// this is the actual (non-rounded) size.
    } Misc;
    DWORD   VirtualAddress;				// RVA(*NOT* VA): Add this to ImageBase to get VA where this section should be loaded
    DWORD   SizeOfRawData;				// Borland->actual size of section; MS-> rounded
    DWORD   PointerToRawData;			// FO: File offset at which section's data lives
    DWORD   PointerToRelocations;		// FO
    DWORD   PointerToLinenumbers;		// FO
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD   Characteristics;                // 0 for terminating null import descriptor
        PIMAGE_THUNK_DATA OriginalFirstThunk;   // RVA to original unbound IAT
    };
    DWORD   TimeDateStamp;                  // 0 if not bound,
                                            // -1 if bound, and real date\time stamp
                                            //     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                                            // O.W. date/time stamp of DLL bound to (Old BIND)

    DWORD   ForwarderChain;                 // -1 if no forwarders
    DWORD   Name;
    PIMAGE_THUNK_DATA FirstThunk;           // RVA to IAT (if bound this IAT has actual addresses)
} IMAGE_IMPORT_DESCRIPTOR;
typedef IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

typedef struct _IMAGE_IMPORT_BY_NAME {
    WORD    Hint;
    BYTE    Name[1];
} IMAGE_IMPORT_BY_NAME, *PIMAGE_IMPORT_BY_NAME;

typedef struct _IMAGE_THUNK_DATA {
    union {
        PBYTE  ForwarderString;
        PDWORD Function;
        DWORD Ordinal;
        PIMAGE_IMPORT_BY_NAME AddressOfData;
    } u1;
} IMAGE_THUNK_DATA;
typedef IMAGE_THUNK_DATA * PIMAGE_THUNK_DATA;

#define IMAGE_ORDINAL_FLAG 0x80000000
#define IMAGE_SNAP_BY_ORDINAL(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG) != 0)
#define IMAGE_ORDINAL(Ordinal) (Ordinal & 0xffff)

*/

IMAGE_DATA_DIRECTORY_NAMES 
CPEImage::ImageDataDirectoryNames[IMAGE_NUMBEROF_DIRECTORY_ENTRIES] =
{
	{ "Export",		"Export Directory"		},
	{ "Import",		"Import Directory"		},
	{ "Resource",	"Resource Directory"	},
	{ "Exception",	"Exception Directory"	},
	{ "Security",	"Security Directory"	},
	{ "BaseReloc",	"Base Relocation Table" },
	{ "Debug",		"Debug Directory"		},
	{ "Copyright",	"Description String"	},
	{ "GlobalPtr",	"Machine Value (MIPS GP)"},
	{ "TLS",		"TLS Directory"			},
	{ "LoadConfig",	"Load Configuration Directory" },
	{ "BoundImport","Bound Import Directory"},
	{ "IAT",		"Import Address Table"	}
};

#define BEGIN_IMAGE_SCN_CHARACTERISTS	\
IMAGE_SCN_FLAG_NAMES	\
CPEImage::ImageScnFlagNames[] =	{
#define IMAGE_SCN_FLAG(_flag, _desc)	\
{ _flag, #_flag, _desc },
#define END_IMAGE_SCN_CHARACTERISTS	\
};
#define BEGIN_IMAGE_SCN_ALIGN_FLAGS	\
IMAGE_SCN_FLAG_NAMES	\
CPEImage::ImageScnAlignFlagNames[IMAGE_NUMBEROF_ALIGN_FLAGS] =	{
#define IMAGE_SCN_FLAG(_flag, _desc)	\
{ _flag, #_flag, _desc },
#define END_IMAGE_SCN_ALIGN_FLAGS	\
};
#include "CPEImage.dat"

void
CPEImage::_clear()
{
	m_dwNumDataDirectories = 0;
	m_dwNumSectionHeaders	= 0;
	m_dwNumImports = 0;
	m_dwSignature = 0;
	m_pDataDirectory = NULL;
	m_pDosHeader = NULL;
	m_pFileHeader = NULL;
	m_pNtHeaders = NULL;
	m_pOptionalHeader = NULL;
	m_pSectionHeaders = NULL;

	memset(&m_flags, 0, sizeof(m_flags));

	m_pszName = 0;
}

CPEImage::CPEImage()
{
	_clear();
}

PIMAGE_DOS_HEADER
CPEImage::MapViewOfFile(const char *pszFilePath)
{
	m_hFile = CreateFile(pszFilePath, GENERIC_READ, 
		FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == m_hFile)	{
		m_errno = CPE_SYSERR;
		return FALSE;
	}
	
	m_hFileMapping = CreateFileMapping(m_hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (0 == m_hFileMapping)
	{
		m_errno = CPE_SYSERR;
		CloseHandle(m_hFile);
		return FALSE;
	}
	
	m_pViewOfFile = ::MapViewOfFile(m_hFileMapping, FILE_MAP_READ, 0, 0, 0);
	if (0 == m_pViewOfFile)
	{
		m_errno = CPE_SYSERR;
		CloseHandle(m_hFile);
		CloseHandle(m_hFileMapping);
		return FALSE;
	}

	return (PIMAGE_DOS_HEADER) m_pViewOfFile;
}

BOOL
CPEImage::UnmapViewOfFile()
{
	if ( !isDiskFile() )	{
		m_errno = CPE_INVAL;
		return FALSE;
	}

	::UnmapViewOfFile(m_pViewOfFile);
	::CloseHandle(m_hFileMapping);
	::CloseHandle(m_hFile);

	return TRUE;
}

BOOL
CPEImage::FixupGlobals()
{
	if (!m_pDosHeader)	{
		m_errno = CPE_INIT;
		return FALSE;
	}

	__try {
	m_pNtHeaders = BUILDPTR(PIMAGE_NT_HEADERS, m_pDosHeader, m_pDosHeader->e_lfanew);
	m_dwSignature = m_pNtHeaders->Signature;
	m_pFileHeader = &m_pNtHeaders->FileHeader;
	m_pOptionalHeader = &m_pNtHeaders->OptionalHeader;

	m_dwNumDataDirectories = m_pOptionalHeader->NumberOfRvaAndSizes;
	m_pDataDirectory = &m_pOptionalHeader->DataDirectory[0];

	m_dwNumSectionHeaders = m_pFileHeader->NumberOfSections;
	// section headers immediately follow the NtHeaders
	m_pSectionHeaders = (PIMAGE_SECTION_HEADER) &(m_pNtHeaders[1]);
	}

	__except(1)	{
		m_errno = CPE_INIT;
		return FALSE;
	}

	if ( m_dwSignature != IMAGE_NT_SIGNATURE )	{
		m_errno = CPE_INIT;
		return FALSE;
	}
	else
		return TRUE;
}

BOOL
CPEImage::MapDiskImage(const char *pszFilePath)
{
	m_pDosHeader = MapViewOfFile(pszFilePath);

	m_pszName = strdup(pszFilePath);

	if (!m_pDosHeader)
		return FALSE;

	if (!FixupGlobals())
		return FALSE;

	m_flags.bIsValid = TRUE;

	return TRUE;

}

CPEImage::~CPEImage()
{
	free(m_pszName);
}

//
// EnumImportModules
//	PFUNC_CPE_ENUM_IMPORT_MODULES pFunc
//		pointer to enumeration function that will be called once for each
//		IMAGE_IMPORT_DESCRIPTOR in the image.  NULL is permitted.
//	DWORD dwExtra
//		Extra value to be passed as context to the enumeration function
//		on each iteration.
//	Returns
//		Number of IMAGE_IMPORT_DESCRIPTORS in this image.
//
DWORD CPEImage::EnumImportModules(PFUNC_CPE_ENUM_IMPORT_MODULES pFunc, DWORD dwExtra) const
{
	DWORD dwNum=0;
	// Each module referenced by a PE module has an IMAGE_IMPORT_DESCRIPTOR
	// in the Import Directory.  Despite what Pietrek says (WSPS, p. 587),
	// the import directory is not always in the .idata section.
	// Use DataDirectory(IMAGE_DIRECTORY_ENTRY_IMPORT) to find the directory.
	// This directory is just an array of IMAGE_IMPORT_DESCRIPTORs, terminated
	// with a zero'd descriptor.

	PIMAGE_DATA_DIRECTORY pImportDirectory = DataDirectory(IMAGE_DIRECTORY_ENTRY_IMPORT);
	// catch the (non-existant?) case of no imports.
	if (!pImportDirectory || !pImportDirectory->VirtualAddress)
		return 0;

	PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor = 
		(PIMAGE_IMPORT_DESCRIPTOR) ConvertRVAToPtr(pImportDirectory->VirtualAddress);

	// The array of descriptors is terminated with a 0 Characteristics field
	while (pImportDescriptor->Characteristics)	{
		if (pFunc) (*pFunc)(pImportDescriptor, dwExtra);
		pImportDescriptor++;
		dwNum++;
	}

	return dwNum;
}

PIMAGE_SECTION_HEADER
CPEImage::GetContainingSectionHeader(DWORD dwRVA)	const
{
	for (DWORD i=0;i<m_dwNumSectionHeaders;i++)	{
		if ( m_pSectionHeaders[i].VirtualAddress <= dwRVA )	{
			if ( m_pSectionHeaders[i].VirtualAddress +
				 m_pSectionHeaders[i].Misc.VirtualSize > dwRVA )	{
				return &m_pSectionHeaders[i];
			} // end if (containing)
		} // end if (section start < dwrva)
	}
	return NULL;
}

PVOID CPEImage::ConvertVirtualAddressToPtr(DWORD dwVA) const
{
	if ( dwVA < ImageBase() )
		return NULL;

	DWORD dwRVA = dwVA - ImageBase();
	return ConvertRVAToPtr( dwRVA );
}

DWORD CPEImage::ConvertVirtualAddressToRVA(DWORD dwVA) const
{
	if ( OptionalHeader()->ImageBase <= dwVA )
		return dwVA - OptionalHeader()->ImageBase;
	else
		return 0;
}

DWORD CPEImage::ConvertRVAToVirtualAddress(DWORD dwRVA) const
{
	return OptionalHeader()->ImageBase + dwRVA;
}

PVOID CPEImage::ConvertRVAToPtr(DWORD dwRVA) const
{
	// if this module is loaded into memory, RVAs can simply be added to the
	// base address of the module, and we're done.
	// however, if the module is being mapped on disk, we first have to determine
	// which section the RVA refers to.

	if ( isDiskFile() )	{
		// Find the section this RVA refers to
		PIMAGE_SECTION_HEADER pHead = GetContainingSectionHeader(dwRVA);
		if (!pHead)	{
			// this address doesn't correspond to anything in any of the
			// sections.  It might, however, refer to something like the
			// import table.  If the RVA is less than the size of the
			// file, just return ImageBase + RVA
			// BUGBUG: I think I'm high.  The only RVAs that wont map
			// into a section are ones that point to the headers.
//			if ( dwRVA && dwRVA < OptionalHeader()->SizeOfImage )
//				return (PVOID) (ImageBasePointer() + dwRVA);

			return NULL;
		}

		// Since we didn't load this guy like the Windows loader would,
		// the PointerToRawData field is the one that we are interested in.
		// This field is a file-based offset, as opposed to the VirtualAddress
		// field, which is where the section would be relative to the beginning
		// of the module *if it were loaded by Windows*.
		// The difference between these two values gives us the relationship
		// between RVAs embedded in the file, and the actual offset from beginning
		// of file we need.
		int delta = pHead->VirtualAddress - pHead->PointerToRawData;
		return BUILDPTR(PVOID, m_pViewOfFile, (dwRVA - delta));	// delta may be negative
	} else {
		// If this file is loaded, just add the RVA to the module base
		return BUILDPTR(PVOID, m_pViewOfFile, dwRVA);
	}
}

PVOID CPEImage::ConvertFOToPtr(DWORD dwFO) const
{
	return (PBYTE)m_pViewOfFile + dwFO;
}
DWORD CPEImage::EnumDataDirectories(PFUNC_CPE_ENUM_DATA_DIRECTORIES pFunc, DWORD dwExtra) const
{
 	DWORD dwNum=0;
	for (DWORD i=0; i< m_dwNumDataDirectories; i++)	{
		PIMAGE_DATA_DIRECTORY pImageDataDir = &m_pDataDirectory[i];
		if (pImageDataDir->VirtualAddress)	{
			(*pFunc)(pImageDataDir, i, dwExtra);
			dwNum++;
		}
	}
	return dwNum;
}

DWORD
CPEImage::EnumSections(PFUNC_CPE_ENUM_SECTIONS pFunc, DWORD dwExtra) const
{
	DWORD dwNum=0;
	for (DWORD i=0; i < m_dwNumSectionHeaders; i++)	{
		PIMAGE_SECTION_HEADER pSectionHeader = &m_pSectionHeaders[i];
		(*pFunc)(pSectionHeader, dwExtra);
		dwNum++;
	}

	return dwNum;
}

DWORD
CPEImage::EnumImportThunkData(
	PIMAGE_IMPORT_DESCRIPTOR pDesc, 
	PFUNC_CPE_ENUM_THUNK_DATA pFunc, 
	DWORD dwExtra
) const
{
#if 0
	PIMAGE_THUNK_DATA pThunkData = 
		(PIMAGE_THUNK_DATA) ConvertRVAToPtr((DWORD)pDesc->FirstThunk);
#else	
	PIMAGE_THUNK_DATA pThunkData = 
		(PIMAGE_THUNK_DATA) ConvertRVAToPtr((DWORD)pDesc->OriginalFirstThunk);
#endif
	if (!pThunkData)
		return 0;

	DWORD dwNum=0;
	while(*(DWORD *)pThunkData)	{
		(*pFunc)(pThunkData, dwExtra);
		pThunkData++;
	}

	return dwNum;
}

PIMAGE_SECTION_HEADER
CPEImage::GetSectionHeader(PCSTR pName)
{
	for (DWORD i=0; i < m_dwNumSectionHeaders; i++)	{
		PIMAGE_SECTION_HEADER pSectionHeader = &m_pSectionHeaders[i];
		if ( !strnicmp((char *)pSectionHeader->Name, pName, IMAGE_SIZEOF_SHORT_NAME) )
			return pSectionHeader;
	}

	return NULL;
}

// Returns number of exported functions.
DWORD
CPEImage::EnumExports(PFUNC_CPE_ENUM_EXPORTS pEnumFunc, DWORD dwExtra) const
{
	EXPORTED_FUNCTION	ef;

	// Get a pointer to the data directory for the export section of this module
	PIMAGE_DATA_DIRECTORY pExportDataDirectory = DataDirectory(IMAGE_DIRECTORY_ENTRY_EXPORT);
	if (!pExportDataDirectory || !pExportDataDirectory->VirtualAddress)
		return 0;

	// Now, get a pointer to the actual export information
	PIMAGE_EXPORT_DIRECTORY pExportDirectory = 
		(PIMAGE_EXPORT_DIRECTORY) ConvertRVAToPtr(pExportDataDirectory->VirtualAddress);	

	// check for no exports (even though there is an export section...)
	if (!pExportDirectory->AddressOfFunctions)
		return 0;

	PDWORD	pdwAddressOfFunctions		= 
		(PDWORD)	ConvertRVAToPtr( (DWORD) pExportDirectory->AddressOfFunctions );
	
	PDWORD	prvaAddressOfNames		=
		(PDWORD)	ConvertRVAToPtr( (DWORD) pExportDirectory->AddressOfNames );

	PWORD	pwAddressOfNameOrdinals	= 
		(PWORD)		ConvertRVAToPtr( (DWORD) pExportDirectory->AddressOfNameOrdinals );
	//
	// The total number of functions exported by a module, either by name or by
	// ordinal, is given by the NumberOfFunctions field.
	//
	for (DWORD i=0; i < pExportDirectory->NumberOfFunctions ; i++)	{
		ef.clear();
		
		// Get the RVA of the i'th exported function
		DWORD dwFuncRVA = pdwAddressOfFunctions[i];

		// if an ordinal value is skipped, we can have a NULL entry (essentially
		// wasted space) in the AddressOfFunctions array...
		if (!dwFuncRVA)
			continue;

		// The ordinal value is just the index value of the function pointer,
		// plus the Base field of pExportDirectory
		ef.wOrdinal = (WORD) (pExportDirectory->Base + i);

		// Try to find a name associated with this exported function.
		// We know that a name is associated with the function if there is
		// an entry in the AddressOfNamesOrdinals array that matches this
		// function's ordinal.
		// Note that even though it seems as though the AddressOfNames array
		// has functions listed in ascended ordinal number, there is really
		// no guarentee of this happening.  We have to search through the whole
		// array.
		// (The number of entries in the AddressOfNameOrdinals is given by
		// the NumberOfNames field)
		DWORD dwNameRVA = 0;
		for (DWORD j=0; j < pExportDirectory->NumberOfNames ; j++)	{
			if ( pwAddressOfNameOrdinals[j] == ef.wOrdinal )	{
				// Since the ordinal value at index j of the AddressOfNameOrdinals
				// array matches this function, the function name is at index j
				// of the AddressOfNames array.
				dwNameRVA = prvaAddressOfNames[j];
				break;
			}
		}

		//
		// At this point, we have the RVA of the exported function, the ordinal
		// value for the export, and the RVA of the function's name, if exported.
		//
		// Convert the RVAs to pointers, and call the callback function.
		//
		ef.pEntry = ConvertRVAToPtr( dwFuncRVA );
		ef.dwImageOff = dwFuncRVA;
		if ( dwNameRVA )	{
			strncpy( (char *)ef.pszName, (PCSTR) ConvertRVAToPtr( dwNameRVA ), sizeof(ef.pszName)-1 );
			ef.dwFlags |= EXPORTED_FUNCTION_BY_NAME;
		} else	{
			wsprintf((char *)ef.pszName, "%s!%u", ModuleName(), (unsigned)ef.wOrdinal);
		}

		(*pEnumFunc)(&ef, dwExtra);
	}

	return pExportDirectory->NumberOfFunctions;
}

STDMETHODIMP
CPEImage::EnumExports(IDisEnumExports **ppEnum)
{
	*ppEnum = NULL;
	return E_NOTIMPL;
}

typedef struct
{
	CPEImage *pThis;		
	IMG_IMPORT *pImports;	// array of IMG_IMPORT data
	BSTR ModuleName;		// temporary used between function calls
	DWORD FirstThunk;
	int pos;				// current position in pImports array
	int cnt;				// total elements in pImports array
} IMG_IMPORT_DATA;

BSTR
AllocSysStringA(char *sz)
{
	BSTR b;
	size_t s = mbstowcs(NULL, sz, 0);
	wchar_t *wsz = new wchar_t [s+1];
	mbstowcs(wsz, sz, s+1);
	b = ::SysAllocString(wsz);
	delete [] wsz;
	return b;
}

//
// EnumImports_IMG_IMPORT
//
//	This enumeration function fills in an IMG_IMPORT structure
//	(contained in the passed-in IMG_IMPORT_DATA structure) with
//	information from the PIMAGE_THUNK_DATA.
//
// PIMAGE_THUNK_DATA pDesc
//	Pointer to the (NT-defined) PIMAGE_THUNK_DATA structure for this import
// DWORD dwExtra
//	Holds an IMG_IMPORT_DATA structure to use for context
// Returns
//	NIL
//	
void
EnumImports_IMG_IMPORT(PIMAGE_THUNK_DATA pDesc, DWORD dwExtra)
{
	IMG_IMPORT_DATA *pData = (IMG_IMPORT_DATA *)dwExtra;
	CPEImage *pImage = pData->pThis;

	//
	// Find the IMG_IMPORT structure to fill in for this import
	//
	IMG_IMPORT *pImport = &pData->pImports[ pData->pos ];
	pData->pos++;

	pImport->Module = ::SysAllocString( pData->ModuleName );

	if ( IMAGE_SNAP_BY_ORDINAL(pDesc->u1.Ordinal) )	{
		// Imports snapped by ordinal have no name associated
		pImport->Name = ::SysAllocString( L"Ordinal" );
		pImport->Ordinal = IMAGE_ORDINAL(pDesc->u1.Ordinal);
	} else {
		PIMAGE_IMPORT_BY_NAME pByName = (PIMAGE_IMPORT_BY_NAME) pImage->ConvertRVAToPtr((DWORD)pDesc->u1.AddressOfData);
		pImport->Name = AllocSysStringA( (PSTR)&(pByName->Name[0]) );
		pImport->Ordinal = 0;
	}

	//
	// Calculate the address of the DWORD that will hold this imports address in a
	// loaded module.
	//
	pImport->Address = pImage->ConvertRVAToVirtualAddress( pData->FirstThunk + (4*pData->cnt) );
	pData->cnt++;
}

void
EnumImportModules_IMG_IMPORT(PIMAGE_IMPORT_DESCRIPTOR pDesc, DWORD dwExtra)
{
	IMG_IMPORT_DATA *pData = (IMG_IMPORT_DATA *)dwExtra;
	
	//
	// The pData->ModuleName pointer is allocated in this routine (before
	// the call to the function enumerator), and freed here.  The last
	// import module to be enumerated has its ModuleName freed in the
	// EnumImports() method.
	//
	if (pData->ModuleName)
		::SysFreeString( pData->ModuleName );

	//
	// Grab the name of the imported module
	//
	char *szModuleName = (char *)pData->pThis->ConvertRVAToPtr( pDesc->Name );
	if (!szModuleName) {
		szModuleName = "[null]";
	} 
	
	pData->ModuleName = AllocSysStringA(szModuleName);
	
	pData->FirstThunk = (DWORD) pDesc->FirstThunk;
	pData->cnt = 0;

	//
	// Enumerate all of the individual imports from this module
	//
	pData->pThis->EnumImportThunkData(pDesc, EnumImports_IMG_IMPORT, dwExtra);
}


#if _MSC_VER>1020
template<>
#endif
class _Copy<IMG_IMPORT>
{
public:
	static void copy(IMG_IMPORT* p1, IMG_IMPORT* p2) {
		p1->Module = ::SysAllocString(p2->Module);
		p1->Name = ::SysAllocString(p2->Name);
		p1->Ordinal = p2->Ordinal;
		p1->Address = p2->Address;
	}
	static void init(IMG_IMPORT* p) {memset(p, 0, sizeof(p));}
	static void destroy(IMG_IMPORT* p) {
		::SysFreeString(p->Module);
		::SysFreeString(p->Name);
		//delete p;	// NO! ATL will free the actual structure
	}
};
typedef CComEnum<IDisEnumImports, &IID_IDisEnumImports, IMG_IMPORT, _Copy<IMG_IMPORT> > CEnumImports;

STDMETHODIMP
CPEImage::EnumImports(IDisEnumImports **ppEnum)
{
	DWORD NumberOfImports = NumImports();

	IMG_IMPORT_DATA ImportData;
	ImportData.pThis = this;
	ImportData.pImports = new IMG_IMPORT [ NumberOfImports ];
	ImportData.ModuleName = NULL;
	ImportData.pos = 0;

	EnumImportModules( EnumImportModules_IMG_IMPORT, (DWORD)&ImportData );
	
	//
	// This will have been allocated by the last call to EnumImportModules_IMG_IMPORT
	//
	if (ImportData.ModuleName)
		::SysFreeString( ImportData.ModuleName );

	//
	// Create the enumeration object, and give it ownership of the IMG_IMPORT
	// structures allocated above.
	//
	// BUGBUG: is this going to cause a leak in the CRT since we allocated with
	// BUGBUG: the new [] operator?
	//
	CComObject<CEnumImports> *pEnum = new CComObject<CEnumImports>;
	pEnum->Init(&ImportData.pImports[0], &ImportData.pImports[NumberOfImports], NULL, AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hRes = pEnum->_InternalQueryInterface(IID_IDisEnumImports, (void**)ppEnum);
	if (FAILED(hRes))
		delete pEnum;
	
	return hRes;
}
typedef struct
{
	CPEImage *This;
	IMG_SECTION *Sections;
	DWORD Current;
} ESDATA;

void
EnumSections_IMG_SECTION(PIMAGE_SECTION_HEADER pSectionHeader, DWORD dwExtra)
{
	ESDATA *SectionData = (ESDATA *)dwExtra;
	IMG_SECTION &Section = SectionData->Sections[SectionData->Current];

	Section.Address = SectionData->
		This->ConvertRVAToVirtualAddress( pSectionHeader->VirtualAddress );
	// BUGBUG: This might not be right!
	// BUGBUG: we may want to use pSectionHeader->Misc->VirtualSize
	Section.Size = pSectionHeader->Misc.VirtualSize;
	
	//
	// We say it's DATA if the CNT_CODE flag isn't present
	//
	Section.Type = pSectionHeader->Characteristics & IMAGE_SCN_CNT_CODE ? IMG_SECTION_CODE : IMG_SECTION_DATA;
	
	SectionData->Current++;
}

typedef CComEnum<IEnumSections, &IID_IEnumSections, IMG_SECTION, _Copy<IMG_SECTION> > CEnumSections;

STDMETHODIMP
CPEImage::EnumSections(IEnumSections **ppEnum)
{
	ESDATA SectionData;
	SectionData.Sections = new IMG_SECTION [ NumSectionHeaders() ];
	SectionData.Current = 0;
	SectionData.This = this;

	EnumSections(EnumSections_IMG_SECTION, (DWORD)&SectionData);

	CComObject<CEnumSections> *pEnum = new CComObject<CEnumSections>;
	pEnum->Init(&SectionData.Sections[0], 
				&SectionData.Sections[NumSectionHeaders()], 
				NULL, 
				AtlFlagTakeOwnership);

	//
	// I'm not sure why this is necessary, but this is the technique used by
	// Microsoft code using the CComEnum<> template.
	//
	HRESULT hRes = pEnum->_InternalQueryInterface(IID_IEnumSections, (void**)ppEnum);
	if (FAILED(hRes))
		delete pEnum;
	
	return hRes;
}

typedef struct 
{
	CPEImage *pThis;
	int count;
} CountData;

void
EnumImports_count(PIMAGE_THUNK_DATA , DWORD dwExtra)
{
	CountData *pData = (CountData *)dwExtra;
	pData->count++;
}

void
EnumImportModules_count(PIMAGE_IMPORT_DESCRIPTOR pDesc, DWORD dwExtra)
{
	CountData *pData = (CountData *)dwExtra;
	pData->pThis->EnumImportThunkData(pDesc, EnumImports_count, dwExtra);
}

DWORD
CPEImage::_GetNumImports(void)
{
	CountData data;
	data.pThis = this;
	data.count = 0;
	EnumImportModules( EnumImportModules_count, (DWORD)&data);
	m_dwNumImports = (DWORD) data.count;
	return m_dwNumImports;
}

DWORD
CPEImage::_GetNumImportModules(void)
{
	//
	// Calling EnumImportModules() with a NULL function just returns
	// the number of import modules
	//
	m_dwNumImportModules = EnumImportModules(NULL, 0);
	return m_dwNumImportModules;
}