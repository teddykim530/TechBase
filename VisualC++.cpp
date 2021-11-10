#include <windows.h>
#include <stdio.h>
#include <iostream>

// Getting the Hardware info(CPU, Memory, HDD)
void hardware_info()
{
   SYSTEM_INFO siSysInfo;
   // Copy the hardware information to the SYSTEM_INFO structure. 
 
   GetSystemInfo(&siSysInfo); 
   // Display the contents of the SYSTEM_INFO structure. 

   printf("Hardware information: \n");  
   printf("===================== \n");
   printf("OEM ID: %u\n", siSysInfo.dwOemId);
   printf("Number of processors: %u\n", siSysInfo.dwNumberOfProcessors); 
   printf("Page size: %u\n", siSysInfo.dwPageSize); 
   printf("Processor type: %u\n", siSysInfo.dwProcessorType); 
   printf("Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress); 
   printf("Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress); 
   printf("Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);
   printf("===================== \n"); 
}

// *Source
// https://docs.microsoft.com/ko-kr/windows/win32/sysinfo/getting-hardware-information



///////////////////////////////

//동작중인 프로세스 리스트 보기
// void process_info() 
// {
//    DWORD process_id = GetCurrentProcessId();
//    HANDLE process_handle = OpenProcess 
//    ( PROCESS_QUERY_LIMITED_INFORMATION, FALSE, process_id );

//    if (process_handle) 
//    {
//       wchar_t buffer[MAX_PATH] = {};
//       DWORD buffer_size = MAX_PATH;
//       if (QueryFullProcessImageNameW(process_handle, 0, buffer, &buffer_size)) {
//       std::wcout << L"QueryFullProcessImageNameW process name : " << buffer << std::endl;
//    }
//       CloseHandle(process_handle);
//    }
// }

// *Source
// https://wendys.tistory.com/165


int main()
{
   hardware_info();
   //process_info();
}