/**
  * File: PlanManager.h
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
#include "IPlanManager.h"

class CPlanManager : public IPlanManager
{
protected:
	CPlanManager() = default;
	~CPlanManager() {
		delete singleton_;
	}

	static CPlanManager* singleton_;

public:
	static CPlanManager* GetInstance();
	void foo() override;
	//void* RequestPlans(void*) override;
	void* RequestPlans(void*);
	void ReleasePlans(void*);

};

