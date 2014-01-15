#include <iostream>
#include <algorithm>
using namespace std;

struct person
{
	int h;
	int w;
};

person p[10];
int d[10];

bool cmp(person p1, person p2)
{
	if (p1.h == p2.h) return p1.w < p2.w;
	else return p1.h < p2.h;
}

int tower(person p[])
{
	int k[6] = { 1, 0, 0, 0, 0, 0 };
	for (int i = 1; i < 6; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (p[i].w>p[j].w)
			{
				if (k[j] + 1>k[i])
					k[i] = k[j] + 1;
			}
		}
	}
	return k[5];
}

int main()
{
	int hh[6] = { 100, 150, 90, 190, 95, 110 };
	int ww[6] = { 65, 70, 56, 75, 60, 68 };
	for (int i = 0; i < 6; ++i)
	{
		p[i].h = hh[i];
		p[i].w = ww[i];
	}
	for (int i = 0; i < 6; ++i)
	{
		cout<<p[i].h<<' '<<p[i].w <<endl;
	}
	sort(p, p + 6, cmp);
	for (int i = 0; i < 6; ++i)
	{
		cout << p[i].h << ' ' << p[i].w << endl;
	}
	cout << tower(p) << endl;
}
