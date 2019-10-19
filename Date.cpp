#include "Header.h";
#include <iostream>;
using namespace std;
namespace ext
{
	string monthToString(Month month)
	{
		switch (month)
		{
		case ext::Month::January:
			return "January";
			break;
		case ext::Month::February:
			return "February";
			break;
		case ext::Month::March:
			return "March";
			break;
		case ext::Month::April:
			return "April";
			break;
		case ext::Month::May:
			return "May";
			break;
		case ext::Month::June:
			return "June";
			break;
		case ext::Month::July:
			return "July";
			break;
		case ext::Month::August:
			return "August";
			break;
		case ext::Month::September:
			return "September";
			break;
		case ext::Month::October:
			return "October";
			break;
		case ext::Month::Novemver:
			return "Novemver";
			break;
		case ext::Month::December:
			return "December";
			break;
		default:
			break;
		}
	}

	void print(Date data, DateFormat format)
	{
		cout << data.year << " ";
		print(data.month, format);
		cout << data.day << " " << endl;

	}
	void print(Month month, DateFormat format)
	{
		if (format == DateFormat::MonthAsInt)
		{
			cout << static_cast<int>(month) << " ";
		}
		else if (format == DateFormat::MonthAsString)
		{

			cout << monthToString(month) << " ";
		}
		else
		{
			throw  exception();
		}
	}
	bool operator == (const Date lhs, const Date rhs)
	{
		return lhs.year == rhs.year
			&& lhs.month == rhs.month
			&& lhs.day == rhs.day;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
}