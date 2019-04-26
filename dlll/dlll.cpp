#include "stdafx.h"
#include "dlll.h"
#include<WinUser.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
//typedef HHOOK (_stdcall * P)(int idHook,HOOKPROC lpfn,HINSTANCE hMod,DWORD dwThreadId);
HHOOK P;
MSG msg;
__declspec(dllexport) int FFF(void)
{
	LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);
	P = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle(TEXT("dlll.dll")), 0);
	while (PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
/*int file()
{   
	
	ofstream ofile;
	ofile.open("d:\\hhh.txt");
	//ofile << "b";
	return 0;
}*/
	LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam)
	{
		/*if (wParam == 0x42)
		{
			ofstream ofile;
			ofile.open("d:\\hhh.txt");
			ofile << "b";
			return 1;
		}*/
		if (wParam == 0x42)
		{
			//fstream ofile;
			//ofile.open("d:\\hhh.txt",NULL,NULL);
			//ofile << "b";a
			//return CallNextHookEx(P, code, wParam, lParam);
		//}
			HWND h1;
			h1 = GetForegroundWindow();
			PostMessage(h1, WM_SYSCOMMAND, SC_MINIMIZE, 0);
			return CallNextHookEx(P, 0, wParam, lParam);
		}
		else
			return CallNextHookEx(P, 0, wParam, lParam);
		}