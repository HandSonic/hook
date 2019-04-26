#include<Windows.h>
#include<iostream>
#include <Tlhelp32.h>
UINT GetProcessIdByName(LPCTSTR pszExeFile)

{

	UINT nProcessID = 0;

	PROCESSENTRY32 pe = { sizeof(PROCESSENTRY32) };



	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

	if (hSnapshot != INVALID_HANDLE_VALUE)

	{

		if (Process32First(hSnapshot, &pe))

		{

			while (Process32Next(hSnapshot, &pe))

			{

				if (lstrcmpi(pszExeFile, pe.szExeFile) == 0)

				{

					nProcessID = pe.th32ProcessID;

					break;

				}

			}

		}

		CloseHandle(hSnapshot);

	}

	return nProcessID;

}
