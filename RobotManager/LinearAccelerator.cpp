/**
  * File: LinearAccelerator.cpp
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
#include <ctime>
#include <assert.h>
//#include "Event.h"
#include "SignalGenerator.h"
#include "../CommonDataLibrary/Robot.h"
#include "LinearAccelerator.h"


LinearAccelerator::LinearAccelerator(void)
{
	// setting signal type to triangle wave because can create basic pulse with a duty cycle determined by a threshold trigger
	m_signalgenerator = new SignalGenerator();
	SignalGenerator* sig_gen = (SignalGenerator*)m_signalgenerator;
}

LinearAccelerator::~LinearAccelerator(void)
{
	delete m_signalgenerator;
}

void LinearAccelerator::start(void)
{
	// need to initialize timer reference
	std::time_t result = std::time(nullptr);
	SignalGenerator* sig_gen = (SignalGenerator*)m_signalgenerator;
	sig_gen->set_startTime((long)result);
	m_is_running = true;
	StartMyThread();

}

void LinearAccelerator::stop(void)
{
	m_is_running = false;
	StopMyThread();
}



DWORD WINAPI LinearAccelerator::StaticThreadStart(void* param)
{
	LinearAccelerator* This = (LinearAccelerator*)(param);
	return This->WorkerThread();
}

DWORD LinearAccelerator::WorkerThread(void)
{
	SignalGenerator* signalgen = (SignalGenerator*)m_signalgenerator;
	signalgen->set_SignalType(PulseTrain);
	float running_state = 0;
	float MU_sum = 0;
	bool loop = true;
	while (loop)
	{
		float value = signalgen->GetValue();
		assert(value >= -1 || value <= 1);              // ensuring normalization
		if (value == 0 && running_state != value)
		{
			running_state = value;
			//RadiationOff();
		}
		if (value > 0 && running_state != value)
		{
			running_state = value;
			//RadiationOn();
		}
		if (value > 0 && running_state == value)
		{
			MU_sum += (float)rads_per_pulse;
			if (MU_sum > m_MU)
			{
				//Complete();
				loop = false;
			}
		}
	}

	return 0;
}



void LinearAccelerator::StartMyThread(void)
{
	CreateThread(NULL, 0, StaticThreadStart, (void*)(this), 0, &m_threadId);
}

void LinearAccelerator::StopMyThread(void)
{
	TerminateThread((HANDLE)(m_threadId), 0);

}


