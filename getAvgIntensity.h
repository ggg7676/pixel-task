#pragma once
#include <iostream>

typedef unsigned char pixel[3];

double getAvgIntensity(const pixel curr)
{
	double first = (double)curr[0],
		   second = (double)curr[1],
		   third = (double)curr[2] ;

	return (first + second + third) / 3.0;

}