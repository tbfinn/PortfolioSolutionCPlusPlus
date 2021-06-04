/**
  * File: RunManager.h
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
#include "IRunManager.h"

class CRunManager : public IRunManager
{
protected:
	CRunManager() = default;
	~CRunManager() {
		delete singleton_;
	}

	static CRunManager* singleton_;

public:
	static CRunManager* GetInstance();
	void foo() override;
};
