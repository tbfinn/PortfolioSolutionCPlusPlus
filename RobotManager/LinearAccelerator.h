/**
  * File: LinearAccelerator.h
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
#include "ILinearAccelerator.h"
class LinearAccelerator :ILinearAccelerator
{
public:
	// Constructor/Destructor
	LinearAccelerator(void);
	~LinearAccelerator(void);

	// Properties
public:

	bool get_is_running(void);

	void set_MU(float);
	float get_MU(void);

	// Methods
public:
	virtual void start(void);
	virtual void stop(void);

	static DWORD WINAPI StaticThreadStart(void* param);
	DWORD WorkerThread(void);

	void StartMyThread(void);
	void StopMyThread(void);

	// Events
	//Sharp::Event<void> RadiationOn;  // will be raised whenever the clock shifts state
	//Sharp::Event<void> RadiationOff;  // will be raised whenever the clock shifts state
	//Sharp::Event<void> Complete;

	// Functions
private:

	// Fields
private:

	// Attributes
private:


	bool m_is_running;

	float m_MU;



	void* m_signalgenerator;

	DWORD m_threadId;
};

inline bool LinearAccelerator::get_is_running(void)
{
	return m_is_running;
}

inline void LinearAccelerator::set_MU(float val)
{
	m_MU = val;
}
inline float LinearAccelerator::get_MU(void)
{
	return m_MU;
}



