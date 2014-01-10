#include <iostream>
using namespace std;

int fibor(int n)
{
	if (n == 1 || n == 2) return 1;
	else return fibor(n - 1) + fibor(n - 2);
}

void fibo(int n)
{
	int a[100];
	memset(a, 0, sizeof(a));
	a[0] = 1;
	a[1] = 1;
	cout << a[0] << ' ' << a[1] << ' ';
	int m = 0;
	for (int i = 0; i < n-2; ++i)
	{
		cout << (a[m+2]=a[m] + a[m + 1]) << ' ';
		m++;
	}
	cout << endl;
}

int main()
{
	int x;
	cin >> x;
	fibo(x);
	cout << fibor(x) << endl;
	return 0;	
}
