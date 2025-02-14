#include <iostream>

typedef unsigned char pixel[3];

void print(pixel** image, size_t height, size_t width)
{
	for (unsigned i = 0; i < height; ++i)
	{
		for (unsigned j = 0; j < width; ++j)
		{
			for (unsigned k = 0; k < 3; ++k)
			{
				unsigned curr = image[i][j][k];
				std::cout << (unsigned)curr << " ";
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}