//하드웨어 정보 가져오기 c++

#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

void main()
{
    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure. 

    GetSystemInfo(&siSysInfo);

    // Display the contents of the SYSTEM_INFO structure. 

    printf("Hardware information: \n");
    printf("  OEM ID: %u\n", siSysInfo.dwOemId);
    printf("  Number of processors: %u\n",
        siSysInfo.dwNumberOfProcessors);                                    //  cpu의 개수
    printf("  Page size: %u\n", siSysInfo.dwPageSize);

    //printf("  Processor type: %u\n", siSysInfo.dwProcessorType);          //더이상 사용안됨

    printf("  Minimum application address: %lx\n",
        siSysInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n",
        siSysInfo.lpMaximumApplicationAddress);

                                                                            //각각 프로세스가 사용할 수 있는 가장 작은값
                                                                            //: 대부분의 경우 0주소부터 64 kb 해당하는 주소 공간은
                                                                            //프리 상태를 유지 해야 하기 때문에 이값은 65536 혹은 0x00010000 이다

    printf("  Active processor mask: %u\n",                                 
        siSysInfo.dwActiveProcessorMask);                                   //사용 가능한 CPU를 가리키는 비트마스크(스레드를 수행할 수 있는 CPU)

//https://docs.microsoft.com/ko-kr/windows/win32/sysinfo/getting-hardware-information



//동작중인 프로세스 리스트 보기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

FILE* fp;


int main() {
    const DWORD process_id = GetCurrentProcessId();
    PROCESSENTRY32 pe32;

    pe32.dwSize = sizeof(pe32);

    HANDLE processes_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    fp = _wfopen(L"", L"w+");


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
    system("pause");

}

//https://wendys.tistory.com/165





//특정 폴더 파일 리스트 보기

#define _CRT_SECURE_NO_WARNINGS 
#include <Windows.h>
#include <string>
#include <stdio.h>


FILE* fp;

void FindFile(wchar_t* path);
void main()
{
    // 파일리스트를 파일로 저장합니다.
    fp = _wfopen(L"C:\\test\\filelist.txt", L"w+");
    // 특정경로지정
    wchar_t path[256] = L"C:\\test\\";

    FindFile(path);
    fclose(fp);

}
void FindFile(wchar_t* path)
{
    WIN32_FIND_DATA fd;

    wchar_t path2[256];
    wsprintf(path2, L"%s%s", path, L"*.*");

    HANDLE hFind = ::FindFirstFile(path2, &fd);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                // 콘솔창에서 출력
                wprintf(L"%s\n", fd.cFileName);
                // 파일로 저장
                fwprintf(fp, L"%s\n", fd.cFileName);
            }
            else
            {
                if (fd.cFileName[0] != '.')
                {

                    wchar_t path3[256];
                    wsprintf(path3, L"%s%s\\", path, fd.cFileName);
                    //재귀호출합니다.
                    FindFile(path3);
                }
            }
        } while (::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
}

//https://scvtwo.tistory.com/168



//네트워크 주소 확인 하기

#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#pragma warning(disable:4996)
FILE* fp;
#pragma comment(lib,"ws2_32")
void ViewLocalHostIPv4();

int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    fp = _wfopen(L"network.txt", L"w+");

    ViewLocalHostIPv4();

    WSACleanup();
    fclose(fp);
    return 0;
}

void ViewLocalHostIPv4()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
    {
        return;
    }
    HOSTENT* ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
        {
            for (int index = 0; ptr->h_addr_list[index]; index++)
            {
                memcpy(&addr, ptr->h_addr_list[index], ptr->h_length);//메모리 복사
                printf("%s\n", inet_ntoa(addr));
                fprintf(fp, "%s\n", inet_ntoa(addr));
            }
        }
        ptr++;
    }
}

//https://ehpub.co.kr/2-4-%EB%A1%9C%EC%BB%AC-%ED%98%B8%EC%8A%A4%ED%8A%B8-ip-%EC%A3%BC%EC%86%8C-%EC%96%BB%EC%96%B4%EC%98%A4%EA%B8%B0-tcpip-%EC%86%8C%EC%BC%93-%ED%86%B5%EC%8B%A0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98/
