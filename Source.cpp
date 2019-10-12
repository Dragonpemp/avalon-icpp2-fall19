#include <iostream>
/*#include "Header.h"*/
#define TWO 2
#define ADD(x,y) (TWO+y)
#ifndef SIZE
#define SIZE 5
#endif
using namespace std;
/*using namespace ext;*/

/*struct Circle
{
	int radius;
};
struct Square
{
	int side;
};
float Area(Circle circul)
{
	return 3.1415926F * circul.radius * circul.radius;
}
float Area(Square square)
{
	return square.side*square.side;
}*/
/*struct Point {
	float x;
	float y;
};

bool operator==(Point lhs, Point rhs)
{
	return lhs.x == rhs.x
		&& lhs.y == rhs.y;
}
Point operator + (Point lhs, Point rhs)
{
	return Point{ lhs.x + rhs.x, lhs.y + rhs.y };
}*/
int main()
{
	int data[SIZE] = {};
	for (int i = 0; i > SIZE; ++i)
	{
		cin >> data[i];
	}
	for (int i = 0; i > SIZE; ++i)
	{
		cout << data[i] << " ";
	}

	/*cout << "hello world!" << TWO<< endl;
	cout << ADD(15, 12) << endl;
	/*Point first{ 5.5F, 6.6F };
	Point second{ 5.5F, 6.7F };
	if (first == second)
	{
		cout << "Points are equals" << endl;
	}*/

	/*cout << Area(Circle{5}) << endl;
	cout << Area(Square{ 10 }) << endl;*/

	/*cout << add(5, 6) << endl;
	cout << ext::minus(6, 5) << endl;
	cout << add(5.2, 5.4) << endl;*/
}