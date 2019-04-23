
#ifndef DWSPP_PRIVATE_H
#define DWSPP_PRIVATE_H

#include <string>
#include <vector>
#include <windows.h>
#include "dwspp.h"

class DWS_Instance_imp
{
    std::wstring              LogFileName = L"DWS.log";
    std::wstring              _systemPath;
    bool                      _destroyFlag = false;
    std::vector<std::wstring> _errorsList;
    int                       _fatalErrors = 0;
    std::wstring              _system32Location;
    bool                      _win10 = true;

    WindowsVersion _windowsVersion = WINDOWS_UNKNOWN;

    void detectWindowsVersion();
public:
    void init();

    DWS_Instance_imp();
    ~DWS_Instance_imp();

    void setLogPath(const std::wstring &logPath);

    WindowsVersion getWindowsVersion();
};


#endif /* DWSPP_PRIVATE_H */
