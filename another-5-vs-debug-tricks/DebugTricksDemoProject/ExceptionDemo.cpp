#include "stdafx.h"
#include <exception>

bool application_quit = false;
int g_runningLoop = 0;

void FunctionA();
void FunctionB();
void FunctionC();
void FunctionD();
void FunctionE();

void ExceptionDemo()
{
    try
    {
        while (!application_quit)
        {
            FunctionA();
        }
    }
    catch (std::exception)
    {
    }
}

void FunctionA() { FunctionB(); }
void FunctionB() { FunctionC(); }
void FunctionC() { FunctionD(); }
void FunctionD()
{
    if (++g_runningLoop > 6)
    {
        throw std::exception("too many loops!");
    }
    FunctionE();
}

void FunctionE()
{
    if (g_runningLoop > 10)
    {
        application_quit = true;
    }
}
