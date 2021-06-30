/**
  * File: DBManager.cpp
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
#include "DBManager.h"
#include "IDBManager.h"
#include <vector>
#include "../CommonDataLibrary/Plan.h"

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
////This function returns a new object, not a reference to the object
//const Point multiply(const Point& p) {
//	Point point();
//	//... Do multiplication
//	return point;
//}

std::vector<DataLibrary::CPlan> CDBManager::QueryPlans()
{
	std::vector<DataLibrary::CPlan> working;

	// TODO query a database
	// for now we toenail in dummy code

	for(int i = 0; i < 10;i++)
	{
		std::time_t result = std::time(nullptr);
		const std::wstring name = L"Plan " + std::to_wstring(i);
		DataLibrary::CPlan plan(name, result);
		working.push_back(plan);
	}

	return working;
}
std::vector<DataLibrary::CDetector> CDBManager::QueryDetectors()
{
	std::vector<DataLibrary::CDetector> working;

	// TODO query a database
	// for now we toenail in dummy code

	for (int i = 0; i < 10; i++)
	{
		std::time_t result = std::time(nullptr);
		const std::wstring name = L"Detector " + std::to_wstring(i);
		DataLibrary::CDetector detector(name, result);
		working.push_back(detector);
	}

	return working;
}
std::vector<DataLibrary::CRobot> CDBManager::QueryRobots()
{
	std::vector<DataLibrary::CRobot> working;

	// TODO query a database
	// for now we toenail in dummy code

	for (int i = 0; i < 10; i++)
	{
		std::time_t result = std::time(nullptr);
		const std::wstring name = L"Robot " + std::to_wstring(i);
		DataLibrary::CRobot robot(name, result);
		working.push_back(robot);
	}

	return working;
}
