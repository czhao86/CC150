#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int size_int = sizeof(int)*8;
	int n = 0xFFFFFFFF / size_int;
	int *p = new int[n];
	freopen("12.3.in","r",stdin);
	int v;
	while (scanf("%d", &v) != EOF)
		p[v / size_int] |= 1<<p[v%size_int];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < size_int; ++j)
		{
			if (p[i]&(1<<j)==0)
			{
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
	delete[] p;
	fclose(stdin);
	return 0;
}
