/**
  * File: IStopWatch.h
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
class IStopWatch
{
public:
	virtual ~IStopWatch() {}

	virtual long GetTimestamp() = 0;

	virtual void Reset() = 0;

	virtual void Restart() = 0;

	virtual void Start() = 0;

	virtual float GetSeconds() = 0;

	virtual void Stop() = 0;
};


