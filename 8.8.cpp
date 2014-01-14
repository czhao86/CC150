#include <iostream>
#include <cmath>
using namespace std;

int *columnForRow = new int[8];
int cnt = 0;

bool check(int row)
{
	for (int i = 0; i < row; ++i)
	{
		if (abs(columnForRow[row] - columnForRow[i]) == (row - i) || columnForRow[row] - columnForRow[i] == 0)
			return false;
	}
	return true;
}

void placeQueen(int row)
{
	if (row == 8)
	{
		cnt++;
		for (int m = 0; m < 8; ++m)
		{
			cout << columnForRow[m];
		}
		cout << endl;
	}
	for (int i = 0; i < 8; ++i)
	{
		columnForRow[row] = i;
		if (check(row)) placeQueen(row + 1);
	}
}

int main()
{
	placeQueen(0);
	cout << cnt << endl;
}
