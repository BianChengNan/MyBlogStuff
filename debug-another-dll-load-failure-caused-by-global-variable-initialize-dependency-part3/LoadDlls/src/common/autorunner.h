#pragma once

class AutoRunner
{
public:
    AutoRunner(void (*func)())
    {
        func();
    }
};

#define STR_CAT(s1, s2) s1 ## s2
#define NAME_WITH_LINE(name, line) STR_CAT(name, line)

#define BEGIN_AUTO_RUN static AutoRunner NAME_WITH_LINE(s_auto_runner_, __LINE__) ([](){
#define END_AUTO_RUN  });
