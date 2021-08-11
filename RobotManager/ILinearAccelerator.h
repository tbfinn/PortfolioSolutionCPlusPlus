/**
  * File: ILinearAccelerator.h
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
class ILinearAccelerator
{
public:
	virtual ~ILinearAccelerator() {}

	virtual void start(void) = 0;
	virtual void stop(void) = 0;

};


