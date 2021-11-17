#include <windows.h> // windows info api   //
#include <stdio.h>

void hardware_info();

// Getting the Hardware info(CPU, Memory, HDD)
void hardware_info()
{  
   SYSTEM_INFO siSysInfo;
   GetSystemInfo(&siSysInfo); 

   printf("\tHardware information \n");  
   printf("====================================\n");
   printf("OEM ID: %u\n", siSysInfo.dwOemId);
   printf("Number of processors: %u\n", siSysInfo.dwNumberOfProcessors); 
   printf("Page size: %u\n", siSysInfo.dwPageSize); 
   printf("Processor type: %u\n", siSysInfo.dwProcessorType); 
   printf("Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress); 
   printf("Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress); 
   printf("Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);

   MEMORYSTATUSEX memInfo;
   GlobalMemoryStatusEx(&memInfo);
   memInfo.dwLength = sizeof(MEMORYSTATUSEX);

   DWORDLONG totalPhysMem = memInfo.ullTotalPhys; // 전체 메모리
   DWORDLONG availPhysMem = memInfo.ullAvailPhys; // 남은 메모리

   printf("Total Mem: %I64u KB, Available Mem: %I64u KB\n", totalPhysMem / 1024, availPhysMem / 1024); // KB 로 출력

   BOOL  fResult;
   unsigned __int64 i64FreeBytesToCaller, i64TotalBytes, i64FreeBytes;

   fResult = GetDiskFreeSpaceEx("C:",
      (PULARGE_INTEGER)&i64FreeBytesToCaller,
      (PULARGE_INTEGER)&i64TotalBytes,
      (PULARGE_INTEGER)&i64FreeBytes);

   if (fResult)
   {
      printf("Available space to caller = %I64u MB\n",
         i64FreeBytesToCaller / (1024 * 1024));

      printf("Total space               = %I64u MB\n",
         i64TotalBytes / (1024 * 1024));

      printf("Free space on drive       = %I64u MB\n",
         i64FreeBytes / (1024 * 1024));
   }
}

int main()
{
   hardware_info();
   printf("====================================\n");
}

// *Source
// https://docs.microsoft.com/ko-kr/windows/win32/sysinfo/getting-hardware-information
// https://stackoverflow.com/questions/11917946/how-do-i-get-available-disk-space-from-windows-using-c
// https://ospace.tistory.com/514

