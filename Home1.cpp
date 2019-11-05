#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	long long ISBN, Num, ISBNtest, ISBNuser;
	bool valid = false;
	cout << "¬ведите : ";
	cin >> Num;
	cout << endl;
	for (int i = 1; i <= Num; ++i)
	{
		cout << "¬ведите ISBN #" << i << " ";
		cin >> ISBN;
		ISBNuser = ISBN % 10;
		ISBN /= 10;
		ISBNtest = 0;
		for (int j = 1; j <= 12; ++j)
		{
			if (j % 2 == 1) ISBNtest += (ISBN % 10) * 3;
			else ISBNtest += (ISBN % 10) * 1;
			ISBN /= 10;
		}
		ISBNtest %= 10;
		ISBNtest = 10 - ISBNtest;
		valid = ISBNuser == ISBNtest;
		if (valid) cout << " валиден" << endl;
		else cout << " невалиден" << endl;
		cout << endl;
	}

}