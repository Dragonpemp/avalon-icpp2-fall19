#include <iostream>;
#include "Date.hpp";
#include "Header.h";
using namespace std;
using namespace ext;

/*Month intToMOnth(int value)
{
	switch (value)
	{
	case 1:
		return Month::January;
	case 2:
		return Month::February;
	default:
		break;
	}
}*/

int main()
{
	//Date date= { 2001,static_cast<Month>(10),12 };

	Date date = { 2001,Month::April,12 };
	//2-лучший
	print(date,DateFormat::MonthAsInt);  // 2001 04 12

	print(date, DateFormat::MonthAsString);  // 2001  april 12

	//	void print(Month month, DateFormat format = DateFormat::MonthAsInt);
	Month month = Month::February;
	print(month, DateFormat::MonthAsInt);//2
	print(month, DateFormat::MonthAsString);//February
	Date first = { 2005,Month::April,15 };
	Date second = { 2005,Month::April,15 };
	Date third = { 2006,Month::April,15 };
	cout << endl;
	cout << (first == second) << endl;
	cout << (second != third) << endl;
}