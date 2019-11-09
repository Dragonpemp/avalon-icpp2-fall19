#include "Date.hpp";
#include <iostream>;
using namespace std;
namespace ext
{
	TimeDelta countJND(Date date)
	{
		int a, y, m, day = date.day, month = static_cast<int>(date.month), year = date.year;
		TimeDelta JDN;
		a = (14 - month) / 12;
		y = year + 4800 - a;
		m = month + (12 * a) - 3;
		JDN.delta = day + int((153 * m + 2) / 5) + int(365 * y) + int(y / 4) - int(y / 100) + int(y / 400) - 32045;
		return JDN;
	}
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
	Season getSeason(Month month)
	{
		if ((static_cast<int>(month) == 12) || (static_cast<int>(month) == 1) || (static_cast<int>(month) == 2))
		{
			return Season::Winter;
		}
		if ((static_cast<int>(month) > 2) & (static_cast<int>(month) < 6))
		{
			return Season::Spring;
		}
		if ((static_cast<int>(month) > 5) & (static_cast<int>(month) < 9))
		{
			return Season::Summer;
		}
		if ((static_cast<int>(month) > 8) & (static_cast<int>(month) < 12))
		{
			return Season::Autumn;
		}

	}
	Season getSeason(Date date)
	{
		return getSeason(date.month);

	}
	bool  operator == (const Date lhs, const Date rhs)
	{
		return lhs.day == rhs.day
			&& lhs.month == rhs.month
			&& lhs.year == rhs.year;
	}
	bool operator != (const Date lhs, const Date rhs)
	{
		return !(lhs == rhs);
	}
	bool operator < (const Date lhs, const Date rhs)
	{
		return lhs.day < rhs.day
			&& lhs.month < rhs.month
			&& lhs.year < rhs.year;
	}
	bool operator <= (const Date lhs, const Date rhs)
	{
		return(lhs == rhs) || (lhs < rhs);
	}
	bool operator > (const Date lhs, const Date rhs)
	{
		return lhs.day > rhs.day
			&& lhs.month > rhs.month
			&& lhs.year > rhs.year;
	}
	bool operator >= (const Date lhs, const Date rhs)
	{
		return (lhs == rhs) || (lhs > rhs);
	}
	Date JDNToDate(TimeDelta delta) {
		Date output;
		int a = delta.delta + 32044;
		int b = ((4 * a) + 3) / 146097;
		int c = a - ((146097 * b) / 4);
		int d = ((4 * c) + 3) / 1461;
		int e = c - ((1461 * d) / 4);
		int m = ((5 * e) + 2) / 153;
		output.day = e - ((153 * m + 2) / 5) + 1;
		output.month = static_cast<Month>(m + 3 - 12 * (m / 10));
		output.year = (100 * b) + d - 4800 + (m / 10);
		return output;
	}
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta one;
		one.delta= lhs.delta + rhs.delta;
		return one;
	}
	Date operator + (const Date date, const TimeDelta delta) {
		TimeDelta one = countJND(date);
		return JDNToDate(one + delta);
	}
	Date operator + (const TimeDelta delta, const Date date) {
		TimeDelta one = countJND(date);
		return JDNToDate(one + delta);
	}
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs) {
		TimeDelta one;
		one.delta = lhs.delta - rhs.delta;
		return one;
	}
	Date operator - (const Date date, const TimeDelta delta) {
		TimeDelta one = countJND(date);
		return JDNToDate(one - delta);
	}
	Date operator - (const TimeDelta delta, const Date date) {
		TimeDelta one = countJND(date);
		return JDNToDate(one - delta);
	}
	TimeDelta operator * (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta * multiplier);
		return one;
	}
	TimeDelta operator / (const TimeDelta delta, int multiplier) {
		TimeDelta one;
		one.delta = (delta.delta / multiplier);
		return one;
	}
	TimeDelta operator ++ (TimeDelta& delta)
	{
		++delta.delta;
		return delta;
	}
	TimeDelta operator ++ (TimeDelta& delta, int)
	{
		
		++delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta)
	{
		--delta.delta;
		return delta;
	}
	TimeDelta operator -- (TimeDelta& delta, int)
	{

		--delta.delta;
		return delta;
	}
	Date operator ++ (Date& delta)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator ++ (Date& delta,int)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator ++ (Date& delta)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	Date operator ++ (Date& delta, int)
	{
		delta.day++;
		delta.year++;
		delta.month = static_cast<Month>(static_cast<int>(delta.month) + 1);
		return delta;
	}
	void swap(Date& lhs, Date& rhs)
	{
		Date	temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
	void swap(TimeDelta& lhs, TimeDelta& rhs)
	{
		TimeDelta temp = lhs;
		lhs = rhs;
		rhs = temp;
	}
	Date & max(Date & lhs, Date & rhs)
	{
		if (lhs > rhs)
		{
			return lhs;
		}
		else
		{
			return rhs;
		}
	}
	Date & min(Date & lhs, Date & rhs)
	{
		if (lhs > rhs)
		{
			return rhs;
		}
		else
		{
			return lhs;
		}
	}
	Date& getMinDate(Date dates[], int size)
	{
		Date min = dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta < countJND(min).delta)
			{
				min = dates[i];
			}
		}
		return min;
	}
	Date& getMaxDate(Date dates[], int size)
	{
		Date max = dates[0];

		for (int i = 1; i < size; ++i)
		{
			if (countJND(dates[i]).delta > countJND(max).delta)
			{
				max = dates[i];
			}
		}
		return max;
	}
	void sort(Date dates[],int size, SortBy sortBy)
	{ 
		if (sortBy == SortBy::Date) {
			for (int i = 0; i < size; ++i) {
				for (int k = 0; k < size - 1; ++k) {
					if (dates[k] >dates[k + 1]) {
						Date temp1 = dates[k];
						dates[k] = dates[k + 1];
						dates[k + 1] = temp1;
					}
				}
			}
		}
	else if (sortBy == SortBy::Season) {
		for (int i = 0; i < size; ++i) {
			for (int k = 0; k < size - 1; ++k) {
				if (getSeason(dates[k].month)> getSeason(dates[k + 1].month))
				{
					Date temp = dates[k];
					dates[k] = dates[k + 1];
					dates[k + 1] = temp;

				}
				
			}
		}
	}
	}
	bool Vis(int year)
	{
		bool vis;
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			vis = true;
		}
		else
		{
			vis = false;
		}
		return vis;
	}
	int DayMax(bool vis, int month)
	{
		int daymax;
		int monthx = month % 2;
		switch (monthx)
		{
		case 1:

			if ((month == 9) || (month == 11))
			{
				daymax = 30;
			}
			else
			{
				daymax = 31;
			}
			break;
		case 0:
			if ((month == 8) || (month == 10) || (month == 12))
			{
				daymax = 31;
			}
			else if (month == 2)
			{
				daymax = 28;
			}
			else
			{
				daymax = 30;
			}
			break;
		}
		if ((vis) && (month == 2))
		{
			daymax = 29;
		}
	}
	Date& tryFillDate(int& year , int& month, int& day)
	{
		Date data;
		bool vis = Vis(year); 
		int  daymax = DayMax(vis, month), monthx;
		daymax = DayMax(vis, month);
		if ((day < daymax) && (month <= 12))
		{
			data.day = day;
			data.year = year;
			data.month = static_cast<Month>(month);
		}
		else
		{
			throw std::exception("Даты не существует");
		}
		return data ;
	}
}
