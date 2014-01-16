#include <iostream>
#include <queue>
using namespace std;

int mini(int a, int b)
{
	int c = a < b ? a : b;
	return c;
}

int minim(int a, int b, int c)
{
	return mini(mini(a, b), mini(b, c));
}

int findnth(int n)
{
	queue<int> q3, q5, q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	int small;
	for (int i = 0; i < n; ++i)
	{
		small = minim(q3.front(), q5.front(), q7.front());
		if (small == q7.front())
			q7.pop();
		else
		{
			if (small == q5.front())
				q5.pop();
			else
			{
				if (small == q3.front())
					q3.pop();
				q3.push(small * 3);
			}
			q5.push(small * 5);
		}
		q7.push(small * 7);
	}	
	return small;
}

int main()
{
	for (int i = 1; i < 13; ++i)
	{
		cout << findnth(i) << endl;
	}

}
