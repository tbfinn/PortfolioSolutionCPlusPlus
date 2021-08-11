/**
  * File: SignalGenerator.cpp
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
#include <cmath> 
#include <math.h>
#include <cstdlib>
#include <assert.h>
#include "StopWatch.h"
#include "StatisticFunction.h"
#include "SignalGenerator.h"

StatisticFunction* StatisticFunction::instance = nullptr;

double round(double number) { return number < 0.0 ? ceil(number - 0.5) : floor(number + 0.5); }
int sign(float number) { int value; if (number < 0) { value = -1; } else if (number == 0) { value = 0; } else { value = 1; } return value; }


SignalGenerator::SignalGenerator(void)
{
	m_stopwatch = new StopWatch();
	m_amplitude = 1.0;
}

SignalGenerator::SignalGenerator(SignalType signalType)
{
	m_signalType = signalType;

	m_stopwatch = new StopWatch();
	m_amplitude = 1.0;
}

SignalGenerator::~SignalGenerator(void)
{
	delete m_stopwatch;
}

float SignalGenerator::GetValue()
{
	if (m_stopwatch != NULL)
	{
		StopWatch* var = (StopWatch*)(m_stopwatch);
		return GetValue(var->GetSeconds());
	}
	throw m_stopwatch;
}

float SignalGenerator::GetValue(float time)
{
	float value = 0.0;
	float t = m_frequency * time + m_phase;
	switch (m_signalType)
	{
	case Sine:
	{
		// sin( 2 * pi * t )
		value = (float)sin(2.0*PI*t);
		break;
	}
	case Square:
	{
		// sign( sin( 2 * pi * t ) )
		return (float)(sign((float)sin(2.0*PI*t)));
		break;
	}

	case Triangle:
	{
		// 2 * abs( t - 2 * floor( t / 2 ) - 1 ) - 1
		value = (float)(1.0 - 4.0*abs(round(t - 0.25) - (t - 0.25)));
		break;
	}
	case Sawtooth:
	{
		// 2 * ( t/a - floor( t/a + 1/2 ) )
		value = (float)(2.0*(t - floor(t + 0.5)));
		break;
	}
	case Pulse:
	{
		// http://en.wikipedia.org/wiki/Pulse_wave
		value = (float)((abs(sin(2 * PI*t)) < 1.0 - 10E-3) ? (0) : (1)); // (logic evaluation) ? (true value) : (false value);
		break;
	}
	case WhiteNoise:
	{
		// http://en.wikipedia.org/wiki/White_noise
		//v1 = rand() % 100;         // v1 in the range 0 to 99
		value = (float)((2.0*(rand() % 65536)) / (65535));
		assert(value >= 1);
		// value = 2.0*(float)rand.Next(int.MaxValue) / int.MaxValue - 1.0;
		break;
	}
	case GaussNoise:
	{
		// http://en.wikipedia.org/wiki/Gaussian_noise
		float val = (float)(rand() % 65536) / 65535;
		value = (float)(StatisticFunction::GetInstance()->NORMINV(val, 0.0, 0.4));
		break;
	}
	case DigitalNoise:
	{
		//Binary Bit Generators
		value = (float)(rand() % 2);
		break;
	}
	//case UserDefined:
	//{
	//	// output = (condition) ? (true value): (false value);
	//	value = (float)((callback==NULL) ? (0.0): (callback(t)));
	//	break;
	//}
	case PulseTrain:
	{
		// 2 * abs( t - 2 * floor( t / 2 ) - 1 ) - 1
		value = (float)(1.0 - 4.0*abs(round(t - 0.25) - (t - 0.25)));
		if (value > m_trigger_level)
		{
			value = m_amplitude;
		}
		else
		{
			value = 0;
		}
		break;
	}
	default:;

	}
	return(m_invert*m_amplitude*value + m_offset);
}


void SignalGenerator::Reset()
{
	m_startTime = StopWatch::GetInstance()->GetTimestamp();
}

void SignalGenerator::Synchronize(SignalGenerator instance)
{
	m_startTime = instance.get_startTime();
	m_ticksPerSecond = instance.get_ticksPerSecond();
}



