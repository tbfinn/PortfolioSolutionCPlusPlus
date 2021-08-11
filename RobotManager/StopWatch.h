/**
  * File: StopWatch.h
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
#include "IStopWatch.h"
class StopWatch :IStopWatch
{
public:
	// constructor/destructor
	StopWatch(void);
	~StopWatch(void);

public:
	// properties

public:
	// methods
	virtual long GetTimestamp();

	virtual void Reset();

	virtual void Restart();

	virtual void Start();

	static StopWatch* GetInstance();

	virtual float GetSeconds();

	virtual void Stop();

public:

	// Events

private:
	// Functions

private:
	// Attributes

	static StopWatch* instance;
	time_t StartTime;
	bool Running;
};

inline StopWatch* StopWatch::GetInstance()
{
	// check to see if an instance has already been created
	// if not, create an instance
	if (instance == NULL) { instance = new StopWatch(); }

	// return the instance
	return instance;
}

