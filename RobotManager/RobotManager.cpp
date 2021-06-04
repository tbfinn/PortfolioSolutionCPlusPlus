/**
  * File: RobotManager.cpp
  *
  * Author:  Timothy B. Finn (tbf.lodi@gmail.com)
  * Date:     Spring 2021
  * Project:   Portfolio Project
  *
  * Summary of File:
  *
  *
  *
  */

#include "stdafx.h"
#include "RobotManager.h"
#include "IRobotManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}

IRobotManager* GetRobotManagerInstance()
{
	return CRobotManager::GetInstance();
}

CRobotManager* CRobotManager::singleton_ = nullptr;

void CRobotManager::foo()
{
	/* code */
}
CRobotManager* CRobotManager::GetInstance()
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (singleton_ == nullptr) {
		OutputDebugString(L"\nCRobotManager::GetInstance() - Creating Robot Manager");
		singleton_ = new CRobotManager();
	}
	else
		OutputDebugString(L"\nCRobotManager::GetInstance() - Robot Manager Already Exists");

	return singleton_;
}