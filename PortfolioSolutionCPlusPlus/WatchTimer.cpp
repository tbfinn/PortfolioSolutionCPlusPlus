#include "stdafx.h"
#include "WatchTimer.h"

// Can be implemented to be more thread safe. But, it's only for the example.
// If the interval is too big, the Stop function will be affected too.

#define DEFAULT_TIMER_INTERVAL 1000

CWatchTimer::CWatchTimer()
{
	m_isRunning = false;
	m_isKilled = false;
}
CWatchTimer::~CWatchTimer()
{
}
bool CWatchTimer::Start(unsigned int millisecondsInterval)
{
	if (m_isRunning) { return false; }
	m_isRunning = true;
	m_millisecondsInterval = millisecondsInterval > 0 ? millisecondsInterval : DEFAULT_TIMER_INTERVAL;
	m_timerThread = std::thread([this]() { TimerFunc(); });

	return true;
}
bool CWatchTimer::Pause()
{
	if (!m_isRunning) { return false; }
	m_isRunning = false;
	return true;
}
bool CWatchTimer::Resume()
{
	if (m_isRunning) {	return false; }
	m_isRunning = true;
	return true;
}
bool CWatchTimer::Stop()
{
	m_isRunning = false;
	m_isKilled = true;
	return true;
}
void CWatchTimer::TimerFunc()
{

	while (!m_isKilled)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(m_millisecondsInterval));

		if (m_isRunning)
		{
			Tick();
		}
	}
}