/**
  * File: RobotManager.h
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
#include "IRobotManager.h"

class CRobotManager : public IRobotManager
{
protected:
	CRobotManager() = default;
	~CRobotManager() {
		delete singleton_;
	}

	static CRobotManager* singleton_;

public:
	static CRobotManager* GetInstance();
	void foo() override;
};
