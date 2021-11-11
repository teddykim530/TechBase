//동작중인 프로세스 리스트 보기
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

FILE* fp;

int main() 
{
    const DWORD process_id = GetCurrentProcessId();
    PROCESSENTRY32 pe32;

    pe32.dwSize = sizeof(pe32);

    HANDLE processes_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    fp = _wfopen(L"p_list.txt", L"w+");

    if (INVALID_HANDLE_VALUE != processes_snapshot) 
    {
        BOOL first = Process32First(processes_snapshot, &pe32);
        do {
            if (process_id == pe32.th32ProcessID) {
                std::wcout << "Process name : " << pe32.szExeFile << std::endl;
                fwprintf(fp, L"%s\n", pe32.szExeFile);
                break;
            }
        } while (Process32Next(processes_snapshot, &pe32));
        CloseHandle(processes_snapshot);
    }
    fclose(fp);
}