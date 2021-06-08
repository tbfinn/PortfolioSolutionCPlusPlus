/**
  * File: Controller.h
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
#include "IController.h"


class Controller : public IController
{
	// Constructors/Destructors
public:
	Controller();
	Controller(void*, void*, void*, void*, void*, void*);
	~Controller();
	// Properties
public:

	// Methods
public:
	bool LoadPlanView();
	bool LoadDetectorView();
	bool LoadRobotView();

	// Functions
private:

	// Fields
private:

	// Attributes
private:

	void* m_pModel;
	void* m_pPlanManager;
	void* m_pRobotManager;
	void* m_pDetectorManager;
	void* m_pRunManager;
	void* m_pDBManager;
};

