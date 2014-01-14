#include <iostream>
using namespace std;

int makeChange(int n, int denom)
{
	int next_denom;
	switch (denom)
	{
	case 25:
		next_denom = 10;
		break;
	case 10:
		next_denom = 5;
		break;
	case 5:
		next_denom = 1;
		break;
	case 1:
		return 1;
	}
	int ways = 0;
	for (int i = 0; i*denom <= n; ++i)
		ways+=makeChange(n - i*denom, next_denom);
	return ways;
}

int makeChange1(int sum, int c, int n)
{
	int ways = 0;
	if (sum <= n)
	{
		if (sum == n) return 1;
		if (c >= 25) ways += makeChange1(sum + 25, 25, n);
		if (c >= 10) ways += makeChange1(sum + 10, 10, n);
		if (c >= 5) ways += makeChange1(sum + 5, 5, n);
		if (c >= 1) ways += makeChange1(sum + 1, 1, n);
	}
	return ways;
}

int main()
{
	cout << makeChange(100, 25) << endl;
	cout << makeChange1(0, 25, 100) << endl;
}
