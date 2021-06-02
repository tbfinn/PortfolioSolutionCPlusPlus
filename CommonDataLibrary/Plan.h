#pragma once
#include <ctime>
#include <string>

namespace DataLibrary
{
	class CPlan
	{
		// Constructors/Destructors
	public:
		CPlan();
		CPlan(void*);
		CPlan(std::wstring, std::time_t);
		~CPlan();

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
	inline std::wstring CPlan::get_name()
	{
		return m_name;
	}
	inline std::time_t CPlan::get_timestamp()
	{
		return m_timestamp;
	}
}
