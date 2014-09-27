#include <iostream>
using namespace std;

void merge(int a[], int b[])
{
	int m = 4, n = 4;
	int i;
	for (i = 9; i >=0; --i)
	{
		if (n >= 0 && m>=0)
		{
			if (a[m]>b[n]) {a[i]=a[m];m--;}
			else {a[i]=b[n];n--;}
		}
	}
	while (n>=0)
	{a[i]=b[n];n--;i--;}
	while (m>=0)
	{a[i]=a[m];m--;i--;}
}

int main()
{
	int a[10] = { 1, 3, 5, 7, 9 };
	int b[5] = { 2, 4, 6, 8, 10 };
	merge(a, b);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i]<<' ';
	}
	cout << endl;
	return 0;
}
