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
	bool Resume();
	bool Pause();

private:
	void TimerFunc();
	bool m_isRunning = false;
	bool m_isKilled = false;

	unsigned int m_millisecondsInterval;
	std::thread m_timerThread;
};