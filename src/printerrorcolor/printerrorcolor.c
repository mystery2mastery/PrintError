#include "printerrorcolor.h"

#include <strsafe.h>
#include <windows.h>

// Helper function to print the error message (with color) to console
// PrintErrorColor("String to show. This is usually an API name")
// Ex: PrintErrorColor("GetProcessId()");

void PrintErrorColor(LPTSTR lpszFunction)
{    
	DWORD errorCode = GetLastError();
	LPSTR messageBuffer = NULL;
    DWORD dwBufferLength = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        errorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)&messageBuffer,
        0,
        NULL
    );
	
	//Just for showing colored output in console
	HANDLE  h_stdout;
	h_stdout = GetStdHandle(STD_OUTPUT_HANDLE);

    if (dwBufferLength) {
        SetConsoleTextAttribute(h_stdout, 4); // 4 = red
		printf("[X] %s failed!\n", lpszFunction);
		printf("[-] Error code: %lu\n", errorCode);
        printf("[-] Error message: %s\n", messageBuffer);
		SetConsoleTextAttribute(h_stdout, 7); // 7 = default = white

        // Free the buffer allocated by FormatMessage
        LocalFree(messageBuffer);
    }
}