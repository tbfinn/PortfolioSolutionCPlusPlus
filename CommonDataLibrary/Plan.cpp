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


namespace DataLibrary
{
	CPlan::CPlan()
	{
	}
	CPlan::CPlan(void* pPlan)
	{
		CPlan* pplan = (CPlan*)pPlan;
		//	copy incoming plan to this one.
		this->m_name = pplan->get_name();
		this->m_timestamp = pplan->get_timestamp();

	}
	CPlan::CPlan(std::wstring name, std::time_t time)
	{
		m_name = name;
		m_timestamp = time;
	}
	CPlan::~CPlan()
	{
	}
}
