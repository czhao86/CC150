#include <iostream>
using namespace std;

int find(int a[], int m, int n, int x)
{
	while (m<n)
	{
		int mid = (m + n) >> 1;
		if (x == a[mid]) return mid;
		if (x > a[mid])
		{
			if (a[mid] > a[m])
				m = mid;
			else
			{
				if (x > a[m])
					n = mid;
				else m = mid;
			}
		}
		else
		{
			if (a[mid] < a[m])
				n = mid;
			else
			{
				if (x>a[m])
					n = mid;
				else m = mid;
			}
		}
	}
}

int main()
{
	int a[] = { 6, 7, 8, 9, 10, 11, 12, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, -1, 0, 1, 2, 3, 4, 5 };
	cout << find(a, 0, 11, 8) << endl;
	cout << find(b, 0, 11, 4) << endl;
}
