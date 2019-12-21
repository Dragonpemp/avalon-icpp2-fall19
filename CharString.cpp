#include "CharString.hpp"
#include <iostream>
namespace ext
{
	void append(CharString* ptr, char symbol)
	{
		if (ptr == nullptr)
		{
			throw std::exception("Fuck!");
		}

		CharString* newSymbol = new CharString{ symbol };
		while (ptr->nextSymbol != nullptr)
		{
			ptr = ptr->nextSymbol;
		}
		ptr->nextSymbol = newSymbol;
	}



	void print(CharString* ptr)
	{
		while (ptr != nullptr)
		{
			std::cout << ptr->symbol;
			ptr = ptr->nextSymbol;
		}
	}

	char characterAt(CharString* ptr, int one)
	{
		if (one == 0) one = 1;
		for (int i = 1; i < one; ++i)
		{
			ptr = ptr->nextSymbol;
		}
		return ptr->symbol;
	}

	void removeChars(CharString* ptr, int first, int second)
	{
		CharString *temp;
		if (first == 0) first = 1;
		for (int i = 1; i < first - 1; ++i)
		{
			ptr = ptr->nextSymbol;
		}
		for (int i = 1; i < second + 1; ++i)
		{
			temp = ptr->nextSymbol;
			ptr->nextSymbol = ptr->nextSymbol->nextSymbol;
			delete temp;
		}

	}

}