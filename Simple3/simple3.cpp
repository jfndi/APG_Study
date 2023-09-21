#include "Trace.h"

void foo();

int ACE_TMAIN(int, ACE_TCHAR* [])
{
	ACE_TRACE(ACE_TEXT("main"));

	MY_DEBUG(ACE_TEXT("Hi, Mom!\n"));
	foo();
	MY_DEBUG(ACE_TEXT("Goodnight!\n"));

	return 0;
}

void foo(void)
{
	ACE_TRACE(ACE_TEXT("foo"));

	MY_DEBUG(ACE_TEXT("%IHowdy Pardner!\n"));
}