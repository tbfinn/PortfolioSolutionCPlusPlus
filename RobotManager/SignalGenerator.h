/**
  * File: SignalGenerator.h
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
#include "ISignalGenerator.h"
class SignalGenerator :ISignalGenerator
{
public:
	// Constructor/Destructor
	SignalGenerator(void);
	SignalGenerator(SignalType);
	~SignalGenerator(void);

public:
	// Properties

	void set_SignalType(SignalType signaltype);
	//SignalType get_SignalType();

	void set_duty_cycle(float);
	float get_duty_cycle(void);

	//void set_trigger_level(float);
	//float get_trigger_level(void);

	void  set_Frequency(float);
	float get_Frequency();

	void set_Phase(float);
	float get_Phase();

	void set_Amplitude(float);
	float get_Amplitude();

	void set_Offset(float);
	float get_Offset();

	void set_Invert(bool);
	bool get_Invert();


	void set_startTime(long);
	long get_startTime();

	void set_ticksPerSecond(float);
	float get_ticksPerSecond();

	//void set_GetValueCallback(float(*callback)(float));

public:
	// Methods

	virtual float GetValue(float time);

	virtual float GetValue();

	virtual void Reset();

	void Synchronize(SignalGenerator instance);

public:
	// Events

private:
	// Functions

private:
	// Attributes
	// private SignalType signalType = SignalType.Sine;
	SignalType m_signalType;

	// private float frequency = 1f;
	float m_frequency;

	// private float phase = 0f;
	float m_phase;

	// private float amplitude = 1f;
	float m_amplitude;

	// private float offset = 0f;
	float m_offset;

	// private float invert = 1; // Yes=-1, No=1

	bool m_invert;

	long m_startTime;

	float m_ticksPerSecond;

	void* m_stopwatch;   // this is a pointer to a StopWatch class instance

	float m_duty_cycle;  // range between 0 and 1

	float m_trigger_level;




};


inline void SignalGenerator::set_duty_cycle(float val)
{
	m_duty_cycle = val;
	m_trigger_level = (1 - m_duty_cycle)*m_amplitude;
}
inline float SignalGenerator::get_duty_cycle(void)
{
	return m_duty_cycle;
}


inline void SignalGenerator::set_SignalType(SignalType signaltype)
{
	m_signalType = signaltype;
}

inline void SignalGenerator::set_Frequency(float val)
{
	m_frequency = val;
}

inline float SignalGenerator::get_Frequency(void)
{
	return m_frequency;
}

inline void SignalGenerator::set_Phase(float val)
{
	m_phase = val;
}

inline float SignalGenerator::get_Phase(void)
{
	return m_phase;
}

inline void SignalGenerator::set_Amplitude(float val)
{
	m_amplitude = val;
	m_amplitude = 1;
}

inline float SignalGenerator::get_Amplitude(void)
{
	return m_amplitude;
}

inline void SignalGenerator::set_Offset(float val)
{
	m_phase = val;
}

inline float SignalGenerator::get_Offset(void)
{
	return m_phase;
}

inline void SignalGenerator::set_Invert(bool val)
{
	m_invert = val;
}

inline bool SignalGenerator::get_Invert(void)
{
	return m_invert;
}

inline void SignalGenerator::set_startTime(long val)
{
	m_startTime = val;
}

inline long SignalGenerator::get_startTime(void)
{
	return m_startTime;
}

inline void SignalGenerator::set_ticksPerSecond(float val)
{
	m_ticksPerSecond = val;
}

inline float SignalGenerator::get_ticksPerSecond(void)
{
	return m_ticksPerSecond;
}