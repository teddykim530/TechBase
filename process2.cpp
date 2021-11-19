#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h> // process memory structure api

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1
void PrintProcessNameAndID( DWORD processID )
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.
    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, processID );

    // Get the process name.
    if (NULL != hProcess )
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod), 
             &cbNeeded) )
        {
            GetModuleBaseName( hProcess, hMod, szProcessName, 
                               sizeof(szProcessName)/sizeof(TCHAR) );
        }
    }

    // Print the process name and identifier.
    _tprintf( TEXT("%s  (PID: %u)\n"), szProcessName, processID );

    // Release the handle to the process.
    CloseHandle( hProcess );
}

int main( void )
{
    // Get the list of process identifiers.
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
    {
        return 1;
    }

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.

    printf("\tCurrent Running Processes \n");
    printf("==========================================\n");
    for ( i = 0; i < cProcesses; i++ )
    {
        if( aProcesses[i] != 0 )
        {
            PrintProcessNameAndID( aProcesses[i] );
        }
    }
    printf("==========================================\n");
    return 0;
}

//Source
//https://stackoverflow.com/questions/11564148/how-to-get-the-starting-base-address-of-a-process-in-c



Current Running Processes 
==========================================
<unknown>  (PID: 4)
<unknown>  (PID: 172)
<unknown>  (PID: 600)
<unknown>  (PID: 900)
<unknown>  (PID: 752)
<unknown>  (PID: 1012)
<unknown>  (PID: 1000)
<unknown>  (PID: 1144)
<unknown>  (PID: 1172)
<unknown>  (PID: 1300)
<unknown>  (PID: 1388)
<unknown>  (PID: 1504)
<unknown>  (PID: 1516)
<unknown>  (PID: 1580)
<unknown>  (PID: 1708)
<unknown>  (PID: 1788)
<unknown>  (PID: 1808)
<unknown>  (PID: 1844)
<unknown>  (PID: 1876)
<unknown>  (PID: 1968)
<unknown>  (PID: 2028)
<unknown>  (PID: 2036)
<unknown>  (PID: 2044)
<unknown>  (PID: 760)
<unknown>  (PID: 2052)
<unknown>  (PID: 2112)
<unknown>  (PID: 2164)
<unknown>  (PID: 2176)
<unknown>  (PID: 2184)
<unknown>  (PID: 2204)
<unknown>  (PID: 2548)
<unknown>  (PID: 2580)
<unknown>  (PID: 2636)
<unknown>  (PID: 2740)
<unknown>  (PID: 2816)
<unknown>  (PID: 2820)
<unknown>  (PID: 2868)
<unknown>  (PID: 2888)
<unknown>  (PID: 3000)
<unknown>  (PID: 3036)
<unknown>  (PID: 2496)
<unknown>  (PID: 3232)
<unknown>  (PID: 3240)
<unknown>  (PID: 3248)
<unknown>  (PID: 3256)
<unknown>  (PID: 3264)
<unknown>  (PID: 3276)
<unknown>  (PID: 3284)
<unknown>  (PID: 3292)
<unknown>  (PID: 3300)
<unknown>  (PID: 3456)
<unknown>  (PID: 3464)
<unknown>  (PID: 3492)
<unknown>  (PID: 3512)
<unknown>  (PID: 3520)
<unknown>  (PID: 3528)
<unknown>  (PID: 3552)
<unknown>  (PID: 3660)
<unknown>  (PID: 3784)
<unknown>  (PID: 3792)
<unknown>  (PID: 3852)
<unknown>  (PID: 3872)
<unknown>  (PID: 4072)
<unknown>  (PID: 4904)
<unknown>  (PID: 3136)
<unknown>  (PID: 6136)
<unknown>  (PID: 5404)
<unknown>  (PID: 5612)
<unknown>  (PID: 2896)
<unknown>  (PID: 7124)
<unknown>  (PID: 6348)
<unknown>  (PID: 6340)
<unknown>  (PID: 9096)
<unknown>  (PID: 8060)
<unknown>  (PID: 10668)
<unknown>  (PID: 3676)
<unknown>  (PID: 11956)
<unknown>  (PID: 12576)
<unknown>  (PID: 13240)
<unknown>  (PID: 12932)
<unknown>  (PID: 12472)
<unknown>  (PID: 3048)
<unknown>  (PID: 12624)
<unknown>  (PID: 6952)
<unknown>  (PID: 9836)
<unknown>  (PID: 19208)
<unknown>  (PID: 18404)
<unknown>  (PID: 15712)
<unknown>  (PID: 20948)
<unknown>  (PID: 12480)
<unknown>  (PID: 13484)
<unknown>  (PID: 14524)
<unknown>  (PID: 17476)
<unknown>  (PID: 3616)
<unknown>  (PID: 12068)
<unknown>  (PID: 17356)
<unknown>  (PID: 20020)
<unknown>  (PID: 3172)
<unknown>  (PID: 7144)
<unknown>  (PID: 19204)
<unknown>  (PID: 7052)
<unknown>  (PID: 5320)
DPM.exe  (PID: 2120)
sihost.exe  (PID: 10792)
svchost.exe  (PID: 20288)
svchost.exe  (PID: 7500)
taskhostw.exe  (PID: 20864)
Explorer.EXE  (PID: 17620)
svchost.exe  (PID: 2276)
<unknown>  (PID: 20128)
AnySign4PC.exe  (PID: 9500)
ApplicationFrameHost.exe  (PID: 8164)
Microsoft.Notes.exe  (PID: 13852)
RuntimeBroker.exe  (PID: 18552)
StartMenuExperienceHost.exe  (PID: 13656)
RuntimeBroker.exe  (PID: 12808)
SearchApp.exe  (PID: 20148)
RuntimeBroker.exe  (PID: 5692)
YourPhone.exe  (PID: 16744)
LockApp.exe  (PID: 5496)
RuntimeBroker.exe  (PID: 16392)
RuntimeBroker.exe  (PID: 11816)
RuntimeBroker.exe  (PID: 11976)
TextInputHost.exe  (PID: 17836)
SecurityHealthSystray.exe  (PID: 9552)
RtkAudUService64.exe  (PID: 14932)
OneDrive.exe  (PID: 9072)
KakaoTalk.exe  (PID: 17188)
Cortana.exe  (PID: 15132)
RuntimeBroker.exe  (PID: 7924)
svchost.exe  (PID: 20976)
Win32Bridge.Server.exe  (PID: 14100)
svchost.exe  (PID: 10620)
SettingSyncHost.exe  (PID: 3404)
RuntimeBroker.exe  (PID: 6668)
Microsoft.Photos.exe  (PID: 14928)
RuntimeBroker.exe  (PID: 10548)
WinStore.App.exe  (PID: 9396)
DllHost.exe  (PID: 7152)
chrome.exe  (PID: 7528)
chrome.exe  (PID: 16896)
chrome.exe  (PID: 15316)
chrome.exe  (PID: 19088)
chrome.exe  (PID: 1428)
chrome.exe  (PID: 19372)
chrome.exe  (PID: 2100)
chrome.exe  (PID: 6284)
chrome.exe  (PID: 1720)
chrome.exe  (PID: 18740)
chrome.exe  (PID: 21144)
chrome.exe  (PID: 12592)
chrome.exe  (PID: 9904)
chrome.exe  (PID: 6480)
chrome.exe  (PID: 11876)
Code.exe  (PID: 14120)
Code.exe  (PID: 5212)
Code.exe  (PID: 16968)
Code.exe  (PID: 14904)
Code.exe  (PID: 17908)
Code.exe  (PID: 18580)
Code.exe  (PID: 9324)
Code.exe  (PID: 4416)
Code.exe  (PID: 18244)
conhost.exe  (PID: 7088)
powershell.exe  (PID: 14184)
cpptools.exe  (PID: 17684)
conhost.exe  (PID: 16716)
git.exe  (PID: 10236)
Code.exe  (PID: 1432)
conhost.exe  (PID: 20372)
vsls-agent.exe  (PID: 18148)
Code.exe  (PID: 5636)
<unknown>  (PID: 12488)
<unknown>  (PID: 13668)
ShellExperienceHost.exe  (PID: 20820)
RuntimeBroker.exe  (PID: 18844)
<unknown>  (PID: 18392)
<unknown>  (PID: 19252)
<unknown>  (PID: 11372)
<unknown>  (PID: 10112)
VirtualBox.exe  (PID: 11648)
VBoxSVC.exe  (PID: 4248)
<unknown>  (PID: 4940)
VirtualBoxVM.exe  (PID: 19676)
VirtualBoxVM.exe  (PID: 7036)
VirtualBoxVM.exe  (PID: 6248)
SystemSettings.exe  (PID: 3960)
UserOOBEBroker.exe  (PID: 13804)
chrome.exe  (PID: 20816)
<unknown>  (PID: 11964)
chrome.exe  (PID: 19872)
chrome.exe  (PID: 1060)
chrome.exe  (PID: 20928)
chrome.exe  (PID: 13384)
Video.UI.exe  (PID: 16872)
RuntimeBroker.exe  (PID: 5236)
chrome.exe  (PID: 14996)
chrome.exe  (PID: 11448)
chrome.exe  (PID: 18020)
<unknown>  (PID: 1672)
WINWORD.EXE  (PID: 18292)
chrome.exe  (PID: 11912)
splwow64.exe  (PID: 17900)
svchost.exe  (PID: 15836)
chrome.exe  (PID: 9012)
SearchProtocolHost.exe  (PID: 12884)
<unknown>  (PID: 5960)
cpptools-srv.exe  (PID: 18664)
process2.exe  (PID: 9412)
==========================================