#include <iostream>
#include "Header.h"



	int lenth(char_array s)
	{
		int out = 0;
		while (s[out] != '\0') 
		{
			++out;
		}
		return out;
	}


	void concatenate(char_array &first, char_array second)
	{
		char_array out = new char[lenth(first) + lenth(second) - 1];
		for (int i = 0; i < lenth(first); ++i)
		{

			out[i] = first[i];
		}

		for (int i = 0; i < lenth(second); ++i)
		{
			out[lenth(first) + i] = second[i];
		}
		out[lenth(first) + lenth(second)] = '\0';
		delete[] first;
		first = out;
	}

	char characterAt(char_array s, int position)
	{
		if ((position <= 0) || (position > lenth(s))) { s[0]; }
		else { return s[position - 1]; }
	}

	void append(char_array &s, char input)
	{
		char_array out = new char[lenth(s) + 2];
		for (int i = 0; i < lenth(s); ++i)
		{
			out[i] = s[i];
		}
		out[lenth(s)] = input;
		out[lenth(s) + 1] = '\0';
		delete[] s;
		s = out;
	}


	char_array substring(char_array& s, int start, int length)
	{
		char_array out = new char[length];
		for (int i = start - 1; i < start + length; ++i)
		{
			out[i] = s[i];
		}
		return out;
	}


int main()
{
	setlocale(0, "");
	char_array first = new char[6]{ "first" };
	char_array second = new char[8]{ " second" };
	concatenate(first, second);
	append(first, '!');

	for (int i = 0; i < lenth(first); ++i)
	{
		std::cout << first[i];
	}

	/*first = substring(first, 3, 5);
	for (int i = 2; i < lenth(first); ++i)
	{
		std::cout << first[i];
	}*/
}