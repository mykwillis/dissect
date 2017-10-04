#include "stdafx.h"
#include "CMyClass.h"

extern "C" {
const GUID IID_IMyClass = 
{ 0x3b7575f0, 0xcabb, 0x11d1, { 0xae, 0x9a, 0xb2, 0xd3, 0x26, 0x0, 0x0, 0x0 } };

const CLSID CLSID_MyClass = 
{ 0x1022d090, 0xcabc, 0x11d1, { 0xae, 0x9a, 0xb2, 0xd3, 0x26, 0x0, 0x0, 0x0 } };
};

typedef CComQIPtr<IMyClass, &IID_IMyClass> PMyClass;

int
foofunc()
{
	PMyClass m_IMyClass;
	m_IMyClass->Foo();
	return 1;
}