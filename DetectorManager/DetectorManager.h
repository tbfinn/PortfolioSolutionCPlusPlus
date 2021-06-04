/**
  * File: DetectorManager.h
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
#include "IDetectorManager.h"

class CDetectorManager : public IDetectorManager
{
protected:
	CDetectorManager() = default;
	~CDetectorManager() {
		delete singleton_;
	}

	static CDetectorManager* singleton_;

public:
	static CDetectorManager* GetInstance();
	void foo() override;
};


