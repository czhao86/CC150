#include <iostream>
#include <string>
using namespace std;

void find(int a[], int n)
{
	int current[4];
	for (int j = 0; j < 4; ++j)
	{
		current[j] = 0;
		int c[10], d[10],mm=0,nn=0;
		for (int i = 0; i < n; ++i)
		{
			if (((a[i] >> j) & 1) == 1)	
			{
				c[mm] = a[i]; mm++;
			}
			else
			{
				d[nn] = a[i]; nn++;
			}
		}
		if (mm >= nn)
		{	current[j] = 0;
			for (int p = 0; p < nn; ++p)
				a[p] = d[p];
			n = nn;}
		else
		{	current[j] = 1;
			for (int q = 0; q < mm; ++q)
				a[q] = c[q];
			n = mm;}
	}	
	for (int k = 3; k >=0; k--)
	{
		cout << current[k];		
	}
	cout << endl;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10 };
	find(a, 10);
}
