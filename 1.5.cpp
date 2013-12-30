#include <iostream>
using namespace std;

string space(string a)
{
	string b="";
	for (int i = 0; i < a.length(); ++i)
	{
		if (a[i] != ' ') b += a[i];
		if (a[i] == ' ') b += "%20";
	}
	return b;
}

int main()
{
	string x = "abc de f";
	string y = space(x);
	for (int i = 0; i < y.length();++i)
		cout << y[i];
	cout << endl;
	return 0;
}
