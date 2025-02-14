#pragma once
#include <iostream>
#include <cmath>

typedef unsigned char pixel[3];

void transformHelper(double** avgImage, double** temp, size_t height, size_t width, size_t row, size_t col)
{
	if (row < 0 || col < 0 || row >= height || col >= width)
		return;

	//left
	if (col >= 1)
	{
		if (abs(avgImage[row][col] - avgImage[row][col - 1]) <= 1 && temp[row][col - 1] != 0)
		{
			temp[row][col] = 0;
			temp[row][col - 1] = 0;
			transformHelper(avgImage, temp, height, width, row, col - 1);

		}
	}
	//right
	if (col + 1 < width)
	{
		if (abs(avgImage[row][col] - avgImage[row][col + 1]) <= 1 && temp[row][col + 1] != 0)
		{
			temp[row][col] = 0;
			temp[row][col + 1] = 0;
			transformHelper(avgImage, temp, height, width, row, col + 1);

		}
	}
	

	//down
	if (row + 1 < height)
	{
		if (abs(avgImage[row][col] - avgImage[row + 1][col]) <= 1 && temp[row + 1][col] != 0)
		{
			temp[row][col] = 0;
			temp[row + 1][col] = 0;
			transformHelper(avgImage, temp, height, width, row + 1, col);

		}
	}
	//up
	if (row >= 1)
	{
		if (abs(avgImage[row][col] - avgImage[row - 1][col]) <= 1 && temp[row - 1][col] != 0)
		{
			temp[row][col] = 0;
			temp[row - 1][col] = 0;
			transformHelper(avgImage, temp, height, width, row - 1, col);

		}
	}

	
}
void transform(double** avgImage, size_t height, size_t width, size_t row, size_t col)
{
	double** temp = new(std::nothrow) double*[height];
	if (!temp)
	{
		delete[] temp;
		std::cerr << "no dynamic memory allocated.\n";
	}
	for (size_t i = 0; i < height; ++i)
	{
		temp[i] = new(std::nothrow) double[width];
		if (!temp[i])
		{
			for (size_t j = 0; j <= i; ++j)
				delete[] temp[j];
			delete[] temp;
			std::cerr << "No dynamic memory allocated.\n";
		}
	}

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
			temp[i][j] = avgImage[i][j];
	}

	transformHelper(avgImage, temp, height, width, row, col);
	
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
			avgImage[i][j] =  temp[i][j];
	}

	for (size_t i = 0; i < height; ++i)
		delete[] temp[i];
	delete[] temp;
	
}