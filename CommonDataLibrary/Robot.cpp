/**
	* File: Robot.cpp
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
#include "Robot.h"


namespace DataLibrary
{
	CRobot::CRobot()
	{
	}
	CRobot::CRobot(void* pRobot)
	{
		CRobot* probot = (CRobot*)pRobot;
		//	copy incoming plan to this one.
		this->m_name = probot->get_name();
		this->m_timestamp = probot->get_timestamp();

	}
	CRobot::CRobot(std::wstring name, std::time_t time)
	{
		m_name = name;
		m_timestamp = time;
	}
	CRobot::~CRobot()
	{
	}
}