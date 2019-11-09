#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
int main()
{
	int Workers[10][12];
	int Median[10];
	for (int i = 0;i < 10;i++)
	{
		int ef = GetRandomValue(0, 1); 
		if (ef == 0)
		{
			int k = GetRandomValue(0, 9);
			for (int j=0;j < k; j++)
			{
				Workers[i][j] = -1;
			}
			for (int j = k;j < 12; j++)
			{
				Workers[i][j] = GetRandomValue(1000, 116500);
				if (Workers[i][j] > 100000)
				{
					Workers[i][j] = -1;
				}
			}
		
		}
		else if (ef == 1)
		{
			int k = GetRandomValue(2, 11);
			for (int j = k;j < 12; j++)
			{
				Workers[i][j] = -1;
			}
			for (int j = 0;j < k; j++)
			{
				Workers[i][j] = GetRandomValue(1000, 116500);
				if (Workers[i][j] > 100000)
				{
					Workers[i][j] = -1;
				}
			}
		}
	}
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 12;j++)
		{
			for (int l = 0; l < 12-1; ++l) {
				if (Workers[i][l] > Workers[i][l+1])
				{
						int temp = Workers[i][l];
						Workers[i][l] = Workers[i][l + 1];
						Workers[i][l + 1] = temp;

				}				
			}
		}
	}
	int counter = 0;
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 12;j++)
		{
			if (Workers[i][j] == -1)
				counter++;
		}
		if (counter / 2==1)
		{
			Median[i] = Workers[i][(12 - counter) / 2 + 1 + counter - 1];
		}
		else if (counter / 2 == 0)
		{
			Median[i] = (Workers[i][(12 - counter) / 2 + counter]+ Workers[i][(12 - counter) / 2  + counter - 1]) / 2;
		}
		int l = (12 - counter) / 2 + 1 + counter - 1;
		counter = 0;

	}
}