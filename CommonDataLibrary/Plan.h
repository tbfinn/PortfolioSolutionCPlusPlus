/**
  * File: Plan.h
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
#include <ctime>
#include <string>
#include <iostream>

namespace DataLibrary
{
	class CPlan
	{
		// Constructors/Destructors
	public:
		CPlan(const CPlan &obj);  // copy constructor
		CPlan(std::wstring, std::time_t); 

		// Properties
	public:
		std::wstring get_name() const;
		std::time_t get_timestamp() const;
		void set_name(std::wstring);
		void set_timestamp(std::time_t);

		// Methods
	public:
		void foo();

		// Functions
	private:

		// Fields
	private:

		// Attributes
	private:
		std::wstring m_name;
		std::time_t m_timestamp;

	};
	inline std::wstring CPlan::get_name() const
	{
		return m_name;
	}
	inline std::time_t CPlan::get_timestamp() const
	{
		return m_timestamp;
	}
	inline void CPlan::set_name(std::wstring val)
	{
		m_name = val;
	}
	inline void CPlan::set_timestamp(std::time_t val) 
	{
		m_timestamp = val;
	}

}
