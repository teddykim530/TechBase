//네트워크 주소 확인 하기

//#define _CRT_SECURE_NO_WARNINGS
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

// #pragma warning(disable:4996)
// #pragma comment(lib, "ws2_32.lib")

FILE* fp;
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
}

//https://ehpub.co.kr/2-4-%EB%A1%9C%EC%BB%AC-%ED%98%B8%EC%8A%A4%ED%8A%B8-ip-%EC%A3%BC%EC%86%8C-%EC%96%BB%EC%96%B4%EC%98%A4%EA%B8%B0-tcpip-%EC%86%8C%EC%BC%93-%ED%86%B5%EC%8B%A0-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98/
