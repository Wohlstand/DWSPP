
#ifndef DWSPP_PRIVATE_H
#define DWSPP_PRIVATE_H

#include <string>
#include <vector>
#include <windows.h>

bool fileExists(const std::wstring &filePath);

class DWS_Instance_imp
{
    std::wstring              LogFileName = L"DWS.log";
    std::wstring              _systemPath;
    bool                      _destroyFlag = false;
    std::vector<std::wstring> _errorsList;
    int                       _fatalErrors = 0;
    std::wstring              _system32Location;
    bool                      _win10 = true;

    enum WindowsVersion
    {
        WINDOWS_UNKNOWN = 0,
        WINDOWS_7,
        WINDOWS_SERVER_2008,
        WINDOWS_8,
        WINDOWS_SERVER_2012,
        WINDOWS_81,
        WINDOWS_10,
        WINDOWS_SERVER_2019
    } _windowsVersion = WINDOWS_UNKNOWN;

    void detectWindowsVersion();
public:
    void init();

    DWS_Instance_imp();
    ~DWS_Instance_imp();

    void setLogPath(const std::wstring &logPath);
};


#endif /* DWSPP_PRIVATE_H */
