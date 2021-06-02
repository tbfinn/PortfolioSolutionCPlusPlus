#pragma once
#ifdef DBMANAGER_EXPORTS
#define DBMANAGER_API __declspec(dllexport)
#else
#define DBMANAGER_API __declspec(dllimport)
#endif

class IDBManager
{
public:
	virtual void foo() = 0;
};

DBMANAGER_API IDBManager* GetDbManagerInstance();