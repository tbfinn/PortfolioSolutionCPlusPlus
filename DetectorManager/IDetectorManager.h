/**
  * File: IDetectorManager.h
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
#ifdef DETECTORMANAGER_EXPORTS
#define DETECTORMANAGER_API __declspec(dllexport)
#else
#define DETECTORMANAGER_API __declspec(dllimport)
#endif


class IDetectorManager
{
public:
	virtual void foo() = 0;

	virtual void* RequestDetectors(void* pDetectorManager) = 0;
	virtual void ReleaseDetectors(void* pDBManager) = 0;
};

DETECTORMANAGER_API IDetectorManager* GetDetectorManagerInstance();


