#pragma once
#include <ctime>
#include <string>

namespace DataLibrary
{
	class CRobot
	{
		// Constructors/Destructors
	public:
		CRobot();
		CRobot(void*);
		CRobot(std::wstring, std::time_t);
		~CRobot();

		// Properties
	public:
		std::wstring get_name();
		std::time_t get_timestamp();

		// Methods
	public:

		// Functions
	private:

		// Fields
	private:

		// Attributes
	private:
		std::wstring m_name;
		std::time_t m_timestamp;

	};
	inline std::wstring CRobot::get_name()
	{
		return m_name;
	}
	inline std::time_t CRobot::get_timestamp()
	{
		return m_timestamp;
	}
}
