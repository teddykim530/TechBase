#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

// Getting the Hardware info(CPU, Memory, HDD)
void hardware_info()
{  
   SYSTEM_INFO siSysInfo;
   GetSystemInfo(&siSysInfo); 
   // Display the contents of the SYSTEM_INFO structure. 

   printf("\tHardware information \n");  
   printf("====================================\n");
   printf("Number of processors: %u\n", siSysInfo.dwNumberOfProcessors); 
   printf("Page size: %u\n", siSysInfo.dwPageSize); 
   printf("Processor type: %u\n", siSysInfo.dwProcessorType); 
   printf("Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress); 
   printf("Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress); 
   printf("Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);
}


// *Source
// https://docs.microsoft.com/ko-kr/windows/win32/sysinfo/getting-hardware-information

int main()
{
   hardware_info();
   printf("====================================\n");
}