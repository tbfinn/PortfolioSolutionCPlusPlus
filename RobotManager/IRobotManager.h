/**
  * File: IRobotManager.h
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

	virtual void* RequestRobots(void* pRobotManager) = 0;
	virtual void ReleaseRobots(void* pDBManager) = 0;
};

ROBOTMANAGER_API IRobotManager* GetRobotManagerInstance();