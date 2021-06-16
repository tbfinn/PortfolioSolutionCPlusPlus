#pragma once

#include "event.h"
#include <thread>

class CWatchTimer
{
public:
	CWatchTimer();
	~CWatchTimer();
	sz::event<> Tick;
	bool Start(unsigned int millisecondsInterval);
	bool Stop();

private:
	void TimerFunc();
	bool m_isRunning;
	unsigned int m_millisecondsInterval;
	std::thread m_timerThread;
};