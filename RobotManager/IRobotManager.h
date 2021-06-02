#pragma once
#ifdef ROBOTMANAGER_EXPORTS
#define ROBOTMANAGER_API __declspec(dllexport)
#else
#define ROBOTMANAGER_API __declspec(dllimport)
#endif

class IRobotManager
{
public:
	virtual void foo() = 0;
};

ROBOTMANAGER_API IRobotManager* GetRobotManagerInstance();