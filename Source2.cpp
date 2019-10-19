#include <iostream>
#include <cmath>
using namespace std;


struct Point
{
	float x;
	float y;
};
namespace my
{
	void swap(int *ptrA, int *ptrB)
	{
		int temp = *ptrA;
		*ptrA = *ptrB;
		*ptrB = temp;
	}
	void swap(int &ptrA, int &ptrB)
	{
		int temp = ptrA;
		ptrA = ptrB;
		ptrB = temp;
	}
}
Point & min(Point &a, Point &b)
{
	float dA = sqrt(a.x * a.x + a.y * a.y);
	float dB = sqrt(b.x * b.x + b.y * b.y);
	if (dA < dB) return a;
	return b;
}
Point& operator ++ (Point& point)
{
	++point.x;
	++point.y;
	return point;
}
Point& operator ++ (Point& point,int)
{
	++point.x;
    point.y;
	return point;
}
int main()
{
	/*int first = 10;
int second = 12;


int& reffirst = first;
cout << first << " " << second << endl;
my::swap(&first, &second);
cout << first << " " << second << endl;*/
Point first{ 2.2F,2.5F };
Point second{ 2.5F,2.6F };

Point &minPoint = min(first, second);
}