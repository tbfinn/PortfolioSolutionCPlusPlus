/**
  * File: IDBManager.h
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
#ifdef DBMANAGER_EXPORTS
#define DBMANAGER_API __declspec(dllexport)
#else
#define DBMANAGER_API __declspec(dllimport)
#endif
#include "../CommonDataLibrary/Plan.h"
#include <vector>

class IDBManager
{
public:
	virtual void foo() = 0;

	virtual std::vector<DataLibrary::CPlan> QueryPlans(void) = 0;
	virtual void* QueryDetectors(void) = 0;
	virtual void* QueryRobots(void) = 0;

};

DBMANAGER_API IDBManager* GetDbManagerInstance();