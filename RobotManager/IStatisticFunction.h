/**
  * File: IStatisticFunction.h
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
class IStatisticFunction
{
public:
	virtual ~IStatisticFunction() {}

	virtual double Mean(double* arr, int n_elements) = 0;

	virtual double StandardDeviation(double* arr, int n_elements) = 0;

	virtual double Variance(double* arr, int n_elements) = 0;

	virtual double NORMSINV(double) = 0;

	virtual double NORMINV(double, double, double) = 0;

	virtual double NORMINV(double probability, double* arr, int elements) = 0;


};

