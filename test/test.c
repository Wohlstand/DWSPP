#include <dwspp.h>
#include <stdio.h>

static const char* g_winVers[] = {
    "Unknown",
    "Windows 7",
    "Windows Server 2008",
    "Windows 8",
    "Windows Server 2012",
    "Windows 8.1",
    "Windows 10",
    "Windows Server 2019"
};

int main()
{
    DWS_Instance dws;
    int ver = WINDOWS_UNKNOWN;

    dws = dws_init();
    if(!dws)
    {
        fprintf(stderr, "ERROR: CAN'T INITIALIZE dws!\n\n");
        return 1;
    }

    ver = dws_getWindowsVersion(dws);
    fprintf(stdout, "TEST: Detected Windows version code is: %s\n\n", g_winVers[ver]);

    dws_free(dws);

    return 0;
}
