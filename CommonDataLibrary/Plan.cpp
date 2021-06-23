/**
	* File: Plan.cpp
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
#include "stdafx.h"
#include "Plan.h"
#include "IDBManager.h"


namespace DataLibrary
{
	CPlan::CPlan(std::wstring name, std::time_t time)
	{
		m_name = name;
		m_timestamp = time;
	}
	CPlan::CPlan(const CPlan &obj)
	{
		m_name = obj.m_name; // copy the name
		m_timestamp = obj.m_timestamp; // copy the name
	}

	void CPlan::foo()
	{
		/* code */
		//IDBManager* pdbm = GetDbManagerInstance();

	}
}
