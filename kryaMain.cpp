#include <iostream>
#include <math.h>
#include <sstream>
#include "Main_Header.h"
#include <fstream>

namespace krya
{
	std::ostream& operator << (std::ostream& out, triangle x)
	{
		out << x.a << ' ' << x.b << ' ' << x.c << ' ' << x.width;
		return out;
	}
	int perimeter(triangle x)
	{
		return x.a + x.b + x.c;
	}
	int digit(int x, int pos)
	{
		int out = x / static_cast<int>(pow(10, pos - 1)) % 10;
		return out;
	}
	void task()
	{
		bool answer = false;
		int size, l_index, r_index;
		int input;
		triangle buf;
		std::cin >> input;
		std::ifstream file;
		file.open("triangle.bin", std::istream::in | std::istream::binary);
		file.seekg(0, std::ios_base::end);
		size = file.tellg() / sizeof(triangle);
		l_index = 0; r_index = size - 1;
		while (l_index != r_index - 1)
		{
			file.seekg(sizeof(triangle)*((l_index + r_index) / 2));
			file.read(reinterpret_cast<char*>(&buf), sizeof(triangle));
			if (input == perimeter(buf))
			{
				std::cout << buf;
				answer = true;
				break;
			}
			else
			{
				if (input > perimeter(buf))
				{
					l_index = (l_index + r_index) / 2;
				}
				else
				{
					r_index = (l_index + r_index) / 2;
				}
			}
		
		}
		if (!answer)
		{
			std::cout << "No Triangle with such perimeter.";
		}


		file.close();
	}

}