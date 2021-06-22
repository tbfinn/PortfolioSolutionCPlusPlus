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
	Model();
	~Model();
	// Properties
public:
	int get_PlanCount(void) const;
	DataLibrary::CPlan* get_Plan(int index);

	//void set_Plans(void*);

	/*void* get_Robots(void);
	void set_Robots(void*);*/

	int get_RobotCount(void) const;
	DataLibrary::CRobot* get_Robot(int index);

	/*void* get_Detectors(void);
	void set_Detectors(void*);*/

	int get_DetectorCount(void) const;
	DataLibrary::CDetector* get_Detector(int index);

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
};
inline int Model::get_PlanCount(void) const
{
	return m_pPlans.size();
}
inline DataLibrary::CPlan* Model::get_Plan(int index)
{
	return static_cast<DataLibrary::CPlan*>(m_pPlans[index]);
}

inline int Model::get_RobotCount(void) const
{
	return m_pRobots.size();
}
inline DataLibrary::CRobot* Model::get_Robot(int index)
{
	return static_cast<DataLibrary::CRobot*>(m_pRobots[index]);
}

inline int Model::get_DetectorCount(void) const
{
	return m_pDetectors.size();
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

