#include <iostream>
#include "Header.h"
#include <string>
using namespace std;
using namespace ext;
struct Student {
	int Id;
	int Grade;
	string Name;
};
int main()
{

	/*setlocale(0, "");
	Student array[100];
	string data;
	string param;
	for (int i = 0; i < 100; i++) {
		array[i].Grade = GetRandomValue(0, 100);
		array[i].Id = GetRandomValue(1, 1000);
		int length = GetRandomValue(3, 6);
		char letter = GetRandomValue('A', 'Z');
		data += letter;
		for (int j = 1; j < length; ++j) {
			data += GetRandomValue('a', 'z');
		}
		array[i].Name += data;
		data = "";
	}
	for (int i = 0; i < 100; i++) {
		cout << "" << array[i].Id << " " << array[i].Grade << " " << array[i].Name << endl;
	}
	cin >> param;
	if (param == "Id") {
		for (int i = 0; i < 100; ++i) {
			for (int k = 0; k < 100 - 1; ++k) {
				if (array[k].Id > array[k + 1].Id) {
					int temp1 = array[k].Id;
					array[k].Id = array[k + 1].Id;
					array[k + 1].Id = temp1;
					int temp2 = array[k].Grade;
					array[k].Grade = array[k + 1].Grade;
					array[k + 1].Grade = temp2;
					string temp = array[k].Name;
					array[k].Name = array[k + 1].Name;
					array[k + 1].Name = temp;
				}
			}
		}
	}
	else if (param == "Grade") {
		for (int i = 0; i < 100; ++i) {
			for (int k = 0; k < 100 - 1; ++k) {
				if (array[k].Grade > array[k + 1].Grade) {
					int temp1 = array[k].Id;
					array[k].Id = array[k + 1].Id;
					array[k + 1].Id = temp1;
					int temp2 = array[k].Grade;
					array[k].Grade = array[k + 1].Grade;
					array[k + 1].Grade = temp2;
					string temp = array[k].Name;
					array[k].Name = array[k + 1].Name;
					array[k + 1].Name = temp;
				}
			}
		}
	}
	else if (param == "Name") {
		for (int i = 0; i < 100; ++i) {
			for (int k = 0; k < 100 - 1; ++k) {
				if (array[k].Name > array[k + 1].Name) {
					int temp1 = array[k].Id;
					array[k].Id = array[k + 1].Id;
					array[k + 1].Id = temp1;
					int temp2 = array[k].Grade;
					array[k].Grade = array[k + 1].Grade;
					array[k + 1].Grade = temp2;
					string temp = array[k].Name;
					array[k].Name = array[k + 1].Name;
					array[k + 1].Name = temp;
				}
			}
		}

	}
	for (int i = 0; i < 100; i++) {
		cout << "" << array[i].Id << " " << array[i].Grade << " " << array[i].Name << endl;
	}
}*/

int Marks[100][5];
float Students[100];
int sum = 0, rand = 0;
for (int i = 0; i < 100; i++) {
	for (int j = 0; j < 5; j++) {
		rand = GetRandomValue(2, 5);
		Marks[i][j] = rand;
		sum += rand;
	}
	Students[i] = static_cast<float>(sum) / 5;
	sum = 0;
}
for (int j = 0; j < 100; j++) {
	for (int k = 0; k < 99; k++) {
		if (Students[k] > Students[k + 1]) {
			swap(Marks[k], Marks[k + 1]);
			swap(Students[k], Students[k + 1]);
		}
	}
}
cout << "25%";
for (int j = 0; j < 5; j++) {
	cout << Marks[26][j] << " ";
}
cout << endl;
cout << "50%";
for (int j = 0; j < 5; j++) {
	cout << Marks[51][j] << " ";
}
cout << endl;
cout << "75%";
for (int j = 0; j < 5; j++) {
	cout << Marks[76][j] << " ";
}
cout << endl;
}
