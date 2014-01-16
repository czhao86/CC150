#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int total_num = 20000;
	int block_size = 2000;
	int *p = new int[total_num/block_size];
	for (int i = 0; i < total_num / block_size; ++i)
	{
		p[i] = 0;
	}
	freopen("12.3.in", "r", stdin);
	int v;
	while (scanf("%d", &v) != EOF)
		++p[v / block_size];
	fclose(stdin);
	for (int i = 0; i < total_num / block_size; ++i)
	{
		if (p[i] < block_size)
		{
			cout << i << endl;
			break;
		}
	}
	delete[] p;
	return 0;
}
