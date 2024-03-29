/**
  * File: Model.cpp
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
#include "Model.h"
#include "..\CommonDataLibrary\Plan.h"
#include "..\CommonDataLibrary\Robot.h"
#include "..\CommonDataLibrary\Detector.h"
#include "IDBManager.h"
#include "DBManager.h"


Model::Model(void* pDbManager)
{
	m_pDbManager = pDbManager;
	OutputDebugStringW(L"SETTING UP TIMER\n");

	m_timer.Tick += [this]() {
		m_counter++;
		if (m_dirty)
		{
			m_dirty = false;
			m_timer.Pause();
			OutputDebugStringW(L"CALLING REGISTERED CLIENT.\n");
			DataChange(m_counter);
			OutputDebugStringW(L"CALLED REGISTERED CLIENT.\n");
			m_timer.Resume();
		}
		OutputDebugStringW(L"TICK\n");
	};
	m_timer.Start(1000); // 1 seconds interval

}
Model::~Model()
{
	m_timer.Stop();
}


bool Model::LoadPlans(void)
{
	bool rt = false;

	//	retrieve a list of plans in the database
	std::vector<DataLibrary::CPlan>p = static_cast<CDBManager*>(m_pDbManager)->QueryPlans();

	m_pPlans.clear();

	//	copy the list to a local container
	for (auto i = 0; i < static_cast<int>(p.size()); i++)
	{
		DataLibrary::CPlan plan(p[i]);
		m_pPlans.push_back(plan);
	}
	rt = m_dirty = true;
	return rt;
}

bool Model::LoadRobots(void)
{
	bool rt = false;

	//	retrieve a list of plans in the database
	std::vector<DataLibrary::CRobot>p = static_cast<CDBManager*>(m_pDbManager)->QueryRobots();

	m_pRobots.clear();

	//	copy the list to a local container
	for (auto i = 0; i < static_cast<int>(p.size()); i++)
	{
		DataLibrary::CRobot robot(p[i]);
		m_pRobots.push_back(robot);
	}
	rt = m_dirty = true;
	return rt;
}

bool Model::LoadDetectors(void)
{
	bool rt = false;

	//	retrieve a list of plans in the database
	std::vector<DataLibrary::CDetector>p = static_cast<CDBManager*>(m_pDbManager)->QueryDetectors();

	m_pDetectors.clear();

	//	copy the list to a local container
	for (auto i = 0; i < static_cast<int>(p.size()); i++)
	{
		DataLibrary::CDetector detector(p[i]);
		m_pDetectors.push_back(detector);
	}
	rt = m_dirty = true;
	return rt;
}
//void Model::set_Plans(void* plans)
//{
//	//	clear the plan collection
//	ReleasePlans();
//
//	std::vector<void*>* working = new std::vector<void*>();
//
//	//	dereference the input argument to a plan collection instance
//	std::vector<void*> input = *(std::vector<void*>*)plans;
//
//	for (int i = 0; i < (int)input.size(); i++)
//	{
//		void* p = input[i];
//		void* pp = new DataLibrary::CPlan(p);
//		working->push_back((void*)pp);
//	}
//	m_pPlans = (void*)working;
//}

//void Model::set_Detectors(void* arg)
//{
//	//	clear the plan collection
//	ReleaseDetectors();
//
//	std::vector<void*>* working = new std::vector<void*>();
//
//	//	dereference the input argument to a plan collection instance
//	std::vector<void*> input = *(std::vector<void*>*)arg;
//
//	for (int i = 0; i < (int)input.size(); i++)
//	{
//		void* p = input[i];
//		void* pp = new DataLibrary::CDetector(p);
//		working->push_back((void*)pp);
//	}
//	m_pDetectors = (void*)working;
//}

//void Model::set_Robots(void* arg)
//{
//	//	clear the plan collection
//	ReleaseRobots();
//
//	std::vector<void*>* working = new std::vector<void*>();
//
//	//	dereference the input argument to a plan collection instance
//	std::vector<void*> input = *(std::vector<void*>*)arg;
//
//	for (int i = 0; i < (int)input.size(); i++)
//	{
//		void* p = input[i];
//		void* pp = new DataLibrary::CRobot(p);
//		working->push_back((void*)pp);
//	}
//	m_pRobots = (void*)working;
//}

//void Model::ReleasePlans(void)
//{
//	//std::vector<void*>* pvec = (std::vector<void*>*)m_pPlans;
//	for (int i = 0; i < (int)m_pPlans.size(); i++)
//	{
//		delete m_pPlans[i];
//	}
//	m_pPlans.clear();
//	//delete m_pPlans;
//	//m_pPlans = nullptr;
//}
//void Model::ReleaseRobots(void)
//{
//	std::vector<void*>* pvec = (std::vector<void*>*)m_pRobots;
//	for (int i = 0; i < (int)pvec->size(); i++)
//	{
//		delete &pvec[i];
//	}
//	delete m_pRobots;
//	m_pRobots = nullptr;
//}
//void Model::ReleaseDetectors(void)
//{
//	std::vector<void*>* pvec = (std::vector<void*>*)m_pDetectors;
//	for (int i = 0; i < (int)pvec->size(); i++)
//	{
//		delete &pvec[i];
//	}
//	delete m_pDetectors;
//	m_pDetectors = nullptr;
//}


