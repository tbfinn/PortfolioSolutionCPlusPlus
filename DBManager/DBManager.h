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
};

