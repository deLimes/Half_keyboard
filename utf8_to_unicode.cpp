/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

///////
#include <windows.h>
#include <Wininet.h>
#include <stdio.h>
#include <Tlhelp32.h>
#include <conio.h>
#include <Tchar.h>
#include <stdlib.h>
#include <wchar.h>
#pragma comment(lib, "wininet.lib")


char buffer[64000];
DWORD readd = 0;
 
wchar_t * utf8_to_unicode(char *utf8_string)
{
    int err;
    wchar_t * res;
    int res_len = MultiByteToWideChar(
        CP_UTF8,            // Code page
        0,                  // No flags
        utf8_string,        // Multibyte characters string
        -1,                 // The string is NULL terminated
        NULL,               // No buffer yet, allocate it later
        0                   // No buffer
        );
    if (res_len == 0)
    {
        printf("Failed to obtain utf8 string length\n");
        return NULL;
    }
    res = (wchar_t*)calloc(res_len + 1, sizeof(wchar_t)); //сначала сколько, затем размер, на всякий случай +1 к размеру юникодной строки
    if (res == NULL)
    {
        printf("Failed to allocate unicode string\n");
        return NULL;
    }
    err = MultiByteToWideChar(
        CP_UTF8,            // Code page
        0,                  // No flags
        utf8_string,        // Multibyte characters string
        -1,                 // The string is NULL terminated
        res,                // Output buffer
        res_len             // buffer size
        );
    if (err == 0)
    {
        printf("Failed to convert to unicode\n");
        free(res);
        return NULL;
    }
    return res;
}
///////
