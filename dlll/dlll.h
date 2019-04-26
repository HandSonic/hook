#ifdef DLLL_EXPORTS
#define DLLL_API __declspec(dllexport)
#else
#define DLLL_API __declspec(dllimport)
#endif
_declspec(dllexport) int FFF(void);