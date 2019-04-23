#include <windows.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <winver.h>
#include <stdlib.h>
#include <assert.h>
#include <versionhelpers.h>

#include "dwspp.h"
#include "dwspp_private.h"
#include "windows_utils.h"

#ifndef FILE_VER_GET_NEUTRAL
// Missing prototypes in MinGW headers
DWORD APIENTRY GetFileVersionInfoSizeExW(_In_ DWORD dwFlags, _In_ LPCWSTR lpwstrFilename, _Out_ LPDWORD lpdwHandle);
BOOL APIENTRY GetFileVersionInfoExW(_In_ DWORD dwFlags,
                                    _In_ LPCWSTR lpwstrFilename,
                                    _Reserved_ DWORD dwHandle,
                                    _In_ DWORD dwLen,
                                    _Out_writes_bytes_(dwLen) LPVOID lpData);
#define FILE_VER_GET_NEUTRAL    0x02
#endif


void DWS_Instance_imp::detectWindowsVersion()
{
    if(IsWindows10OrGreater())
    {
        _windowsVersion = WINDOWS_10;
        _win10 = true;
        if(IsWindowsServer())
            _windowsVersion = WINDOWS_SERVER_2019;
    }
    else if(IsWindows8Point1OrGreater())
    {
        _windowsVersion = WINDOWS_81;
        _win10 = false;
        if(IsWindowsServer())
            _windowsVersion = WINDOWS_SERVER_2012;
    }
    else if(IsWindows8OrGreater())
    {
        _windowsVersion = WINDOWS_8;
        _win10 = false;
        if(IsWindowsServer())
            _windowsVersion = WINDOWS_SERVER_2012;
    }
    else if(IsWindows7OrGreater())
    {
        _windowsVersion = WINDOWS_7;
        _win10 = false;
        if(IsWindowsServer())
            _windowsVersion = WINDOWS_SERVER_2008;
    }
    else
    {
        _windowsVersion = WINDOWS_UNKNOWN;
        _win10 = false;
    }
}

void DWS_Instance_imp::init()
{
    detectWindowsVersion();

    wchar_t systemDirectory[MAX_PATH];
    _systemPath = std::wstring(_wgetenv(L"WinDir"));
    if(SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_WINDOWS, NULL, 0, systemDirectory)))
    {
        _systemPath = std::wstring(systemDirectory);
    }

    if(WindowsUtil::fileExists(_systemPath + L"\\Sysnative\\cmd.exe"))
    {
        _system32Location = _systemPath + + L"\\Sysnative\\";
    }
    else
    {
        _system32Location = _systemPath + + L"\\system32\\";
    }
}

DWS_Instance_imp::DWS_Instance_imp()
{
    init();
}

DWS_Instance_imp::~DWS_Instance_imp()
{}

void DWS_Instance_imp::setLogPath(const std::wstring &logPath)
{
    LogFileName = logPath;
}

WindowsVersion DWS_Instance_imp::getWindowsVersion()
{
    return _windowsVersion;
}
