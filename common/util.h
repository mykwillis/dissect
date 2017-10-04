#ifndef _UTIL_H
#define _UTIL_H

#define HIDECLASS	class
HIDECLASS wstring
{
	wchar_t *m_wsz;
public:
	wstring(const char *sz)
	{ 
		if (!sz) {
			m_wsz = NULL;
			return;
		}
		size_t s = mbstowcs(NULL, sz, 0);
		m_wsz = new wchar_t[s+1];
		mbstowcs(m_wsz, sz, s+1);
	}
	operator wchar_t *() { return m_wsz; }
	~wstring() { delete [] m_wsz; }
};

HIDECLASS astring
{
	char *m_sz;
public:
	astring(const wchar_t *wsz)
	{
		size_t s = wcstombs(NULL, wsz, 0);
		m_sz = new char [s+1];
		wcstombs(m_sz, wsz, s+1);
	}
	operator char *() { return m_sz; }
	~astring() { delete [] m_sz; }
};

#define _STR(__s) #__s
#define _FL_MSG(__f,__l,__msg) __f "(" _STR(__l) ") : " __msg

#define _ERROR(__msg) \
	message(_FL_MSG(__FILE__,__LINE__,"error: " __msg))
#define _WARN(__msg)  \
	message(_FL_MSG(__FILE__,__LINE__,"warning: " __msg))
#define _TODO(_msg)  \
	message(_FL_MSG(__FILE__,__LINE__,"todo: " _msg))

#define _MSG(__msg)  message(__msg)

#define BITTEST(_word, _bit)	((BOOL)(_word & _bit ? 1 : 0 ))

#define UNUSED_ARG(_param)	_param
//
// Calculate the address of the base of the structure given its type, and an
// address of a field within the structure.
//

#define CONTAINING_RECORD( address, type, field ) ((type *)( \
                                                   (PCHAR)(address) - \
                                                   (PCHAR)(&((type *)0)->field)))

//
//  Doubly-linked list manipulation routines.  Implemented as macros
//  but logically these are procedures.
//

//
//  VOID
//  InitializeListHead(
//      PLIST_ENTRY ListHead
//      );
//

#define InitializeListHead(ListHead) (\
    (ListHead)->Flink = (ListHead)->Blink = (ListHead) )

//
//  BOOLEAN
//  IsListEmpty(
//      PLIST_ENTRY ListHead
//      );
//

#define IsListEmpty(ListHead) (\
    ( ((ListHead)->Flink == (ListHead)) ? TRUE : FALSE ) )

//
//  PLIST_ENTRY
//  RemoveHeadList(
//      PLIST_ENTRY ListHead
//      );
//

#define RemoveHeadList(ListHead) \
    (ListHead)->Flink;\
    {\
        PLIST_ENTRY FirstEntry;\
        FirstEntry = (ListHead)->Flink;\
        FirstEntry->Flink->Blink = (ListHead);\
        (ListHead)->Flink = FirstEntry->Flink;\
    }

#define GetHeadList(ListHead) \
	(ListHead)->Flink

//
//  VOID
//  RemoveEntryList(
//      PLIST_ENTRY Entry
//      );
//

#define RemoveEntryList(Entry) {\
        PLIST_ENTRY _EX_Entry;\
        _EX_Entry = (Entry);\
        _EX_Entry->Blink->Flink = _EX_Entry->Flink;\
        _EX_Entry->Flink->Blink = _EX_Entry->Blink;\
        }

//
//  VOID
//  InsertTailList(
//      PLIST_ENTRY ListHead,
//      PLIST_ENTRY Entry
//      );
//

#define InsertTailList(ListHead,Entry) \
    (Entry)->Flink = (ListHead);\
    (Entry)->Blink = (ListHead)->Blink;\
    (ListHead)->Blink->Flink = (Entry);\
    (ListHead)->Blink = (Entry)

//
//  VOID
//  InsertHeadList(
//      PLIST_ENTRY ListHead,
//      PLIST_ENTRY Entry
//      );
//

#define InsertHeadList(ListHead,Entry) \
    (Entry)->Flink = (ListHead)->Flink;\
    (Entry)->Blink = (ListHead);\
    (ListHead)->Flink->Blink = (Entry);\
    (ListHead)->Flink = (Entry)


#endif // _UTIL_H