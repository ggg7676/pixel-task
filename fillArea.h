#include <iostream>
#include "getAvgIntensity.h"
#include "transform.h"
typedef unsigned char pixel[3];

pixel** fillArea(const pixel *const *const image, size_t width, size_t height, size_t row, size_t column)
{
	if (row < 0 || column < 0 || row >= height || column >= width)
		return nullptr;

	double**avgImage = new(std::nothrow) double*[height];
	if (!avgImage)
	{
		delete[] avgImage;
		std::cerr << "No dynamic memory allocated.\n";
	}
	for (size_t i = 0; i < height; ++i)
	{
		avgImage[i] = new(std::nothrow) double[width];
		if (!avgImage[i])
		{
			for (size_t j = 0; j <= i; ++j)
				delete[] avgImage[j];
			delete[] avgImage;
			std::cerr << "No dynamic memory allocated.\n";
		}
	}

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
			avgImage[i][j] = getAvgIntensity(image[i][j]);
		
	}

	/*cout << endl << "avr. intensity version: " << endl;
	
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
			cout << avgImage[i][j] << " ";
		cout << endl;
		
	}*/

	transform(avgImage, height, width, row, column);

	/*cout << endl << "avg. intensity version after transfrom: " << endl;
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
			cout << avgImage[i][j] << " ";
		cout << endl;
	}*/

	pixel** result = new(std::nothrow) pixel*[height];
	if (!result)
	{
		delete[] result;
		std::cerr << "No dynamic memory allocated.\n";
	}

	for (size_t i = 0; i < height; ++i)
	{
		result[i] = new(std::nothrow)pixel[width];
		if (!result[i])
		{
			for (size_t j = 0; j <= i; ++j)
				delete[] result[j];
			delete[] result;
			std::cerr << "No dynamic memory allocated.\n";
		}
	}

	for (size_t i = 0; i < height; ++i)
	{
		for(size_t j = 0; j<width; ++j)
			if (avgImage[i][j] == 0)
			{
				result[i][j][0] = 0;
				result[i][j][1] = 0;
				result[i][j][2] = 0;
			}
			else
			{
				result[i][j][0] = image[i][j][0];
				result[i][j][1] = image[i][j][1];
				result[i][j][2] = image[i][j][2];
			}
	}

	for (size_t i = 0; i < height; ++i)
		delete[] avgImage[i];
	delete[] avgImage;

	return result;
	
	
}