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
};

DETECTORMANAGER_API IDetectorManager* GetDetectorManagerInstance();