#define ACE_NTRACE 0
#include "ace/Log_Msg.h"
#include "callback.hpp"

int ACE_TMAIN(int, ACE_TCHAR* [])
{
    Callback* callback = new Callback;

    ACE_LOG_MSG->set_flags(ACE_Log_Msg::MSG_CALLBACK);
    ACE_LOG_MSG->clr_flags(ACE_Log_Msg::STDERR);
    ACE_LOG_MSG->msg_callback(callback);

    ACE_TRACE(ACE_TEXT("main"));

    ACE_DEBUG((LM_DEBUG, ACE_TEXT("%IHi Mom.\n")));
    ACE_DEBUG((LM_INFO, ACE_TEXT("%IGoodnight.\n")));
    
    return 0;
}