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
//#include "event.h"
//#include "WatchTimer.h"

class Model : IModel
{
	// Constructors/Destructors
public:
	Model();
	~Model();
	// Properties
public:
	void* get_Plans(void);
	void set_Plans(void*);

	void* get_Robots(void);
	void set_Robots(void*);

	void* get_Detectors(void);
	void set_Detectors(void*);

	//// Robot property
	//bool get_Dirty(void);
	//void set_Dirty(bool);

	// Methods
public:

	//void ReleasePlans(void);
	//void ReleaseDetectors(void);
	//void ReleaseRobots(void);

public:
	// Events
	//sz::event<unsigned int> DataChange;

public:

	// Functions
private:

	// Fields
private:
	// Attributes
private:
	void* m_pPlans;
	void* m_pDetectors;
	void* m_pRobots;

	//CWatchTimer m_timer;
	//unsigned int m_counter = 0;
	//bool m_dirty = false;
};
inline void* Model::get_Plans(void)
{
	return m_pPlans;
}
inline void* Model::get_Detectors(void)
{
	return m_pDetectors;
}
inline void* Model::get_Robots(void)
{
	return m_pRobots;
}
//// Robot property
//inline bool Model::get_Dirty(void)
//{
//	return m_dirty;
//}
//inline void Model::set_Dirty(bool val)
//{
//	m_dirty = val;
//	m_timer.Start(100); // 100 milliseconds interval
//}

