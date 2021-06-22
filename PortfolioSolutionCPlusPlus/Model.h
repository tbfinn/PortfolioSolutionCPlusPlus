/**
  * File: Model.h
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
#pragma once
#include <list>
#include "IModel.h"
#include "event.h"
#include "WatchTimer.h"
#include "../CommonDataLibrary/Plan.h"
#include "../CommonDataLibrary/Robot.h"
#include "../CommonDataLibrary/Detector.h"


class Model : IModel
{
	// Constructors/Destructors
public:
	Model(void*);
	~Model();
	// Properties
public:
	int get_PlanCount(void) override;
	DataLibrary::CPlan* get_Plan(int index) override;

	//void set_Plans(void*);

	/*void* get_Robots(void);
	void set_Robots(void*);*/

	int get_RobotCount(void) override;
	DataLibrary::CRobot* get_Robot(int index) override;

	/*void* get_Detectors(void);
	void set_Detectors(void*);*/

	int get_DetectorCount(void) override;
	DataLibrary::CDetector* get_Detector(int index) override;

	// Dirty property
	bool get_Dirty(void);
	void set_Dirty(bool);

	// Methods
public:

	//void ReleasePlans(void);
	//void ReleaseDetectors(void);
	//void ReleaseRobots(void);

	bool LoadPlans(void);

public:
	// Events
	sz::event<unsigned int> DataChange;

public:

	// Functions
private:

	// Fields
private:
	// Attributes
private:
	std::vector<void*> m_pPlans;
	std::vector<void*> m_pDetectors;
	std::vector<void*> m_pRobots;

	CWatchTimer m_timer;
	unsigned int m_counter = 0;
	bool m_dirty = false;

	void* m_pDbManager = nullptr;
};
inline int Model::get_PlanCount(void)
{
	return static_cast<int>(m_pPlans.size());
}
inline DataLibrary::CPlan* Model::get_Plan(int index)
{
	return static_cast<DataLibrary::CPlan*>(m_pPlans[index]);
}

inline int Model::get_RobotCount(void)
{
	return (int)m_pRobots.size();
}
inline DataLibrary::CRobot* Model::get_Robot(int index)
{
	return static_cast<DataLibrary::CRobot*>(m_pRobots[index]);
}
inline int Model::get_DetectorCount(void)
{
	return (int)m_pDetectors.size();
}
inline DataLibrary::CDetector* Model::get_Detector(int index)
{
	return static_cast<DataLibrary::CDetector*>(m_pDetectors[index]);
}

inline bool Model::get_Dirty(void)
{
	return m_dirty;
}
inline void Model::set_Dirty(bool val)
{
	m_dirty = val;
}

