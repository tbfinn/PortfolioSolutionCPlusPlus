/**
  * File: DetectorManager.cpp
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
#include "DetectorManager.h"
#include "IDetectorManager.h"
#include "IDBManager.h"

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

IDetectorManager* GetDetectorManagerInstance()
{
	return CDetectorManager::GetInstance();
}

CDetectorManager* CDetectorManager::singleton_ = nullptr;

void CDetectorManager::foo()
{
	/* code */
	IDBManager* pdbm =  GetDbManagerInstance();
}
CDetectorManager* CDetectorManager::GetInstance()
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (singleton_ == nullptr) {
		OutputDebugString(L"\nCDetectorManager::GetInstance() - Creating Detector Manager");
		singleton_ = new CDetectorManager();
	}
	else
		OutputDebugString(L"\nCDetectorManager::GetInstance() - Detector Manager Already Exists");

	return singleton_;
}
