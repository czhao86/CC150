#include <iostream>
using namespace std;

int flipsign(int a)
{
	int d = a > 0 ? -1 : 1;
	int x = 0;
	while (a != 0)
	{
		a += d;
		x += d;
	}
	return x;
}

int subtract(int x, int y)
{
	return x + flipsign(y);
}

int multiply(int x, int y)
{
	if (x > 0)
	{
		int a = y;
		for (int i = 1; i < x; ++i)
		{
			y += a;
		}
		return y;
	}
	else
	{
		for (int i = 1; i < flipsign(x); ++i)
		{
			y += y;
		}
		return flipsign(y);
	}
}

int divide(int x, int y)
{
	int xx = abs(x), yy = abs(y), n = 0,sign=1;
	while (xx>yy)
	{
		xx -= yy;
		n++;
	}
	if (multiply(x, y) < 0) sign = -1;
	return multiply(sign,n);
}

int main()
{
	cout << flipsign(2) << endl;
	cout << subtract(2,3) << endl;
	cout << multiply(22, 3) << endl;
	cout << divide(22, -3) << endl;
}
