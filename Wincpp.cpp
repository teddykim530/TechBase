#include <WinSock2.h>
#include <windows.h>
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <TlHelp32.h>
#include <io.h>
#include <conio.h>
#include <string>

#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

using namespace std;

//Getting the Hardware info(CPU, Memory, HDD)
void getHardware_info()
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
	printf("Active processor mask: %lu\n", siSysInfo.dwActiveProcessorMask);
}


//Getting the Process info that you working on
void getProcess_info()
{
    FILE* fp1;
    const DWORD process_id = GetCurrentProcessId();
    PROCESSENTRY32 pe32;

    pe32.dwSize = sizeof(pe32);

    HANDLE processes_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    fp1 = _wfopen(L"p_list.txt", L"w+");

    if (INVALID_HANDLE_VALUE != processes_snapshot)
    {
        BOOL first = Process32First(processes_snapshot, &pe32);

        printf("\tCurrent Process information \n");
        printf("====================================\n");
        do {
            if (process_id == pe32.th32ProcessID) {
                wcout << "Process name : " << pe32.szExeFile << endl;
                fwprintf(fp1, L"%s\n", pe32.szExeFile);
                break;
            }
        } while (Process32Next(processes_snapshot, &pe32));
        CloseHandle(processes_snapshot);
    }
    fclose(fp1);
}

//Getting the File list in a specific repository
void getFile_list()
{
	string path = "C:\\Users\\teddy\\TechBase\\*.*";

	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

        std::cout << "No file in directory!" << std::endl;

	printf("\tFile list information \n");
    printf("====================================\n");
	do
	{
		cout << "File: " << fd.name << endl;

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
}

//Getting the Network info that you working on
void getNetwork_info()
{
    FILE* fp;
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    fp = _wfopen(L"network.txt", L"w+");

    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
    {
        return;
    }
    HOSTENT* ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기

    printf("Network list information \n");
    printf("====================================\n");

    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
        {   
            for (int index = 0; ptr->h_addr_list[index]; index++)
            {
                printf("IP: ");
                memcpy(&addr, ptr->h_addr_list[index], ptr->h_length);//메모리 복사
                printf("%s\n", inet_ntoa(addr));
                fprintf(fp, "%s\n", inet_ntoa(addr));
            }
        }
        ptr++;
    }

    WSACleanup();
    fclose(fp);
}

int main()
{
	getHardware_info();
	printf("====================================\n\n");

    getProcess_info();
    printf("====================================\n\n");

    getFile_list();
    printf("====================================\n\n");

    getNetwork_info();
    printf("====================================\n\n");
}