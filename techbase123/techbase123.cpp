﻿/*
* 2021 11/09 ~
* Teddy
*
*/
#include <iostream>
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

void main()
{
    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure. 
    GetSystemInfo(&siSysInfo);

    // Display the contents of the SYSTEM_INFO structure. 
    printf("Teddy's Hardware information: \n\n");
    printf("  OEM ID: %u\n", siSysInfo.dwOemId);
    printf("  Number of processors: %u\n",
        siSysInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", siSysInfo.dwPageSize);
    printf("  Processor type: %u\Wn", siSysInfo.dwProcessorType);
    printf("  Minimum application address: %lx\n",
        siSysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n",
        siSysInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n",
        siSysInfo.dwActiveProcessorMask);
    // test

    printf("hello");
    printf("hello");
    printf("hello");
}