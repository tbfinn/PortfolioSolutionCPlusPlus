/**
  * File: ISignalGenerator.h
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
class ISignalGenerator
{
public:
	virtual ~ISignalGenerator() {}

	virtual float GetValue(float time) = 0;

	virtual float GetValue() = 0;

	virtual void Reset() = 0;

};

