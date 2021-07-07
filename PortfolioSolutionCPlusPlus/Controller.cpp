/**
  * File: Controller.h
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
#include <list>
#include "IController.h"
#include "Controller.h"
#include "../PlanManager/IPlanManager.h"
#include "../DetectorManager/IDetectorManager.h"
#include "../RobotManager/IRobotManager.h"

#include "IModel.h"
#include "Model.h"

Controller::Controller()
{
	m_pModel = nullptr;
	m_pPlanManager = nullptr;
	m_pRobotManager = nullptr;
	m_pDetectorManager = nullptr;
	m_pRunManager = nullptr;
	m_pDBManager = nullptr;
}

Controller::Controller(void* pModel, void* pPlanManager, void* pRobotManager, void* pDetectorManager, void* pRunManager, void* pDBManager)
{
	m_pModel = pModel;
	m_pPlanManager = pPlanManager;
	m_pRobotManager = pRobotManager;
	m_pDetectorManager = pDetectorManager;
	m_pRunManager = pRunManager;
	m_pDBManager = pDBManager;
}

Controller::~Controller()
{
}

bool Controller::LoadRobotView()
{
	try
	{
		IModel* model = (IModel*)m_pModel;
		bool flag = model->LoadRobots();

		return true;
	}
	catch (...)
	{
		return false;

	}
}
bool Controller::LoadDetectorView()
{
	try
	{
		IModel* model = (IModel*)m_pModel;
		bool flag = model->LoadDetectors();

		return true;
	}
	catch (...)
	{
		return false;

	}
}

bool Controller::LoadPlanView()
{
	try
	{
		//	cast plan manager to class from void so I can use it.
		IModel* model = (IModel*)m_pModel;
		bool flag = model->LoadPlans();

		return true;
	}
	catch (...)
	{
		return false;

	}
}

