#ifdef EXTENSION_EXPORTS
#define EXTENSION_API extern "C" __declspec(dllexport)
#else
#define EXTENSION_API extern "C" __declspec(dllimport)
#endif

EXTENSION_API int fnExtension1(void);
