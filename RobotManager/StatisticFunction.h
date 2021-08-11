/**
  * File: StatisticFunction.h
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
#include "IStatisticFunction.h"
class StatisticFunction :IStatisticFunction
{
public:
	// Constructor/Destructor
	StatisticFunction(void);
	~StatisticFunction(void);

public:
	// Properties

public:
	// Methods


	virtual double Mean(double* arr, int n_elements);

	virtual double StandardDeviation(double* arr, int n_elements);

	virtual double Variance(double* arr, int n_elements);

	virtual double NORMSINV(double);

	virtual double NORMINV(double, double, double);

	virtual double NORMINV(double probability, double* arr, int elements);

	static StatisticFunction* GetInstance();


public:
	// Events

private:
	// Functions

private:
	// Attributes
	static StatisticFunction* instance;

};

inline StatisticFunction* StatisticFunction::GetInstance()
{
	// check to see if an instance has already been created
	// if not, create an instance
	if (instance == NULL) { instance = new StatisticFunction(); }

	// return the instance
	return instance;
}

