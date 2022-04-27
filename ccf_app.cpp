// ccf_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>

#include <ClusAPI.h>                   // Cluster API.

#include <ResApi.h>                    // Resource API.

#pragma comment( lib, "ClusAPI.lib" )  // Cluster API library.
#pragma comment( lib, "ResUtils.lib" ) // Utility Library.
#pragma comment( lib, "NTLanMan.lib" ) // NTLANMAN

#include <iostream>
#include <smbclnt.h> /* RegisterAppInstance* */
#include <processthreadsapi.h> /* GetCurrentProcess */
#include <combaseapi.h> /* CoCreateGuid */

using std::cout;
using std::endl;

int main()
{
    GUID appGuid;
    
    if (S_OK == CoCreateGuid(&appGuid)) {
        cout << "Failed to generate a GUID" << endl;
        exit(1);
    }

    // Register new app instance, uniquely identifies this app (static across processes for same app e.g. failover/restart etc.)
    DWORD dwError = RegisterAppInstance(
        GetCurrentProcess(), /* ProcessHandle */
        &appGuid, /* AppInstanceId */
        false /* ChildrenInheritAppInstance */
        );

    if (dwError != ERROR_SUCCESS) {
        cout << "Failed to register app instance with error " << dwError << 
            " and ID " << appGuid.Data1 << " " << appGuid.Data2 << " " << appGuid.Data3 << " " << appGuid.Data4 << endl;
        exit(1);
    }

    // Once We have registered a new app, must instantiate version specifically for this process (each distinct process for an app is a "version")
    dwError = RegisterAppInstanceVersion(
        &appGuid /* AppInstanceId*/,
        10 /* InstanceVersionHigh */,
        0 /* InstanceVersionLow */);

    if (dwError != ERROR_SUCCESS) {
        cout << "Failed to register app instance with error " << dwError << endl;
        exit(1);
    }
}