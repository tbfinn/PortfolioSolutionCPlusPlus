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
class IModel
{
	// Properties
public:
	virtual void* get_Plans(void) = 0;
	//virtual void set_Plans(void*) = 0;
	virtual void* get_Robots(void) = 0;
	virtual void set_Robots(void*) = 0;
	virtual void* get_Detectors(void) = 0;
	virtual void set_Detectors(void*) = 0;

	//methods
public:
	virtual bool LoadPlans(void) = 0;
};

