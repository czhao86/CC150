#include <iostream>
using namespace std;

class bitmap
{
	int *p;
public:
	bitmap(int size = 32)
	{
		p = new int[size / 32];
		memset(p, 0, 1000);
	}
	~bitmap(){ delete[] p; }
	bool check(int n)
	{
		return ((p[n / 32])&(1 << n % 32));
	}
	void set(int n)
	{
		p[n / 32] |= (1 << n % 32);
	}
};

void checkDuplicate(int a[], int n)
{
	bitmap bm(32000);
	for (int i = 0; i < n; ++i)
	{
		if (bm.check(a[i])) cout << a[i] << endl;
		else bm.set(a[i]);
	}

}

int main()
{
	int a[] = {
		1, 2, 3, 4, 5, 32000, 7, 8, 9, 10, 11, 1, 2, 13, 15, 16, 32000, 11, 5, 8
	};
	checkDuplicate(a, 20);
	return 0;
}
