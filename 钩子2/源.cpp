#include"pid.h"
using namespace std;
int main()
{
	typedef int(*pfun)(void);
	pfun FF;
	HMODULE dll;
	dll = LoadLibrary(L"dlll.dll");
	//cout << dll;
	//getchar();
	FF = (pfun)GetProcAddress(dll, "FFF");
<<<<<<< HEAD
=======
	cout << FF << endl;
	if (dll == NULL)
	{
		printf("The dll coulde not be found");
		getchar();
	}
	if (FF == NULL)
	{
		printf("The Function coulde not be found");
		getchar();
	}
	//cout << FF;
	int   cxScreen = GetSystemMetrics(SM_CXSCREEN);
	int   cyScreen = GetSystemMetrics(SM_CYSCREEN);
	//UINT id = GetProcessIdByName(L"360rp.exe");
	//HANDLE h1;
	//h1 = OpenProcess(PROCESS_ALL_ACCESS, TRUE, id);
	HWND hq = FindWindow(NULL, L"ÆÁÄ»¹ã²¥");
	RECT rect;
	GetWindowRect(hq, &rect);
	//if (rect.right - rect.left >= cxScreen)
	//{
	Sleep(5000);
		FF();
	//}
	getchar();
}