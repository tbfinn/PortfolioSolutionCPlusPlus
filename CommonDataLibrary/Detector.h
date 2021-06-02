#pragma once
#include <ctime>
#include <string>

namespace DataLibrary
{
	class CDetector
	{
		// Constructors/Destructors
	public:
		CDetector();
		CDetector(void*);
		CDetector(std::wstring, std::time_t);
		~CDetector();

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
	inline std::wstring CDetector::get_name()
	{
		return m_name;
	}
	inline std::time_t CDetector::get_timestamp()
	{
		return m_timestamp;
	}
}
