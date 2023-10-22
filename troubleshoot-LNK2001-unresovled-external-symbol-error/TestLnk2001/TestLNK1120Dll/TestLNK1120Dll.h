#pragma once

#include <string>

#ifdef DLL_EXPORT
#define TEST_EXTERN_EXPORT __declspec(dllexport)
#else
#define TEST_EXTERN_EXPORT __declspec(dllimport)
#endif

#define TRIGGER_LINK_ERROR_1120

#ifdef TRIGGER_LINK_ERROR_1120
TEST_EXTERN_EXPORT std::string& GetStaticData();
#else
TEST_EXTERN_EXPORT std::string GetStaticData();
#endif