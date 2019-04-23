#include "dwspp.h"
#include "dwspp_private.h"

DWS_Instance dws_init()
{
    return new DWS_Instance_imp();
}

void dws_free(DWS_Instance instance)
{
    DWS_Instance_imp *ins = reinterpret_cast<DWS_Instance_imp*>(instance);
    if(ins)
        delete ins;
}

int dws_getWindowsVersion(DWS_Instance instance)
{
    DWS_Instance_imp *ins = reinterpret_cast<DWS_Instance_imp*>(instance);
    if(!ins)
        return WINDOWS_UNKNOWN;
    return ins->getWindowsVersion();
}
