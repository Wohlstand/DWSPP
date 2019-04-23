#include <windows.h>
#include <shlwapi.h>
#include <cstdio>
#include <cstdlib>
#include "windows_utils.h"

bool WindowsUtil::fileExists(const std::wstring &filePath)
{
    return PathFileExistsW(filePath.c_str()) == TRUE;
}

static LONG GetStringRegKey(HKEY hKey, const std::wstring &strValueName, std::wstring &strValue, const std::wstring &strDefaultValue)
{
    strValue = strDefaultValue;
    WCHAR szBuffer[512];
    DWORD dwBufferSize = sizeof(szBuffer);
    ULONG nError;
    nError = RegQueryValueExW(hKey, strValueName.c_str(), 0, NULL, (LPBYTE)szBuffer, &dwBufferSize);
    if (ERROR_SUCCESS == nError)
    {
        strValue = szBuffer;
    }
    return nError;
}

std::wstring WindowsUtil::getRegistryStrHKLM(const std::wstring &path, const std::wstring &key, const std::wstring &defaultValue)
{
    HKEY hKey;
    RegOpenKeyExW(HKEY_LOCAL_MACHINE, path.c_str(), 0, KEY_READ, &hKey);
    std::wstring strOutValue;
    GetStringRegKey(hKey, key.c_str(), strOutValue, defaultValue.c_str());
    return strOutValue;
}

std::wstring WindowsUtil::getRegistryStrHKCU(const std::wstring &path, const std::wstring &key, const std::wstring &defaultValue)
{
    HKEY hKey;
    RegOpenKeyExW(HKEY_CURRENT_USER, path.c_str(), 0, KEY_READ, &hKey);
    std::wstring strOutValue;
    GetStringRegKey(hKey, key.c_str(), strOutValue, defaultValue.c_str());
    return strOutValue;
}


int WindowsUtil::GetWindowsBuildNumber()
{
    std::wstring wb = getRegistryStrHKLM(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", L"CurrentBuildNumber");
    return _wtoi(wb.c_str());
}

bool WindowsUtil::UAC_Status()
{
    std::wstring wb = getRegistryStrHKLM(L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System\\", L"EnableLUA");
    return _wtoi(wb.c_str()) != 0;
}

int WindowsUtil::SystemRestore_Status()
{
    std::wstring wb = getRegistryStrHKLM(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\SystemRestore\\", L"RPSessionInterval");
    return _wtoi(wb.c_str()) != 0;
}

std::wstring WindowsUtil::GetProductName()
{
    return getRegistryStrHKLM(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", L"ProductName");
}

std::wstring WindowsUtil::GetSystemBuild()
{
    return getRegistryStrHKLM(L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\", L"BuildLabEx");
}

int WindowsUtil::exec(std::wstring commandAndArgs)
{
    //TODO: Implement ability to capture output and writing of error info/code into the log
    return _wsystem(commandAndArgs.c_str());
}
