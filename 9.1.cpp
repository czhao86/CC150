#include <iostream>
using namespace std;

void merge(int a[], int b[])
{
	int m = 4, n = 4, t = 9;
	for (int i = 0; i < 10; ++i)
	{
		if (n >= 0)
		{
			if (a[m]>b[n])
				a[t--] = a[m--];
			else a[t--] = b[n--];
		}
		if (m >= 0)
		{
			a[t--] = a[m--];
		}
	}
}

int main()
{
	int a[10] = { 1, 3, 5, 7, 9 };
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i]<<' ';
	}
	cout << endl;
	int b[5] = { 2, 4, 6, 8, 10 };
	merge(a, b);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i]<<' ';
	}
	cout << endl;
	return 0;
}
