#include <iostream>
using namespace std;

void transpose(int a[][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
			swap(a[i][j], a[j][i]);
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
			swap(a[j][i], a[j][3-i]);
	}
}

int main()
{
	int a[4][4]=
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	for (int i = 0; i < 4; ++i)
	{
		{
			for (int j = 0; j < 4; ++j)
			cout << a[i][j]<<' ';
		}
		cout << endl;
	}
	transpose(a);
	for (int i = 0; i < 4; ++i)
	{
		{
			for (int j = 0; j < 4; ++j)
			cout << a[i][j]<<' ';
		}
		cout << endl;
	}
	return 0;
}
