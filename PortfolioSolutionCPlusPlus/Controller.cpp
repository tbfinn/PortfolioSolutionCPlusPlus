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
		//	cast Robot manager to class from void so I can use it.
		IRobotManager* pm = (IRobotManager*)m_pRobotManager;

		//	ask the database manager for a list of active robots
		//CPlan* pPlan = (CPlan*)(pm->RequestPlan(m_pDBManager));
		assert(m_pDBManager != nullptr);

		void* robots = pm->RequestRobots(m_pDBManager);

		//	cast robot manager to class from void so I can use it.
		IModel* model = (IModel*)m_pModel;
		model->set_Robots(robots);

		// clean up your temporary memory resoureces related to robots
		pm->ReleaseRobots(m_pDBManager);

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
		//	cast detector manager to class from void so I can use it.
		IDetectorManager* pm = (IDetectorManager*)m_pDetectorManager;

		//	ask the database manager for a list of active detectors
		//CPlan* pPlan = (CPlan*)(pm->RequestPlan(m_pDBManager));
		assert(m_pDBManager != nullptr);

		void* detectors = pm->RequestDetectors(m_pDBManager);

		//	cast plan manager to class from void so I can use it.
		IModel* model = (IModel*)m_pModel;
		model->set_Detectors(detectors);

		// clean up your temporary memory resoureces related to plans
		pm->ReleaseDetectors(m_pDBManager);

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
		IPlanManager* pm = (IPlanManager*)m_pPlanManager;

		//	ask the database manager for a list of active plans
		//CPlan* pPlan = (CPlan*)(pm->RequestPlan(m_pDBManager));
		assert(m_pDBManager != nullptr);

		void* plans = pm->RequestPlans(m_pDBManager);

		//	cast plan manager to class from void so I can use it.
		IModel* model = (IModel*)m_pModel;
		model->set_Plans(plans);

		// clean up your temporary memory resoureces related to plans
		pm->ReleasePlans(m_pDBManager);

		return true;
	}
	catch (...)
	{
		return false;

	}
}

