#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

void AlertWithMessageBox(SYSTEM_POWER_STATUS sps)
{
    LPCWSTR Title = (LPCWSTR)L"BatteryAlert";
    BYTE LowThreshold = 40;
    BYTE HighThreshold = 80;

    //when battery is not charging and percentage of remained life < LowThreshold%
    if (sps.BatteryFlag <= 4 && sps.BatteryLifePercent < LowThreshold)
    {
        MessageBox(NULL,
                   (LPCWSTR)L"Power is low!",
                   Title,
                   MB_OK);
    }
    //when battery is charging and percentage of remained life > HighThreshold%
    if (sps.BatteryFlag == 8 && sps.BatteryLifePercent > HighThreshold)
    {
        MessageBox(NULL,
                   (LPCWSTR)L"Power is high!",
                   Title,
                   MB_OK);
    }
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow)
{
    // https://docs.microsoft.com/en-us/windows/win32/api/winbase/ns-winbase-system_power_status
    SYSTEM_POWER_STATUS sps;
    if (GetSystemPowerStatus(&sps))
    {
        AlertWithMessageBox(sps);
    }

    return 0;
}