#define ACE_NTRACE 0
#include "ace/Log_Msg.h"

void foo();

int ACE_TMAIN(int, ACE_TCHAR* argv[])
{
    /*
     * This will be directed to stderr (the default
     * ACE_Log_Msg behavior).
     */
    ACE_TRACE(ACE_TEXT("main"));

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("%IHi Mom\n")));
    /*
     * Everything from foo() will be directed to the
     * system logger.
     */
    ACE_LOG_MSG->open(argv[0], ACE_Log_Msg::SYSLOG, ACE_TEXT("syslogtest"));
    foo();

    /*
     * Now, we reset the log output to the default (stderr).
     */
    ACE_LOG_MSG->open(argv[0]);

    ACE_DEBUG((LM_INFO, ACE_TEXT("%IGoodnight\n")));

    return 0;
}

void foo()
{
    ACE_TRACE(ACE_TEXT("foo"));

    ACE_DEBUG((LM_INFO, ACE_TEXT("%IHowdy Pardner\n")));
}