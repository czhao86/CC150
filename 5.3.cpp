#include <iostream>
#include <string>
using namespace std;

int countone(int a)
{
	int no = 0;
	while (a > 0)
	{
		if (a & 1) no++;
		a >>= 1;
	}
	return no;
}

int larger(int a)
{
	int b = a+1;
	while (countone(b) != countone(a)) b++;
	return b;
}

int smaller(int a)
{
	int c = a - 1;
	while (countone(c) != countone(a)) c--;
	return c;
}

int main()
{
	int a = 11;
	cout<<countone(a)<<endl;
	cout << larger(a) << endl;
	cout << smaller(a) << endl;
}
