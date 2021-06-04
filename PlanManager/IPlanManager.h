/**
  * File: IPlanManager.h
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
#ifdef PLANMANAGER_EXPORTS
#define PLANMANAGER_API __declspec(dllexport)
#else
#define PLANMANAGER_API __declspec(dllimport)
#endif

class IPlanManager
{
public:
	virtual void foo() = 0;
};

PLANMANAGER_API IPlanManager* GetPlanManagerInstance();