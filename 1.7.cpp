#include <iostream>
using namespace std;

void zero(int a[][4])
{
	int x[4], y[4],i,j;
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		if (a[i][j] == 0) { x[i] = 0; y[j] = 0; }
	}
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		if (x[i] == 0 || y[j] == 0)
			a[i][j] = 0;
	}
}

int main()
{
	int a[4][4] =
	{
		{ 1, 2, 3, 4 },
		{ 5, 6, 0, 8 },
		{ 9, 0, 11, 12 },
		{ 13, 14, 15, 16 }
	};
	for (int i = 0; i < 4; ++i)
	{
		{
			for (int j = 0; j < 4; ++j)
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	zero(a);
	for (int i = 0; i < 4; ++i)
	{
		{
			for (int j = 0; j < 4; ++j)
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
