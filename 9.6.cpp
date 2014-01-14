#include <iostream>
using namespace std;

void find(int a[][5], int goal)
{
	int x = 0, y = 4;
	while (x <= 4 && x >= 0)
	{
		if (goal == a[x][y]) cout << x << ' ' << y << endl;
		if (goal > a[x][y]) x++;
		else y--;
	}
	cout << "not found!" << endl;
}

int main()
{
	int a[][5] = { { 1, 2, 3, 4, 5 },
	{ 3, 7, 8, 9, 11 },
	{ 5, 9, 10, 17, 18 },
	{ 7, 12, 15, 19, 23 },
	{ 9, 13, 16, 20, 25 } };
	find(a, 100);
}
