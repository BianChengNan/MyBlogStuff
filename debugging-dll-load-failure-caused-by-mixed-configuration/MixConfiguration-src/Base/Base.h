#include <map>
#include <string>
#ifdef BASEFUNCTION_EXPORTS
#define BASEFUNCTION_API __declspec(dllexport)
#else
#define BASEFUNCTION_API __declspec(dllimport)
#endif

class BASEFUNCTION_API CObjectManager
{
public:
	static std::map<std::string, std::string>& GetMap();
};
