
#ifndef DWSPP_H
#define DWSPP_H

#ifdef __cplusplus
extern "C" {
#endif

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
};

typedef void* DWS_Instance;


extern DWS_Instance dws_init();

extern void dws_free(DWS_Instance instance);

extern int dws_getWindowsVersion(DWS_Instance instance);


#ifdef __cplusplus
}
#endif


#endif /* DWSPP_H */
