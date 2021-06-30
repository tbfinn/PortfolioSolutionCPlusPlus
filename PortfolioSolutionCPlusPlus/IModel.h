/**
  * File: IModel.h
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
#include <vector>
#include "../CommonDataLibrary/Plan.h"
#include "../CommonDataLibrary/Robot.h"
#include "../CommonDataLibrary/Detector.h"

class IModel
{
	// Properties
public:

	virtual int get_PlanCount(void) = 0;
	virtual DataLibrary::CPlan get_Plan(int index) = 0;

	virtual int get_RobotCount(void) = 0;
	virtual DataLibrary::CRobot get_Robot(int index) = 0;

	virtual int get_DetectorCount(void) = 0;
	virtual DataLibrary::CDetector get_Detector(int index) = 0;

	virtual bool get_Dirty(void) = 0;
	virtual void set_Dirty(bool) = 0;

	//methods
public:
	virtual bool LoadPlans(void) = 0;
	virtual bool LoadRobots(void) = 0;
	virtual bool LoadDetectors(void) = 0;


};

