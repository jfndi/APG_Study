#define ACE_NTRACE 0
#include "ace/Log_Msg.h"

/*
 * Enabling/ disabling logging severities.
 */

void foo(void);

int ACE_TMAIN(int, ACE_TCHAR* [])
{
    ACE_TRACE(ACE_TEXT("main"));

    ACE_LOG_MSG->priority_mask(LM_DEBUG | LM_NOTICE,
        ACE_Log_Msg::PROCESS);

    /*
     * From that point until the nex call to the
     * priority mask LM_INFO severity messages will
     * be ignored.
     */
    ACE_DEBUG((LM_INFO, ACE_TEXT("%IHi Mom\n")));
    foo();
    ACE_DEBUG((LM_DEBUG, ACE_TEXT("%IGoodnight\n")));

    /*
     * We re-activate the LM_INFO severity in order to see
     * the exit trace.
     */
    ACE_LOG_MSG->priority_mask(LM_INFO, ACE_Log_Msg::PROCESS);

    return 0;
}

void foo(void)
{
    ACE_TRACE(ACE_TEXT("foo"));

    ACE_DEBUG((LM_NOTICE, ACE_TEXT("%IHowdy Pardner\n")));
}