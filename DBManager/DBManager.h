#pragma once
/**
  * File: DBManager.h
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
#include "IDBManager.h"
#include "../CommonDataLibrary/Plan.h"
#include <vector>

class CDBManager : public IDBManager
{
protected:
	CDBManager() = default;
	~CDBManager() {
		delete singleton_;
	}

	static CDBManager* singleton_;

public:
	static CDBManager* GetInstance();
	void foo() override;


	std::vector<DataLibrary::CPlan> QueryPlans(void) override;
	void* QueryDetectors(void) override;
	void* QueryRobots(void) override;
};

