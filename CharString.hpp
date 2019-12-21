#pragma once
namespace ext
{
	struct CharString
	{
		char symbol;
		CharString* nextSymbol;
	};

	void append(CharString* ptr, char symbol);
	void print(CharString* ptr);
	char characterAt(CharString* ptr, int q);
	void removeChars(CharString* ptr, int q, int w);

}
