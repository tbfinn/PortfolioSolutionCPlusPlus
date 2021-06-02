#pragma once
#ifdef RUNMANAGER_EXPORTS
#define RUNMANAGER_API __declspec(dllexport)
#else
#define RUNMANAGER_API __declspec(dllimport)
#endif

class IRunManager
{
public:
	virtual void foo() = 0;
};

RUNMANAGER_API IRunManager* GetRunManagerInstance();