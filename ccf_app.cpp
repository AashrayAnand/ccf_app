// ccf_app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>

#include <ClusAPI.h>                   // Cluster API.

#include <ResApi.h>                    // Resource API.

#pragma comment( lib, "ClusAPI.lib" )  // Cluster API library.
#pragma comment( lib, "ResUtils.lib" ) // Utility Library.
#pragma comment( lib, "NTLanMan.lib" ) // NTLANMAN
#include <iostream>
#include <smbclnt.h>
#include <processthreadsapi.h>
#include <combaseapi.h>

int main()
{
    GUID appGuid;
    CoCreateGuid(&appGuid);
    DWORD dwError = RegisterAppInstance(
        GetCurrentProcess(), /* ProcessHandle */
        &appGuid, /* AppInstanceId */
        false /* ChildrenInheritAppInstance */
        );

    if (dwError != ERROR_SUCCESS) {
        std::cout << "Failed to register app instance with error " << dwError << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
