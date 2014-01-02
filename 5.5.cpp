#include <iostream>
#include <string>
using namespace std;

int bitsno(int a, int b)
{
	int c = a^b, count = 0;
	while (c > 0)
	{
		if (c & 1) count++;
		c >>= 1;
	}
	return count;
}

int main()
{
	int a = 11, b = 12;
	cout<<bitsno(a,b)<<endl;
}
