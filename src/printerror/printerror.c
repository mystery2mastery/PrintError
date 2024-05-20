#include "printerror.h"

#include <strsafe.h>
#include <windows.h>


// Helper function to print the error message (without color) to console
// PrintError("String to show. This is usually an API name")
// Ex: PrintError("GetProcessId()");
/* 
[X] GetProcessId() failed!
[-] Error code: 6
[-] Error message: The handle is invalid. 
*/

void PrintError(LPTSTR lpszFunction)
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

    if (dwBufferLength) {
        printf("[X] %s failed!\n", lpszFunction);
		printf("[-] Error code: %lu\n", errorCode);
        printf("[-] Error message: %s\n", messageBuffer);

        // Free the buffer allocated by FormatMessage
        LocalFree(messageBuffer);
    }
}