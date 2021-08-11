/**
  * File: StopWatch.cpp
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
#include "StdAfx.h"
#include "StopWatch.h"
#include <time.h>

// tasks:
// finish stopwatch.h based on c# webpage
// understand how time.h is used for timestamps (look for examples)
StopWatch* StopWatch::instance = NULL;

StopWatch::StopWatch(void)
{
	Reset();
}

StopWatch::~StopWatch(void)
{
}

long StopWatch::GetTimestamp()
{
	// get current time; same as: timer = time(NULL)
	time_t CurrentTime;
	time(&CurrentTime);

	// get timespan 
	double seconds = difftime(CurrentTime, StartTime);

	// convert timespan to milliseconds
	long milliseconds = (long)(seconds*(1000));

	// return 
	return milliseconds;
}
float StopWatch::GetSeconds()
{
	// get current time; same as: timer = time(NULL)
	time_t CurrentTime;
	time(&CurrentTime);

	// get timespan 
	double seconds = difftime(CurrentTime, StartTime);

	// return 
	return (float)seconds;
}

void StopWatch::Reset()
{
	// stop it
	Running = false;
}

void StopWatch::Restart()
{
	// set the start time and turn it on.
	Running = true;
	time(&StartTime);
}
void StopWatch::Start()
{
	// check to see if already running, abort if so.
	if (!Running)
	{
		// set the start time and turn it on.
		Running = true;
		time(&StartTime);
	}
}

void StopWatch::Stop()
{
	Running = false;
}