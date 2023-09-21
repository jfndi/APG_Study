#define ACE_NTRACE 0
#include "Trace.hpp"

void foo(void);

int ACE_TMAIN(int, ACE_TCHAR* [])
{
    TRACE(ACE_TEXT("main"));

    MY_DEBUG(ACE_TEXT("Hi Mom\n"));
    foo();
    MY_DEBUG(ACE_TEXT("Goodnight\n"));

    TRACE_RETURN(0);
}

void foo(void)
{
    TRACE(ACE_TEXT("foo"));
    MY_DEBUG(ACE_TEXT("Howdy Pardner\n"));
    TRACE_RETURN_VOID();
}