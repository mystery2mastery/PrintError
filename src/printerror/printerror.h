#ifndef PRINTERROR_H
#define PRINTERROR_H

#include <windows.h> // Include Windows header for LPTSTR

#ifdef __cplusplus
extern "C" {	// If it is C++ compiler then this line will be included.
#endif

void PrintError(LPTSTR lpszFunction);

#ifdef __cplusplus
}				// If it is C++ compiler then this line will be included.
#endif

#endif /* PRINTERROR_H */
