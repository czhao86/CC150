#include <iostream>
using namespace std;

void paren(int l, int r, char a[], int count)
{
	if (l<0 || l>r) return;
	if (l == 0 && r == 0)
	{
		for (int i = 0; i<8; ++i)
		{
			cout << a[i];
		}
		cout << endl;
	}
	if (l > 0)
	{
		a[count] = '(';
		paren(l - 1, r, a, count + 1);
	}
	if (l < r)
	{
		a[count] = ')';
		paren(l, r - 1, a, count + 1);
	}
}

int main()
{
	char a[8];
	paren(4, 4, a, 0);
}
