#include <iostream>
#include <map>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

struct point
{
	double x, y;
};

class line
{
public:
	double slope, intercept, epsilon;
	bool bslope;
public:
	line() {}
	line(point p1, point p2)
	{
		epsilon = 0.0001;
		if (abs(p1.x - p2.x) > epsilon)
		{
			intercept = p1.y-(p2.y-p1.y)/(p2.x-p1.x)*p1.x;
			slope = (p2.y - p1.y) / (p2.x - p1.x);
			bslope = true;
		}
		else
		{
			intercept = p1.x;
			bslope = false;
		}
	}
	int hashcode()
	{
		int sl = (int)(slope * 1000);
		int in = (int)(intercept * 1000);
		return (sl*1000 + in);
	}
	void print()
	{
		cout <<"y="<<intercept<<"+"<<slope<<"*x" << endl;
	}
};

line bestline(point *p, int totalnum)
{
	map<int,int> q;
	line bestline;
	bool first = true;
	for (int i = 0; i < totalnum; ++i)
	{
		for (int j = i + 1; j < totalnum; ++j)
		{
			line l(p[i], p[j]);
			if (q.find(l.hashcode()) == q.end())
				q[l.hashcode()] = 0;
			q[l.hashcode()]++;
			if (first)
			{
				bestline = l;
				first = false;
			}
			else
			{
				if (q[l.hashcode()] > q[bestline.hashcode()])
					bestline = l;
			}
		}
	}
	return bestline;
}

int main()
{
	srand((unsigned)time(0));
	int graph_size = 100;
	int point_num = 100;
	point *p = new point[point_num];
	for (int i = 0; i < point_num; ++i)
	{
		p[i].x = rand() / double(RAND_MAX)*graph_size;
		p[i].y = rand() / double(RAND_MAX)*graph_size;
	}
	line bl = bestline(p, 100);
	bl.print();
	return 0;
}
