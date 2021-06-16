
// Detector.cpp
// compile with: cl /c /EHsc Detector.cpp
// post-build command: lib Detector.obj

/**
	* File: Detector.cpp
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
#include "Detector.h"
#include "IDBManager.h"


namespace DataLibrary
{
	CDetector::CDetector()
	{
	}
	CDetector::CDetector(void* pDetector)
	{
		CDetector* pdetector = (CDetector*)pDetector;
		//	copy incoming plan to this one.
		this->m_name = pdetector->get_name();
		this->m_timestamp = pdetector->get_timestamp();

	}
	CDetector::CDetector(std::wstring name, std::time_t time)
	{
		m_name = name;
		m_timestamp = time;
	}
	CDetector::~CDetector()
	{
	}

	void CDetector::foo()
	{
		/* code */
		//IDBManager* pdbm = GetDbManagerInstance();

	}
}