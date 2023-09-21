#pragma once

#include "Trace.h"
class Trace
{
public:
    Trace(const ACE_TCHAR* prefix,
        const ACE_TCHAR* name,
        int line,
        const ACE_TCHAR* file)
    {
        this->prefix_ = prefix;
        this->name_ = name;
        this->line_ = line;
        this->file_ = file;

        ACE_Log_Msg* lm = ACE_LOG_MSG;
        if (lm->tracing_enabled() &&
            lm->trace_active() == 0)
        {
            lm->trace_active(1);
            ACE_DEBUG((
                LM_TRACE,
                ACE_TEXT("%s%*s(%t) calling %s in file `%s`")
                ACE_TEXT(" on line %d\n"),
                this->prefix_,
                Trace::nesting_indent_ * lm->inc(),
                ACE_TEXT(""),
                this->name_,
                this->file_,
                this->line_
            ));
            lm->trace_active(0);
        }
    }

    void setLine(int line)
    {
        this->line_ = line;
    }

    ~Trace()
    {
        ACE_Log_Msg* lm = ACE_LOG_MSG;
        if (lm->tracing_enabled() &&
            lm->trace_active() == 0)
        {
            lm->trace_active(1);
            ACE_DEBUG((
                LM_TRACE,
                ACE_TEXT("%s%*s(%t) leaving %s in file `%s`")
                ACE_TEXT(" on line %d\n"),
                this->prefix_,
                Trace::nesting_indent_ * lm->inc(),
                ACE_TEXT(""),
                this->name_,
                this->file_,
                this->line_
            ));
            lm->trace_active(0);
        }
    }

private:
    enum {nesting_indent_ = 3};
    const ACE_TCHAR* prefix_{};
    const ACE_TCHAR* name_{};
    const ACE_TCHAR* file_{};
    int line_{};
};

#define TRACE_PREFIX    ACE_TEXT("TRACE ")

#if (ACE_NTRACE == 1)
#   define TRACE(X)
#   define TRACE_RETURN(V)
#   define TRACE_RETURN_VOID()
#else
#   define TRACE(X)                     \
        Trace ____ (TRACE_PREFIX,       \
                   ACE_TEXT(X),         \
                   __LINE__,            \
                   ACE_TEXT(__FILE__))

#   define TRACE_RETURN(V)              \
        do { ____.setLine(__LINE__); return V; } while (0) 

#   define TRACE_RETURN_VOID()          \
        do { ____.setLine(__LINE__);} while (0)
#endif
