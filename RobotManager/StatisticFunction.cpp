/**
  * File: StatisticFunction.cpp
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
#include "StdAfx.h"
#include <cmath>
#include "StatisticFunction.h"


StatisticFunction::StatisticFunction(void)
{
}

StatisticFunction::~StatisticFunction(void)
{
}

//public static double Mean(double[] values)
//		{
//			double tot = 0;
//			foreach (double val in values)
//				tot += val;
//
//			return (tot / values.Length);
//		}

double StatisticFunction::Mean(double* arr, int n_elements)
{
	// double tot = 0
	double tot = 0;
	// foreach (double val in values)
	for (int i = 0; i < (n_elements - 1); i++)
	{
		// tot += val;
		double val = arr[i];
		tot += val;
	}
	// return (tot / values.Length);
	return tot / n_elements;
}

/*public static double StandardDeviation(double[] values)
		{
			return Math.Sqrt(Variance(values));
		}*/
double StatisticFunction::StandardDeviation(double* arr, int n_elements)
{
	// return Math.Sqrt(Variance(values));

	return sqrt(Variance(arr, n_elements));
}
/*public static double Variance(double[] values)
		{
			double m = Mean(values);
			double result = 0;
			foreach (double d in values)
				result += Math.Pow((d - m), 2);

			return (result / values.Length);
		}*/

double StatisticFunction::Variance(double* arr, int n_elements)
{
	// double m = Mean(values);
	double m = Mean(arr, n_elements);
	// double result = 0;
	double result = 0;
	// foreach (double d in values)
	for (int i = 0; i < n_elements - 1; i++)
	{
		// result += Math.Pow((d - m), 2);
		result += pow((i - m), 2);
	}

	return (result / (n_elements));

}

//
		// Lower tail quantile for standard normal distribution function.
		//
		// This function returns an approximation of the inverse cumulative
		// standard normal distribution function.  I.e., given P, it returns
		// an approximation to the X satisfying P = Pr{Z <= X} where Z is a
		// random variable from the standard normal distribution.
		//
		// The algorithm uses a minimax approximation by rational functions
		// and the result has a relative error whose absolute value is less
		// than 1.15e-9.
		//
		// Author:      Peter J. Acklam
		// (Javascript version by Alankar Misra @ Digital Sutras (alankar@digitalsutras.com))
		// Time-stamp:  2003-05-05 05:15:14
		// E-mail:      pjacklam@online.no
		// WWW URL:     http://home.online.no/~pjacklam

		// An algorithm with a relative error less than 1.15*10-9 in the entire region.

	//public static double NORMSINV(double p)
	//	{
	//		
double StatisticFunction::NORMSINV(double p)
{

	// Coefficients in rational approximations
	//		double[] a = {-3.969683028665376e+01,  2.209460984245205e+02,
	//			-2.759285104469687e+02,  1.383577518672690e+02,
	//			-3.066479806614716e+01,  2.506628277459239e+00};
	//		

	double a[6] = { -3.969683028665376e+01,  2.209460984245205e+02,
				-2.759285104469687e+02,  1.383577518672690e+02,
				-3.066479806614716e+01,  2.506628277459239e+00 };

	//		double[] b = {-5.447609879822406e+01,  1.615858368580409e+02,
	//			-1.556989798598866e+02,  6.680131188771972e+01,
	//			-1.328068155288572e+01 };
	//		
	double b[6] = { -5.447609879822406e+01,  1.615858368580409e+02,
				-1.556989798598866e+02,  6.680131188771972e+01,
				-1.328068155288572e+01 };

	//		double[] c = {-7.784894002430293e-03, -3.223964580411365e-01,
	//			-2.400758277161838e+00, -2.549732539343734e+00,
	//			4.374664141464968e+00,  2.938163982698783e+00};
	double c[6] = { -7.784894002430293e-03, -3.223964580411365e-01,
				-2.400758277161838e+00, -2.549732539343734e+00,
				4.374664141464968e+00,  2.938163982698783e+00 };

	//		
	//		double[] d = { 7.784695709041462e-03,  3.224671290700398e-01,
	//			2.445134137142996e+00,  3.754408661907416e+00};
	double d[4] = { 7.784695709041462e-03,  3.224671290700398e-01,
				2.445134137142996e+00,  3.754408661907416e+00 };

	//		
	//		// Define break-points.
	//		double plow  = 0.02425;
	//		double phigh = 1 - plow;
	//		
	double plow = 0.02425;
	double phigh = 1 - plow;
	//		// Rational approximation for lower region:
	//		if ( p < plow )
	//		{
	//			double q  = Math.Sqrt(-2*Math.Log(p));
	//			return (((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) /
	//				((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
	//		}
	if (p < plow)
	{
		double q = sqrt(-2 * log(p));
		return (((((c[0] * q + c[1])*q + c[2])*q + c[3])*q + c[4])*q + c[5]) /
			((((d[0] * q + d[1])*q + d[2])*q + d[3])*q + 1);
	}

	//		// Rational approximation for upper region:
	//		if ( phigh < p )
	//		{
	//			double q  = Math.Sqrt(-2*Math.Log(1-p));
	//			return -(((((c[0]*q+c[1])*q+c[2])*q+c[3])*q+c[4])*q+c[5]) /
	//				((((d[0]*q+d[1])*q+d[2])*q+d[3])*q+1);
	//		}
	if (phigh < p)
	{
		double q = sqrt(-2 * log(1 - p));
		return -(((((c[0] * q + c[1])*q + c[2])*q + c[3])*q + c[4])*q + c[5]) /
			((((d[0] * q + d[1])*q + d[2])*q + d[3])*q + 1);
	}

	//		
	//		// Rational approximation for central region:
	//		{
	//			double q = p - 0.5;
	//			double r = q*q;
	//			return (((((a[0]*r+a[1])*r+a[2])*r+a[3])*r+a[4])*r+a[5])*q /
	//				(((((b[0]*r+b[1])*r+b[2])*r+b[3])*r+b[4])*r+1);
	//		}
	//	}
	{
		double q = p - 0.5;
		double r = q * q;
		return (((((a[0] * r + a[1])*r + a[2])*r + a[3])*r + a[4])*r + a[5])*q /
			(((((b[0] * r + b[1])*r + b[2])*r + b[3])*r + b[4])*r + 1);
	}
}

//public static double NORMINV(double probability, double mean, double standard_deviation)
//	{
//		return (NORMSINV(probability) * standard_deviation + mean);
//	}


double StatisticFunction::NORMINV(double probability, double mean, double standard_deviation)
{
	return (NORMSINV(probability) * standard_deviation + mean);
}

//public static double NORMINV(double probability, double[] values)
//		{
//			return NORMINV(probability, Mean(values), StandardDeviation(values));
//		}

double StatisticFunction::NORMINV(double probability, double* arr, int n_elements)
{
	return NORMINV(probability, Mean(arr, n_elements), StandardDeviation(arr, n_elements));
}

