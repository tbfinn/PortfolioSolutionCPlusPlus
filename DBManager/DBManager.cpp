// DBManager.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DBManager.h"
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

IDBManager* GetDbManagerInstance()
{
	return CDBManager::GetInstance();
}

CDBManager* CDBManager::singleton_ = nullptr;

void CDBManager::foo()
{
	/* code */
}
CDBManager* CDBManager::GetInstance()
{
	/**
	 * This is a safer way to create an instance. instance = new Singleton is
	 * dangeruous in case two instance threads wants to access at the same time
	 */
	if (singleton_ == nullptr) {
		OutputDebugString(L"\nCDbManager::GetInstance() - Creating Database Manager");
		singleton_ = new CDBManager();
	}
	else
		OutputDebugString(L"\nCDbManager::GetInstance() - Database Manager Already Exists");

	return singleton_;
}
