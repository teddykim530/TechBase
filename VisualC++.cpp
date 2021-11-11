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
   printf("Number of processors: %u\n", siSysInfo.dwNumberOfProcessors); 
   printf("Page size: %u\n", siSysInfo.dwPageSize); 
   printf("Processor type: %u\n", siSysInfo.dwProcessorType); 
   printf("Minimum application address: %lx\n", siSysInfo.lpMinimumApplicationAddress); 
   printf("Maximum application address: %lx\n", siSysInfo.lpMaximumApplicationAddress); 
   printf("Active processor mask: %u\n", siSysInfo.dwActiveProcessorMask);
}

#define INFO_BUFFER_SIZE 32767
void printError( TCHAR* msg );

void hardward_info2()
{
  DWORD i;
  TCHAR  infoBuf[INFO_BUFFER_SIZE];
  DWORD  bufCharCount = INFO_BUFFER_SIZE;
 
  // Get and display the name of the computer. 
  bufCharCount = INFO_BUFFER_SIZE;
  if( !GetComputerName( infoBuf, &bufCharCount ) )
    printError( TEXT("GetComputerName") ); 
  _tprintf( TEXT("\nComputer name:      %s"), infoBuf ); 
 
  // Get and display the user name. 
  bufCharCount = INFO_BUFFER_SIZE;
  if( !GetUserName( infoBuf, &bufCharCount ) )
    printError( TEXT("GetUserName") ); 
  _tprintf( TEXT("\nUser name:          %s"), infoBuf ); 
 
  // Get and display the system directory. 
  if( !GetSystemDirectory( infoBuf, INFO_BUFFER_SIZE ) )
    printError( TEXT("GetSystemDirectory") ); 
  _tprintf( TEXT("\nSystem Directory:   %s"), infoBuf ); 
 
  // Get and display the Windows directory. 
  if( !GetWindowsDirectory( infoBuf, INFO_BUFFER_SIZE ) )
    printError( TEXT("GetWindowsDirectory") ); 
  _tprintf( TEXT("\nWindows Directory:  %s\n"), infoBuf ); 
 
}
void printError( TCHAR* msg )
{
  DWORD eNum;
  TCHAR sysMsg[256];
  TCHAR* p;

  eNum = GetLastError( );
  FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | 
         FORMAT_MESSAGE_IGNORE_INSERTS,
         NULL, eNum,
         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
         sysMsg, 256, NULL );

  // Trim the end of the line and terminate it with a null
  p = sysMsg;
  while( ( *p > 31 ) || ( *p == 9 ) )
    ++p;
  do { *p-- = 0; } while( ( p >= sysMsg ) &&
                          ( ( *p == '.' ) || ( *p < 33 ) ) );

  // Display the message
  _tprintf( TEXT("\n\t%s failed with error %d (%s)"), msg, eNum, sysMsg );
}

// *Source
// https://docs.microsoft.com/ko-kr/windows/win32/sysinfo/getting-hardware-information



///////////////////////////////

//동작중인 프로세스 리스트 보기
void process_info() 
{
   const DWORD process_id = GetCurrentProcessId();
    PROCESSENTRY32 pe32;

    pe32.dwSize = sizeof(pe32);

    HANDLE processes_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    fp = _wfopen(L"p_list.txt", L"w+");


    if (INVALID_HANDLE_VALUE != processes_snapshot) {
        BOOL first = Process32First(processes_snapshot, &pe32);
        do {
            if (process_id == pe32.th32ProcessID) {
                std::wcout << "CreateToolhelp32Snapshot process name : " << pe32.szExeFile << std::endl;
                fwprintf(fp, L"%s\n", pe32.szExeFile);
                break;
            }
        } while (Process32Next(processes_snapshot, &pe32));
        CloseHandle(processes_snapshot);
    }
    fclose(fp);
}

// *Source
// https://wendys.tistory.com/165


int main()
{
   printf("====================================\n");
   hardware_info();
   printf("====================================\n");
   hardward_info2();
   printf("====================================\n");
   process_info();
   printf("====================================\n");
}