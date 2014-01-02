#include <iostream>
#include <stack>
using namespace std;

void print_binary(int n)
{
	stack<int> x;
	while (n>0)
	{
		if (n & 1) x.push(1);
		else x.push(0);
		n >>= 1;
	}
	while (!x.empty())
	{
		cout << x.top();
		x.pop();
	}
	cout << endl;
}

int move(int n, int m, int i, int j)
{
	int max = ~0;
	int left = max - (1 << (j + 1) - 1);
	int right = ((1 << i)-1);
	int mask = left | right;
	return (mask&n)|(m << i);
}

int main()
{
	int N=263, M=31, i=2, j=6;
	print_binary(N);
	print_binary(M);
	print_binary(move(N, M, i, j));
}
