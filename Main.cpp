#include <iostream>
#include "Header.h"


	//Returns the index of the last element (\0).
	int lenth(char_array s)
	{
		int out = 0;
		while (s[out] != '\0') 
		{
			++out;
		}
		return out;
	}

	//Concatenates two char arrays and renames first pointer to the new char array.
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

		/*
		for (int i = len(first); i < len(first)+len(second); ++i)
		{
			out[i] = second[i-len(first)];
		}*/
		out[lenth(first) + lenth(second)] = '\0';
		delete[] first;
		first = out;
	}

	//Returns character given counting from 1.
	char characterAt(char_array s, int position)
	{
		if ((position <= 0) || (position > lenth(s))) { s[0]; }
		else { return s[position - 1]; }
	}

	//Append the char in the end of array and renames pointer to the new char array.
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

	//Return new array which contains first "length" symbols from "start"(counting from 1).
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
	//setlocale(0, "");
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