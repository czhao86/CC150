#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool m[20][20], n[20];
queue<int> q;

void init()
{
	memset(m, false, sizeof(m));
	memset(n, false, sizeof(n));
}

bool route(int a, int b)
{
	q.push(a);
	while (!q.empty())
	{
		int r = q.front();
		q.pop();
		if (r == b) return true;
		for (int i = 0; i < 20; ++i)
		{
			if (m[r][i] && !n[i]) {
				q.push(i); n[i] = true;
			}
		}
	}
	return false;
}

int main()
{
	init();
	//freopen("D:\4.2.in", "r", stdin);
	//int nn,mm,u,v;
	//cin >> nn >> mm;
	//cout << nn << mm << endl;
	//for (int j = 0; j < mm; ++j)
	//{
	//	cin >> u >> v;
	//	m[u][v] = true;
	//}
	m[0][1] = true;
	m[1][0] = true;
	m[1][5] = true;
	m[5][3] = true;
	m[3][2] = true;
	m[2][6] = true;
	cout << route(0, 6) << endl;
	fclose(stdin);
	return 0;
}
