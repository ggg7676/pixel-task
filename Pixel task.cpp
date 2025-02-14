#include <iostream>
#include "fillArea.h"
#include "print.h"
typedef unsigned char pixel[3];


int main()
{
	size_t height, width;
	std::cin >> height;
	std::cin >> width;


	pixel** image = new(std::nothrow) pixel*[height];
	if (!image)
	{
		delete[] image;
		std::cerr << "No dynamic memory allocated.\n";
	}
	for (size_t i = 0; i<height; ++i)
	{
		image[i] = new(std::nothrow)pixel[width];
		if (!image[i])
		{
			for (size_t j = 0; j <= i; ++j)
				delete[] image[j];
			delete[] image;
			std::cerr << "No dynamic memory allocated.\n";
		}
	}

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			for (size_t k = 0; k < 3; ++k)
			{
				unsigned curr;
				std::cin >> curr;
				while (curr < 0 || curr>255)
				{
					std::cout << "Invalid number. Enter a new one: ";
					std::cin >> curr;
				}
				image[i][j][k] = curr;
		}
		
		    }
	}

	size_t row, column;
	std::cin >> row >> column;

	std::cout << std::endl << "before transfromations: " << std::endl;
	print(image, height, width);

	pixel** result = fillArea(image, width, height, row, column);
	if (result)
	{
		std::cout << std::endl << "after transformations: " << std::endl;
		print(result, height, width);
	}
	else
		std::cout << std::endl<< "Unsuccessful transformation. \n";
	
	for (size_t i = 0; i < height; ++i)
		delete[] image[i];
	delete[] image;

	return 0;
}