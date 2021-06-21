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

	void* get_Robots(void);
	void set_Robots(void*);

	void* get_Detectors(void);
	void set_Detectors(void*);

	// Robot property
	bool get_Dirty(void);
	void set_Dirty(bool);

	// Methods
public:

	void ReleasePlans(void);
	void ReleaseDetectors(void);
	void ReleaseRobots(void);

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
	void* m_pDetectors;
	void* m_pRobots;

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
inline void* Model::get_Detectors(void)
{
	return m_pDetectors;
}
inline void* Model::get_Robots(void)
{
	return m_pRobots;
}
inline bool Model::get_Dirty(void)
{
	return m_dirty;
}
inline void Model::set_Dirty(bool val)
{
	m_dirty = val;
}

