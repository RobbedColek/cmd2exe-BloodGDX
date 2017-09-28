#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <windows.h>

int main()
{
	STARTUPINFO             si = { sizeof(si) };
	PROCESS_INFORMATION     pi;

	if (CreateProcess(0, "java -jar BloodGDX.jar", 0, 0, FALSE, CREATE_NO_WINDOW, 0, 0, &si, &pi))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	return 0;
}
